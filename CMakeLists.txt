cmake_minimum_required(VERSION 3.5)
project (Intent_Recongition)
set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES intentRecognition.h)
set(SOURCES intentRecognition.cpp main.cpp)

add_executable(application ${SOURCES} ${HEADER_FILES})
