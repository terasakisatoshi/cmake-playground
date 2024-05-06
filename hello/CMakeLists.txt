cmake_minimum_required(VERSION 3.14)

project(MyHello)

# GoogleTest requires at least C++14
# set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyHello hello.cpp)

add_subdirectory(test)
