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

/// @brief TODO: Add overview text for this function here
/// @return TODO: Add return description here
std::string get_db_filepath()
{
    std::string current_file = std::source_location::current().file_name();
    return current_file.substr(0, current_file.length() - std::string("src/main.cpp").length()) + "database/plant_store.db";
}

int main()
{
    try // Check database file can be accessed
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