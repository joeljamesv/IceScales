#include <filesystem>
#include <fstream>
#include <format>
#include <chrono>
#include <iostream>

class Dex
{
private:
     std::filesystem::path logDir = "../../../Firmware/var/log";
     std::filesystem::path logFile = logDir / "journal.log"; 

public:
Dex()
{
     if(!std::filesystem::exists(logDir))
     {
          std::filesystem::create_directories(logDir);
     }
}

void logJournal(const char* requester, const char* message, const char* priority)
{
     std::ofstream logFileHandler(logFile, std::ios::app);
     if(logFileHandler.is_open())
     {
          auto now = std::chrono::system_clock::now();
          
          std::string journalLog = std::format("{} {} : [{}] {}\n", now, requester, priority, message);
          
          logFileHandler << journalLog;
     }
     else 
     {
          std::cerr << "Failed to open log file at: " << logFile << "\n";
     }
}
};

int main()
{
     Dex logger;
     logger.logJournal("Requestee", "The Message", "Priority");
}