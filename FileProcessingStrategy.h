#pragma once

#include <string>

// Интерфейс стратегии для обработки файлов
class FileProcessingStrategy {
public:
    virtual void process(const std::string& filename, const std::string& word = "") const = 0;
    virtual ~FileProcessingStrategy() {}
};