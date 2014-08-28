//
//  BDRecognizerViewParamsObject.h
//  BDVoiceRecognitionClient
//
//  Created by Baidu on 13-9-25.
//  Copyright (c) 2013年 Baidu, Inc. All rights reserved.
//

// 头文件
#import <Foundation/Foundation.h>
#import "BDVoiceRecognitionClient.h"

// 枚举 - 弹窗中连续上屏效果开关
typedef enum
{
    BDRecognizerResultShowModeWholeShow     = 0,  // 无连续上屏效果
    BDRecognizerResultShowModeContinuousShow,     // 连续上屏效果支持
} TBDRecognizerResultShowMode;

// 枚举 - 播放提示音开关
typedef enum
{
    EBDRecognizerPlayTonesRecordForbidden = 0,                  // 不开启提示音
    EBDRecognizerPlayTonesRecordPlay = 1,                          //  提示音开启
} TBDRecognizerPlayTones;

// 枚举 - 设置识别语言
typedef enum
{
    BDVoiceRecognitionLanguageChinese = 0,
    BDVoiceRecognitionLanguageCantonese,
    BDVoiceRecognitionLanguageEnglish,
} TBDVoiceRecognitionLanguage;

// @class - BDRecognizerViewParamsObject
// @brief - 语音识别弹窗参数配置类
@interface BDRecognizerViewParamsObject : NSObject

@property (nonatomic, copy) NSString *productID;  // 向百度语音技术部申请
@property (nonatomic, copy) NSString *apiKey;  // 开发者apiKey，在百度开放平台申请
@property (nonatomic, copy) NSString *secretKey;  // 开发者secretKey，在百度开放平
@property (nonatomic) BOOL isNeedNLU;  // 是否请求语义解析，只对搜索模式有影响
@property (nonatomic) TBDVoiceRecognitionLanguage language;   // 识别语言
@property (nonatomic) TBDVoiceRecognitionProperty recognitionProperty;  // 识别模式
@property (nonatomic) BOOL disablePuncs;  // 是否禁止标点
@property (nonatomic) TBDRecognizerResultShowMode resultShowMode;   // 显示效果
@property (nonatomic) TBDRecognizerPlayTones recordPlayTones;   // 提示音开关
@property (nonatomic) BOOL isShowTipsOnStart; // 是否在对话框启动后展示引导提示，而不启动识别
@property (nonatomic) BOOL isShowTipAfter3sSilence; // 引擎启动后3秒没检测到语音，是否在动效下方随机出现一条提示语。如果配置了提示语列表，则默认开启
@property (nonatomic) BOOL isShowHelpButtonWhenSilence; // 未检测到语音异常时，将“取消”按钮替换成帮助按钮。在配置了提示语列表后，默认开启
@property (nonatomic, copy) NSString *tipsTitle; // 提示语标题
@property (nonatomic, copy) NSArray *tipsList; // 提示语列表

@end // BDRecognizerViewParamsObject
