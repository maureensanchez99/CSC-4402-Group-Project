#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <chrono>
#include <thread>

// Importing an unofficial sqlite3 library wrapper for C++
// Source: https://github.com/SRombauts/SQLiteCpp/tree/sqlitecpp-release-3.3.1
#include <SQLiteCpp/SQLiteCpp.h>

#include "dblink.hpp"
#include "sqlfunctions.hpp"
#include "userinterface.hpp"

int main()
{
    std::pair<int, std::string> user_info;

    title_card();

    /*
    try {
        SQLite::Database db("database.db");
    }
    catch (const std::exception& e) {
        std::cout << "SQLite exception: " << e.what() << std::endl;
        return EXIT_FAILURE; // unexpected error
    }
    */

    user_info = display_login_menu();

    if (user_info.first > 0)
    {
        display_main_menu(user_info.first);
    }

    return 0;
}