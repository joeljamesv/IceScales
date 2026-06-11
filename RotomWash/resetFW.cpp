#include "../Dex/logger.hpp"

#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>

int main() {
  Dex logger;
  std::filesystem::path sysPath = "/home/joeljames/Firmware/";
  std::error_code ec;
  auto count = std::filesystem::remove_all(sysPath, ec);

  if (ec) {
    logger.logJournal("RotomWash", ec.message(), "ERROR");
  } else {
    logger.logJournal("RotomWash", std::format("Removed {} entries", count),
                      "INFO");
  }
}