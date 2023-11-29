#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

/// @brief Generates a border of a set length out of '='
/// \param length The length of the border to be 
/// generated; this value is set to 100 by default
/// @return A string containing the finished border
std::string generate_border(int length = 100)
{
    std::string border;
    for (int i = 0; i < length; ++i)
    {
        border += '=';
    }
    return border;
}

/// @brief Takes a string and breaks it into individual words
/// @param raw The original string of text to be broken apart
/// @return A vector containing all of the words from `raw`
std::vector<std::string> word_breaker(std::string raw)
{
    std::vector<std::string> words;
    std::string temp;
    for (auto x : raw) // Iterate through each character in `raw`
    {
        if (x == ' ') // If whitespace is encountered, the current word is finished
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

/// \brief Concatenates strings from a vector into lines
/// of a specified size to be sent to the terminal
/// @param words The vector containing all of the strings to be wrapped
/// \param wrap_size The maximum length of each line sent to the 
/// terminal by `word_wrapper`; this value is set to 100 by default
void word_wrapper(std::vector<std::string> words, int wrap_size = 100)
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

/// \brief Sends the name of the company (as ASCII art)
/// to the terminal, surrounded by borders
void title_card()
{
    const std::string ascii_title = 
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
    std::cout << generate_border() << std::endl;
    std::cout << ascii_title << std::endl;
    std::cout << generate_border() << std::endl;
}

/// @brief Prompts the user to input their ID to login to the program
/// @return An interger value representing the user's status (1, 2, 3) or exit request (-1)
int display_login_menu()
{
    std::string login_id;
    char query_response;

    std::cout << "Please select one of the following." << std::endl;
    std::cout << "1] Login as a customer" << std::endl;
    std::cout << "2] Login as an employee" << std::endl;
    std::cout << "3] Login as an administrator" << std::endl;
    std::cout << "4] Exit the program" << std::endl;

    while (true) // Loop the selection until a valid selection is made
    {
        std::cout << "> ";
        query_response = getchar();

        if (query_response == '1' || query_response == '2' || query_response == '3')
        {
            std::cout << "Enter your login ID: " << std::endl;
            std::cout << "> ";
            getline(std::cin, login_id);
        }
        else if (query_response == '4') 
        {
            std::cout << "Now exiting the program." << std::endl;
            return -1;
        }
        else
        {
            std::cout << "Invalid selection. Please try again." << std::endl;
            continue; // Continue to the next loop iteration, don't attempt to check the ID
        }
    
        /* The two functions called upon below have not been implemented yet
        if (is_valid_id(login_id, query_response)) // Check if the input ID is valid
        {
            switch (query_response) // Return a welcome statement depending on the user's status
            {
                case '1':
                    std::cout << "Valid customer ID entered. Welcome, " + name_lookup(login_id) + "." << std::endl;
                case '2':
                    std::cout << "Valid employee ID entered. Welcome, " + name_lookup(login_id) + "." << std::endl;
                case '3':
                    std::cout << "Valid administrator ID entered. Welcome, " + name_lookup(login_id) + "." << std::endl;
                default:
                    break;
            }
            return atoi((char[2]) {query_response, '\0'}); // using C function to convert char to int
        }
        else
        {
            std::cout << "Invalid ID. Please try again." << std::endl;
        }
        */

       return 3; // Temporary return as administrator
    }

    return -1; // Fallback return
}

/// @brief TODO: Add overview text for this function here
/// \param admin_access A boolean value representing if the 
/// menu is being shown to the system administrator or not
void display_main_menu(bool admin_access)
{
    // TODO: Add a way for the user to quit the menu when they're finished

    std::cout << generate_border() << std::endl;
    std::cout << "Standard access functions:" << std::endl;
    std::cout << "1] View item information" << std::endl;
    std::cout << "2] Find item information" << std::endl;
    std::cout << "3] Add item to order" << std::endl;
    std::cout << "4] View current order" << std::endl;

    if (admin_access)
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
        switch (selection) // switch for each selection listed above
        {
            case '1':
                // TODO: implement functionality
                break;
            case '2':
                // TODO: implement functionality
                break;
            case '3':
                // TODO: implement functionality
                break;
            case '4':
                // TODO: implement functionality
                break;
            // admin selections below
            // note: the switch break is inside so that the default case will run if admin_access is false
            case '5':
                if (admin_access)
                {
                    // TODO: implement functionality
                    break;
                }
            case '6':
                if (admin_access)
                {
                    // TODO: implement functionality
                    break;
                }
            case '7':
                if (admin_access)
                {
                    // TODO: implement functionality
                    break;
                }
            case '8':
                if (admin_access)
                {
                    // TODO: implement functionality
                    break;
                }
            case '9':
                if (admin_access)
                {
                    // TODO: implement functionality
                    break;
                }
            default:
                std::cout << "Invalid selection. Please try again." << std::endl;
                break;
        }
    }
}

#endif