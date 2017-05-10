//
//  MAChartTitle.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MAChartUtils.h"
#import "MAChartColor.h"

@interface MAChartTitle : NSObject

@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) NSNumber *height;
@property (nonatomic, strong) NSNumber *fontsize;
@property (nonatomic, strong) MAChartColor *color;

MAInitializerTemplate(MAChartTitle, title);
MAPropertyEqualTemplate(MAChartTitle, NSString *, text);
MAPropertyEqualTemplate(MAChartTitle, NSNumber *, height);
MAPropertyEqualTemplate(MAChartTitle, NSNumber *, fontsize);
MAPropertyEqualTemplate(MAChartTitle, MAChartColor *, color);

@end
