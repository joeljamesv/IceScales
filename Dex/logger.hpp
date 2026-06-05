#pragma once

#include <filesystem>

class Dex
{
private:
     std::filesystem::path firmwareRoot =
    "/home/joeljames/Firmware";
     std::filesystem::path logFile = firmwareRoot / "var/log/journal.log"; 
public:
     Dex();
    void logJournal(const std::string& requester, const std::string& message, const std::string& priority);
};