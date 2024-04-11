#include <iostream>
#include <stdexcept>

#include "FileProcessingStrategy.h"
#include "StrategyFactory.h"

namespace
{
    void printHelp()
    {
        std::cout << "Usage: test -f <filename> -m <mode> [-v <word>]" << std::endl;
        std::cout << "Modes:" << std::endl;
        std::cout << "  words      - Count occurrences of a word in the file." << std::endl;
        std::cout << "  checksum   - Calculate checksum of the file." << std::endl;
        std::cout << "  help       - Print this help message." << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4)
    {
        if(argc == 2 && std::string(argv[1]) == "-h")
        {
            printHelp();
            return 0;
        }

        std::cerr << "Usage: " << argv[0] << " -f <filename> -m <mode> [-v <word>]" << std::endl;
        return 1;
    }

    std::string filename, modeArg, mode, word;

    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg == "-f" && i + 1 < argc) {
            filename = argv[++i];
        } else if (arg == "-m" && i + 1 < argc) {
            modeArg = argv[++i];
        } else if (arg == "-v" && i + 1 < argc) {
            word = argv[++i];
        }
    }

    if (filename.empty() || modeArg.empty()) 
    {
        std::cerr << "Filename and mode are required." << std::endl;
        return 1;
    }

    try 
    {
        FileProcessingStrategyFactory::Mode modeEnum;
        if (modeArg == "words")
        {
            modeEnum = FileProcessingStrategyFactory::Mode::WORD_COUNT;
        }
        else if (modeArg == "checksum") 
        {
            modeEnum = FileProcessingStrategyFactory::Mode::CHECKSUM;
        } 
        else 
        {
            std::cerr << "Invalid mode." << std::endl;
            return 1;
        }

        auto strategy = FileProcessingStrategyFactory::createStrategy(modeEnum);
        strategy->process(filename, word);
    } 
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}