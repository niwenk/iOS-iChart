//
//  MAChartView.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAChartOption.h"

typedef NSString *MAiChartAction;
static MAiChartAction const MAiChartActionHandle = @"maichartactionhandle";
static MAiChartAction const MAiChartActionClick = @"MAClick";

typedef NSString *MAParamsDict;
static MAParamsDict const MAParamsDictName = @"name";
static MAParamsDict const MAParamsDictValue = @"value";
static MAParamsDict const MAParamsDictSection = @"section";
static MAParamsDict const MAParamsDictRow = @"row";

typedef NS_ENUM(NSInteger, MAChartType) {
    MAChartColumn3D,
    MAChartColumnMulti3D,
    MAChartPie3D
};

typedef void(^MAChartActionHandler)(NSDictionary *params);

@interface MAChartView : UIWebView

//iChart 类型
@property (nonatomic) IBInspectable NSInteger chartType;

- (void)loadiCharts;

- (void)setOption:(MAChartOption *)chartOption;

- (void)addHandlerForAction:(MAiChartAction)name withBlock:(MAChartActionHandler)block;

@end
