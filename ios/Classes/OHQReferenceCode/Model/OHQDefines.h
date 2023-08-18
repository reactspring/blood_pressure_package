//
//  OHQDefines.h
//  OHQReferenceCode
//
//  Copyright © 2017 Omron Healthcare Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

///---------------------------------------------------------------------------------------
#pragma mark Build options
///---------------------------------------------------------------------------------------

/** Build Option：OHQ_OPTION_CALLBACK_USING_MAIN_QUEUE
 Callback in the main queue from BLEDeviceManager if defined.
 Callback in the unique serial queue generated by BLEDeviceManager if not defined.
 */
#define OHQ_OPTION_CALLBACK_USING_MAIN_QUEUE

/** Build Option：OHQ_OPTION_ENABLE_RETRY_FOR_NOTIFICATION_ACTIVATION
 Retry for enable Notification if defined.
 */
#define OHQ_OPTION_ENABLE_RETRY_FOR_NOTIFICATION_ACTIVATION

/** Build Option：OHQ_OPTION_RETRY_INTERVAL_FOR_NOTIFICATION_ACTIVATION
 Retry interval for enable Notification.
 */
#define OHQ_OPTION_RETRY_INTERVAL_FOR_NOTIFICATION_ACTIVATION (1.0)

/** Build Option : OHQ_OPTION_RETRY_INTERVAL_FOR_NOTIFICATION_ACTIVATION
 Maximum retry count for enable Notification.
 */
#define OHQ_OPTION_RETRY_COUNT_FOR_NOTIFICATION_ACTIVATION (30)

/** Build Option：OHQ_OPTION_ENABLE_LOG
 Logging if defined.
 */
#define OHQ_OPTION_ENABLE_LOG

/** Build Option：OHQ_OPTION_ENABLE_LOG_OUTPUT_TO_CONSOLE
 Output log to the console if defined.
 */
#define OHQ_OPTION_ENABLE_LOG_OUTPUT_TO_CONSOLE

///---------------------------------------------------------------------------------------
#pragma mark - Constants
///---------------------------------------------------------------------------------------

/** Default Consent Code */
extern const UInt16 OHQDefaultConsentCode;

/** Omron Healthcare Company Identifier */
extern const UInt16 OHQOmronHealthcareCompanyIdentifier;

/** Gender */
typedef NSString * OHQGender;
extern OHQGender const OHQGenderMale;   /**< Male */
extern OHQGender const OHQGenderFemale; /**< Female */

///---------------------------------------------------------------------------------------
#pragma mark - Enumerations
///---------------------------------------------------------------------------------------

/** Device Manager State */
typedef NS_ENUM(NSUInteger, OHQDeviceManagerState) {
    OHQDeviceManagerStateUnknown = 0,
    OHQDeviceManagerStateUnsupported,
    OHQDeviceManagerStateUnauthorized,
    OHQDeviceManagerStatePoweredOff,
    OHQDeviceManagerStatePoweredOn,
};

/** Connection State */
typedef NS_ENUM(NSUInteger, OHQConnectionState) {
    OHQConnectionStateDisconnected = 0,
    OHQConnectionStateConnecting,
    OHQConnectionStateConnected,
    OHQConnectionStateDisconnecting,
};

/** Device Manager Authorization */
typedef NS_ENUM(NSUInteger, OHQDeviceManagerAuthorization) {
    OHQDeviceManagerAuthorizationDenied = 0,
    OHQDeviceManagerAuthorizationAllowed,
    OHQDeviceManagerAuthorizationNotDetermined,
    OHQDeviceManagerAuthorizationRestricted,
};

/** Reason for Processing Completion */
typedef NS_ENUM(NSUInteger, OHQCompletionReason) {
    OHQCompletionReasonUnknown = 0,
    OHQCompletionReasonDisconnected,
    OHQCompletionReasonCanceled,
    OHQCompletionReasonPoweredOff,
    OHQCompletionReasonBusy,
    OHQCompletionReasonInvalidDeviceIdentifier,
    OHQCompletionReasonFailedToConnect,
    OHQCompletionReasonFailedToTransfer,
    OHQCompletionReasonFailedToRegisterUser,
    OHQCompletionReasonFailedToAuthenticateUser,
    OHQCompletionReasonFailedToDeleteUser,
    OHQCompletionReasonFailedToSetUserData,
    OHQCompletionReasonOperationNotSupported,
    OHQCompletionReasonConnectionTimedOut,
};

