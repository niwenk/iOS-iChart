//
//  MAChartSubOption.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAChartUtils.h"
#import "MAChartMinilabel.h"
#import "MAChartLabel.h"
#import "MAChartFontweight.h"
#import "MAChartBorder.h"
#import "MAChartListener.h"

@interface MAChartSubOption : NSObject

@property (nonatomic, strong) NSNumber *mini_label_threshold_angle;//迷你label的阀值,单位:角度
@property (nonatomic, strong) MAChartMinilabel *mini_label;//迷你label配置项
@property (nonatomic, strong) id label;
@property (nonatomic, strong) NSNumber *fontsize;
@property (nonatomic, strong) MAChartFontweight *fontweight;
@property (nonatomic, strong) MAChartBorder *border;

@property (nonatomic, strong) NSArray<MAChartListener *> *listeners;

MAInitializerTemplate(MAChartSubOption, sub_option);
MAPropertyEqualTemplate(MAChartSubOption, NSNumber *, mini_label_threshold_angle);
MAPropertyEqualTemplate(MAChartSubOption, MAChartMinilabel *, mini_label);
MAPropertyEqualTemplate(MAChartSubOption, id, label);
MAPropertyEqualTemplate(MAChartSubOption, NSNumber *, fontsize);
MAPropertyEqualTemplate(MAChartSubOption, MAChartFontweight *, fontweight);
MAPropertyEqualTemplate(MAChartSubOption, MAChartBorder *, border);
MAPropertyEqualTemplate(MAChartSubOption, NSArray<MAChartListener *> *, listeners);


/**
 添加事件监听

 @param blcok 参数 key对应的只是事件名称（参考官网），value对应的是事件内容（局部内容，现阶段只支持占位符）
 @return @[@{@"key":@"click"},@{@"key":@"parseText",@"value":@"测试%@"}];
 */
+ (id)addListeners:(NSMutableArray *(^)())blcok;

@end
