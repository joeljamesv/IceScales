#include "../../Dex/logger.hpp"

#include <iostream>
#include <systemd/sd-bus.h>
#include <format>

int main() {
  Dex logger;
  sd_bus *bus = nullptr;

  int ret = sd_bus_default_user(&bus);
  if (ret < 0) {
    logger.logJournal("Foresight", "Failed to connect to bus", "ERROR");
    return 1;
  }

  ret = sd_bus_request_name(bus, "com.Foresight.Sensors", 0);

  if (ret < 0) {
   logger.logJournal(
        "Foresight",
        std::format(
            "Failed claim service name com.Foresight.Sensors ret={} err={}",
            ret,
            strerror(-ret)),
        "ERROR");
    return 1;
  }

  logger.logJournal(
      "Foresight",
      std::format("Claimed service name {}", "com.Foresight.Sensors"), "INFO");

  while (true) {
    sd_bus_process(bus, nullptr);
    sd_bus_wait(bus, UINT64_MAX);
  }

  logger.logJournal("Foresight",
                    std::format("Bus exits {}", "com.Foresight.Sensors"),
                    "INFO");

  sd_bus_unref(bus);
}