/** Device Category */
typedef NS_ENUM(NSUInteger, OHQDeviceCategory) {
    OHQDeviceCategoryUnknown = 0,
    OHQDeviceCategoryBloodPressureMonitor,
    OHQDeviceCategoryWeightScale,
    OHQDeviceCategoryBodyCompositionMonitor,
    OHQDeviceCategoryPulseOximeter,
    OHQDeviceCategoryHealthThermometer,
    OHQDeviceCategoryAny = NSUIntegerMax,
};

/** Data Type */
typedef NS_ENUM(NSUInteger, OHQDataType) {
    OHQDataTypeCurrentTime = 0,              /**< Current Time (Type of Data : NSDate) */
    OHQDataTypeBatteryLevel,                 /**< Battery Level (Type of Data : NSNumber(float)) */
    OHQDataTypeModelName,                    /**< Model Name (Type of Data : NSString) */
    OHQDataTypeDeviceCategory,               /**< Device Category (Type of Data : NSNumber(OHQDeviceCategory)) */
    OHQDataTypeRegisteredUserIndex,          /**< Registered User Index (Type of Data : NSNumber) */
    OHQDataTypeAuthenticatedUserIndex,       /**< Authenticated User Index (Type of Data : NSNumber) */
    OHQDataTypeDeletedUserIndex,             /**< Deleted User Index (Type of Data : NSNumber(UInt8)) */
    OHQDataTypeUserData,                     /**< User Data (Type of Data : NSDictionary<OHQUserDataKey,id>)  */
    OHQDataTypeDatabaseChangeIncrement,      /**< Database Change Increment (Type of Data : NSNumber(UInt32)) */
    OHQDataTypeSequenceNumberOfLatestRecord, /**< Sequence Number (Type of Data : NSNumber(UInt16)) */
    OHQDataTypeMeasurementRecords,           /**< Measurement Records (Type of Data : NSArray<NSDictionary<OHQMeasurementRecordKey,id> *>) */
};

/** Blood Pressure Measurement Status */
typedef NS_OPTIONS(UInt16, OHQBloodPressureMeasurementStatus) {
    OHQBloodPressureMeasurementStatusBodyMovementDetected = 1 << 0,
    OHQBloodPressureMeasurementStatusCuffTooLoose = 1 << 1,
    OHQBloodPressureMeasurementStatusIrregularPulseDetected = 1 << 2,
    OHQBloodPressureMeasurementStatusPulseRateTooHigher = 1 << 3,
    OHQBloodPressureMeasurementStatusPulseRateTooLower = 1 << 4,
    OHQBloodPressureMeasurementStatusImproperMeasurementPosition = 1 << 5,
};

///---------------------------------------------------------------------------------------
#pragma mark - Enumeration Description Functions
///---------------------------------------------------------------------------------------

extern NSString * OHQDeviceManagerStateDescription(OHQDeviceManagerState value);
extern NSString * OHQConnectionStateDescription(OHQConnectionState value);
extern NSString * OHQCompletionReasonDescription(OHQCompletionReason value);
extern NSString * OHQDeviceCategoryDescription(OHQDeviceCategory value);
extern NSString * OHQDataTypeDescription(OHQDataType value);
extern NSString * OHQBloodPressureMeasurementStatusDescription(OHQBloodPressureMeasurementStatus value);

///---------------------------------------------------------------------------------------
#pragma mark - Dictionary Keys
///---------------------------------------------------------------------------------------

