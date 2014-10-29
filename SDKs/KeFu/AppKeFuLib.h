//
//  AppKeFuLib.h
//  AppKeFuLib
//
//  Created by jack on 14-5-18.
//  Copyright (c) 2014年 appkefu.com. All rights reserved.
//

#import <Foundation/Foundation.h>

//登录成功通知
#define APPKEFU_LOGIN_SUCCEED_NOTIFICATION          @"appkefu_login_succeed_notification"

//客服工作组在线状态
#define APPKEFU_WORKGROUP_ONLINESTATUS              @"appkefu_workgroup_online_status"


@interface AppKeFuLib : NSObject

//1. 获取AppKeFuLib单例
+(AppKeFuLib *)sharedInstance;

//2.登录, appkey需要开发者到 http://appkefu.com 申请
-(void)loginWithAppkey:(NSString *)appkey;

//3. 注销，退出登录
-(void)logout;

//4. 显示会话窗口
- (void)pushChatViewController:(UINavigationController *)navController
             withWorkgroupName:(NSString *)workgroupName                        //1. 需要填写 工作组名称，需要到管理后台申请，
                                                                                //   注意：不是客服用户名，而是工作组名称，支持多客服
    rightBarButtonItemCallback:(void (^)())rightBarButtonTouchUpInsideCallback  //2. 会话页面右上角按钮回调函数；注意:VIP接口，需要另行开通
        showInputBarSwitchMenu:(BOOL)shouldShowInputBarSwitchMenu               //3. 在会话窗口显示自定义菜单, 类似于微信的自定义菜单；
                                                                                //      如果需要显示自定义菜单,请首先到管理后台分配自定义菜单,请分配且只分配三个自定义菜单,多于三个的自定义菜单将不予显示。
                                                                                //      显示: YES, 不显示: NO
                     withTitle:(NSString *)title                                //4. 自定义会话窗户标题

               withProductInfo:(NSString *)productInfo                          //5. 成功连接客服之后,自动将此消息发送给客服,
                                                                                //   如果不需要发送此信息, 可将其设置为 nil 或者 ""
    withLeftBarButtonItemColor:(UIColor *)color                                 //6. 导航左上角“结束会话”按钮颜色
      hidesBottomBarWhenPushed:(BOOL)shouldHide;                                //7. 从具有Tabbar的viewController打开的时候,隐藏tabbar


//4.1
-(void)presentChatViewController:(UIViewController *)navController
               withWorkgroupName:(NSString *)workgroupName
      rightBarButtonItemCallback:(void (^)())rightBarButtonTouchUpInsideCallback
          showInputBarSwitchMenu:(BOOL)shouldShowInputBarSwitchMenu
                       withTitle:(NSString *)title
                 withProductInfo:(NSString *)productInfo
      withLeftBarButtonItemColor:(UIColor *)color
        hidesBottomBarWhenPushed:(BOOL)shouldHide;

//5.查询工作组当前在线状态，如果工作组内客服至少有一个客服账号在线，则显示在线。否则，显示离线
-(void) queryWorkgroupOnlineStatus:(NSString *)workgroupname;

//5.1 清空与workgroupName的所有聊天信息
- (void) deleteMessagesWith:(NSString*)workgroupName;

#pragma mark 用户标签

//函数6：设置用户标签昵称
- (NSString *)getTagNickname;

//函数7：获取用户标签昵称
- (void) setTagNickname:(NSString *)nickname;

//函数8：设置用户标签性别
- (NSString *)getTagSex;

//函数9：获取用户标签性别
- (void) setTagSex:(NSString *)sex;

//函数10：设置用户标签语言
- (NSString *)getTagLanguage;

//函数11：获取用户标签语言
- (void) setTagLanguage:(NSString *)language;

//函数12：设置用户标签城市
- (NSString *)getTagCity;

//函数13：获取用户标签城市
- (void) setTagCity:(NSString *)city;

//函数14：设置用户标签省份
- (NSString *)getTagProvince;

//函数15：获取用户标签省份
- (void) setTagProvince:(NSString *)province;

//函数16：设置用户标签国家
- (NSString *)getTagCountry;

//函数17：设置用户标签国家
- (void) setTagCountry:(NSString *)country;

//函数18：设置用户标签其他
- (NSString *)getTagOther;

//函数19：获取用户标签其他
- (void) setTagOther:(NSString *)other;

//函数20：上传DeviceToken，用于离线消息推送
- (void) uploadDeviceToken:(NSData *)deviceToken;

@end















