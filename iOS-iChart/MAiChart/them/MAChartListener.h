//
//  MAChartListener.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/10.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAChartUtils.h"

@interface MAChartListener : NSObject

@property (nonatomic, strong) NSString *eventName;
@property (nonatomic, strong) NSString *event;

MAInitializerTemplate(MAChartListener, listener);
MAPropertyEqualTemplate(MAChartListener, NSString *, eventName);
MAPropertyEqualTemplate(MAChartListener, NSString *, event);

@end
