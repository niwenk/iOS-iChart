//
//  MAChartData.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAChartUtils.h"
#import "MAChartColor.h"

@interface MAChartData : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) id value;
@property (nonatomic, strong) MAChartColor *color;

MAInitializerTemplate(MAChartData, data);
MAPropertyEqualTemplate(MAChartData, NSString *, name);
MAPropertyEqualTemplate(MAChartData, id, value);
MAPropertyEqualTemplate(MAChartData, MAChartColor *, color);

@end
