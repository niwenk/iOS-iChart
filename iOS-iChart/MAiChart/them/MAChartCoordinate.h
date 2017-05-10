//
//  MAChartCoordinate.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAChartUtils.h"
#import "MAChartScale.h"
#import "MAChartColor.h"
#import "MAChartListener.h"

@interface MAChartCoordinate : NSObject

@property (nonatomic, strong) NSNumber *width;
@property (nonatomic, strong) NSMutableArray<MAChartScale *> *scale;
@property (nonatomic, strong) MAChartColor *background_color;
@property (nonatomic, strong) MAChartColor *grid_color;
@property (nonatomic, strong) NSNumber *color_factor;
@property (nonatomic, strong) NSNumber *board_deep;
@property (nonatomic, strong) NSNumber *offsety;
@property (nonatomic, strong) NSNumber *pedestal_height;
@property (nonatomic, assign) BOOL left_board;//取消左侧面板
@property (nonatomic, strong) NSNumber *height;
@property (nonatomic, strong) NSArray<MAChartListener *> *listeners;

MAInitializerTemplate(MAChartCoordinate, coordinate);
MAPropertyEqualTemplate(MAChartCoordinate, NSMutableArray<MAChartScale *> *, scale);
MAPropertyEqualTemplate(MAChartCoordinate, MAChartColor *, background_color);
MAPropertyEqualTemplate(MAChartCoordinate, MAChartColor *, grid_color);
MAPropertyEqualTemplate(MAChartCoordinate, NSNumber *, color_factor);
MAPropertyEqualTemplate(MAChartCoordinate, NSNumber *, board_deep);
MAPropertyEqualTemplate(MAChartCoordinate, NSNumber *, offsety);
MAPropertyEqualTemplate(MAChartCoordinate, NSNumber *, pedestal_height);
MAPropertyEqualTemplate(MAChartCoordinate, BOOL, left_board);
MAPropertyEqualTemplate(MAChartCoordinate, NSNumber *, width);
MAPropertyEqualTemplate(MAChartCoordinate, NSNumber *, height);
MAPropertyEqualTemplate(MAChartCoordinate, NSArray<MAChartListener *> *, listeners);

@end
