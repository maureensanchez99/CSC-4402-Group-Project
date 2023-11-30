#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <chrono>
#include <thread>
#include <source_location>

// Importing an unofficial sqlite3 library wrapper for C++
// Source: https://github.com/SRombauts/SQLiteCpp/tree/sqlitecpp-release-3.3.1
#include <SQLiteCpp/SQLiteCpp.h>

#include "helperfunctions.hpp"
#include "sqlfunctions.hpp"
#include "userinterface.hpp"

int main()
{
    try // Check that the db can be accessed; if not, quit program
    {
        SQLite::Database db(get_db_filepath());
    }
    catch (const std::exception& e) 
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    title_card();
    std::pair<int, int> user_info = display_login_menu();

    if (user_info.first > 0)
    {
        display_main_menu(user_info.first);
    }

    return 0;
}