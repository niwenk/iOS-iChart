//
//  MAChartOption.m
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import "MAChartOption.h"
#import "MAChartJson.h"

@implementation MAChartOption

MAInitializerImpTemplate(MAChartOption);

MAPropertyEqualImpTemplate(MAChartOption, NSString *, render);
MAPropertyEqualImpTemplate(MAChartOption, NSMutableArray<MAChartData *> *, data);
MAPropertyEqualImpTemplate(MAChartOption, NSMutableArray<NSString *> *, labels);
MAPropertyEqualImpTemplate(MAChartOption, MAChartTitle *, title);
MAPropertyEqualImpTemplate(MAChartOption, MAChartLegend *, legend);
MAPropertyEqualImpTemplate(MAChartOption, MAChartSubOption *, sub_option);
MAPropertyEqualImpTemplate(MAChartOption, MAChartFootnote *, footnote);
MAPropertyEqualImpTemplate(MAChartOption, MAChartCoordinate *, coordinate);


MAPropertyEqualImpTemplate(MAChartOption, MAChartColor *, shadow_color);
MAPropertyEqualImpTemplate(MAChartOption, MAChartColor *, background_color);
MAPropertyEqualImpTemplate(MAChartOption, BOOL, shadow);
MAPropertyEqualImpTemplate(MAChartOption, NSString *, align);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, shadow_blur);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, shadow_offsetx);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, shadow_offsety);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, width);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, height);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, offsetx);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, offset_angle);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, radius);

MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, column_width);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, zScale);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, xAngle);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, bottom_scale);
MAPropertyEqualImpTemplate(MAChartOption, MAChartLabel *, label);
MAPropertyEqualImpTemplate(MAChartOption, MAChartTip *, tip);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, text_space);

MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, yHeight);
MAPropertyEqualImpTemplate(MAChartOption, BOOL, mutex);
MAPropertyEqualImpTemplate(MAChartOption, BOOL, showpercent);
MAPropertyEqualImpTemplate(MAChartOption, NSNumber *, decimalsnum);

@end
