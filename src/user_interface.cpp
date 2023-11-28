#include <iostream>
#include <algorithm>
#include <string>

std::string generate_border(int wrap_size = 88)
{
    std::string border;
    for (int i = 0; i < wrap_size; ++i)
    {
        border += '=';
    }
    return border;
}

std::vector<std::string> word_breaker(std::string raw)
{
    std::vector<std::string> words;
    std::string temp;
    for (auto x : raw) // Iterate through each character in `raw`
    {
        if (x == ' ') // If a whitespace is encountered, the current word is finished
        {   
            if (temp != "")
            {
                words.insert(words.end(), temp); // Add stored current word to the end of `words`
            }
            temp = "";
        }
        else 
        {
            temp = temp + x; // If the char isn't a whitespace, add it to the end of `temp`
        }
    }
    words.insert(words.end(), temp); // Add anything left from `temp` to `words`
    return words;
}


void word_wrapper(std::vector<std::string> words, int wrap_size = 88)
{
    std::string current_line;
    for (auto x: words) // Iterate through each string in `words`
    {
        if (x.length() + current_line.length() > wrap_size)
        { // If the current string + `current_line` exceeds `wrap_size`, output and reset the string
            std::cout << current_line << std::endl;
            current_line = x + " "; // Reset `current_line` to be equal to the next word, then add a space
        }
        else // Add string to `current_line` if it doesn't exceed `wrap_size`, then add a space
        {
            current_line = current_line + x + " ";
        }
    }

    if (!current_line.empty() && current_line != " ")
    {
        std::cout << current_line << std::endl; // Ensures the last line is always sent (if it exists)
    }

    std::cout << generate_border() << std::endl; // Printing the lower border
}


const std::string title_card = 
"  /$$$$$$                                          /$$$$$$$                                  /$$    \n"
" /$$__  $$                                        | $$__  $$                                | $$    \n"
"| $$  \\__/  /$$$$$$   /$$$$$$  /$$  /$$  /$$      | $$  \\ $$  /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$  \n"
"| $$ /$$$$ /$$__  $$ /$$__  $$| $$ | $$ | $$      | $$  | $$ /$$__  $$ /$$__  $$ /$$__  $$|_  $$_/  \n"
"| $$|_  $$| $$  \\__/| $$  \\ $$| $$ | $$ | $$      | $$  | $$| $$$$$$$$| $$  \\ $$| $$  \\ $$  | $$    \n"
"| $$  \\ $$| $$      | $$  | $$| $$ | $$ | $$      | $$  | $$| $$_____/| $$  | $$| $$  | $$  | $$ /$$\n"
"|  $$$$$$/| $$      |  $$$$$$/|  $$$$$/$$$$/      | $$$$$$$/|  $$$$$$$| $$$$$$$/|  $$$$$$/  |  $$$$/\n"
" \\______/ |__/       \\______/  \\_____/\\___/       |_______/  \\_______/| $$____/  \\______/    \\___/  \n"
"                                                                      | $$                          \n"
"                                                                      | $$                          \n"
"                                                                      |__/                          \n";

void TitleCard()
{
    std::cout << generate_border() << std::endl;
    std::cout << title_card << std::endl;
    std::cout << generate_border() << std::endl;
}

//might just scrap the actual login system for a simple which mode query
//because actual security of the program isn't really important
bool display_login_menu()
{
    while (true)
    {
        std::cout << "1: Customer Login" << std::endl << "2: Administrator Login" << std::endl;
        char query_response = getchar();
        std::string login_id;

        //switch for promting them to enter the appropriate ID
        switch (query_response)
        {
            case '1':
                std::cout << "Enter Customer Login ID: ";
                getline(std::cin, login_id);
                break;
            case '2':
                std::cout << "Enter Admin Login ID: ";
                getline(std::cin, login_id);
                break;
            default:
                std::cout << "Invalid Selection";
                break;
        }

        //secondary switch to check if entered values for ID match
        /* not yet implemented

        switch(query_response)
        {
            case '1':
                if (isValid(login_id, customer))
                    return true;
                else
                    std::cout << "Invalid Login ID"
            case '2':
        }

        */
    }
}


void display_menu(bool menu_type = false)
{
    //this boolean value ^ represents whether this is administrator or customer access
    //True is administrator and False is customer, default is false
    std::cout << generate_border() << std::endl;

    std::cout << "Standard access functions:" << std::endl;
    std::cout << "1] View item information" << std::endl;
    std::cout << "2] Find item information" << std::endl;
    std::cout << "3] Add item to order" << std::endl;
    std::cout << "4] View current order" << std::endl;

    if (menu_type)
    {
        std::cout << std::endl;
        std::cout << "Administrator access functions:" << std::endl;
        std::cout << "5] View employee information" <<std::endl;
        std::cout << "6] View all orders" <<std::endl;
        std::cout << "7] Update employee information" <<std::endl;
        std::cout << "8] Update item information" <<std::endl;
        std::cout << "9] Update order information" <<std::endl;
    }

    std::cout << generate_border() << std::endl;

    while (true)
    {
        std::cout << "> ";
        char selection = getchar();
        switch (selection)
        {
            //standard stuff//
            case '1':
                //do stuff
                break;
            case '2':
                //do stuff
                break;
            case '3':
                //do stuff
                break;
            case '4':
                //do stuff
                break;
            
            //Admin stuff//
            case '5':
                if (menu_type)
                {
                    //do appropriate actions
                }
                else
                    std::cout << "Invalid Selection:";
                break;
            case '6':
                if (menu_type)
                {
                    //do appropriate actions
                }
                else
                    std::cout << "Invalid Selection:";
                break;
            case '7':
                if (menu_type)
                {
                    //do appropriate actions
                }
                else
                    std::cout << "Invalid Selection:";
                break;
            case '8':
                if (menu_type)
                {
                    //do appropriate actions
                }
                else
                    std::cout << "Invalid Selection:";
                break;
            case '9':
                if (menu_type)
                {
                    //do appropriate actions
                }
                else
                    std::cout << "Invalid Selection:";
                break;
            default:
                std::cout << "Invalid Selection:";
                break;
        }
    }
}

