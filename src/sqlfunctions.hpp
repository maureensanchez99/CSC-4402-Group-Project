#ifndef SQLFUNCTIONS_HPP
#define SQLFUNCTIONS_HPP

std::string get_db_filepath();

/// @brief TODO: Add overview text for this function here
/// @param employee_login TODO: Add param description here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string check_id(bool employee_login, std::string id)
{
    std::string return_val = std::string();

    try
    {
        SQLite::Database db(get_db_filepath());
        if (employee_login)
        {
            return_val = (std::string) db.execAndGet("SELECT name_first FROM employee WHERE employee_id = " + id);
        }
        else
        {
            return_val = (std::string) db.execAndGet("SELECT name_first FROM customer WHERE customer_id = " + id);
        }
    }
    catch (const std::exception& e) {} // If query fails, the ID is invalid

    return return_val;
}

//menu functions//


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


//admin functions//


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