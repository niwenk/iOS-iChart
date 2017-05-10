//
//  MAChartUtils.h
//  iOS-iChart
//
//  Created by nwk on 2017/5/9.
//  Copyright © 2017年 com.sh.n22. All rights reserved.
//

#ifndef MAChartUtils_h
#define MAChartUtils_h

/**
 *  The template of custom initializer.
 *  We can use this initializer to create the object,
 *  then use the block to update the property of the object.
 */
#define MAInitializerTemplate(cls, name)                                        \
    + (cls *)init##cls##WithBlock:(void(^)(cls * name))block;

/**
 *  The implemention of the custom initializer(above).
 */
#define MAInitializerImpTemplate(cls)                                           \
    + (cls *)init##cls##WithBlock:(void(^)(cls *))block {                       \
        cls *tmp = [[self alloc] init];                                         \
        block(tmp);                                                             \
        return tmp;                                                             \
    }

/**
 *  The template of the interface which is property custom setter.
 *  You can use this interface to set value for special property.
 *
 *  @param cls  The property is in this class
 *  @param type The property's type
 *  @param name The name of parameter which the property in the object.
 */
#define MAPropertyEqualTemplate(cls, type, name)                                \
    - (cls * (^) (type name)) name##Equal;                                      \


/**
 *  The default implementation for the special the interface(above).
 *  You can use this default in the object.
 *
 *  @param cls  The property is in this class
 *  @param type The property's type
 *  @param name The name of parameter which the property in the object.
 */
#define MAPropertyEqualImpTemplate(cls, type, name)                             \
    - (cls * (^) (type name))name##Equal{                                       \
        return ^(type name) {                                                   \
            self.name = name;                                                   \
            return self;                                                        \
        };                                                                      \
    }                                                                           \

#endif /* MAChartUtils_h */
