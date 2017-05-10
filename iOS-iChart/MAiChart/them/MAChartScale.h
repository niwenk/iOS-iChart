//
//  MAChartScale.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAChartUtils.h"
#import "MAChartLabel.h"

@interface MAChartScale : NSObject

@property (nonatomic, strong) NSString *position;
@property (nonatomic, strong) NSNumber *start_scale;
@property (nonatomic, strong) NSNumber *end_scale;
@property (nonatomic, strong) NSNumber *scale_space;
@property (nonatomic, assign) BOOL scale_enable;
@property (nonatomic, strong) MAChartLabel *label;

// 添加监听
//listeners:{
//parseText:function(t,x,y){
//    return {text:t+"%"}
//}

MAInitializerTemplate(MAChartScale, scale);

MAPropertyEqualTemplate(MAChartScale, NSString *, position);
MAPropertyEqualTemplate(MAChartScale, NSNumber *, start_scale);
MAPropertyEqualTemplate(MAChartScale, NSNumber *, end_scale);
MAPropertyEqualTemplate(MAChartScale, NSNumber *, scale_space);
MAPropertyEqualTemplate(MAChartScale, BOOL, scale_enable);
MAPropertyEqualTemplate(MAChartScale, MAChartLabel *, label);

@end
