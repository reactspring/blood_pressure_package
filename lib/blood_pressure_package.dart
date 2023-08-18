import 'blood_pressure_package_platform_interface.dart';

class BloodPressurePackage {
  Future<void> bloodPressureInit() {
    return BloodPressurePackagePlatform.instance.bloodPressureInit();
  }

  Future<List> bloodPressureStartScan() {
    return BloodPressurePackagePlatform.instance.bloodPressureStartScan();
  }

  Future<void> bloodPressureStopScan() {
    return BloodPressurePackagePlatform.instance.bloodPressureStopScan();
  }
}
