//
//  MAChartJson.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MAChartJson : NSObject
/**
 *  NSObject转json
 *
 *  @param obj 带信息的NSObject对象
 *
 *  @return 转换后的Json
 */
+ (NSString *)getJSONString:(id)obj;

/**
 *  NSObject转json
 *
 *  @param obj 带信息的NSObject对象
 *
 *  @return 转换后的包含Json的NSData
 */
+ (NSData*)getJSONData:(id)obj;


/**
 *  将指定对象转换成NSDirectory
 *
 *  @param obj 需要转换的对象
 *
 *  @return 转换后的NSDictionary对象
 */
+ (NSDictionary*)getObjectData:(id)obj;

@end
