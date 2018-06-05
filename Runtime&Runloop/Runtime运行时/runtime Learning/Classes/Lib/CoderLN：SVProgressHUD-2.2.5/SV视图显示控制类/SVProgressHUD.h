//
//  SVProgressHUD.h
//  SVProgressHUD, https://github.com/SVProgressHUD/SVProgressHUD
//
//  Copyright (c) 2011-2018 Sam Vermette and contributors. All rights reserved.
//

/**
 SVProgressHUD继承自UIView类, 该类提供了两类方法供使用者调用,其中
 +setXXX:方法用于设置HUD的外观：样式、遮罩、颜色等,
 +showXXX:方法用于设置HUD的显示,
 +dismissXX:方法用于设置HUD的隐藏
 */

#import <UIKit/UIKit.h>
//#import <AvailabilityMacwros.h>


#pragma mark - ↑
#pragma mark - const 常量通知

/**
 SVProgressHUD发布四个通知，NSNotificationCenter以响应被显示/拒绝：
 每个通知通过一个userInfo保存HUD状态字符串（如果有的话）的字典，可以通过检索SVProgressHUDStatusUserInfoKey。
 
 SVProgressHUD SVProgressHUDDidReceiveTouchEventNotification当用户触摸整个屏幕或SVProgressHUDDidTouchDownInsideNotification用户直接触摸HUD时也会发布。由于此通知userInfo未被传递，而对象参数包含UIEvent与触摸相关的参数。
 */

extern NSString * _Nonnull const SVProgressHUDDidReceiveTouchEventNotification;
extern NSString * _Nonnull const SVProgressHUDDidTouchDownInsideNotification;
extern NSString * _Nonnull const SVProgressHUDWillDisappearNotification;//提示框即将消失
extern NSString * _Nonnull const SVProgressHUDDidDisappearNotification;//提示框已经消失
extern NSString * _Nonnull const SVProgressHUDWillAppearNotification;//提示框即将出现
extern NSString * _Nonnull const SVProgressHUDDidAppearNotification;// 提示框已经出现

extern NSString * _Nonnull const SVProgressHUDStatusUserInfoKey;





#pragma mark - ↑
#pragma mark - NS_ENUM 枚举

// 设置显示样式
typedef NS_ENUM(NSInteger, SVProgressHUDStyle) {
    SVProgressHUDStyleLight,        // 显示白底黑字 默认样式背景将模糊 default style, white HUD with black text, HUD background will be blurred
    SVProgressHUDStyleDark,         // 显示黑底白字  black HUD and white text, HUD background will be blurred
    SVProgressHUDStyleCustom        // 显示黑底白字 uses the fore- and background color properties
};


// 设置HUD背景遮罩类型
typedef NS_ENUM(NSUInteger, SVProgressHUDMaskType) {
    SVProgressHUDMaskTypeNone = 1,  // 默认图层样式，当HUD显示的时候，允许用户交互。 default mask type, allow user interactions while HUD is displayed
    SVProgressHUDMaskTypeClear,     // 当HUD显示的时候，不允许用户交互。 don't allow user interactions with background objects
    SVProgressHUDMaskTypeBlack,     // 当HUD显示的时候，不允许用户交互，且显示黑色背景图层。 don't allow user interactions with background objects and dim the UI in the back of the HUD (as seen in iOS 7 and above)
    SVProgressHUDMaskTypeGradient,  // 当HUD显示的时候，不允许用户交互，且显示渐变的背景图层。 don't allow user interactions with background objects and dim the UI with a a-la UIAlertView background gradient (as seen in iOS 6)
    SVProgressHUDMaskTypeCustom     // 当HUD显示的时候，不允许用户交互，且显示背景图层自定义的颜色。 don't allow user interactions with background objects and dim the UI in the back of the HUD with a custom color
};



// 设置动画类型
typedef NS_ENUM(NSUInteger, SVProgressHUDAnimationType) {
    SVProgressHUDAnimationTypeFlat,     //显示黑色圆圈 default animation type, custom flat animation (indefinite animated ring)
    SVProgressHUDAnimationTypeNative    //显示菊花 iOS native UIActivityIndicatorView
};

