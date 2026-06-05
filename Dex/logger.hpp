#pragma once

#include <filesystem>

class Dex
{
private:
     std::filesystem::path logDir = "../../../Firmware/var/log";
     std::filesystem::path logFile = logDir / "journal.log"; 
public:
     Dex();
    void logJournal(const char* requester, const char* message, const char* priority);
};