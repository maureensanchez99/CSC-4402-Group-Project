cmake_minimum_required(VERSION 3.19)

project(csc-4402-group-project)

set(CMAKE_CXX_STANDARD 20)

add_executable(project src/main.cpp)
target_link_libraries(project
    sqlite3
)

# To install the required sqlite3 library on Linux, 
# run this command: sudo apt-get install libsqlite3-dev