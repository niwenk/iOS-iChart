//
//  MAChartLabel.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAChartUtils.h"
#import "MAChartColor.h"
#import "MAChartBorder.h"

@interface MAChartLabel : NSObject

@property (nonatomic, strong) MAChartColor *background_color;
@property (nonatomic, assign) BOOL sign;//设置禁用label的小图标
@property (nonatomic, strong) NSString *padding;
@property (nonatomic, strong) MAChartBorder *border;
@property (nonatomic, strong) NSNumber *fontsize;
@property (nonatomic, strong) NSNumber *fontweight;
@property (nonatomic, strong) MAChartColor *color;

MAInitializerTemplate(MAChartLabel, label);
MAPropertyEqualTemplate(MAChartLabel, MAChartColor *, background_color);
MAPropertyEqualTemplate(MAChartLabel, BOOL, sign);
MAPropertyEqualTemplate(MAChartLabel, NSString *, padding);
MAPropertyEqualTemplate(MAChartLabel, MAChartBorder *, border);
MAPropertyEqualTemplate(MAChartLabel, NSNumber *, fontsize);
MAPropertyEqualTemplate(MAChartLabel, NSNumber *, fontweight);
MAPropertyEqualTemplate(MAChartLabel, MAChartColor *, color);
@end
