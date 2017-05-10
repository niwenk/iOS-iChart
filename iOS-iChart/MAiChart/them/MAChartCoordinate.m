//
//  MAChartCoordinate.m
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import "MAChartCoordinate.h"

@implementation MAChartCoordinate

MAInitializerImpTemplate(MAChartCoordinate);
MAPropertyEqualImpTemplate(MAChartCoordinate, NSMutableArray<MAChartScale *> *, scale);

MAPropertyEqualImpTemplate(MAChartCoordinate, MAChartColor *, background_color);
MAPropertyEqualImpTemplate(MAChartCoordinate, MAChartColor *, grid_color);
MAPropertyEqualImpTemplate(MAChartCoordinate, NSNumber *, color_factor);
MAPropertyEqualImpTemplate(MAChartCoordinate, NSNumber *, board_deep);
MAPropertyEqualImpTemplate(MAChartCoordinate, NSNumber *, offsety);
MAPropertyEqualImpTemplate(MAChartCoordinate, NSNumber *, pedestal_height);
MAPropertyEqualImpTemplate(MAChartCoordinate, BOOL, left_board);
MAPropertyEqualImpTemplate(MAChartCoordinate, NSNumber *, width);
MAPropertyEqualImpTemplate(MAChartCoordinate, NSNumber *, height);
MAPropertyEqualImpTemplate(MAChartCoordinate, NSArray<MAChartListener *> *, listeners);

@end
