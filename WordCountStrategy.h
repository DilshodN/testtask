#pragma once

#include <fstream>
#include <iostream>

#include "FileProcessingStrategy.h"

// Стратегия для подсчета количества слов в файле
class WordCountStrategy final : public FileProcessingStrategy
{
public:
void process(const std::string& filename, const std::string& word = "") const override {
    std::ifstream file(filename);
    if (!file.is_open()) 
    {
        throw std::runtime_error("Error opening file.");
    }

    std::string token;
    uint32_t count = 0;
    while (file >> token)
    {
        if (token == word)
        {
            count++;
        }
    }

    std::cout << "Word count for '" << word << "': " << count << std::endl;
}
};