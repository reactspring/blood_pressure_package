import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'blood_pressure_package_platform_interface.dart';

/// An implementation of [BloodPressurePackagePlatform] that uses method channels.
class MethodChannelBloodPressurePackage extends BloodPressurePackagePlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('blood_pressure_package');

  @override
  Future<void> bloodPressureInit() async {
    await methodChannel.invokeMethod('bloodPressureInit');
  }

  @override
  Future<List<dynamic>> bloodPressureStartScan() async {
    List result = await methodChannel.invokeMethod('bloodPressureStartScan');
    return result;
  }

  @override
  Future<void> bloodPressureStopScan() async {
    await methodChannel.invokeMethod('bloodPressureStopScan');
  }
}
