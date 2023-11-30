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
/*
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
*/
}

#endif