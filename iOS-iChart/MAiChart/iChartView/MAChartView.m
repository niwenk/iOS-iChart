//
//  MAChartView.m
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import "MAChartView.h"
#import "MAChartJson.h"

@interface MAChartView()<UIWebViewDelegate> {
    NSString *bundlePath;
    NSString *localHtmlContents;
    MAChartOption *option;
    NSMutableDictionary<NSString *, MAChartActionHandler> *actionHandleBlocks;
}

@end

@implementation MAChartView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self setupWebView];
    }
    
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder:aDecoder];
    if (self) {
        [self setupWebView];
    }
    
    return self;
}

- (void)setChartType:(NSInteger)chartType {
    _chartType = chartType;
}

- (void)setupWebView {
    actionHandleBlocks = [NSMutableDictionary dictionary];
    
    bundlePath = [[NSBundle mainBundle] bundlePath];
    
    NSString *urlString = [[NSBundle mainBundle] pathForResource:@"iChart" ofType:@"html"];
    localHtmlContents =[[NSString alloc] initWithContentsOfFile:urlString encoding:NSUTF8StringEncoding error:nil];
    
    if (localHtmlContents == nil || [localHtmlContents isEqualToString:@""]) {
        NSLog(@"Error: Can't load echart's files.");
    }
    
    self.delegate = self;
    self.scrollView.bounces = NO;
    self.scrollView.scrollEnabled = NO;
    self.scalesPageToFit = NO;
    // set the view background is transparent
    self.opaque = NO;
    self.backgroundColor = [UIColor clearColor];
//    UIPinchGestureRecognizer *pinchGestureRecognizer = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(pinchGestureHandle:)];
//    pinchGestureRecognizer.cancelsTouchesInView = NO;
//    [self addGestureRecognizer:pinchGestureRecognizer];
}

- (void)setOption:(MAChartOption *)chartOption {
    option = chartOption;
}

/**
 *  Load the web view request
 */
- (void)loadiCharts {
    [self loadHTMLString:localHtmlContents baseURL:[NSURL fileURLWithPath: bundlePath]];
}

- (void)addHandlerForAction:(MAiChartAction)name withBlock:(MAChartActionHandler)block {
    [actionHandleBlocks setObject:block forKey:name];
}

- (void)webViewDidFinishLoad:(UIWebView *)webView {
    if ([[webView stringByEvaluatingJavaScriptFromString:@"document.readyState"] isEqualToString:@"complete"]) {
       
        if (option == nil) {
//            NSLog(@"Warning: The option is nil.");
//            [self callJsMethods:@"initEchartView()"];
            return ;
        }
        
        NSString *jsonStr = [MAChartJson getJSONString:option];
        
        NSLog(@"%@",jsonStr);
        
        NSString *js = [NSString stringWithFormat:@"loadiChartView(%@,%zd)", jsonStr, self.chartType];
        
        [webView stringByEvaluatingJavaScriptFromString:js];

        [webView stringByEvaluatingJavaScriptFromString:@"document.documentElement.style.webkitUserSelect='none';"];
        
        // Disable callout
        [webView stringByEvaluatingJavaScriptFromString:@"document.documentElement.style.webkitTouchCallout='none';"];
    } else {
//        __weak __typeof(self) weakSelf = self;
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.05 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//            __typeof(self) strongSelf = weakSelf;
//            if (!strongSelf.finishRender) {
//                [self loadEcharts];
//            }
        });
    }
}

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
    NSURL *url = request.URL;
    
    if (![[url.scheme lowercaseString] hasPrefix:MAiChartActionHandle]) {
        return YES;
    }
    
    // get the action from the path
    NSString *actionType = url.host;
    
    NSLog(@"---%@",actionType);
    if ([actionType isEqual:MAiChartActionClick]) {
        // deserialize the request JSON
        NSString *jsonDictString = [url.fragment stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        // decode the json params to dictionary
        NSData *paramData = [jsonDictString dataUsingEncoding:NSUTF8StringEncoding];
        NSError *err;
        NSDictionary *paramsDic;
        if (jsonDictString != nil && ![jsonDictString isEqualToString:@""]) {
            paramsDic = [NSJSONSerialization JSONObjectWithData:paramData options:NSJSONReadingMutableLeaves error:&err];
            if(err) {
                NSLog(@"Json decode failed：%@",err);
                paramsDic = nil;
            }
        }
        
        if (actionHandleBlocks[actionType]) {
            MAChartActionHandler handler = actionHandleBlocks[actionType];
            handler(paramsDic);
        }
    }
    
    return NO;
}

- (void)callJsMethods:(NSString *)methodWithParam {
    [self stringByEvaluatingJavaScriptFromString:methodWithParam];
}

- (void)dealloc {
    [self stopLoading];
}
@end
