#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

#include "sqlite3.h" // External sqlite3 library

#include "userinterface.hpp"
#include "checksql.hpp"

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