import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'blood_pressure_package_method_channel.dart';

abstract class BloodPressurePackagePlatform extends PlatformInterface {
  /// Constructs a BloodPressurePackagePlatform.
  BloodPressurePackagePlatform() : super(token: _token);

  static final Object _token = Object();

  static BloodPressurePackagePlatform _instance =
      MethodChannelBloodPressurePackage();

  /// The default instance of [BloodPressurePackagePlatform] to use.
  ///
  /// Defaults to [MethodChannelBloodPressurePackage].
  static BloodPressurePackagePlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [BloodPressurePackagePlatform] when
  /// they register themselves.
  static set instance(BloodPressurePackagePlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<void> bloodPressureInit() {
    throw UnimplementedError('bloodPressureInit() has not been implemented.');
  }

  Future<List> bloodPressureStartScan() {
    throw UnimplementedError(
        'bloodPressureStartScan() has not been implemented.');
  }

  Future<void> bloodPressureStopScan() {
    throw UnimplementedError(
        'bloodPressureStopScan() has not been implemented.');
  }
}
