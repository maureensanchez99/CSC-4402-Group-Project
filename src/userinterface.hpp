#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

/// @brief Prompts the user to input their ID to login to the program
/// \return An std::pair containing the type of user and their ID 
/// (or an empty pair for exiting the program)
std::pair<int, int> display_login_menu()
{
    std::pair<int, int> return_val;
    std::pair<bool, std::string> lookup_return;
    std::string input = std::string();
    bool employee_login = false;
    bool loop_active = true;

    std::cout << "Welcome to the Grow Depot UI!" << std::endl;

    while(loop_active) // Loop until the user inputs a valid login or quits the program
    {
        std::cout << "Are you logging in as an employee? (Y/N): ";
        input = get_input(true);
        std::cout << generate_border() << std::endl;

        if (input == "y" || input == "Y")
        {
            employee_login = true;
            input = std::string();
            loop_active = false;
        }
        else if (input == "n" || input == "N")
        {    
            employee_login = false;
            input = std::string();
            loop_active = false;
        }
        else
        {
            invalid_msg();
        }
    }

    sleep(1); // Used to make the text more readable
    std::cout << "To login, enter your ID number." << std::endl
    << "To quit, type exit." << std::endl << generate_border() << std::endl;

    while(true) // Loop until the user inputs a valid login or quits the program
    {
        std::cout << "Enter your login ID: ";
        input = get_input(true);
        std::cout << generate_border() << std::endl;
        
        if (input == "exit")
        {
            std::cout << "Now exiting the program." << std::endl
            << generate_border() << std::endl;
            return {-1, -1}; // Tells the main function to exit
        }
        else
        {
            try
            {
                return_val.second = std::stoi(input); // Convert ID into an int
            }
            catch(const std::exception& e) // If stoi() fails, prompt user to try again
            {
                invalid_msg("login");
                continue;
            }

            lookup_return = check_id(employee_login, return_val.second); // Lookup the user ID

            if (lookup_return.second.empty()) // Restart loop if ID is invalid
            {
                invalid_msg("login");
                continue;
            }
            else if (employee_login && lookup_return.first) // Output welcome statement
            {
                std::cout << "Valid administrator ID entered. Welcome, " 
                + lookup_return.second + "." << std::endl;
                return_val.first = 3;
            }
            else if (employee_login)
            {
                return_val.first = 2;
                std::cout << "Valid employee ID entered. Welcome, " 
                + lookup_return.second + "." << std::endl;
            }
            else
            {
                return_val.first = 1;
                std::cout << "Valid customer ID entered. Welcome, "
                + lookup_return.second + "." << std::endl;
            }

            std::cout << generate_border() << std::endl;
            sleep(1); // Used to make the text more readable

            return return_val;
        }
    }
}

