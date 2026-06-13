#include <filesystem>
#include <random>

#pragma once

inline std::filesystem::path firmwareRoot = "/home/joeljames/Firmware";

inline std::random_device rd;
inline std::mt19937 gen(rd());

inline std::uniform_int_distribution<> magbyDist(25, 40);
inline std::uniform_int_distribution<> elekidDist(10, 19);