/** Device Info key */
typedef NSString * OHQDeviceInfoKey NS_STRING_ENUM;
/** Identifier (Type of value : NSUUID) */
extern OHQDeviceInfoKey const OHQDeviceInfoIdentifierKey;
/** Advertisement Data (Type of value : NSDictionary<OHQAdvertisementDataKey,id>) */
extern OHQDeviceInfoKey const OHQDeviceInfoAdvertisementDataKey;
/** RSSI (Type of value : NSNumber, unit is in "dBm") */
extern OHQDeviceInfoKey const OHQDeviceInfoRSSIKey;
/** Model Name (Type of value : NSUUID) */
extern OHQDeviceInfoKey const OHQDeviceInfoModelNameKey;
/** Model Name (Type of value : NSNumber[OHQDeviceCategory]) */
extern OHQDeviceInfoKey const OHQDeviceInfoCategoryKey;

/** Advertisement Data key */
typedef NSString * OHQAdvertisementDataKey NS_STRING_ENUM;
/** Local Name (Type of value : NSString) */
extern OHQAdvertisementDataKey const OHQAdvertisementDataLocalNameKey;
/** Is Connectable (Type of value : NSNumber[BOOL]) */
extern OHQAdvertisementDataKey const OHQAdvertisementDataIsConnectable;
/** Service UUIDs (Type of value : NSArray<CBUUID *>) */
extern OHQAdvertisementDataKey const OHQAdvertisementDataServiceUUIDsKey;
/** Service Data (Type of value : NSDictionary<CBUUID *,NSData>) */
extern OHQAdvertisementDataKey const OHQAdvertisementDataServiceDataKey;
/** Overflow Service UUIDs (Type of value : NSArray<CBUUID *>) */
extern OHQAdvertisementDataKey const OHQAdvertisementDataOverflowServiceUUIDsKey;
/** Solicited Service UUIDs (Type of value : NSArray<CBUUID *>) */
extern OHQAdvertisementDataKey const OHQAdvertisementDataSolicitedServiceUUIDsKey;
/** Tx Power Level (Type of value : NSNumber, Unit is ["dBm"]) */
extern OHQAdvertisementDataKey const OHQAdvertisementDataTxPowerLevelKey;
/** Manufacturer Data (Type of value : NSDictionary<OHQManufacturerDataKey,id>) */
extern OHQAdvertisementDataKey const OHQAdvertisementDataManufacturerDataKey;

/** Manufacturer Data key */
typedef NSString * OHQManufacturerDataKey NS_STRING_ENUM;
/** Company Identifier (Type of value : NSNumber) */
extern OHQManufacturerDataKey const OHQManufacturerDataCompanyIdentifierKey;
/** Company Identifier Description (Type of value : NSString) */
extern OHQManufacturerDataKey const OHQManufacturerDataCompanyIdentifierDescriptionKey;
/** Number of User (Type of value : NSNumber) */
extern OHQManufacturerDataKey const OHQManufacturerDataNumberOfUserKey;
/** Is Pairing Mode (Type of value : NSNumber[BOOL]) */
extern OHQManufacturerDataKey const OHQManufacturerDataIsPairingMode;
/** Time Not Configured (Type of value : NSNumber[BOOL]) */
extern OHQManufacturerDataKey const OHQManufacturerDataTimeNotConfigured;
/** Is Bluetooth Standard Mode (Type of value: NSNumber[BOOL])*/
extern OHQManufacturerDataKey const OHQManufacturerDataIsBluetoothStandardMode;
/** Record Info Array (Type of value : NSArray<NSDictionary<OHQRecordInfoKey,id> *>) */
extern OHQManufacturerDataKey const OHQManufacturerDataRecordInfoArrayKey;

/** Record info key */
typedef NSString * OHQRecordInfoKey NS_STRING_ENUM;
/** User Index (Type of value : NSNumber) */
extern OHQRecordInfoKey const OHQRecordInfoUserIndexKey;
/** Sequence Number (Type of value : NSNumber) */
extern OHQRecordInfoKey const OHQRecordInfoLastSequenceNumberKey;
/** Number of Records (Type of value : NSNumber) */
extern OHQRecordInfoKey const OHQRecordInfoNumberOfRecordsKey;

/** Session option key */
typedef NSString * OHQSessionOptionKey NS_STRING_ENUM;

/** Read Measurement Records (Type of value : NSNumber[BOOL])
 
 A Boolean value that specifies whether reading records of measurement.
 The value for this key is an NSNumber object. If the key is not specified, the default value is NO.
 */
