#include <filesystem>
#include <fstream>

int main() {
  std::filesystem::path baseDir =
      std::filesystem::absolute("../../../Firmware");

  std::filesystem::path deviceClassPath = baseDir / "sys/class/hwmon/hwmon0";
  std::filesystem::path deviceName = deviceClassPath / "name";
  std::filesystem::path deviceType = deviceClassPath / "type";
  std::filesystem::path deviceValue = deviceClassPath / "value";

  if (!std::filesystem::exists(deviceClassPath)) {
    std::filesystem::create_directories(deviceClassPath);
  }

  std::ofstream(deviceName) << "Magby\n";
  std::ofstream(deviceType) << "Celcius\n";
  std::ofstream(deviceValue) << "34.5\n";

  std::string busName = "2";
  std::string busAddress = "0048";

  std::filesystem::path deviceBusPath =
      baseDir / "sys/i2c/device" / (busName + "-" + busAddress);

  std::filesystem::path i2cHwmonFolder = deviceBusPath / "hwmon";

  if (!std::filesystem::exists(i2cHwmonFolder)) {
    std::filesystem::create_directories(i2cHwmonFolder);
  }

  std::filesystem::path symlinkPath = i2cHwmonFolder / "hwmon0";

  if (!std::filesystem::exists(symlinkPath)) {
    std::filesystem::create_symlink(deviceClassPath, symlinkPath);
  }

  return 0;
}