// show Block回调
typedef void (^SVProgressHUDShowCompletion)(void);
// dismiss Block回调
typedef void (^SVProgressHUDDismissCompletion)(void);



#pragma mark - ↑
#pragma mark - SVProgressHUD : UIView

@interface SVProgressHUD : UIView


#pragma mark - 自定义HUD Customization UI_APPEARANCE_SELECTOR

@property (assign, nonatomic) SVProgressHUDStyle defaultStyle ;                  // 设置背景样式 default is SVProgressHUDStyleLight
@property (assign, nonatomic) SVProgressHUDMaskType defaultMaskType ;             // default is SVProgressHUDMaskTypeNone
@property (assign, nonatomic) SVProgressHUDAnimationType defaultAnimationType ;   // default is SVProgressHUDAnimationTypeFlat
@property (strong, nonatomic, nullable) UIView *containerView;                              // if nil then use default window level
@property (assign, nonatomic) CGSize minimumSize ;                    // default is CGSizeZero, can be used to avoid resizing for a larger message
@property (assign, nonatomic) CGFloat ringThickness ;                 // default is 2 pt
@property (assign, nonatomic) CGFloat ringRadius ;                    // default is 18 pt
@property (assign, nonatomic) CGFloat ringNoTextRadius ;              // default is 24 pt
@property (assign, nonatomic) CGFloat cornerRadius ;                  // default is 14 pt
@property (strong, nonatomic, nonnull) UIFont *font ;                 // default is [UIFont preferredFontForTextStyle:UIFontTextStyleSubheadline]
@property (strong, nonatomic, nonnull) UIColor *backgroundColor ;     // 设置背景颜色 default is [UIColor whiteColor]
@property (strong, nonatomic, nonnull) UIColor *foregroundColor ;     // 设置前景(文本和动画)颜色 default is [UIColor blackColor]
@property (strong, nonatomic, nonnull) UIColor *backgroundLayerColor ;// default is [UIColor colorWithWhite:0 alpha:0.4]
@property (assign, nonatomic) CGSize imageViewSize ;                  // 设置动画图片大小 default is 28x28 pt
@property (assign, nonatomic) BOOL shouldTintImages ;                 // 是否渲染自定义图片 default is YES
@property (strong, nonatomic, nonnull) UIImage *infoImage ;           // 设置内容图片 default is the bundled info image provided by Freepik
@property (strong, nonatomic, nonnull) UIImage *successImage ;        // 设置动画显示成功图片 default is the bundled success image provided by Freepik
@property (strong, nonatomic, nonnull) UIImage *errorImage ;          // 设置动画显示失败图片 default is the bundled error image provided by Freepik
@property (strong, nonatomic, nonnull) UIView *viewForExtension ;     // default is nil, only used if #define SV_APP_EXTENSIONS is set
@property (assign, nonatomic) NSTimeInterval graceTimeInterval;       // 设置HUD动画宽限时间 default is 0 seconds
@property (assign, nonatomic) NSTimeInterval minimumDismissTimeInterval; // 设置HUD销毁的最短时间 default is 5.0 seconds
@property (assign, nonatomic) NSTimeInterval maximumDismissTimeInterval; // 设置HUD销毁的最长时间 default is CGFLOAT_MAX

@property (assign, nonatomic) UIOffset offsetFromCenter ; // default is 0, 0

@property (assign, nonatomic) NSTimeInterval fadeInAnimationDuration ;    // 设置HUD动画逐渐 出现的持续时间 default is 0.15
@property (assign, nonatomic) NSTimeInterval fadeOutAnimationDuration ;   // 设置HUD动画逐渐 消失的持续时间 default is 0.15

@property (assign, nonatomic) UIWindowLevel maxSupportedWindowLevel; // default is UIWindowLevelNormal

