#import "BloodPressurePackagePlugin.h"
#import "OHQReferenceCode.h"

@interface BloodPressurePackagePlugin () <OHQDeviceManagerDataSource>

@end

@implementation BloodPressurePackagePlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  FlutterMethodChannel* channel = [FlutterMethodChannel
      methodChannelWithName:@"blood_pressure_package"
            binaryMessenger:[registrar messenger]];
  BloodPressurePackagePlugin* instance = [[BloodPressurePackagePlugin alloc] init];
  [registrar addMethodCallDelegate:instance channel:channel];
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
    if ([@"bloodPressureInit" isEqualToString:call.method]) {
        OHQDeviceManager *manager = [OHQDeviceManager sharedManager];
        manager.dataSource = self;
    } else if ([@"bloodPressureStartScan" isEqualToString:call.method]) {
        [[OHQDeviceManager sharedManager] writeBluetoothStatusToLog];
        [[OHQDeviceManager sharedManager] scanForDevicesWithCategory:OHQDeviceCategoryBloodPressureMonitor usingObserver:^(NSDictionary<OHQDeviceInfoKey,id> * _Nonnull deviceInfo) {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSString *modelName = deviceInfo[OHQDeviceInfoModelNameKey];
                NSUUID *identifier = deviceInfo[OHQDeviceInfoIdentifierKey];
                [[OHQDeviceManager sharedManager] startSessionWithDevice:identifier usingDataObserver:^(OHQDataType aDataType, id  _Nonnull data) {
                    if (aDataType == OHQDataTypeMeasurementRecords) {
                        if (![data  isEqual: @[]]) {
                            result(@[data[0][OHQMeasurementRecordSystolicKey], data[0][OHQMeasurementRecordDiastolicKey], data[0][OHQMeasurementRecordPulseRateKey], modelName]);
                            #ifdef DEBUG
                            NSLog(@"data[0] : %@", data[0]);
                            #endif
                            [[OHQDeviceManager sharedManager] stopScan];
                        } else {
                            result(@[@"", @"", @"", modelName]);
                        }
                    }
                } connectionObserver:^(OHQConnectionState aState) {
                    if (aState == OHQConnectionStateConnected) {
                        #ifdef DEBUG
                        NSLog(@"state is connected.");
                        #endif
                    } else if (aState == OHQConnectionStateDisconnected) {
                        #ifdef DEBUG
                        NSLog(@"state is disconnected.");
                        #endif
                    }
                } completion:^(OHQCompletionReason aReason) {
                    #ifdef DEBUG
                    NSLog(@"session completion reason: %lu", aReason);
                    #endif
                }options: @{
                    OHQSessionOptionReadMeasurementRecordsKey: @YES,
                    OHQSessionOptionConnectionWaitTimeKey: @60.0
                }];
            });
        } completion:^(OHQCompletionReason aReason) {
            dispatch_async(dispatch_get_main_queue(), ^{
                #ifdef DEBUG
                NSLog(@"scan completion reason: %lu", aReason);
                #endif
            });
        }];
    } else if ([@"bloodPressureStopScan" isEqualToString:call.method]) {
        [[OHQDeviceManager sharedManager] stopScan];
    } else {
        result(FlutterMethodNotImplemented);
    }
    
//  if ([@"getPlatformVersion" isEqualToString:call.method]) {
//    result([@"iOS " stringByAppendingString:[[UIDevice currentDevice] systemVersion]]);
//  } else {
//    result(FlutterMethodNotImplemented);
//  }
}

@end
