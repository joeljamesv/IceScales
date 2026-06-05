#include "logger.hpp"

#include <filesystem>
#include <fstream>
#include <format>
#include <chrono>
#include <iostream>


Dex::Dex()
{
     if(!std::filesystem::exists(logDir))
     {
          std::filesystem::create_directories(logDir);
     }
}

void Dex::logJournal(const char* requester, const char* message, const char* priority)
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
