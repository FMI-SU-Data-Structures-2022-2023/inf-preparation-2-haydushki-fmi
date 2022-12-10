cmake_minimum_required (VERSION 3.13)

project ("Exam Preparation 2" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Library target for the sample library
add_library(cs1 STATIC)

target_sources(
        cs1
        PRIVATE
                "src/cs1/node.hpp"
                "src/cs1/task1.cpp"
                "src/cs1/task2.cpp"
                "src/cs1/task3.cpp"
)


#
# Make Catch2 available. For more information check
# https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md
#
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.1.1)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)


# Executable target for the unit tests
add_executable(unit-tests)

target_link_libraries(
        unit-tests
        PRIVATE
                cs1
                Catch2::Catch2WithMain
)

target_include_directories(unit-tests PRIVATE "src")

target_sources(
        unit-tests
        PRIVATE
                "tests/cs1/task1Tests.cpp"
                "tests/cs1/task2Tests.cpp"
                "tests/cs1/task3Tests.cpp"
)


# Automatically register all tests
include(CTest)
include(Catch)
catch_discover_tests(unit-tests)
