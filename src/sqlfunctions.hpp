#ifndef SQLFUNCTIONS_HPP
#define SQLFUNCTIONS_HPP

/// @brief Determines if a user's ID is valid or not
/// \param employee_login A boolean value representing 
/// if the user is logging in as an employee
/// @param id A string containing the user's ID number
/// @return An std::pair of the user's status as a manager and their first name
std::pair<bool, std::string> check_id(bool employee_login, std::string id)
{
    std::pair<bool, std::string> return_val = {false, std::string()};

    try
    {
        SQLite::Database db(get_db_filepath());
        if (employee_login)
        {
            return_val.second = (std::string) db.execAndGet("SELECT name_first FROM employee WHERE employee_id = " + id);
            std::string temp = db.execAndGet("SELECT manager FROM employee WHERE employee_id = " + id);
            if (std::stoi(temp) == 1)
            {
                return_val.first = true;
            }
        }
        else
        {
            return_val.second = (std::string) db.execAndGet("SELECT name_first FROM customer WHERE customer_id = " + id);
        }
    }
    catch (const std::exception& e) {} // If query fails, the ID is invalid

    return return_val;
}

// Regular menu functions

/// @brief 
/// @return A bool representing the success of the function
bool view_available_items()
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
            std::string output = "| " + id;
            while (output.size() < 12)
            {
                output += " ";
            }
            output += "| " + price;
            while (output.size() < 29)
            {
                output +=" ";
            }
            output += "| "+ name;
            while (output.size() < 46)
            {
                output +=" ";
            }
            output += "|";
            std::cout << output << std::endl;
        }
        SQLite::Statement query2(db, "SELECT product_id, price, type FROM product NATURAL JOIN tool WHERE product.product_id = tool.product_id");
        while(query2.executeStep())
        {
            std::string id = query2.getColumn(0);
            std::string price = query2.getColumn(1);
            std::string name = query2.getColumn(2);
            std::string output = "| " + id;
            while (output.size() < 12)
            {
                output += " ";
            }
            output += "| " + price;
            while (output.size() < 29)
            {
                output +=" ";
            }
            output += "| " + name;
            while (output.size() < 46)
            {
                output += " ";
            }
            output += "|";
            std::cout << output << std::endl;
        }
        SQLite::Statement query3(db, "SELECT product_id, price, name FROM product NATURAL JOIN seed WHERE product.product_id = seed.product_id");
        while(query3.executeStep())
        {
            std::string id = query3.getColumn(0);
            std::string price = query3.getColumn(1);
            std::string name = query3.getColumn(2);
            std::string output = "| " + id;
            while (output.size() < 12)
            {
                output +=" ";
            }
            output += "| " + price;
            while (output.size() < 29)
            {
                output += " ";
            }
            output += "| " + name;
            while (output.size() < 46)
            {
                output += " ";
            }
            output += "|";
            std::cout << output << std::endl;
        }
        return true;
    }
    catch (const std::exception& e) 
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;
}

