#pragma once

#include "FileProcessingStrategy.h"

#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>

// Стратегия для расчета контрольной суммы файла
class ChecksumStrategy : public FileProcessingStrategy
{
public:
void process(const std::string& filename, const std::string& word = "") const override
{
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open())
    {
        throw std::runtime_error("Error opening file.");
    }

    uint32_t checksum = 0;
    uint32_t word_value;
    while (file.read(reinterpret_cast<char*>(&word_value), sizeof(uint32_t)))
    {
        checksum += word_value;
    }

    std::cout << "Checksum: " << checksum << std::endl;
}
};