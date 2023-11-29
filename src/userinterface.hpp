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

/// @brief Prompts the user for input and stores their response
/// @return A string containing the user's input in all lowercase
std::string get_input(bool is_inline = false)
{
    std::string input;
    if (!is_inline)
    {
    std::cout << "> ";
    }
    getline(std::cin, input); // Reads input until a newline character is reached

    std::transform(input.begin(), input.end(), input.begin(), ::tolower); // Convert input to all lowercase
    return input;
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
    std::cout << generate_border() << std::endl << ascii_title << generate_border() << std::endl;
}

/// @brief Prompts the user to input their ID to login to the program
/// \return An std::pair containing the type of user and their ID 
/// (or an empty pair for exiting the program)
std::pair<int, std::string> display_login_menu()
{
    std::string login_id;
    int login_type;

    std::cout << "Welcome to the Grow Depot UI!" << std::endl
    << "To login, enter your ID number." << std::endl
    << "To quit, type exit." << std::endl << generate_border() << std::endl;

    while(true) // Loop until the user inputs a valid login or quits the program
    {
        std::cout << "Enter your login ID:" << std::endl;
        login_id = get_input();
        std::cout << generate_border() << std::endl;
        
        if (login_id == "exit")
        {
            std::cout << "Now exiting the program." << std::endl
            << generate_border() << std::endl;
            return {-1, ""};
        }
        else if (check_id(login_id)) // Check ID validity
        {
            login_type = check_user_type(login_id); // Get the type of user
            switch (login_type) // Return welcome statement based on user type
            {
                case 1:
                    std::cout << "Valid customer ID entered. Welcome, " 
                    + name_lookup(login_id) + "." << std::endl;
                    break;
                case 2:
                    std::cout << "Valid employee ID entered. Welcome, " 
                    + name_lookup(login_id) + "." << std::endl;
                    break;
                case 3:
                    std::cout << "Valid administrator ID entered. Welcome, " 
                    + name_lookup(login_id) + "." << std::endl;
                    break;
                default:
                    break;
            }
            std::cout << generate_border() << std::endl;
            sleep(2); // The sleep is just here for making the text more readable
            return {login_type, login_id};
        }
        else
        {
            std::cout << "Invalid login. Please try again." << std::endl
            << generate_border() << std::endl;
        }
    }
}

