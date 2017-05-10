//
//  MAChartTip.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAChartUtils.h"


@interface MAChartTip : NSObject

@property (nonatomic, assign) BOOL enable;

MAInitializerTemplate(MAChartTip, tip);

MAPropertyEqualTemplate(MAChartTip, BOOL, enable);

@end
