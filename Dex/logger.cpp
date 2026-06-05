#include "logger.hpp"

#include <filesystem>
#include <fstream>
#include <format>
#include <chrono>
#include <iostream>


Dex::Dex()
{
     if(!std::filesystem::exists(logFile.parent_path()))
     {
          std::filesystem::create_directories(logFile.parent_path());
     }
}

void Dex::logJournal(const std::string& requester, const std::string& message, const std::string& priority)
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
