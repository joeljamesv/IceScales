#include <filesystem>
#include <fstream>
#include <iostream>

int main() {
  std::filesystem::path sysPath = "../../../Firmware";
  std::filesystem::remove_all(sysPath);

  if (std::filesystem::exists(sysPath)) {
    std::cout << "Not able to remove\n";
  }
}