cmake_minimum_required(VERSION 4.0)
project(julia_set)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(julia_set
        src/Bitmap.cpp
        src/Bitmap.h
        src/BmpHeaders.h
        src/main.cpp)
