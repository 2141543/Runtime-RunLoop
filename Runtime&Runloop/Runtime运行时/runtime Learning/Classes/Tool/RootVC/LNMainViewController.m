/*
 * LNMainViewController.m
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN/Runtime-RunLoop』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 *
 * 主界面
 */

#import "LNMainViewController.h"

@interface LNMainViewController ()

@end

@implementation LNMainViewController

- (NSString *)controllerTitle {
    return @"学习思想";
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view addSubview:self.imageV];
}

@end
