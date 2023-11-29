#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <chrono>
#include <thread>

// Importing the official sqlite3 library
// Install: On Linux, run this command: sudo apt-get install libsqlite3-dev
// Source: https://www.sqlite.org/cintro.html
#include "sqlite3.h"

// Importing an unofficial sqlite3 wrapper for modern C++
// No need to install, it's already included in external/sqlite_modern_cpp
// Source: https://github.com/SqliteModernCpp/sqlite_modern_cpp
#include "sqlite_modern_cpp.h"

#include "dblink.hpp"
#include "sqlfunctions.hpp"
#include "userinterface.hpp"

int main()
{
    std::pair<int, std::string> user_info;

    title_card();

    user_info = display_login_menu();

    if (user_info.first > 0)
    {
        display_main_menu(user_info.first);
    }

    return 0;
}