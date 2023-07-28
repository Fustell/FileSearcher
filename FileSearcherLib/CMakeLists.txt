cmake_minimum_required(VERSION 3.8)


project(FileSearcherLib)


add_library(FileSearcherLib STATIC FileSearcher.cpp)
target_compile_features(FileSearcherLib PUBLIC cxx_std_20)

target_include_directories(FileSearcherLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})