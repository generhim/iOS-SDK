//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingEddystoneTLMPowerErrorDomain @"ESTSettingEddystoneTLMPowerErrorDomain"

/**
 *  Describes EddystoneTLM Power validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneTLMPowerError) {
    /**
     *  Provided value does not belong to the ESTEddystoneTLMPower enum.
     */
    ESTSettingEddystoneTLMPowerErrorValueNotAllowed = 1
};

@class ESTSettingEddystoneTLMPower;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Power operation for Eddystone Telemetry packet.
 *
 *  @param power Power setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneTLMPowerCompletionBlock)(ESTSettingEddystoneTLMPower *  powerSetting, NSError *  error);

/**
 *  Available Tx Power levels for Eddystone TLM packet.
 *  @see ESTBeaconPower
 */
typedef NS_ENUM(int8_t, ESTEddystoneTLMPower)
{
    ESTEddystoneTLMPowerLevel1 = -30,
    ESTEddystoneTLMPowerLevel2 = -20,
    ESTEddystoneTLMPowerLevel3 = -16,
    ESTEddystoneTLMPowerLevel4 = -12,
    ESTEddystoneTLMPowerLevel5 = -8,
    ESTEddystoneTLMPowerLevel6 = -4,
    ESTEddystoneTLMPowerLevel7 = 0,
    ESTEddystoneTLMPowerLevel8 = 4
};


/**
 *  ESTSettingEddystoneTLMPower represents Eddystone Telemetry Power value.
 */
@interface ESTSettingEddystoneTLMPower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingEddystoneTLMPower validationErrorForValue:]
 *
 *  @param power Eddystone Telemetry Power value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype )initWithValue:(ESTEddystoneTLMPower)power;

/**
 *  Returns current value of Eddystone Telemetry Power setting.
 *
 *  @return Eddystone Telemetry Power value.
 */
- (ESTEddystoneTLMPower)getValue;

/**
 *  Method allows to read value of initialized Eddystone Telemetry Power setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneTLMPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Eddystone Telemetry Power setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param power Power value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(ESTEddystoneTLMPower)power completion:(ESTSettingEddystoneTLMPowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param power Power value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * )validationErrorForValue:(ESTEddystoneTLMPower)power;

@end

NS_ASSUME_NONNULL_END