extern OHQSessionOptionKey const OHQSessionOptionReadMeasurementRecordsKey;

/** Allow Control of Reading Position to Measurement Records (Type of value : NSNumber[BOOL])
 
 A boolean value that specifies whether to control the reading position of the measurement record.
 If you specify YES, the reading position of the measurement record depends on the value specified by SequenceNumberOfFirstRecordToReadKey.
 If SequenceNumberOfFirstRecordToReadKey is not specifed, all records are read.
 It works only on devices that support the Omron Extension protocol.
 The value for this key is an NSNumber object. If the key is not specified, the default value is NO.
 */
extern OHQSessionOptionKey const OHQSessionOptionAllowControlOfReadingPositionToMeasurementRecordsKey;

/** Sequence Number of First Record to Read (Type of value : NSNumber[0 - 65535])
 
 A sequence number that specifies the reading start position for measurement record.
 It works only on devices that support the Omron Extension protocol.
 */
extern OHQSessionOptionKey const OHQSessionOptionSequenceNumberOfFirstRecordToReadKey;

/** Allow Access to Omron Extended Measurement Records (Type of value : NSNumber[BOOL])
 
 A Boolean value that specifies whether reading omron extended measurement records instead of bluetooth standard measurement record.
 It works only on devices that support the Omron Extension protocol.
 The value for this key is an NSNumber object. If the key is not specified, the default value is NO.
 */
extern OHQSessionOptionKey const OHQSessionOptionAllowAccessToOmronExtendedMeasurementRecordsKey;

/** Register New User (Type of value : NSNumber[BOOL])
 
 A Boolean value that specifies whether register new user to device.
 If the user index is not specified with UserIndexKey, it is assigned to an unregistered user index, and if it is specified, it is assigned to the specified User Index.
 You can specify the User Index only on devices that support Omron Extension Protocol.
 If registration fails, the session will fail with the reason of FailedToRegisterUser.
 It works only on devices that manage users.
 The value for this key is an NSNumber object. If the key is not specified, the default value is NO.
 */
extern OHQSessionOptionKey const OHQSessionOptionRegisterNewUserKey;

/** Delete User Data (Type of value : NSNumber[BOOL])
 
 A Boolean value that specifies whether delete user data from device.
 If you specify YES, the user information registered in the User Index specified by UserIndexKey is deleted.
 If deletion fails, the session will fail with the reason of FailedToDeleteUser.
 It works only with devices that manage users.
 The value for this key is an NSNumber object. If the key is not specified, the default value is NO.
 */
extern OHQSessionOptionKey const OHQSessionOptionDeleteUserDataKey;

/** Consent Code (Type of value : NSNumber[0x0000 - 0x270F])
 
 Consent code used for user authentication and user registration.
 This only works if UserIndexKey is specified.
 The value for this key is an NSNumber object. If the key is not specified, the default value is OHQDefaultConsentCode(0x020E).
 */
extern OHQSessionOptionKey const OHQSessionOptionConsentCodeKey;

/** User Index (Type of value : NSNumber[1 - 4])
 
 User index used for user authentication and user registration.
 It works only with devices that manage users.
 */
extern OHQSessionOptionKey const OHQSessionOptionUserIndexKey;

/** User Data (Type of value : NSDictionary<OHQUserDataKey,id>) */
extern OHQSessionOptionKey const OHQSessionOptionUserDataKey;

/** Database Change Increment Value (Type of value : NSNumber[0 - 4294967295]) */
extern OHQSessionOptionKey const OHQSessionOptionDatabaseChangeIncrementValueKey;

/** User Data Update Flag (Type of value : NSNumber[BOOL]) */
extern OHQSessionOptionKey const OHQSessionOptionUserDataUpdateFlagKey;

/** Connection Wait Time (Type of value : NSNumber[NSTimeInterval]) */
extern OHQSessionOptionKey const OHQSessionOptionConnectionWaitTimeKey;

