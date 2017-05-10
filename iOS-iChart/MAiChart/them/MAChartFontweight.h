//
//  MAChartFontweight.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAChartUtils.h"
#import "MAChartColor.h"

@interface MAChartFontweight : NSObject

@property (nonatomic, strong) MAChartColor *color;


MAInitializerTemplate(MAChartFontweight, border);
MAPropertyEqualTemplate(MAChartFontweight, MAChartColor *, color);

@end
