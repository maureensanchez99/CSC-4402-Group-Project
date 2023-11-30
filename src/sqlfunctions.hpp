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
bool view_availabe_items()
{
    try
    {
        std::cout << "All Items & Prices:" << std::endl
        << "| Item ID   | Item Price     | Item Name      |" << std::endl //|10 char|15 char|//
        << "-----------------------------------------------" << std::endl;
        SQLite::Database db(get_db_filepath());
        SQLite::Statement query1(db, "SELECT product_id, price, name FROM product NATURAL JOIN plant WHERE product.product_id = plant.product_id");
        while(query1.executeStep())
        {
           std::string id = query1.getColumn(0);
           std::string price = query1.getColumn(1);
           std::string name = query1.getColumn(2);
           std::string output = "| "+id;
           while (output.size() < 12)
           {
            output +=" ";
           }
           output += "| "+price;
           while (output.size() < 29)
           {
            output +=" ";
           }
           output += "| "+name;
           while (output.size() < 46)
           {
            output +=" ";
           }
           output +="|";
           std::cout << output << std::endl;
        }
        SQLite::Statement query2(db, "SELECT product_id, price, type FROM product NATURAL JOIN tool WHERE product.product_id = tool.product_id");
        while(query2.executeStep())
        {
           std::string id = query2.getColumn(0);
           std::string price = query2.getColumn(1);
           std::string name = query2.getColumn(2);
           std::string output = "| "+id;
           while (output.size() < 12)
           {
            output +=" ";
           }
           output += "| "+price;
           while (output.size() < 29)
           {
            output +=" ";
           }
           output += "| "+name;
           while (output.size() < 46)
           {
            output +=" ";
           }
           output +="|";
           std::cout << output << std::endl;
        }
        SQLite::Statement query3(db, "SELECT product_id, price, name FROM product NATURAL JOIN seed WHERE product.product_id = seed.product_id");
        while(query3.executeStep())
        {
           std::string id = query3.getColumn(0);
           std::string price = query3.getColumn(1);
           std::string name = query3.getColumn(2);
           std::string output = "| "+id;
           while (output.size() < 12)
           {
            output +=" ";
           }
           output += "| "+price;
           while (output.size() < 29)
           {
            output +=" ";
           }
           output += "| "+name;
           while (output.size() < 46)
           {
            output +=" ";
           }
           output +="|";
           std::cout << output << std::endl;
        }
        return true;
    }
    catch (const std::exception& e) {std::cout << "SQL failure: " << e.what() << std::endl;}
    return false;
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
bool find_an_item(int item_id)
{
    try
    {
        SQLite::Database db(get_db_filepath());
        if (item_id <= 3)
        {
            SQLite::Statement query(db, "Select * FROM plant NATURAL JOIN product WHERE plant.product_id = " + std::to_string(item_id));
            while (query.executeStep())
            {
                std::string col1 = query.getColumn(0);
                std::string col2 = query.getColumn(1);
                std::string col3 = query.getColumn(2);
                std::string col4 = query.getColumn(3);
                std::string col5 = query.getColumn(4);
                std::string col6 = query.getColumn(5);
                std::string col7 = query.getColumn(6);
                std::string col8 = query.getColumn(7);
                std::string output ="|"+col1;
                //11 19 31 44 55 67 75
                while (output.size() < 5)
                {
                    output += " ";
                }
                output +="|"+col2;
                while (output.size() < 19)
                {
                    output += " ";
                }
                output +="|"+col3;
                while (output.size() < 34)
                {
                    output += " ";
                }
                output +="|"+col4;
                while (output.size() < 44)
                {
                    output += " ";
                }
                output +="|"+col5;
                while (output.size() < 59)
                {
                    output += " ";
                }
                output +="|"+col6;
                while (output.size() < 74)
                {
                    output += " ";
                }
                output +="|"+col7;
                while (output.size() < 89)
                {
                    output += " ";
                }
                output +="|"+col8;
                while (output.size() < 99)
                {
                    output += " ";
                }
                output += "|";
                std::cout << output << std::endl;
            }
        }
        else if (item_id <= 6)
        {
            std::cout << "|ID  |Type         |Brand         | Price   |" << std::endl;
            SQLite::Statement query(db, "Select * FROM tool NATURAL JOIN product WHERE tool.product_id = " + std::to_string(item_id));
            while (query.executeStep())
            {
                std::string col1 = query.getColumn(0);
                std::string col2 = query.getColumn(1);
                std::string col3 = query.getColumn(2);
                std::string col4 = query.getColumn(3);
                std::string output ="|"+col1;
                while (output.size() < 5)
                {
                    output += " ";
                }
                output +="|"+col2;
                while (output.size() < 19)
                {
                    output += " ";
                }
                output +="|"+col3;
                while (output.size() < 34)
                {
                    output += " ";
                }
                output +="|"+col4;
                while (output.size() < 44)
                {
                    output += " ";
                }
                output += "|";
                std::cout << output << std::endl;
            }
        }
        else if (item_id <= 9)
        {
            std::cout << "|ID  |Name      |Type       |Season   |Zone|Sunlight      |Water        |Humidity           |Price |" << std::endl
                      << "----------------------------------------------------------------------------------------------------" << std::endl;
            SQLite::Statement query(db, "Select * FROM seed NATURAL JOIN product WHERE seed.product_id = " + std::to_string(item_id));
            while (query.executeStep())
            {
                std::string col1 = query.getColumn(0);
                std::string col2 = query.getColumn(1);
                std::string col3 = query.getColumn(2);
                std::string col4 = query.getColumn(3);
                std::string col5 = query.getColumn(4);
                std::string col6 = query.getColumn(5);
                std::string col7 = query.getColumn(6);
                std::string col8 = query.getColumn(7);
                std::string col9 = query.getColumn(8);
                std::string output ="|"+col1;
                //11 19 31 44 55 67 75
                while (output.size() < 5)
                {
                    output += " ";
                }
                output +="|"+col2;
                while (output.size() < 16)
                {
                    output += " ";
                }
                output +="|"+col3;
                while (output.size() < 28)
                {
                    output += " ";
                }
                output +="|"+col4;
                while (output.size() < 38)
                {
                    output += " ";
                }
                output +="|"+col5;
                while (output.size() < 43)
                {
                    output += " ";
                }
                output +="|"+col6;
                while (output.size() < 58)
                {
                    output += " ";
                }
                output +="|"+col7;
                while (output.size() < 72)
                {
                    output += " ";
                }
                output +="|"+col8;
                while (output.size() < 92)
                {
                    output += " ";
                }
                output +="|"+col9;
                while (output.size() < 99)
                {
                    output += " ";
                }
                output += "|";
                std::cout << output << std::endl;
            }
        }
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string add_item_to_current_order(int item_id)
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string remove_item_from_current_order(int item_id)
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
std::string update_employee_info(int employee_id, std::string name, std::string address, int hours_mod, int wage, bool is_manager)
{
    return std::string();
}

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
std::string add_employee (int employee_id, std::string name, std::string address, int hours_mod, int wage, bool is_manager)
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