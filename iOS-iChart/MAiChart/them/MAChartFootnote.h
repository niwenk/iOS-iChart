//
//  MAChartFootnote.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAChartUtils.h"
#import "MAChartColor.h"

@interface MAChartFootnote : NSObject

@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) MAChartColor *color;
@property (nonatomic, strong) NSNumber *fontsize;
@property (nonatomic, strong) NSString *padding;

MAInitializerTemplate(MAChartFootnote, footnote);
MAPropertyEqualTemplate(MAChartFootnote, NSString *, text);
MAPropertyEqualTemplate(MAChartFootnote, MAChartColor *, color);
MAPropertyEqualTemplate(MAChartFootnote, NSNumber *, fontsize);
MAPropertyEqualTemplate(MAChartFootnote, NSString *, padding);

@end