/** User Data key */
typedef NSString * OHQUserDataKey NS_STRING_ENUM;
/** Date of Birth(of local time zone) (Type of value : NSDate) */
extern OHQUserDataKey const OHQUserDataDateOfBirthKey;
/** Height (Type of value : NSNumber[Float], Unit is ["cm"]) */
extern OHQUserDataKey const OHQUserDataHeightKey;
/** Gender (Type of value : OHQGender) */
extern OHQUserDataKey const OHQUserDataGenderKey;

/** Measurement Record key */
typedef NSString * OHQMeasurementRecordKey NS_STRING_ENUM;
/** User Index (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordUserIndexKey;
/** Time Stamp (Type of value : NSDate) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordTimeStampKey;
/** Sequence Number (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordSequenceNumberKey;
/** Blood Pressure Unit (Type of value : NSString, Unit is ["mmHg" or "kPa"]) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordBloodPressureUnitKey;
/** Systolic Blood Pressure (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordSystolicKey;
/** Diastolic Blood Pressure (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordDiastolicKey;
/** Mean Arterial Pressure (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordMeanArterialPressureKey;
/** Pulse Rate (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordPulseRateKey;
/** Blood Pressure Measurement status (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordBloodPressureMeasurementStatusKey;
/** Weight Unit (Type of value : NSString, Value is ["kg" or "lb"]) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordWeightUnitKey;
/** Height Unit (Type of value : NSString, Value is ["m" of "in"]) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordHeightUnitKey;
/** Weight (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordWeightKey;
/** Height (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordHeightKey;
/** BMI (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordBMIKey;
/** Body Fat Percentage (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordBodyFatPercentageKey;
/** Basal Metabolism (Type of value : NSNumber, Unit is ["kJ"]) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordBasalMetabolismKey;
/** Muscle Percentage (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordMusclePercentageKey;
/** Muscle Mass (Type of value : NSNumber, Unit is ["kg" or "lb"]) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordMuscleMassKey;
/** Fat Free Mass (Type of value : NSNumber, Unit is ["kg" or "lb"]) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordFatFreeMassKey;
/** Soft Lean Mass (Type of value : NSNumber, Unit is ["kg" or "lb"]) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordSoftLeanMassKey;
/** Body Water Mass (Type of value : NSNumber, Unit is ["kg" or "lb"]) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordBodyWaterMassKey;
/** Impedance (Type of value : NSNumber, Unit is ["Ω"]) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordImpedanceKey;
/** Skeletal Muscle Percentage (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordSkeletalMusclePercentageKey;
/** Visceral Fat Level (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordVisceralFatLevelKey;
/** Body Age (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordBodyAgeKey;
/** Body Fat Percentage Stage Evaluation (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordBodyFatPercentageStageEvaluationKey;
/** Skeletal Muscle Percentage Stage Evaluation (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordSkeletalMusclePercentageStageEvaluationKey;
/** Visceral Fat Level Stage Evaluation (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordVisceralFatLevelStageEvaluationKey;
/** Saturation Of Percutaneous Oxygen (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordPulseOximeterSpo2Key;
/** Body Temperature (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordBodyTemperatureKey;
/** Body Temperature Unit (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordBodyTemperatureUnitKey;
/** Body Temperature Type (Type of value : NSNumber) */
extern OHQMeasurementRecordKey const OHQMeasurementRecordBodyTemperatureTypeKey;

///---------------------------------------------------------------------------------------
#pragma mark - Blocks
///---------------------------------------------------------------------------------------

/** Scan monitoring block.
 @param deviceInfo A dictionary containing discovered device information.
 */
typedef void (^OHQScanObserverBlock)(NSDictionary<OHQDeviceInfoKey,id> *deviceInfo);

/** Data monitoring block.
 @param aDataType Type of received data.
 @param data A dictionary containing any received data.
 */
typedef void (^OHQDataObserverBlock)(OHQDataType aDataType, id data);

/** Connection monitoring block.
 @param aState Updated connection state.
 */
typedef void (^OHQConnectionObserverBlock)(OHQConnectionState aState);

/** Complete Process block.
 @param aReason Reason for process complete.
 */
typedef void (^OHQCompletionBlock)(OHQCompletionReason aReason);

NS_ASSUME_NONNULL_END

