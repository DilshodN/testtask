#include <gtest/gtest.h>

#include "../CheckSumStrategy.h"
#include "../FileProcessingStrategy.h"
#include "../StrategyFactory.h"
#include "../WordCountStrategy.h"

TEST(FileProcessingStrategyTest, WordCountTest) {
    std::string filename = "test_file.txt";
    std::ofstream testfile(filename);
    testfile << "apple banana apple orange apple";
    testfile.close();

    std::unique_ptr<FileProcessingStrategy> strategy = FileProcessingStrategyFactory::createStrategy(FileProcessingStrategyFactory::Mode::WORD_COUNT);
    testing::internal::CaptureStdout();
    strategy->process(filename, "apple");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Word count for 'apple': 3\n");
}

TEST(FileProcessingStrategyTest, ChecksumTest) {
    std::string filename = "test_file.bin";
    std::ofstream testfile(filename, std::ios::binary);
    uint32_t values[] = { 10, 20, 30, 40 };
    testfile.write(reinterpret_cast<const char*>(&values), sizeof(values));
    testfile.close();

    std::unique_ptr<FileProcessingStrategy> strategy = FileProcessingStrategyFactory::createStrategy(FileProcessingStrategyFactory::Mode::CHECKSUM);
    testing::internal::CaptureStdout();
    strategy->process(filename);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Checksum: 100\n");
}