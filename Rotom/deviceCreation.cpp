#include <filesystem>
#include <format>
#include <fstream>
#include <random>

int hwmonCounter = 0;
int busCounter = 2;
int addressCounter = 40;

class Device {
public:
  Device() {}
  void init(const std::string &name, const std::string &type, double value) {
    std::filesystem::path baseDir =
        std::filesystem::absolute("../../../Firmware");

    std::filesystem::path deviceClassPath =
        baseDir / "sys/class/hwmon" / ("hwmon" + std::to_string(hwmonCounter));
    std::filesystem::path deviceName = deviceClassPath / "name";
    std::filesystem::path deviceType = deviceClassPath / "type";
    std::filesystem::path deviceValue = deviceClassPath / "value";

    if (!std::filesystem::exists(deviceClassPath)) {
      std::filesystem::create_directories(deviceClassPath);
    }

    std::ofstream(deviceName) << std::format("{}\n", name);
    std::ofstream(deviceType) << std::format("{}\n", type);
    std::ofstream(deviceValue) << std::format("{}\n", value);

    std::string busName = std::to_string(busCounter);
    std::string busAddress = "00" + std::to_string(addressCounter);

    std::filesystem::path deviceBusPath =
        baseDir / "sys/bus/i2c/devices" / (busName + "-" + busAddress);

    std::filesystem::path i2cHwmonFolder =
        deviceBusPath / ("hwmon" + std::to_string(hwmonCounter));

    if (!std::filesystem::exists(deviceBusPath)) {
      std::filesystem::create_directories(deviceBusPath);
    }

    if (!std::filesystem::exists(i2cHwmonFolder)) {
      std::filesystem::create_symlink(deviceClassPath, i2cHwmonFolder);
    }

    hwmonCounter++;
    busCounter++;
    addressCounter = addressCounter + (rand() % 8);
  }
};

class TempSensor : public Device {
public:
  TempSensor() {
    std::string name = "Magby";
    std::string type = "Celsius";
    double value = static_cast<std::double_t>(std::rand() % 16 + 25);
    Device::init(name, type, value);
  }
  ~TempSensor() = default;
};

class VoltSensor : public Device {
public:
  VoltSensor() {
    std::string name = "Elekid";
    std::string type = "Volts";
    double value = static_cast<std::double_t>(std::rand() % 10 + 10);
    Device::init(name, type, value);
  }
  ~VoltSensor() = default;
};

int main() {
  TempSensor tempSensor1;
  TempSensor tempSensor2;
  VoltSensor voltSensor;
  return 0;
}