/// @brief 
/// @param item_id The ID of the item as an integer
/// @return A bool representing the success of the function
bool find_an_item(int item_id)
{
    try
    {
        SQLite::Database db(get_db_filepath());
        if (item_id <= 3)
        {
            SQLite::Statement query(db, "SELECT * FROM plant NATURAL JOIN product WHERE plant.product_id = " + std::to_string(item_id));
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
                
                std::vector<int> col_sizes = {5, 15, 15, 10, 20, 10, 20, 7};
                std::vector<std::string> row_vec = {col1, col2, col3, col4, col5, col6, col7, col8};
                std::string output = generate_table_row(row_vec, col_sizes);
                std::cout << output << std::endl;
            }
        }
        else if (item_id <= 6)
        {
            std::cout << "|ID  |Type         |Brand         | Price   |" << std::endl;
            SQLite::Statement query(db, "SELECT * FROM tool NATURAL JOIN product WHERE tool.product_id = " + std::to_string(item_id));
            while (query.executeStep())
            {
                std::string col1 = query.getColumn(0);
                std::string col2 = query.getColumn(1);
                std::string col3 = query.getColumn(2);
                std::string col4 = query.getColumn(3);
                std::string output = "|" + col1;
                while (output.size() < 5)
                {
                    output += " ";
                }
                output += "|" + col2;
                while (output.size() < 19)
                {
                    output += " ";
                }
                output += "|" + col3;
                while (output.size() < 34)
                {
                    output += " ";
                }
                output += "|"+ col4;
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
            SQLite::Statement query(db, "SELECT * FROM seed NATURAL JOIN product WHERE seed.product_id = " + std::to_string(item_id));
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
                std::string output = "|"+ col1;
                while (output.size() < 5)
                {
                    output += " ";
                }
                output += "|"+ col2;
                while (output.size() < 16)
                {
                    output += " ";
                }
                output += "|" + col3;
                while (output.size() < 28)
                {
                    output += " ";
                }
                output += "|" + col4;
                while (output.size() < 38)
                {
                    output += " ";
                }
                output += "|" + col5;
                while (output.size() < 43)
                {
                    output += " ";
                }
                output += "|" + col6;
                while (output.size() < 58)
                {
                    output += " ";
                }
                output += "|" + col7;
                while (output.size() < 72)
                {
                    output += " ";
                }
                output += "|" + col8;
                while (output.size() < 92)
                {
                    output += " ";
                }
                output += "|" + col9;
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

/// @brief 
/// @param item_id The ID of the item as an integer
/// @param item_amount The amount of the item as an integer
/// @param order_id The ID of the order as an integer
/// @param order_type The type of the order as a string
/// @param customer_id The ID of the customer as an integer
/// @return A bool representing the success of the function
bool add_item_to_order(int item_id, int item_amount, int order_id, std::string order_type, int customer_id)
{
    std::string query1 = "SELECT order_id FROM cust_order WHERE order_id = " 
        + std::to_string(order_id);
    std::string query2 = "INSERT INTO cust_order VALUES (" + std::to_string(order_id) 
        + ", " + order_type + ", " + std::to_string(customer_id) + ", Waiting to be Processed);";
    std::string query3 = "SELECT order_id FROM prod_order WHERE order_id = " 
        + std::to_string(order_id) +" AND product_id = " + std::to_string(item_id);
    std::string query4 = "INSERT INTO prod_order VALUES (" + std::to_string(item_id) 
        + ", " + std::to_string(order_id) + ", " + std::to_string(item_amount) +");";
    std::string query5 = "UPDATE prod_order set quantity_ordered = quantity_ordered + " 
        + std::to_string(item_amount) + " WHERE order_id = " + std::to_string(order_id) +" AND product_id = " + std::to_string(item_id);
    try
    {   // Checks if the order already exists
        SQLite::Database db(get_db_filepath());
        SQLite::Statement check_exists(db, query1);
        bool order_exists = false;
        while (check_exists.executeStep())
        {
            std::string temp_val = check_exists.getColumn(0);
            if (temp_val.empty())
            {
                SQLite::Statement cust_order_insertion(db, query2);
            }
        }

        bool item_order_exists;
        SQLite::Statement check_item_order_exists(db, query3);
        while (check_item_order_exists.executeStep())
        {
            std::string temp_value = check_item_order_exists.getColumn(0);
            if (temp_value.empty())
            {
                SQLite::Statement insertion(db, query4);
            }
            else
            {
                SQLite::Statement order_update(db, query5);
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

/// @brief 
/// @param item_id The ID of the item as an integer
/// @param order_id The ID of the order as an integer
/// @return A bool representing the success of the function
bool remove_item_from_order(int item_id, int order_id)
{
    std::string query1 = "DELETE FROM prod_order WHERE product_id = " 
        + std::to_string(item_id) + "order_id = "+ std::to_string(order_id);
    try
    {
        SQLite::Database db(get_db_filepath());
        SQLite::Statement delete_item(db, query1);
        delete_item.exec();
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;
}

/// @brief 
/// @param order_id The ID of the order as an integer
/// @return A bool representing the success of the function
bool view_order(int order_id)
{
    std::string query1 = "SELECT product_id, quantity_ordered FROM prod_order WHERE order_id = " 
        + std::to_string(order_id);
    try
    {
        std::cout << "Order " << std::to_string(order_id) << "Consists of " << std::endl;
        SQLite::Database db(get_db_filepath());
        SQLite::Statement view_order(db, query1);
        while(view_order.executeStep())
        {
            std::string product = view_order.getColumn(0);
            std::string quantity = view_order.getColumn(1);
            std::string output = quantity + " " + product;
            std::cout << output << std::endl;
        }
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;
}

/// @brief 
/// @param order_id The ID of the order as an integer
/// @param customer_id The ID of the customer as an integer
/// @return A bool representing the success of the function
bool cancel_order(int order_id, int customer_id)
{
    std::string query1 = "DELETE FROM prod_order WHERE order_id = " 
        + std::to_string(order_id) +" AND customer_id = " + std::to_string(customer_id);
    std::string query2 = "DELETE FROM cust_order WHERE order_id = " 
        + std::to_string(order_id) +" AND customer_id = " + std::to_string(customer_id);
    try
    {
        SQLite::Database db(get_db_filepath());
        SQLite::Statement delete1(db, query1);
        SQLite::Statement delete2(db, query2);

        delete1.exec();
        delete2.exec();
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;   
}

/// @brief 
/// @param order_id The ID of the order as an integer
/// @return A bool representing the success of the function
bool checkout_order(int order_id)
{
    std::string query1 = "SELECT sum(price * quantity_ordered) FROM product "
        "NATURAL JOIN (SELECT product_id, quantity_orderd FROM prod_order WHERE order_id = " 
        + std::to_string(order_id) + ")";
    std::string query2 = "UPDATE cust_order SET status = Completed WHERE order_id = " 
        + std::to_string(order_id);
    try
    {
        SQLite::Database db(get_db_filepath());
        SQLite::Statement get_sum(db, query1);
        std::string sum = std::to_string(get_sum.exec());

        SQLite::Statement checkout(db, query2);
        checkout.exec();

        std::cout << "Checkout Complete: Your Order was $"+sum;
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;
}

// Admin functions

/// @brief 
/// @return A bool representing the success of the function
bool view_all_orders()
{
    try
    {
        SQLite::Database db(get_db_filepath());
        SQLite::Statement query(db, "SELECT order_id, order_type, customer_id, "
        "status, product_id, quantity_ordered FROM prod_order NATURAL JOIN "
        "cust_order ORDER BY order_id, product_id");
        std::vector<std::string> row_result;
        std::vector<int> column_widths = {12, 14, 15, 27, 14, 19};
        
        row_result = {"order_id", "order_type", "customer_id", 
            "status", "product_id", "quantity_ordered"};
        std::cout << generate_table_row(row_result, column_widths) << std::endl;
        std::cout << generate_border(97, '-') << std::endl;

        while (query.executeStep())
        {
            row_result.clear();
            for (int i = 0; i < 6; i++) // get all 6 columns
            {
                row_result.insert(row_result.end(), query.getColumn(i));
            }
            std::cout << generate_table_row(row_result, column_widths) << std::endl;
        }
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;
}

/// @brief 
/// @return A bool representing the success of the function
bool view_all_employees()
{
    try
    {
        SQLite::Database db(get_db_filepath());
        SQLite::Statement query(db, "SELECT * FROM employee");
        std::vector<std::string> row_result;
        std::vector<int> column_widths = {15, 14, 14, 17, 23, 14, 17, 15, 9, 9, 8, 11, 11};
        
        row_result = {"employee_id", "name_first", "name_last", "street_number", "street_name", 
            "apt_number", "city", "state", "zip", "hours", "wage", "manager", "store_id"};
        std::cout << generate_table_row(row_result, column_widths) << std::endl;
        std::cout << generate_border(166, '-') << std::endl;

        while (query.executeStep())
        {
            row_result.clear();
            for (int i = 0; i < 13; i++) // get all 13 columns
            {
                row_result.insert(row_result.end(), query.getColumn(i));
            }
            std::cout << generate_table_row(row_result, column_widths) << std::endl;
        }
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;
}

/// @brief 
/// @param employee_id The ID of the employee as an integer
/// @return A bool representing the success of the function
bool remove_employee(int employee_id)
{
    // implement here

    return false;
}

/// @brief Updates an employee's info or adds a new employee if they don't exist
/// @param employee_id The ID of the employee as an integer
/// @param name The name of the employee as a string
/// @param address The address of the employee as a string
/// @param hours The employee's hours as an integer
/// @param wage The wage of the employee as an integer
/// @param is_manager The status of the employee as a bool
/// @return A bool representing the success of the function
bool update_employee_info(int employee_id, std::string name, std::string address, 
    int hours, int wage, bool is_manager)
{
    // implement here

    return false;
}

/// @brief 
/// @param product_type The type of the item as a string
/// @param cost The cost of the item as an integer
/// @param stock_amount The stock of the item as an integer
/// @param product_name The name of the item as a string
/// @return A bool representing the success of the function
bool update_item_info(std::string product_type, int cost, 
    int stock_amount, std::string product_name)
{
    // implement here

    return false;
}

/// @brief 
/// @param order_id The ID of the order as an integer
/// @param customer_id The ID of the customer as an integer
/// @param email The email of the customer as a string
/// @param product_name The name of the item as a string
/// @param quantity The quantity of the order as an integer
/// @return A bool representing the success of the function
bool update_order_info(int order_id, int customer_id, 
    std::string email, std::string product_name, int quantity)
{
    // implement here

    return false;
}

#endif