/// @brief TODO: Add overview text for this function here
/// \param login_type An integer value representing the 
/// type of user that the main menu is being shown to
void display_main_menu(int login_type)
{
    std::string input;
    int input_as_int;
    bool loop_active = true;

    while (loop_active)
    {

        std::cout << "Main Menu" << std::endl
        << generate_border() << std::endl
        << "1] View available items" << std::endl
        << "2] Find an item" << std::endl
        << "3] Add item to current order" << std::endl
        << "4] Remove item from current order" << std::endl
        << "5] View current order" << std::endl
        << "6] Cancel current order" << std::endl
        << "7] Checkout current order" << std::endl;
        if (login_type == 3)
        {
            std::cout << std::endl << "[Admin Options]" << std::endl
            << "8] View employee information" << std::endl
            << "9] View all orders" << std::endl
            << "10] Update employee information" << std::endl
            << "11] Add employee" << std::endl
            << "12] Remove employee" << std::endl
            << "13] Update item information" << std::endl
            << "14] Update order information" << std::endl;
        }
        std::cout << std::endl << "0] Exit the program"
        << std::endl << generate_border() << std::endl;

        input = get_input();

        try
        {
            input_as_int = std::stoi(input);
        }
        catch(const std::exception& e)
        {
            std::cout << "Invalid input. Please try again." << std::endl;
            continue;
        }

        if (input_as_int > 4 && login_type != 3)
        {
            std::cout << "Invalid input. Please try again." << std::endl;
            continue;
        }

        switch (input_as_int)
        {
            case 0:
            {
                loop_active = false; // Exit loop (& program)
                break;
            }
            case 1:
            {
                view_availabe_items();
                std::cout << generate_border() << std::endl;
                break;
            }
            case 2:
            {
                std::cout << "Please enter the item id: ";
                int product_id;
                std::string product_id_string = get_input(true);
                try
                {
                    product_id = std::stoi(product_id_string)
                }
                catch(std::invalid_argument)
                {
                    std::cout << "ERROR: your input must be a number" << std::endl;
                    break;
                }
                find_an_item(product_id);
                std::cout << generate_border() << std::endl;
                break;
            }
            case 3:
            {
                std::cout << "Please enter the item id: ";
                int product_id;
                std::string product_id_string = get_input(true);
                try
                {
                    product_id = std::stoi(product_id_string)
                }
                catch(std::invalid_argument)
                {
                    std::cout << "ERROR: your input must be a number" << std::endl;
                    break;
                }
                add_item_to_current_order(product_id);
                std::cout << generate_border() << std::endl;
                break;
            }
            case 4:
            {
                std::cout << "Please enter the item id: ";
                int product_id;
                std::string product_id_string = get_input(true);
                try
                {
                    product_id = std::stoi(product_id_string)
                }
                catch(std::invalid_argument)
                {
                    std::cout << "ERROR: your input must be a number" << std::endl;
                    break;
                }
                remove_item_from_current_order(product_id);
                std::cout << generate_border() << std::endl;
                break;
            }
            case 5:
            {
                view_current_order();
                std::cout << generate_border() << std::endl;
                break;
            }
            case 6:
            {
                cancel_current_order();
                std::cout << generate_border() << std::endl;
                break;
            }
            case 7:
            {
                checkout_current_order();
                std::cout << generate_border() << std::endl;
                break;
            }

            //ADMIN CASES//

            case 8:
            {
                if (login_type == 3)
                {
                   view_employee_info();
                }
                else
                {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                std::cout << generate_border() << std::endl;
                break;
            }
            case 9:
            {
                if (login_type == 3)
                {
                    view_all_orders();
                }
                else
                {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                std::cout << generate_border() << std::endl;
                break;
            }
            case 10:
            {
                if (login_type == 3)
                {
                    std::cout << "Please enter the following Information" << std::endl;
                    std::cout << "Employee ID: ";
                    int employee_id;
                    std::string employee_id_string = get_input(true);
                    if (employee_id_string.empty())
                    {
                        std::cout << "invalid input, field cannot be empty" << std::endl;
                        break;
                    }
                    else
                    {
                        try
                        {
                            employee_id = std::stoi(employee_id_string);
                        }
                        catch(std::invalid_argument)
                        {
                            std::cout << "ERROR: your input must be a number" << std::endl;
                            break;
                        }
                    }

                    std::cout << "Leave the following fields blank if no change should be made" << std::endl;
                    std::cout << "Employee hours: ";
                    int employee_hours;
                    std::string employee_hours_string = get_input(true);
                    if (employee_hours_string.empty())
                    {
                        employee_hours = -1;
                    }
                    else
                    {
                        try
                        {
                        employee_hours = std::stoi(employee_id_string);
                        }
                        catch(std::invalid_argument)
                        {
                            std::cout << "ERROR: your input must be a number" << std::endl;
                            break;
                        }
                    }

                    std::cout << "Employee wage: ";
                    int employee_wage;
                    std::string employee_wage_string = get_input(true);
                    if (employee_wage_string.empty())
                    {
                        employee_wage = -1;
                    }
                    else
                    {
                        try
                        {
                        employee_wage = std::stoi(employee_id_string);
                        }
                        catch(std::invalid_argument)
                        {
                            std::cout << "ERROR: your input must be a number" << std::endl;
                            break;
                        }
                    }

                    std::cout << "Employee Job Title: ";
                    std::string employee_job_title = get_input(true);
                    
                    update_employee_info(employee_id, employee_wage, employee_hours, employee_job_title);
                }
                else
                {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                std::cout << generate_border() << std::endl;
                break;
            }
            case 11:
            {
                if (login_type == 3)
                {
                    std::cout << "Please enter the following Information" << std::endl;
                    std::cout << "Employee ID: ";
                    int employee_id;
                    std::string employee_id_string = get_input(true);
                    if (employee_id_string.empty())
                    {
                        std::cout << "invalid input, field cannot be empty" << std::endl;
                        break;
                    }
                    else
                    {
                        try
                        {
                            employee_id = std::stoi(employee_id_string);
                        }
                        catch(std::invalid_argument)
                        {
                            std::cout << "ERROR: your input must be a number" << std::endl;
                            break;
                        }
                    }

                    std::cout << "Leave the following fields blank if no change should be made" << std::endl;
                    std::cout << "Employee hours: ";
                    int employee_hours;
                    std::string employee_hours_string = get_input(true);
                    if (employee_hours_string.empty())
                    {
                        std::cout << "invalid input, field cannot be empty" << std::endl;
                        break;
                    }
                    else
                    {
                        try
                        {
                        employee_hours = std::stoi(employee_hours_string);
                        }
                        catch(std::invalid_argument)
                        {
                            std::cout << "ERROR: your input must be a number" << std::endl;
                            break;
                        }
                    }

                    std::cout << "Employee wage: ";
                    int employee_wage;
                    std::string employee_wage_string = get_input(true);
                    if (employee_wage_string.empty())
                    {
                        std::cout << "invalid input, field cannot be empty" << std::endl;
                        break;
                    }
                    else
                    {
                        try
                        {
                        employee_wage = std::stoi(employee_wage_string);
                        }
                        catch(std::invalid_argument)
                        {
                            std::cout << "ERROR: your input must be a number" << std::endl;
                            break;
                        }
                    }

                    std::cout << "Employee Job Title: ";
                    std::string employee_job_title = get_input(true);
                    
                    update_employee_info(employee_id, employee_wage, employee_hours, employee_job_title);
                }
                else
                {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                std::cout << generate_border() << std::endl;
                break;
            }
            case 12:
            {
                if (login_type == 3)
                {
                    std::cout << "Please enter the following Information" << std::endl;
                    std::cout << "Employee ID: ";
                    int employee_id;
                    std::string employee_id_string = get_input(true);
                    if (employee_id_string.empty())
                    {
                        std::cout << "invalid input, field cannot be empty" << std::endl;
                        break;
                    }
                    else
                    {
                        try
                        {
                            employee_id = std::stoi(employee_id_string);
                        }
                        catch(std::invalid_argument)
                        {
                            std::cout << "ERROR: your input must be a number" << std::endl;
                            break;
                        }
                    }

                    remove_employee(employee_id);
                }
                else
                {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                std::cout << generate_border() << std::endl;
                break;
            }
            case 13:
            {
                if (login_type == 3)
                {
                    //TODO: implement functionality
                    std::cout << "Please enter the following Information" << std::endl;
                    std::cout << "Product name: ";
                    std::string product_name = get_input(true);

                    std::cout << "Product type: ";
                    std::string product_type = get_input(true);

                    std::cout << "Product cost: ";
                    int product_cost;
                    std::string product_cost_string = get_input(true);
                    if (product_cost_string.empty())
                    {
                        product_cost = -1;
                        break;
                    }
                    else
                    {
                        try
                        {
                            product_cost = std::stoi(product_cost_string);
                        }
                        catch(std::invalid_argument)
                        {
                            std::cout << "ERROR: your input must be a number" << std::endl;
                            break;
                        }
                    }

                    std::cout << "Product amount: ";
                    int product_amount;
                    std::string product_amount_string = get_input(true);
                    if (product_amount_string.empty())
                    {
                        product_amount = -1;
                        break;
                    }
                    else
                    {
                        try
                        {
                            product_amount = std::stoi(product_amount_string);
                        }
                        catch(std::invalid_argument)
                        {
                            std::cout << "ERROR: your input must be a number" << std::endl;
                            break;
                        }
                    }

                    update_item_info(product_type, product_cost, product_amount, product_name);
                }
                else
                {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                std::cout << generate_border() << std::endl;
                break;
            }
            case 14:
            {
                if (login_type == 3)
                {
                    std::cout << "Please enter the following Information" << std::endl;
                    std::cout << "Order ID: ";
                    int order_id;
                    std::string order_id_string = get_input(true);
                    if (order_id_string.empty())
                    {
                        std::cout << "invalid input, field cannot be empty" << std::endl;
                        break;
                    }
                    else
                    {
                        try
                        {
                            order_id = std::stoi(order_id_string);
                        }
                        catch(std::invalid_argument)
                        {
                            std::cout << "ERROR: your input must be a number" << std::endl;
                            break;
                        }
                    }

                    std::cout << "Leave the following fields blank if no change should be made" << std::endl;
                    std::cout << "Customer ID: ";
                    int customer_id;
                    std::string customer_id_string = get_input(true);
                    if (customer_id_string.empty())
                    {
                        customer_id = -1;
                    }
                    else
                    {
                        try
                        {
                            customer_id = std::stoi(customer_id_string);
                        }
                        catch(std::invalid_argument)
                        {
                            std::cout << "ERROR: your input must be a number" << std::endl;
                            break;
                        }
                    }

                    std::cout << "Associated Email: ";
                    std::string email = get_input(true);

                    std::cout << "Product name: ";
                    std::string product_name = get_input(true);

                    std::cout << "Product quantity: ";
                    int product_quantity;
                    std::string product_quantity_string = get_input(true);
                    if (product_quantity_string.empty())
                    {
                        product_quantity = -1;
                    }
                    else
                    {
                        try
                        {
                            product_quantity = std::stoi(product_quantity_string);
                        }
                        catch(std::invalid_argument)
                        {
                            std::cout << "ERROR: your input must be a number" << std::endl;
                            break;
                        }
                    }

                    update_order_info(order_id, customer_id, email, product_name, product_quantity);
                }
                else
                {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                std::cout << generate_border() << std::endl;
                break;
            }
            default:
            {
                std::cout << "Invalid input. Please try again." << std::endl
                << generate_border() << std::endl;
                break;
            }
        }
        
        if(loop_active)
        {
            std::cout << "Action complete. Returning to main menu." << std::endl
            << generate_border() << std::endl;
            sleep(1);
        }
        else
        {
            std::cout << generate_border() << std::endl << "Now exiting the program." 
            << std::endl << generate_border() << std::endl;
        }
    }
}

#endif