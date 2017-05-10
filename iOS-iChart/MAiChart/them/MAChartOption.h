//
//  MAChartOption.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MAChartUtils.h"
#import "MAChartData.h"
#import "MAChartOption.h"
#import "MAChartTitle.h"
#import "MAChartLegend.h"
#import "MAChartSubOption.h"
#import "MAChartFootnote.h"
#import "MAChartCoordinate.h"
#import "MAChartTip.h"

@interface MAChartOption : NSObject

@property (nonatomic, strong) NSString *render;
@property (nonatomic, strong) NSMutableArray<MAChartData *> *data;
@property (nonatomic, strong) NSMutableArray<NSString *> *labels;
@property (nonatomic, strong) MAChartTitle *title;
@property (nonatomic, strong) MAChartLegend *legend;
@property (nonatomic, strong) MAChartSubOption *sub_option;
@property (nonatomic, strong) MAChartFootnote *footnote;
@property (nonatomic, strong) MAChartCoordinate *coordinate;

//layout
@property (nonatomic, assign) BOOL shadow;
@property (nonatomic, strong) NSNumber *shadow_blur;
@property (nonatomic, strong) MAChartColor *shadow_color;
@property (nonatomic, strong) NSNumber *shadow_offsetx;
@property (nonatomic, strong) NSNumber *shadow_offsety;
@property (nonatomic, strong) MAChartColor *background_color;
@property (nonatomic, strong) NSNumber *width;
@property (nonatomic, strong) NSNumber *height;
@property (nonatomic, strong) NSString *align;
@property (nonatomic, strong) NSNumber *offsetx;//设置向x轴负方向偏移位置
@property (nonatomic, strong) NSNumber *offset_angle;//逆时针偏移
@property (nonatomic, strong) NSNumber *radius;
@property (nonatomic, strong) NSNumber *column_width;//柱形宽度
@property (nonatomic, strong) NSNumber *zScale;//z轴深度倍数
@property (nonatomic, strong) NSNumber *xAngle;
@property (nonatomic, strong) NSNumber *bottom_scale;
@property (nonatomic, strong) MAChartLabel *label;
@property (nonatomic, strong) MAChartTip *tip;
@property (nonatomic, strong) NSNumber *text_space;//坐标系下方的label距离坐标系的距离。

@property (nonatomic, strong) NSNumber *yHeight;//饼图厚度
@property (nonatomic, assign) BOOL mutex;//只允许一个扇形弹出
@property (nonatomic, assign) BOOL showpercent;
@property (nonatomic, strong) NSNumber *decimalsnum;

MAInitializerTemplate(MAChartOption, option);

MAPropertyEqualTemplate(MAChartOption, NSString *, render);
MAPropertyEqualTemplate(MAChartOption, NSMutableArray<MAChartData *> *, data);
MAPropertyEqualTemplate(MAChartOption, NSMutableArray<NSString *> *, labels);
MAPropertyEqualTemplate(MAChartOption, MAChartTitle *, title);
MAPropertyEqualTemplate(MAChartOption, MAChartLegend *, legend);
MAPropertyEqualTemplate(MAChartOption, MAChartSubOption *, sub_option);
MAPropertyEqualTemplate(MAChartOption, MAChartFootnote *, footnote);
MAPropertyEqualTemplate(MAChartOption, MAChartCoordinate *, coordinate);

//layout
MAPropertyEqualTemplate(MAChartOption, MAChartColor *, shadow_color);
MAPropertyEqualTemplate(MAChartOption, MAChartColor *, background_color);
MAPropertyEqualTemplate(MAChartOption, BOOL, shadow);
MAPropertyEqualTemplate(MAChartOption, NSString *, align);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, shadow_blur);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, shadow_offsetx);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, shadow_offsety);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, width);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, height);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, offsetx);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, offset_angle);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, radius);

MAPropertyEqualTemplate(MAChartOption, NSNumber *, column_width);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, zScale);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, xAngle);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, bottom_scale);
MAPropertyEqualTemplate(MAChartOption, MAChartLabel *, label);
MAPropertyEqualTemplate(MAChartOption, MAChartTip *, tip);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, text_space);

MAPropertyEqualTemplate(MAChartOption, NSNumber *, yHeight);
MAPropertyEqualTemplate(MAChartOption, BOOL, mutex);
MAPropertyEqualTemplate(MAChartOption, BOOL, showpercent);
MAPropertyEqualTemplate(MAChartOption, NSNumber *, decimalsnum);

@end