/// @brief Displays the main menu and links all program actions
/// @param login_type An integer value representing the type of user accessing the menu
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
            invalid_msg();
            continue;
        }

        if (input_as_int > 7 && login_type != 3)
        {
            invalid_msg();
            continue;
        }

        switch (input_as_int)
        {
            case 0: // exit
            {
                loop_active = false; // Exit loop (& program)
                break;
            }
            case 1: // view all items
            {
                view_available_items();
                std::cout << generate_border() << std::endl;
                break;
            }
            case 2: // find a specific item
            {
                std::cout << "Please enter the item id: ";
                int product_id;
                std::string product_id_string = get_input(true);
                try
                {
                    product_id = std::stoi(product_id_string);
                }
                catch(std::invalid_argument)
                {
                    std::cout << "ERROR: Your input must be a number." << std::endl;
                    break;
                }
                find_an_item(product_id);
                std::cout << generate_border() << std::endl;
                break;
            }
            case 3: // add item to current order
            {

                std::cout << "Please enter the item id: ";
                std::string product_id = get_input(true);

                std::cout << "Please enter the item amount: ";
                std::string item_amount = get_input(true);

                std::cout << "Please enter the order id: ";
                std::string order_id = get_input(true);

                std::cout << "Please enter the order type: ";
                std::string order_type = get_input(true);

                std::cout << "Please enter the customer id: ";
                std::string customer_id = get_input(true);

                add_item_to_order(product_id, item_amount, order_id, order_type, customer_id);
                std::cout << generate_border() << std::endl;
                break;
            }
            case 4: // remove item from current order
            {
                std::cout << "Please enter the order id: ";
                std::string order_id = get_input(true);

                std::cout << "Please enter the product id: ";
                std::string product_id = get_input(true);

                remove_item_from_order(product_id, order_id);
                std::cout << generate_border() << std::endl;
                break;
            }
            case 5: // view current order
            {
                std::cout << "Please enter the order id: ";
                std::string order_id = get_input(true);
                view_order(order_id);
                std::cout << generate_border() << std::endl;
                break;
            }
            case 6: // cancel current order
            {
                std::cout << "Please enter the order id: ";
                std::string order_id = get_input(true);

                std::cout << "Please enter the customer id: ";
                std::string customer_id = get_input(true);
                cancel_order(order_id, customer_id);
                std::cout << generate_border() << std::endl;
                break;
            }
            case 7: // checkout current order
            {
                std::cout << "Please enter the order id: ";
                std::string order_id = get_input(true);

                checkout_order(order_id);
                std::cout << generate_border() << std::endl;
                break;
            }
            case 8: // view employee information
            {
                view_employee_info();
                std::cout << generate_border() << std::endl;
                break;
            }
            case 9: // view all orders
            {
                view_all_orders();
                std::cout << generate_border() << std::endl;
                break;
            }
            case 10: // update an employee's information
            {
                std::string employee_id;
                std::string name;
                std::string address;
                std::string hours;
                std::string wage;
                bool is_manager;

                std::cout << "Enter the employee's id: ";
                employee_id = get_input(true);

                std::cout << "Enter the following information (leave blank if no change should be made)"
                << std::endl << "Employee name: ";
                name = get_input(true);
                
                while (true)
                {
                    std::cout << "Enter the employee's address in the format"
                    " [street_num street_name apt_num(optional) city state zipcode]: ";
                    address = get_input(true);

                    int temp_int = word_breaker(address).size();
                    if (temp_int == 5 || temp_int == 6)
                    {
                        break;
                    }        
                    else 
                    {
                        invalid_msg("format");
                        continue;
                    }
                }

                std::cout << "Enter the employee's hours: ";
                hours = get_input(true);

                std::cout << "Enter the employee's wage: ";
                wage = get_input(true);
                
                while (true)
                {
                    std::cout << "Please enter if the employee is a manager (Y/N): ";
                    std::string is_manager_str = get_input(true);

                    if (is_manager_str == "Y" || is_manager_str == "y") 
                    {
                        is_manager = true;
                        break;
                    }
                    else if (is_manager_str == "n" || is_manager_str == "n") 
                    {
                        is_manager = false;
                        break;
                    }
                    else 
                    {
                        invalid_msg();
                        continue;
                    }
                }

                update_employee_info(employee_id, name, address, hours, wage, is_manager);
                std::cout << generate_border() << std::endl;
                break;
            }
            case 11: // add a new employee
            {
                //add_employee();
                std::cout << generate_border() << std::endl;
                break;
            }
            case 12: // remove an employee
            {
                //remove_employee();
                std::cout << generate_border() << std::endl;
                break;
            }
            case 13: // update an item's information
            {
                //update_item_info();
                std::cout << generate_border() << std::endl;
                break;
            }
            case 14: // update an order's information
            {
                //update_order_info();
                std::cout << generate_border() << std::endl;
                break;
            }
            default: // invalid input
            {
                invalid_msg();
                break;
            }
        }
        
        if (loop_active)
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