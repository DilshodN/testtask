#pragma once

#include <memory>
#include <stdexcept>

#include "FileProcessingStrategy.h"
#include "WordCountStrategy.h"
#include "CheckSumStrategy.h"

// Фабричный метод для создания стратегий обработки файлов
class FileProcessingStrategyFactory 
{
public:
    enum class Mode { WORD_COUNT, CHECKSUM };

    static std::unique_ptr<FileProcessingStrategy> createStrategy(Mode mode)
    {
        switch (mode)
        {
            case Mode::WORD_COUNT:
                return std::make_unique<WordCountStrategy>();
            case Mode::CHECKSUM:
                return std::make_unique<ChecksumStrategy>();
            default:
                throw std::invalid_argument("Invalid mode.");
        }
    }
};