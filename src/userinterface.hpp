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
            lookup_return = check_id(employee_login, input); // Lookup the user ID

            try // Convert ID into an int
            {
                return_val.second = std::stoi(input);
            }
            catch(const std::exception& e) // If stoi() fails, restart loop
            {
                invalid_msg("ID");
                continue;
            }

            if (lookup_return.second.empty()) // If ID is invalid (empty), restart loop
            {
                invalid_msg("ID");
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
    int input;
    bool loop_active = true;
    bool action_success = false;
    bool fall_trigger = false;

    while (loop_active)
    {
        std::cout << "Main Menu" << std::endl
        << generate_border() << std::endl
        << "1] View available items" << std::endl
        << "2] Find an item" << std::endl
        << "3] Add an item to the current order" << std::endl
        << "4] Remove an item from the current order" << std::endl
        << "5] View current order" << std::endl
        << "6] Cancel current order" << std::endl
        << "7] Checkout current order" << std::endl;
        if (login_type == 3)
        {
            std::cout << std::endl << "[Admin Options]" << std::endl
            << "8] View all orders" << std::endl
            << "9] View all employees" << std::endl
            << "10] Remove an employee" << std::endl
            << "11] Add an employee" << std::endl
            << "12] Update an employee's information" << std::endl
            << "13] Update the details of an item" << std::endl
            << "14] Add a Customer" << std::endl
            << "15] Remove a Customer" << std::endl
            << "16] Update a Customer's information" << std::endl;
        }
        std::cout << std::endl << "0] Exit the program"
        << std::endl << generate_border() << std::endl;

        input = get_int("> ", "input", true);

        if (input > 7 && login_type != 3)
        {
            invalid_msg();
            continue;
        }

        switch (input)
        {
            case 0: // Exit loop (& program)
            {
                loop_active = false;
                break;
            }
            case 1: // View all items
            {
                action_success = view_available_items();
                sleep(2); // Let the user view the info
                break;
            }
            case 2: // Find a specific item
            {
                int product_id = get_int("Enter the item ID: ");

                action_success = find_an_item(product_id);
                sleep(2); // Let the user view the info
                break;
            }
            case 3: // Add item to current order
            {
                int order_id = get_int("Enter the order ID: ");
                int customer_id;

                while (true) // Check the validity of the customer ID
                {
                    std::cout << "Enter the customer's ID: ";
                    std::string customer_id_str = get_input(true);

                    std::pair<bool, std::string> check_return = check_id(false, customer_id_str);
                    if (!(check_return.second).empty())
                    {
                        customer_id = std::stoi(customer_id_str);
                        break;
                    }
                    else
                    {
                        invalid_msg("ID");
                        continue;
                    }
                }

                int product_id = get_int("Enter the item ID: ");
                int item_amount = get_int("Enter the amount to add: ");

                std::cout << "Please enter the order type: ";
                std::string order_type = get_input(true);

                action_success = add_item_to_order(product_id, item_amount, 
                    order_id, order_type, customer_id);
                break;
            }
            case 4: // Remove item from current order
            {
                int order_id = get_int("Enter the order ID: ");
                int product_id = get_int("Enter the item ID: ");

                action_success = remove_item_from_order(product_id, order_id);
                break;
            }
            case 5: // View current order
            {
                int order_id = get_int("Enter the order ID: ");

                action_success = view_order(order_id);
                sleep(2); // Let the user view the info
                break;
            }
            case 6: // Cancel current order
            {
                int order_id = get_int("Enter the order ID: ");
                int customer_id;

                while (true) // Check the validity of the customer ID
                {
                    std::cout << "Enter the customer's ID: ";
                    std::string customer_id_str = get_input(true);

                    std::pair<bool, std::string> check_return = check_id(false, customer_id_str);
                    if (!(check_return.second).empty())
                    {
                        customer_id = std::stoi(customer_id_str);
                        break;
                    }
                    else
                    {
                        invalid_msg("ID");
                        continue;
                    }
                }

                action_success = cancel_order(order_id, customer_id);
                break;
            }
            case 7: // Checkout current order
            {
                int order_id = get_int("Enter the order ID: ");

                action_success = checkout_order(order_id);
                break;
            }
            case 8: // View all orders
            {
                action_success = view_all_orders();
                sleep(2); // Let the user view the info
                break;
            }
            case 9: // View all employees' info
            {
                action_success = view_all_employees();
                sleep(2); // Let the user view the info
                break;
            }
            case 10: // Remove an employee
            {
                int employee_id;

                while (true) // Check the validity of the employee ID
                {
                    std::cout << "Enter the employee's ID: ";
                    std::string employee_id_str = get_input(true);

                    std::pair<bool, std::string> check_return = check_id(true, employee_id_str);
                    if (!(check_return.second).empty())
                    {
                        employee_id = std::stoi(employee_id_str);
                        break;
                    }
                    else
                    {
                        invalid_msg("ID");
                        continue;
                    }
                }

                action_success = remove_employee(employee_id);
                break;
            }
            case 11: // Add a new employee
            {
                fall_trigger = true; // Fall through to next case (behavior is shared)
            }
            case 12: // Update an employee's information
            {
                int employee_id;
                std::string name;
                std::string address;
                int hours;
                int wage;
                bool is_manager;

                if (!fall_trigger) // If the user is trying to update info
                {
                    while (true)
                    {
                        std::cout << "Enter the employee's ID: ";
                        std::string employee_id_str = get_input(true);

                        std::pair<bool, std::string> check_return = check_id(true, employee_id_str);
                        if (!(check_return.second).empty())
                        {
                            employee_id = std::stoi(employee_id_str);
                            break;
                        }
                        else
                        {
                            invalid_msg("ID");
                            continue;
                        }
                    }
                }
                else // If the user is trying to add a new employee
                {
                    std::cout << "Enter the employee's new ID: ";
                    std::string employee_id_str = get_input(true);

                    std::pair<bool, std::string> check_return = check_id(true, employee_id_str);
                    if ((check_return.second).empty())
                    {
                        try
                        {
                            employee_id = std::stoi(employee_id_str);
                        }
                        catch(const std::exception& e)
                        {
                            invalid_msg("input, the ID must be an integer value");
                            continue;
                        }
                        fall_trigger = false; // Reset fall_trigger to false
                        break;
                    }
                    else
                    {
                        invalid_msg("input, this ID has already been taken");
                        continue;
                    }
                }

                std::cout << "Enter the employee's new name: ";
                name = get_input(true);
                
                while (true)
                {
                    std::cout << "Enter the employee's new address in the format "
                    "[street_num street_name apt_num(optional) city state zipcode]: ";
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

                hours = get_int("Enter the employee's new hours: ");
                wage = get_int("Enter the employee's new wage: ");
                
                while (true)
                {
                    std::cout << "Will the employee be a manager? (Y/N): ";
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

                action_success = update_employee_info(employee_id, name, address, 
                    hours, wage, is_manager);
                break;
            }
            case 13: // Update the details of an item
            {
                std::cout << "Enter the item's type: ";
                std::string item_type = get_input(true);

                int cost = get_int("Enter the new cost of the item: ");
                int stock = get_int("Enter the new amount of stock: ");
                
                std::cout << "Enter the name of the item: ";
                std::string item_name = get_input(true);

                action_success = update_item_info(item_type, cost, stock, item_name);
                break;
            }
            case 14: // Add a Customer
            {
                //remove_customer();
                break;
            }
            case 15: // Remove a Customer
            {
                //add_customer();
                break;
            }
            case 16: // Update Customer Info
            {
                //update_customer_info();
            }
            default: // Invalid input
            {
                invalid_msg();
                continue; // Skip to the next loop iteration
            }
        }
        
        if (loop_active) // If the loop continues, output a return message
        {
            std::cout << generate_border() << std::endl;
            if (action_success)
            {
                std::cout << "The action was successful. ";
            }
            else
            {
                std::cout << "The action failed. ";
            }
            std::cout << "Now returning to main menu."
            << std::endl << generate_border() << std::endl;
            sleep(2);
        }
        else // If the loop will end, output an exit message
        {
            std::cout << generate_border() << std::endl
            << "Now exiting the program." << std::endl 
            << generate_border() << std::endl;
        }
    }
}

#endif