@property (assign, nonatomic) BOOL hapticsEnabled;	// default is NO




#pragma mark - 自定义HUD重写set方法
/**
 其实就是调用对应属性的 set方法.
 */

+ (void)setDefaultStyle:(SVProgressHUDStyle)style;                  // 设置显示样式 default is SVProgressHUDStyleLight
+ (void)setDefaultMaskType:(SVProgressHUDMaskType)maskType;         // 设置HUD背景遮罩类型 default is SVProgressHUDMaskTypeNone
+ (void)setDefaultAnimationType:(SVProgressHUDAnimationType)type;   // 设置动画类型 default is SVProgressHUDAnimationTypeFlat
+ (void)setContainerView:(nullable UIView*)containerView;           // default is window level
+ (void)setMinimumSize:(CGSize)minimumSize;                         // 设置显示文字的最小尺寸 default is CGSizeZero, can be used to avoid resizing for a larger message
+ (void)setRingThickness:(CGFloat)ringThickness;                    // 设置圆环宽度 default is 2 pt
+ (void)setRingRadius:(CGFloat)radius;                              // 设置圆环半径 default is 18 pt
+ (void)setRingNoTextRadius:(CGFloat)radius;                        // 设置无文本圆环半 default is 24 pt
+ (void)setCornerRadius:(CGFloat)cornerRadius;                      // 设置圆半径 default is 14 pt
+ (void)setBorderColor:(nonnull UIColor*)color;                     // 设置圆边框颜色 default is nil
+ (void)setBorderWidth:(CGFloat)width;                              // 设置圆边框宽度 default is 0
+ (void)setFont:(nonnull UIFont*)font;                              // 设置文本字体大小  default is [UIFont preferredFontForTextStyle:UIFontTextStyleSubheadline]
+ (void)setForegroundColor:(nonnull UIColor*)color;                 // 设置前景(文本和动画)颜色 default is [UIColor blackColor], only used for SVProgressHUDStyleCustom
+ (void)setBackgroundColor:(nonnull UIColor*)color;                 // 设置背景颜色 default is [UIColor whiteColor], only used for SVProgressHUDStyleCustom
+ (void)setBackgroundLayerColor:(nonnull UIColor*)color;            // default is [UIColor colorWithWhite:0 alpha:0.5], only used for SVProgressHUDMaskTypeCustom
+ (void)setImageViewSize:(CGSize)size;                              // 设置动画图片大小 default is 28x28 pt
+ (void)setShouldTintImages:(BOOL)shouldTintImages;                 // 是否渲染自定义图片 default is YES
+ (void)setInfoImage:(nonnull UIImage*)image;                       // 设置内容图片 default is the bundled info image provided by Freepik
+ (void)setSuccessImage:(nonnull UIImage*)image;                    // 设置动画显示成功图片 default is the bundled success image provided by Freepik
+ (void)setErrorImage:(nonnull UIImage*)image;                      // 设置动画显示失败图片 default is the bundled error image provided by Freepik
+ (void)setViewForExtension:(nonnull UIView*)view;                  // default is nil, only used if #define SV_APP_EXTENSIONS is set
+ (void)setGraceTimeInterval:(NSTimeInterval)interval;              // 设置HUD动画宽限时间 default is 0 seconds
+ (void)setMinimumDismissTimeInterval:(NSTimeInterval)interval;     // 设置HUD销毁的最短时间 default is 5.0 seconds
+ (void)setMaximumDismissTimeInterval:(NSTimeInterval)interval;     // 设置HUD销毁的最长时间  default is infinite
+ (void)setFadeInAnimationDuration:(NSTimeInterval)duration;        // 设置HUD动画逐渐 出现的持续时间 default is 0.15 seconds
+ (void)setFadeOutAnimationDuration:(NSTimeInterval)duration;       // 设置HUD动画逐渐 消失的持续时间 default is 0.15 seconds
+ (void)setMaxSupportedWindowLevel:(UIWindowLevel)windowLevel;      // default is UIWindowLevelNormal
+ (void)setHapticsEnabled:(BOOL)hapticsEnabled;						// default is NO

