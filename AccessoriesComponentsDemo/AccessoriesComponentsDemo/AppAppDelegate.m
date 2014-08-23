//
//  AppAppDelegate.m
//  AccessoriesComponentsDemo
//
//  Created by huangxinping on 8/23/14.
//  Copyright (c) 2014 ShareMerge. All rights reserved.
//

#import "AppAppDelegate.h"
#import "UMessage.h"

#define _IPHONE80_ 80000

@implementation AppAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
	{ // 推送
		[UMessage startWithAppkey:@"53f8292ffd98c585b202215c" launchOptions:launchOptions];
#if __IPHONE_OS_VERSION_MAX_ALLOWED < _IPHONE80_
		//register remoteNotification types
		[UMessage registerForRemoteNotificationTypes:UIRemoteNotificationTypeBadge
		 | UIRemoteNotificationTypeSound
		 | UIRemoteNotificationTypeAlert];
#else
		//register remoteNotification types
		UIMutableUserNotificationAction *action1 = [[UIMutableUserNotificationAction alloc] init];
		action1.identifier = @"action1_identifier";
		action1.title = @"Accept";
		action1.activationMode = UIUserNotificationActivationModeForeground; //当点击的时候启动程序

		UIMutableUserNotificationAction *action2 = [[UIMutableUserNotificationAction alloc] init];  //第二按钮
		action2.identifier = @"action2";
		action2.title = @"Reject";
		action2.activationMode = UIUserNotificationActivationModeBackground; //当点击的时候不启动程序，在后台处理
		action2.authenticationRequired = YES; //需要解锁才能处理，如果action.activationMode = UIUserNotificationActivationModeForeground;则这个属性被忽略；
		action2.destructive = YES;

		UIMutableUserNotificationCategory *categorys = [[UIMutableUserNotificationCategory alloc] init];
		categorys.identifier = @"alert"; //这组动作的唯一标示
		[categorys setActions:@[action1, action2] forContext:(UIUserNotificationActionContextMinimal)];

		UIUserNotificationSettings *userSettings = [UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeBadge | UIUserNotificationTypeSound | UIUserNotificationTypeAlert
		                                                                             categories:[NSSet setWithObject:categorys]];
		[UMessage registerRemoteNotificationAndUserNotificationSettings:userSettings];
#endif

#ifdef DEBUG
		[UMessage setLogEnabled:YES];
#endif

		[UMessage addTag:@[@"摄像", @"人物"] response: ^(id responseObject, NSInteger remain, NSError *error) {
		    if (responseObject) {
		        NSLog(@"添加成功！");
			}
		    else {
		        NSLog(@"%@", error.localizedDescription);
			}
		}];
		[UMessage addAlias:@"huangxinping's iPhone" type:@"iPhoneDevice" response: ^(id responseObject, NSError *error) {
		    if (responseObject) {
		        NSLog(@"添加成功！");
			}
		    else {
		        NSLog(@"%@", error.localizedDescription);
			}
		}];
	}
	return YES;
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
	[UMessage registerDeviceToken:deviceToken];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
	//关闭友盟自带的弹出框
//    [UMessage setAutoAlert:NO];

	[UMessage didReceiveRemoteNotification:userInfo];

//    self.userInfo = userInfo;
//    //定制自定的的弹出框
//    if([UIApplication sharedApplication].applicationState == UIApplicationStateActive)
//    {
//        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"标题"
//                                                            message:@"Test On ApplicationStateActive"
//                                                           delegate:self
//                                                  cancelButtonTitle:@"确定"
//                                                  otherButtonTitles:nil];
//
//        [alertView show];
//
//    }
}

//- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
//{
//    [UMessage sendClickReportForRemoteNotification:self.userInfo];
//}

- (void)applicationWillResignActive:(UIApplication *)application {
	// Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
	// Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
	// Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
	// If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
	// Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
	// Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
	// Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
