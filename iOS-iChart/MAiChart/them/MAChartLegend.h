//
//  MAChartLegend.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAChartUtils.h"
#import "MAChartColor.h"

@interface MAChartLegend : NSObject

@property (nonatomic, assign) BOOL enable;
@property (nonatomic, strong) NSString *padding;
@property (nonatomic, strong) NSNumber *offsetx;
@property (nonatomic, strong) NSNumber *offsety;
@property (nonatomic, strong) MAChartColor *color;
@property (nonatomic, strong) NSNumber *fontsize;//文本大小
@property (nonatomic, strong) NSNumber *sign_size;//小图标大小
@property (nonatomic, strong) NSNumber *line_height;//设置行高
@property (nonatomic, strong) NSNumber *sign_space;//小图标与文本间距
@property (nonatomic, strong) id border;
@property (nonatomic, strong) NSString *align;
@property (nonatomic, strong) NSString *valign;
@property (nonatomic, strong) MAChartColor *background_color;
@property (nonatomic, strong) NSNumber *row;
@property (nonatomic, strong) id column;

MAInitializerTemplate(MAChartLegend, legend);
MAPropertyEqualTemplate(MAChartLegend, BOOL, enable);
MAPropertyEqualTemplate(MAChartLegend, NSString *, padding);
MAPropertyEqualTemplate(MAChartLegend, NSNumber *, offsetx);
MAPropertyEqualTemplate(MAChartLegend, NSNumber *, offsety);
MAPropertyEqualTemplate(MAChartLegend, MAChartColor *, color);
MAPropertyEqualTemplate(MAChartLegend, NSNumber *, fontsize);
MAPropertyEqualTemplate(MAChartLegend, NSNumber *, sign_size);
MAPropertyEqualTemplate(MAChartLegend, NSNumber *, line_height);
MAPropertyEqualTemplate(MAChartLegend, NSNumber *, sign_space);
MAPropertyEqualTemplate(MAChartLegend, id, border);
MAPropertyEqualTemplate(MAChartLegend, NSString *, align);
MAPropertyEqualTemplate(MAChartLegend, NSString *, valign);
MAPropertyEqualTemplate(MAChartLegend, MAChartColor *, background_color);
MAPropertyEqualTemplate(MAChartLegend, NSNumber *, row);
MAPropertyEqualTemplate(MAChartLegend, id, column);

@end
