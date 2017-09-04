cmake_minimum_required(VERSION 3.8)
project(queue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TQueue.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})