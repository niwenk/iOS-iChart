# iOS-iChart
简单的对iChart进行原生封装
# 介绍
与EChart的做法类似，只是事件的添加没有EChart方便，iChart的事件处理比较笨，需要自己手动去配置。iChart还有好多属性未设置，可以根据官方文档对应添加属性。
# 代码片段
```
# 原生代码
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
    
    self.charView.chartType = MAChartPie3D;
    
    [self getPieOption];
    
    [self.charView setOption:self.chartOption];
    
    [self.charView loadiCharts];
```

```
# js
/**
 * 构建动态图表
 */
function loadiChartView(initParams,type) {
    
    var option = preTask(initParams);
    
    console.log(option);
    
//    alert('init params : ' + JSON.stringify(option));
    switch (type) {
        case 0:
            new iChart.Column3D(option).draw();
        break;
        case 1:
            new iChart.ColumnMulti3D(option).draw();
        break;
        case 2:
            new iChart.Pie3D(option).draw();
        break;
        default:
            break;
    }
}
/**
 * 处理监听事件
 */
function addChartListener(listener) {
    try {
        var eventObj = new Object();
        var key, value;
        
        if (typeof(listener) == 'object') {
            
            console.log(listener);
            
            for (var index in listener) {
                var eventName = listener[index][MAListenerKey];
                if (eventName != 'undefined' && eventName != null) {
                    console.log("方法名：" + eventName);
                    if (eventName == MAClickChartEvent) {
                        var clickEvent = function(r,e,m){
                            obtainiCharts(r);
                        };
                        eventObj[eventName] = clickEvent;
                    } else if(eventName == MAParseTextChartEvent) {
                        var value = listener[index][MAListenerValue];
                        var parseEvent = function(d, t){
                            if (value != 'undefined' && value != null)
                                return value.replace(/%@/, d.get('value'));//替换占位符
                            return d.get('value');
                        };
                        eventObj[eventName] = parseEvent;
                    }
                }
            }
            return eventObj;
        }
        
    } catch (e) {
        return null;
    }
    
    return null;
}
```

# 效果图

![柱状图](https://raw.githubusercontent.com/niwenk/iOS-iChart/master/Screenshots/1.png)

![饼状图](https://raw.githubusercontent.com/niwenk/iOS-iChart/master/Screenshots/2.png)




