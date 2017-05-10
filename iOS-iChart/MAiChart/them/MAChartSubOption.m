//
//  MAChartSubOption.m
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import "MAChartSubOption.h"

@implementation MAChartSubOption

MAInitializerImpTemplate(MAChartSubOption);

MAPropertyEqualImpTemplate(MAChartSubOption, NSNumber *, mini_label_threshold_angle);
MAPropertyEqualImpTemplate(MAChartSubOption, MAChartMinilabel *, mini_label);
MAPropertyEqualImpTemplate(MAChartSubOption, id, label);
MAPropertyEqualImpTemplate(MAChartSubOption, NSNumber *, fontsize);
MAPropertyEqualImpTemplate(MAChartSubOption, MAChartFontweight *, fontweight);
MAPropertyEqualImpTemplate(MAChartSubOption, MAChartBorder *, border);
MAPropertyEqualImpTemplate(MAChartSubOption, NSArray<MAChartListener *> *, listeners);

+ (id)addListeners:(NSMutableArray * (^)())blcok {
//    NSDictionary *dict = blcok();
//    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
//    for (NSString *key in dic) {
//        dict[@"key"] = dic[key];
//        
//    }
    
//        NSDictionary *dict = @{@"key" : @"click",@"value" : @"test"};
    
    return blcok();
}

@end
