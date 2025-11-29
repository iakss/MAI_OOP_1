cmake_minimum_required(VERSION 3.14)
project(MAI_OOP_1)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(func STATIC function/function.hpp function/function.cpp)

add_executable(task_program main.cpp)
target_link_libraries(task_program func)
target_include_directories(task_program PUBLIC function)

add_executable(unit_tests tests/unit.cpp)
target_link_libraries(unit_tests func GTest::gtest_main)
target_include_directories(unit_tests PUBLIC function)

include(GoogleTest)
gtest_discover_tests(unit_tests)
