//
//  MAChartLabel.m
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import "MAChartLabel.h"

@implementation MAChartLabel

MAInitializerImpTemplate(MAChartLabel);


MAPropertyEqualImpTemplate(MAChartLabel, MAChartColor *, background_color);
MAPropertyEqualImpTemplate(MAChartLabel, BOOL, sign);
MAPropertyEqualImpTemplate(MAChartLabel, NSString *, padding);
MAPropertyEqualImpTemplate(MAChartLabel, MAChartBorder *, border);
MAPropertyEqualImpTemplate(MAChartLabel, NSNumber *, fontsize);
MAPropertyEqualImpTemplate(MAChartLabel, NSNumber *, fontweight);
MAPropertyEqualImpTemplate(MAChartLabel, MAChartColor *, color);

@end
