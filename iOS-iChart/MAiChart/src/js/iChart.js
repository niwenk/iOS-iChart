var MAListenerKey = 'eventName';
var MAListenerValue = 'event';
var MAClickChartEvent = 'click';
var MAParseTextChartEvent = 'parseText';
/**
 * 添加监听事件
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

function obtainiCharts(obj){
    
//    alert(obj.get('name')+' '+obj.get('value') +' '+obj.get('id'));
        
    var id = obj.get('id');
    var indexPath = id.split("_");
    
    var params = {
        name : obj.get('name'),
        value : obj.get('value'),
        section : indexPath[0],
        row : indexPath[1]
    };
    
    window.location.href = 'MAiChartActionHandle://MAClick#'+JSON.stringify(params);
}

function preTask(obj) {
    var result;
    if(typeof(obj) == 'object') {
        
        if(obj instanceof Array) {
            result = new Array();
            for (var i = 0, len = obj.length; i < len ; i++) {
                result.push(preTask(obj[i]));
            }
            return result;
        } else if(obj instanceof RegExp){
            return obj;
        } else {
            result = new Object();
            for (var prop in obj) {
                if (prop == 'listeners') {
                    var listener = obj[prop];
                    result[prop] = addChartListener(listener);
                } else {
                    result[prop] = preTask(obj[prop]);
                }
            }
            return result;
        }
    } else if(typeof(obj) == 'string'){
        
        try {
            if(typeof(eval(obj)) == 'function'){
                
                return eval(obj);
            } else if (typeof(eval(obj) == 'object') && (eval(obj) instanceof Array || eval(obj) instanceof CanvasGradient)) {
                return eval(obj);
            }
        }catch(e) {
            return obj;
        }
        return obj;
    } else {
        return obj;
    }
}

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

function test() {
    var data = [
                {
                name : '普通高等教育本专科招生人数',
                value:[321,384,447,504,546,566,608,640,662,682],
                color:'#de9972'
                },
                {
                name : '各类中等职业教育招生人数',
                value:[474,516,566,656,748,810,812,869,870,809],
                color:'#28847f'
                },
                {
                name : '全国普通高中招生人数',
                value:[677,752,822,878,871,840,837,830,836,851],
                color:'#90abc0'
                }
                ];
    var tt = {
        render : 'canvasDiv',
    data: data,
    labels:["2002","2003","2004","2005","2006","2007","2008","2009","2010","2011"],
        title : {
            text : '2002-2011年各类教育招生人数',
            color : '#3e576f'
        },
        footnote : {
            text : '数据来源：中华人民共和国国家统计局',
            color : '#909090',
            fontsize : 11,
            padding : '0 44'
        },
        width : 800,
        height : 400,
        background_color : '#ffffff',
    legend:{
    enable:true,
        background_color : null,
        align : 'center',
        valign : 'bottom',
    row:1,
    column:'max',
        border : {
            enable : false
        }
    },
        column_width : 8,//柱形宽度
    zScale:8,//z轴深度倍数
        xAngle : 50,
    bottom_scale:1.1,
    label:{
    color:'#4c4f48'
    },
    sub_option:{
        label :false,
    listeners:{
        /**
         * r:iChart.Rectangle2D对象
         * e:eventObject对象
         * m:额外参数
         */
    click:function(r,e,m){
        alert(r.get('name')+' '+r.get('value'));
    }
    }
    },
    tip:{
        enable :true
    },
        text_space : 16,//坐标系下方的label距离坐标系的距离。
    coordinate:{
        background_color : '#d7d7d5',
        grid_color : '#a4a4a2',
        color_factor : 0.24,
    board_deep:10,
    offsety:-10,
    pedestal_height:10,
    left_board:false,//取消左侧面板
    width:620,
    height:240,
    scale:[{
           position:'left',
           start_scale:0,
           end_scale:1000,
           scale_space:200,
           scale_enable : false,
           label:{
           color:'#4c4f48'
           }
           }]
    }
    };
    
    return preTask(tt);
}
