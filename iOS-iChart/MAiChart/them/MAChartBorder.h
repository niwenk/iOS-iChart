//
//  MAChartBorder.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAChartUtils.h"
#import "MAChartColor.h"

@interface MAChartBorder : NSObject

@property (nonatomic, assign) BOOL enable;
@property (nonatomic, strong) NSNumber *width;
@property (nonatomic, strong) MAChartColor *color;

MAInitializerTemplate(MAChartBorder, border);
MAPropertyEqualTemplate(MAChartBorder, BOOL, enable);
MAPropertyEqualTemplate(MAChartBorder, NSNumber *, width);
MAPropertyEqualTemplate(MAChartBorder, MAChartColor *, color);

@end
