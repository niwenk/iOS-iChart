//
//  MAChartColor.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#define PYRGBA(r, g, b, a) [[MAChartColor alloc] initWithColor:[PY_COLOR colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]]


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  转换UIColor为对应的RGBA的输出
 */
@interface MAChartColor : NSObject

- (instancetype)initWithColor:(UIColor *) pyColor;

+ (MAChartColor *)colorWithHexString:(NSString *)hexString;

/**
 *  设置颜色
 *
 *  @param pyColor 颜色
 */
- (void)setColor:(UIColor *) pyColor;

@end
