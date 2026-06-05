#include "../Dex/logger.hpp"

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
    Dex logger;

    std::filesystem::path firmwareRoot = "/home/joeljames/Firmware";

    std::filesystem::path deviceClassPath =
        firmwareRoot / "sys/class/hwmon" /
        ("hwmon" + std::to_string(hwmonCounter));
    std::filesystem::path deviceName = deviceClassPath / "name";
    std::filesystem::path deviceType = deviceClassPath / "type";
    std::filesystem::path deviceValue = deviceClassPath / "value";

    if (!std::filesystem::exists(deviceClassPath)) {
      std::filesystem::create_directories(deviceClassPath);
    }

    logger.logJournal(
        "Rotom", std::format("{} Directory Created", deviceClassPath.string()),
        "INFO");

    std::ofstream(deviceName) << std::format("{}\n", name);
    std::ofstream(deviceType) << std::format("{}\n", type);
    std::ofstream(deviceValue) << std::format("{}\n", value);

    logger.logJournal(
        "Rotom", std::format("{} : {} Sensor Created", name, type), "INFO");

    std::string busName = std::to_string(busCounter);
    std::string busAddress = "00" + std::to_string(addressCounter);

    std::filesystem::path deviceBusPath =
        firmwareRoot / "sys/bus/i2c/devices" / (busName + "-" + busAddress);

    std::filesystem::path i2cHwmonFolder =
        deviceBusPath / ("hwmon" + std::to_string(hwmonCounter));

    if (!std::filesystem::exists(deviceBusPath)) {
      std::filesystem::create_directories(deviceBusPath);
    }

    if (!std::filesystem::exists(i2cHwmonFolder)) {
      std::filesystem::create_symlink(deviceClassPath, i2cHwmonFolder);
    }

    logger.logJournal(
        "Rotom", std::format("{} symLink Created", i2cHwmonFolder.string()),
        "INFO");

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
    double value = static_cast<double>(std::rand() % 16 + 25);
    Device::init(name, type, value);
  }
  ~TempSensor() = default;
};

class VoltSensor : public Device {
public:
  VoltSensor() {
    std::string name = "Elekid";
    std::string type = "Volts";
    double value = static_cast<double>(std::rand() % 10 + 10);
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