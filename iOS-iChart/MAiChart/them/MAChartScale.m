//
//  MAChartScale.m
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import "MAChartScale.h"

@implementation MAChartScale

MAInitializerImpTemplate(MAChartScale);


MAPropertyEqualImpTemplate(MAChartScale, NSString *, position);
MAPropertyEqualImpTemplate(MAChartScale, NSNumber *, start_scale);
MAPropertyEqualImpTemplate(MAChartScale, NSNumber *, end_scale);
MAPropertyEqualImpTemplate(MAChartScale, NSNumber *, scale_space);
MAPropertyEqualImpTemplate(MAChartScale, BOOL, scale_enable);
MAPropertyEqualImpTemplate(MAChartScale, MAChartLabel *, label);
@end
