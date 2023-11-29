cmake_minimum_required(VERSION 3.19)

project(csc-4402-group-project)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/sqlite_modern_cpp)

add_executable(project
    src/main.cpp
    src/userinterface.hpp
    src/checksql.hpp
    external/sqlite_modern_cpp/sqlite_modern_cpp.h
)

target_link_libraries(project sqlite3)