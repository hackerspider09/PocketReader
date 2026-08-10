// Storage.h
#pragma once // Prevents duplicate inclusion errors

#include <string>
#include <vector>
#include <filesystem>

class Storage{
    public:
        std::vector<std::filesystem::path> getFiles(std::string);
};