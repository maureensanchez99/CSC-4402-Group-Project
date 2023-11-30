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
        std::cout << "Are you logging in as an employee? (Y/N)" << std::endl;
        input = get_input();
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
            std::cout << "Invalid input. Please try again." << std::endl
            << generate_border() << std::endl;
        }
    }

    sleep(1); // Used to make the text more readable
    std::cout << "To login, enter your ID number." << std::endl
    << "To quit, type exit." << std::endl << generate_border() << std::endl;

    while(true) // Loop until the user inputs a valid login or quits the program
    {
        std::cout << "Enter your login ID:" << std::endl;
        input = get_input();
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
                std::cout << "Invalid login. Please try again." << std::endl
                << generate_border() << std::endl;
                continue;
            }

            lookup_return = check_id(employee_login, return_val.second); // Lookup the user ID

            if (lookup_return.second.empty()) // Restart loop if ID is invalid
            {
                std::cout << "Invalid login. Please try again." << std::endl
                << generate_border() << std::endl;
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
            case 0: // exit
            {
                loop_active = false; // Exit loop (& program)
                break;
            }

            case 1: // view all items
            {
                view_availabe_items();
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
                    std::cout << "ERROR: your input must be a number" << std::endl;
                    break;
                }
                find_an_item(product_id);
                std::cout << generate_border() << std::endl;
                break;
            }

            case 3: // add item to current order
            {

                std::cout << "Please enter the item id: ";
                std::string product_id = get_input();

                std::cout << "Please enter the item amount: ";
                std::string item_amount = get_input();

                std::cout << "Please enter the order id: ";
                std::string order_id = get_input();

                std::cout << "Please enter the order type: ";
                std::string order_type = get_input();

                std::cout << "Please enter the customer id: ";
                std::string customer_id = get_input();

                add_item_to_order(product_id, item_amount, order_id, order_type, customer_id);
                std::cout << generate_border() << std::endl;
                break;
            }

            case 4: // remove item from current order
            {
                std::cout << "Please enter the order id: ";
                std::string order_id = get_input();

                std::cout << "Please enter the product id: ";
                std::string product_id = get_input();

                remove_item_from_order(product_id, order_id);
                std::cout << generate_border() << std::endl;
                break;
            }

            case 5: // view current order
            {
                std::cout << "Please enter the order id: ";
                std::string order_id = get_input();
                view_order(order_id);
                std::cout << generate_border() << std::endl;
                break;
            }

            case 6: // cancel current order
            {
                std::cout << "Please enter the order id: ";
                std::string order_id = get_input();

                std::cout << "Please enter the customer id: ";
                std::string customer_id = get_input();
                cancel_order(order_id, customer_id);
                std::cout << generate_border() << std::endl;
                break;
            }

            case 7: // checkout current order
            {
                std::cout << "Please enter the order id: ";
                std::string order_id = get_input();

                checkout_order(order_id);
                std::cout << generate_border() << std::endl;
                break;
            }


            //ADMIN CASES//


            case 8: // view employee information
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

            case 9: // view all orders
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

            case 10: // update an employee's information
            {
                if (login_type == 3)
                {
                    int employee_id;
                    std::string name;
                    std::string address;
                    int hours;
                    int wage;
                    bool is_manager;

                    std::cout << "Please enter the employee id: ";
                    employee_id = convert_string_to_number(get_input(true));
                    if (employee_id = -1) {std::cout << "Invalid input. Please try again" << std::endl; break;}

                    std::cout << "Please enter the following information (leave blank if no change should be made)"
                    << std::endl << "Employee name: ";
                    name = get_input(true);

                    std::cout << "Employee Address in the format [street_num street_name (optional ->) apt_num city state zipcode]: ";
                    address = get_input(true);
                    //check_address(address);

                    std::cout << "Please enter the employee hours: ";
                    hours = convert_string_to_number(get_input(true));
                    if (hours = -1) {std::cout << "Invalid input. Please try again" << std::endl; break;}

                    std::cout << "Please enter the employee wage: ";
                    wage = convert_string_to_number(get_input(true));
                    if (wage = -1) {std::cout << "Invalid input. Please try again" << std::endl; break;}

                    std::cout << "Please enter if the employee is a manager (T/F): ";
                    std::string is_manager_string = get_input();
                    if(is_manager_string == "T" || is_manager_string == "t") {is_manager = true;}
                    else if(is_manager_string != "F" || is_manager_string != "f") {is_manager = false;}
                    else {std::cout << "Invalid input. Please try again" << std::endl; break;}

                    update_employee_info(employee_id, name, address, hours, wage, is_manager);
                }
                else
                {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                std::cout << generate_border() << std::endl;
                break;
            }

            case 11: // add a new employee
            {
                if (login_type == 3)
                {
                 
                }
                else
                {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                std::cout << generate_border() << std::endl;
                break;
            }

            case 12: // remove an employee
            {
                if (login_type == 3)
                {

                }
                else
                {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                std::cout << generate_border() << std::endl;
                break;
            }

            case 13: // update an item's information
            {
                if (login_type == 3)
                {
                    
                }
                else
                {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }
                std::cout << generate_border() << std::endl;
                break;
            }

            case 14: // update an order's information
            {
                if (login_type == 3)
                {
                 
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