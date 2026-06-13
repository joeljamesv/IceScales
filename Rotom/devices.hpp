#include <filesystem>
#pragma once

inline std::filesystem::path firmwareRoot = "/home/joeljames/Firmware";

std::random_device rd;
std::mt19937 gen(rd());

std::uniform_int_distribution<> magbyDist(25, 40);
std::uniform_int_distribution<> elekidDist(10, 19);
