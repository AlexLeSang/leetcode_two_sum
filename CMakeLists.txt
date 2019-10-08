cmake_minimum_required(VERSION 3.13)
project(two-sum)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(two-sum two-sum.cpp)
target_compile_options(two-sum PRIVATE -Wall -Wextra -pedantic -O3)
