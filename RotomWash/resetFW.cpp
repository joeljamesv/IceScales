#include "../Dex/logger.hpp"

#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>

int main() {
  Dex logger;
  std::filesystem::path sysPath = "../../../Firmware";
  std::filesystem::remove_all(sysPath);

  logger.logJournal(
      "Rotom", std::format("Unable to remove {}", sysPath.string()), "ERROR");
}