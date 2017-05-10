//
//  ViewController.m
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import "ViewController.h"
#import "MAChartOption.h"
#import "MAChartData.h"
#import "MAChartJson.h"
#import "MAChartView.h"

@interface ViewController ()

@property (weak, nonatomic) IBOutlet MAChartView *charView;
@property (nonatomic, strong) MAChartOption *chartOption;

@end

@implementation ViewController
- (IBAction)btnPressed:(id)sender {
    
    self.charView.chartType = MAChartColumnMulti3D;
    
    [self getOption];
    
    [self.charView setOption:self.chartOption];
    
    [self.charView loadiCharts];
    
    [self.charView addHandlerForAction:MAiChartActionClick withBlock:^(NSDictionary *params) {
        
        NSString *name = params[MAParamsDictName];
        NSString *value = params[MAParamsDictValue];
        NSString *section = params[MAParamsDictSection];
        NSString *row = params[MAParamsDictRow];
        
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:nil message:[NSString stringWithFormat:@"name:%@\nvalue:%@\nsection:%@\nrow:%@",name,value,section,row] delegate:nil cancelButtonTitle:@"知道了" otherButtonTitles:nil, nil];
        [alertView show];
        
        NSLog(@"%@",params);
    }];
}
- (IBAction)pieBtnPressed:(id)sender {
    self.charView.chartType = MAChartPie3D;
    
    [self getPieOption];
    
    [self.charView setOption:self.chartOption];
    
    [self.charView loadiCharts];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

- (void)getOption {
    NSMutableArray *datas = [NSMutableArray array];
    
    MAChartData *chartData = [MAChartData initMAChartDataWithBlock:^(MAChartData *data) {
        data.nameEqual(@"普通高等教育本专科招生人数");
        data.valueEqual(@[@321,@384,@447,@504,@546,@566]);
        data.colorEqual([MAChartColor colorWithHexString:@"#de9972"]);
    }];
    [datas addObject:chartData];
    
    chartData = [MAChartData initMAChartDataWithBlock:^(MAChartData *data) {
        data.nameEqual(@"各类中等职业教育招生人数");
        data.valueEqual(@[@474,@516,@566,@656,@748,@810]);
        data.colorEqual([MAChartColor colorWithHexString:@"#28847f"]);
    }];
    [datas addObject:chartData];
    
    chartData = [MAChartData initMAChartDataWithBlock:^(MAChartData *data) {
        data.nameEqual(@"全国普通高中招生人数");
        data.valueEqual(@[@677,@752,@822,@878,@871,@840]);
        data.colorEqual([MAChartColor colorWithHexString:@"#90abc0"]);
    }];
    [datas addObject:chartData];
    
    NSMutableArray *scales = [NSMutableArray array];
    MAChartScale *scale = [MAChartScale initMAChartScaleWithBlock:^(MAChartScale *scale) {
        scale.positionEqual(@"left");
        scale.start_scaleEqual(@0);
        scale.end_scaleEqual(@1000);
        scale.scale_spaceEqual(@200);
        scale.scale_enableEqual(NO);
        scale.labelEqual([MAChartLabel initMAChartLabelWithBlock:^(MAChartLabel *label) {
            label.colorEqual([MAChartColor colorWithHexString:@"#4c4f48"]);
        }]);
    }];
    [scales addObject:scale];
    
    NSMutableArray *labels = [NSMutableArray arrayWithObjects:@"2012",@"2013",@"2014",@"2015",@"2016",@"2017", nil];
    
    MAChartOption *option = [MAChartOption initMAChartOptionWithBlock:^(MAChartOption *option) {
        option.dataEqual(datas).
        labelsEqual(labels).
        titleEqual([MAChartTitle initMAChartTitleWithBlock:^(MAChartTitle *title) {
            title.textEqual(@"iOS封装iChart");
            title.colorEqual([MAChartColor colorWithHexString:@"#3e576f"]);
        }]).
        shadowEqual(YES).
        renderEqual(@"canvasDiv").
        widthEqual(@(CGRectGetWidth(self.charView.frame))).
        heightEqual(@(CGRectGetHeight(self.charView.frame))).
        alignEqual(@"center").
//        offsetxEqual(@50).
        legendEqual([MAChartLegend initMAChartLegendWithBlock:^(MAChartLegend *legend) {
            legend.enableEqual(YES).
            alignEqual(@"center").
            valignEqual(@"bottom").
            rowEqual(@1).
            columnEqual(@"max").
            paddingEqual(@"0").
            borderEqual([MAChartBorder initMAChartBorderWithBlock:^(MAChartBorder *border) {
                border.enableEqual(NO);
            }]);
        }]).
//        column_widthEqual(@8).
        zScaleEqual(@3).
        xAngleEqual(@50).
        bottom_scaleEqual(@1.1).
        text_spaceEqual(@16).
        labelEqual([MAChartLabel initMAChartLabelWithBlock:^(MAChartLabel *label) {
            label.colorEqual([MAChartColor colorWithHexString:@"#4c4f48"]);
        }]).
        footnoteEqual([MAChartFootnote initMAChartFootnoteWithBlock:^(MAChartFootnote *footnote) {
            footnote.textEqual(@"niwenkang@n22.com.cn").
            colorEqual([MAChartColor colorWithHexString:@"#909090"]).
            fontsizeEqual(@11).
            paddingEqual(@"0 44");
        }]).
        background_colorEqual([MAChartColor colorWithHexString:@"#fff"]).
        sub_optionEqual([MAChartSubOption initMAChartSubOptionWithBlock:^(MAChartSubOption *sub_option) {
            sub_option.labelEqual([MAChartLabel initMAChartLabelWithBlock:^(MAChartLabel *label) {
                label.colorEqual([MAChartColor colorWithHexString:@"#000"]);
            }]).
            listenersEqual(@[
                             [MAChartListener initMAChartListenerWithBlock:^(MAChartListener *listener) {
                                listener.eventNameEqual(@"click");
                            }],
                             [MAChartListener initMAChartListenerWithBlock:^(MAChartListener *listener) {
                                listener.eventNameEqual(@"parseText").
                                eventEqual(@"测试%@");
                            }]
                             ]);
        }]).
        tipEqual([MAChartTip initMAChartTipWithBlock:^(MAChartTip *tip) {
            tip.enableEqual(NO);
        }]).
        coordinateEqual([MAChartCoordinate initMAChartCoordinateWithBlock:^(MAChartCoordinate *coordinate) {
            coordinate.scaleEqual(scales).
            background_colorEqual([MAChartColor colorWithHexString:@"#d7d7d5"]).
            grid_colorEqual([MAChartColor colorWithHexString:@"#a4a4a2"]).
            color_factorEqual(@0.24).
            board_deepEqual(@10).
            offsetyEqual(@-10).
            pedestal_heightEqual(@10).
            left_boardEqual(YES);
        }]);
    }];
    
    self.chartOption = option;
}

- (void)getPieOption {
    NSMutableArray *datas = [NSMutableArray array];
    
    MAChartData *chartData = [MAChartData initMAChartDataWithBlock:^(MAChartData *data) {
        data.nameEqual(@"普通高等教育本专科招生人数");
        data.valueEqual(@321);
        data.colorEqual([MAChartColor colorWithHexString:@"#de9972"]);
    }];
    [datas addObject:chartData];
    
    chartData = [MAChartData initMAChartDataWithBlock:^(MAChartData *data) {
        data.nameEqual(@"各类中等职业教育招生人数");
        data.valueEqual(@474);
        data.colorEqual([MAChartColor colorWithHexString:@"#28847f"]);
    }];
    [datas addObject:chartData];
    
    chartData = [MAChartData initMAChartDataWithBlock:^(MAChartData *data) {
        data.nameEqual(@"全国普通高中招生人数");
        data.valueEqual(@677);
        data.colorEqual([MAChartColor colorWithHexString:@"#90abc0"]);
    }];
    [datas addObject:chartData];
    
    MAChartOption *option = [MAChartOption initMAChartOptionWithBlock:^(MAChartOption *option) {
        option.renderEqual(@"canvasDiv").
        dataEqual(datas).
        titleEqual([MAChartTitle initMAChartTitleWithBlock:^(MAChartTitle *title) {
            title.textEqual(@"2012年招生情况").
            colorEqual([MAChartColor colorWithHexString:@"#3e576f"]);
        }]).
        footnoteEqual([MAChartFootnote initMAChartFootnoteWithBlock:^(MAChartFootnote *footnote) {
            footnote.textEqual(@"niwenkang@n22.com.cn").
            colorEqual([MAChartColor colorWithHexString:@"#486c8f"]).
            fontsizeEqual(@11).
            paddingEqual(@"0 38");
        }]).
        sub_optionEqual([MAChartSubOption initMAChartSubOptionWithBlock:^(MAChartSubOption *sub_option) {
            sub_option.labelEqual([MAChartLabel initMAChartLabelWithBlock:^(MAChartLabel *label) {
                label.paddingEqual(@"0 4").
                borderEqual([MAChartBorder initMAChartBorderWithBlock:^(MAChartBorder *border) {
                    border.enableEqual(NO).
                    colorEqual([MAChartColor colorWithHexString:@"#be5985"]);
                }]).
                fontsizeEqual(@11).
                fontweightEqual(@600).
                background_colorEqual([MAChartColor colorWithHexString:@"#fff"]).
                colorEqual([MAChartColor colorWithHexString:@"#be5985"]);
            }]).
            
            listenersEqual(@[[MAChartListener initMAChartListenerWithBlock:^(MAChartListener *listener) {
                    listener.eventNameEqual(@"parseText").
                    eventEqual(@"测试%@");
                }]
            ]).
            borderEqual([MAChartBorder initMAChartBorderWithBlock:^(MAChartBorder *border) {
                border.widthEqual(@2).
                colorEqual([MAChartColor colorWithHexString:@"#ffffff"]);
            }]);
        }]).
        shadowEqual(true).
        shadow_blurEqual(@6).
        shadow_colorEqual([MAChartColor colorWithHexString:@"#aaaaaa"]).
        shadow_offsetxEqual(@0).
        shadow_offsetyEqual(@0).
        background_colorEqual([MAChartColor colorWithHexString:@"#fefefe"]).
        yHeightEqual(@20).
        offsetxEqual(@60).
        mutexEqual(YES).
        showpercentEqual(YES).
        decimalsnumEqual(@2).
        widthEqual(@(CGRectGetWidth(self.charView.frame))).
        heightEqual(@(CGRectGetHeight(self.charView.frame))).
        radiusEqual(@150);
    }];
    
    self.chartOption = option;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
