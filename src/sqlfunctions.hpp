#ifndef SQLFUNCTIONS_HPP
#define SQLFUNCTIONS_HPP

std::string get_db_filepath(); // Re-defining function from main.cpp to be used here

/// @brief Determines if a user's ID is valid or not
/// \param employee_login A boolean value representing 
/// if the user is logging in as an employee
/// @param id An integer containing the user's ID number
/// @return An std::pair of the user's status as a manager and their first name
std::pair<bool, std::string> check_id(bool employee_login, int id)
{
    std::pair<bool, std::string> return_val = {false, std::string()};

    try
    {
        SQLite::Database db(get_db_filepath());
        if (employee_login)
        {
            return_val.second = (std::string) db.execAndGet("SELECT name_first FROM employee WHERE employee_id = " + std::to_string(id));
            std::string temp = db.execAndGet("SELECT manager FROM employee WHERE employee_id = " + std::to_string(id));
            if (std::stoi(temp) == 1)
            {
                return_val.first = true;
            }
        }
        else
        {
            return_val.second = (std::string) db.execAndGet("SELECT name_first FROM customer WHERE customer_id = " + std::to_string(id));
        }
    }
    catch (const std::exception& e) {} // If query fails, the ID is invalid

    return return_val;
}

// Regular menu functions

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string view_availabe_items()
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string find_an_item(std::string item_name)
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string add_item_to_current_order(std::string item_name)
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string remove_item_from_current_order(std::string item_name)
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string view_current_order()
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string cancel_current_order()
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string checkout_current_order()
{
    return std::string();
}

// Admin functions

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string view_employee_info()
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string view_all_orders()
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string update_employee_info(int employee_id, int pay_mod, int hours_mod, std::string job_title)
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string add_employee (int employee_id, int pay, int hours, std::string job_title)
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string remove_employee(int employee_id)
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string update_item_info(std::string product_type, int cost, int stock_amount, std::string product_name)
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string update_order_info(int order_id, int customer_id, std::string email, std::string product_name, int quantity)
{
    return std::string();
}

#endif