+ (void)setStatus:(nullable NSString*)status; // change the HUD loading status while it's showing








#pragma mark - ↑
#pragma mark - Show Methods 显示方法


#pragma mark - + Show 显示方法工作流程

+ (void)show;// 显示白底黑色圆圈
+ (void)showWithStatus:(nullable NSString*)status;// 显示白底黑色圆圈图片+提示文本
+ (void)showProgress:(float)progress;// 显示白底黑色圆圈
+ (void)showProgress:(float)progress status:(nullable NSString*)status;// 显示白底黑色圆圈+提示文本


/**
 instead 方法代替
 */
+ (void)showWithMaskType:(SVProgressHUDMaskType)maskType __attribute__((deprecated("Use show and setDefaultMaskType: instead.")));
+ (void)showWithStatus:(nullable NSString*)status maskType:(SVProgressHUDMaskType)maskType __attribute__((deprecated("Use showWithStatus: and setDefaultMaskType: instead.")));

+ (void)showProgress:(float)progress maskType:(SVProgressHUDMaskType)maskType __attribute__((deprecated("Use showProgress: and setDefaultMaskType: instead.")));
+ (void)showProgress:(float)progress status:(nullable NSString*)status maskType:(SVProgressHUDMaskType)maskType __attribute__((deprecated("Use showProgress:status: and setDefaultMaskType: instead.")));




#pragma mark - ↑
#pragma mark - + Show 展示图片方法工作流程


+ (void)showInfoWithStatus:(nullable NSString*)status;// 显示感叹号图片+文本
+ (void)showSuccessWithStatus:(nullable NSString*)status;// 显示打对勾图片+文本
+ (void)showErrorWithStatus:(nullable NSString*)status; // 显示叉号图片+文本
+ (void)showImage:(nonnull UIImage*)image status:(nullable NSString*)status;// 显示自定义图片


// stops the activity indicator, shows a glyph + status, and dismisses the HUD a little bit later
+ (void)showInfoWithStatus:(nullable NSString*)status maskType:(SVProgressHUDMaskType)maskType __attribute__((deprecated("Use showInfoWithStatus: and setDefaultMaskType: instead.")));
+ (void)showSuccessWithStatus:(nullable NSString*)status maskType:(SVProgressHUDMaskType)maskType __attribute__((deprecated("Use showSuccessWithStatus: and setDefaultMaskType: instead.")));
+ (void)showErrorWithStatus:(nullable NSString*)status maskType:(SVProgressHUDMaskType)maskType __attribute__((deprecated("Use showErrorWithStatus: and setDefaultMaskType: instead.")));

// shows a image + status, use white PNGs with the imageViewSize (default is 28x28 pt)
+ (void)showImage:(nonnull UIImage*)image status:(nullable NSString*)status maskType:(SVProgressHUDMaskType)maskType __attribute__((deprecated("Use showImage:status: and setDefaultMaskType: instead.")));

+ (void)setOffsetFromCenter:(UIOffset)offset;
+ (void)resetOffsetFromCenter;


// 应为是单例，想显示多个HUD ，可以使用使用一下方法：
+ (void)popActivity; // decrease activity count, if activity count == 0 the HUD is dismissed





#pragma mark - ↑
#pragma mark - dismiss Methods 隐藏方法

+ (void)dismiss;// 直接隐藏
+ (void)dismissWithCompletion:(nullable SVProgressHUDDismissCompletion)completion;// dismiss Block回调

+ (void)dismissWithDelay:(NSTimeInterval)delay;// 多少秒后隐藏hud
+ (void)dismissWithDelay:(NSTimeInterval)delay completion:(nullable SVProgressHUDDismissCompletion)completion;// 多少秒后隐藏hud，且隐藏后的回调

+ (BOOL)isVisible;// 是否显示或隐藏

+ (NSTimeInterval)displayDurationForString:(nullable NSString*)string;// 显示持续时间

@end

