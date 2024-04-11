cmake_minimum_required(VERSION 3.20)
enable_testing()
project(testapp)

set(CMAKE_CXX_STANDARD 23)
find_package(GTest REQUIRED)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
SET( CMAKE_CXX_FLAGS  "-lgtest")

add_executable(unittest unittest.cpp)

target_link_libraries(unittest gtest gtest_main)
add_test( unittest unittest )