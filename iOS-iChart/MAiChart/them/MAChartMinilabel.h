//
//  MAChartMinilabel.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAChartUtils.h"
#import "MAChartColor.h"

@interface MAChartMinilabel : NSObject

@property (nonatomic, strong) NSNumber *fontsize;
@property (nonatomic, strong) NSNumber *fontweight;
@property (nonatomic, strong) MAChartColor *color;

MAInitializerTemplate(MAChartMinilabel, mini_label);
MAPropertyEqualTemplate(MAChartMinilabel, NSNumber *, fontsize);
MAPropertyEqualTemplate(MAChartMinilabel, NSNumber *, fontweight);
MAPropertyEqualTemplate(MAChartMinilabel, MAChartColor *, color);

@end
