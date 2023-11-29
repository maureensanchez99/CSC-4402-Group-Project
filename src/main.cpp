#include <iostream>
#include <algorithm>
#include <string>

#include "userinterface.hpp"

int main()
{
    title_card();

    int user_type = display_login_menu();

    switch (user_type)
    {
        case -1:
            return 0;
            break;
        case 1:
            // do nothing (for now), use default
        case 2:
            // do nothing (for now), use default
        case 3:
            display_main_menu(true);
            break;
        default:
            display_main_menu(false);
            break;
    }

    return 0;
}