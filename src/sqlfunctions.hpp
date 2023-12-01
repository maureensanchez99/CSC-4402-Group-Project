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
    catch (const std::exception& e) {} // If query fails, the ID is invalid, so ignore the catch

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
        << "|ID | Price | Item Name         |" << std::endl //|10 char|15 char|//
        << "---------------------------------" << std::endl;
        SQLite::Database db(get_db_filepath());
        SQLite::Statement query1(db, "SELECT product_id, price, name FROM product NATURAL JOIN plant WHERE product.product_id = plant.product_id");
        while(query1.executeStep())
        {
            std::string id = query1.getColumn(0);
            std::string price = query1.getColumn(1);
            std::string name = query1.getColumn(2);
            
            std::vector<int> col_sizes = {5, 9, 20};
            std::vector<std::string> row_vec = {id, price, name};
            std::string output = generate_table_row(row_vec, col_sizes);
            std::cout << output << std::endl;
        }
        SQLite::Statement query2(db, "SELECT product_id, price, type FROM product NATURAL JOIN tool WHERE product.product_id = tool.product_id");
        while(query2.executeStep())
        {
            std::string id = query2.getColumn(0);
            std::string price = query2.getColumn(1);
            std::string name = query2.getColumn(2);

            std::vector<int> col_sizes = {5, 9, 20};
            std::vector<std::string> row_vec = {id, price, name};
            std::string output = generate_table_row(row_vec, col_sizes);
            std::cout << output << std::endl;
        }
        SQLite::Statement query3(db, "SELECT product_id, price, name FROM product NATURAL JOIN seed WHERE product.product_id = seed.product_id");
        while(query3.executeStep())
        {
            std::string id = query3.getColumn(0);
            std::string price = query3.getColumn(1);
            std::string name = query3.getColumn(2);

            std::vector<int> col_sizes = {5, 9, 20};
            std::vector<std::string> row_vec = {id, price, name};
            std::string output = generate_table_row(row_vec, col_sizes);
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
        {   std::cout << "|ID | Name        | Type        | Size   | Sunlight         | Water  | Humidity         | Price |" << std::endl
            << "-------------------------------------------------------------------------------------------------" << std::endl;
            //| 1 | Pothos      | House Plant | Medium | Partial Shade    | Daily  | Low Humidity     | 10.99 |
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
            std::cout << "|ID | Type        | Brand         | Price |" << std::endl
            << "-------------------------------------------" << std::endl;
            SQLite::Statement query(db, "SELECT * FROM tool NATURAL JOIN product WHERE tool.product_id = " + std::to_string(item_id));
            while (query.executeStep())
            {
                std::string col1 = query.getColumn(0);
                std::string col2 = query.getColumn(1);
                std::string col3 = query.getColumn(2);
                std::string col4 = query.getColumn(3);

                std::vector<int> col_sizes = {5, 15, 17, 8};
                std::vector<std::string> row_vec = {col1, col2, col3, col4};
                std::string output = generate_table_row(row_vec, col_sizes);
                std::cout << output << std::endl;
            }
        }
        else if (item_id <= 9)
        {
            std::cout << "|ID | Name        | Type        | Season   | Zone | Sunlight         | Water            | Humidity         | Price |" << std::endl
            <<"--------------------------------------------------------------------------------------------------------------------" << std::endl;
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

                std::vector<int> col_sizes = {5, 15, 15, 12, 8, 20, 20, 20, 7};
                std::vector<std::string> row_vec = {col1, col2, col3, col4, col5, col6, col7, col8, col9};
                std::string output = generate_table_row(row_vec, col_sizes);
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
        std::cout << "Order " << std::to_string(order_id) << " Consists of " << std::endl
        << "|ID | Quantity |" << std::endl
        << "----------------" << std::endl;
        SQLite::Database db(get_db_filepath());
        SQLite::Statement view_order(db, query1);
        while(view_order.executeStep())
        {
            std::string product = view_order.getColumn(0);
            std::string quantity = view_order.getColumn(1);
            
            std::vector<int> col_sizes = {5, 11};
            std::vector<std::string> row_vec = {product, quantity};
            std::string output = generate_table_row(row_vec, col_sizes);
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
        "NATURAL JOIN (SELECT product_id, quantity_ordered FROM prod_order WHERE order_id = " 
        + std::to_string(order_id) + ")";
    std::string query2 = "UPDATE cust_order SET status = \"Completed\" WHERE order_id = " 
        + std::to_string(order_id);
    try
    {
        SQLite::Database db(get_db_filepath(), SQLite::OPEN_READWRITE);
        SQLite::Statement get_sum(db, query1);
        std::string sum1;
        while(get_sum.executeStep())
        {
            std::string sum2 = get_sum.getColumn(0);
            sum1 = sum2;
        }

        SQLite::Statement checkout(db, query2);
        checkout.exec();

        std::cout << "Checkout Complete!" << std::endl << "Your Order was $" + sum1 << std::endl;
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;
}

// Admin functions

/// @brief Returns a table of all orders stored in the database
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

/// @brief Returns a table of all employees stored in the database
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

/// @brief Attempt to remove an employee from the database
/// @param employee_id The ID of the employee as an integer
/// @return A bool representing the success of the function
bool remove_employee(int employee_id)
{
    try
    {
        SQLite::Database db(get_db_filepath(), SQLite::OPEN_READWRITE);
        db.exec("DELETE FROM employee WHERE employee_id = " + std::to_string(employee_id));
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;
}

/// @brief Updates an employee's info or adds a new employee if they don't exist
/// @param employee_id The ID of the employee as an integer
/// @param name The name of the employee as a pair of strings
/// @param address The address of the employee as a vector of strings
/// @param hours The employee's hours as an integer
/// @param wage The wage of the employee as an integer
/// @param store_id The ID of the employee's store as an integer
/// @param is_manager The status of the employee as a string
/// @param is_new Showing if the employee should be added or modified as a bool
/// @return A bool representing the success of the function
bool update_employee_info(int employee_id, std::pair<std::string, std::string> name, 
    std::vector<std::string> address, int hours, int wage, int store_id, 
    std::string is_manager, bool is_new)
{
    try // Running the query
    {
        SQLite::Database db(get_db_filepath(), SQLite::OPEN_READWRITE);
        if (is_new && address.size() == 6) // use INSERT query
        {
            db.exec("INSERT INTO employee VALUES ('" + std::to_string(employee_id) + "', '" 
                + name.first + "', '" + name.second + "', '" + address.at(0) + "', '" + address.at(1) + "', '" 
                + address.at(2) + "', '" + address.at(3) + "', '" + address.at(4) + "', '" + address.at(5) + "', '" 
                + std::to_string(hours) + "', '" + std::to_string(wage) + "', '" + is_manager + "', '" 
                + std::to_string(store_id) + "')");
        }
        else if (is_new) // use NULL for apt_num because it was optional
        {
            db.exec("INSERT INTO employee VALUES ('" + std::to_string(employee_id) + "', '" 
                + name.first + "', '" + name.second + "', '" + address.at(0) + "', '" + address.at(1) 
                + "', NULL, ', '" + address.at(2) + "', '" + address.at(3) + "', '" + address.at(4) + "', '" 
                + std::to_string(hours) + "', '" + std::to_string(wage) + "', '" + is_manager + "', '" 
                + std::to_string(store_id) + "')");
        }
        else if (address.size() == 6) // use UPDATE query
        {
            db.exec("UPDATE employee SET name_first = " + name.first + ", name_last = " + name.second 
                + ", street_number = " + address.at(0) + ", street_name = " + address.at(1) 
                + ", apt_number = " + address.at(2) + ", city = " + address.at(3) + ", state = " 
                + address.at(4) + ", zip = " + address.at(5) + ", hours = " + std::to_string(hours)
                + ", wage = " + std::to_string(wage) + ", manager = " + is_manager + ", store_id = " 
                + std::to_string(store_id) + " WHERE employee_id = " + std::to_string(employee_id));
        }
        else // use NULL for apt_num because it was optional
        {
            db.exec("UPDATE employee SET name_first = " + name.first + ", name_last = " + name.second 
                + ", street_number = " + address.at(0) + ", street_name = " + address.at(1) 
                + ", apt_number = NULL, city = " + address.at(2) + ", state = " + address.at(3) 
                + ", zip = " + address.at(4) + ", hours = " + std::to_string(hours) + ", wage = " 
                + std::to_string(wage) + ", manager = " + is_manager + ", store_id = " 
                + std::to_string(store_id) + " WHERE employee_id = " + std::to_string(employee_id));
        }
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;
}

/// @brief Attempt to remove a customer from the database
/// @param customer_id The ID of the customer as an integer
/// @return A bool representing the success of the function
bool remove_customer(int customer_id)
{
    try
    {
        SQLite::Database db(get_db_filepath(), SQLite::OPEN_READWRITE);
        db.exec("DELETE FROM customer WHERE customer_id = " + std::to_string(customer_id));
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;
}

/// @brief Updates a customer's info or adds a new customer if they don't exist
/// @param customer_id The ID of the customer as an integer
/// @param name The name of the customer as a pair of strings
/// @param address The address of the customer as a vector of strings
/// @param is_member The membership status of the customer as a string
/// @param is_new Showing if the customer should be added or modified as a bool
/// @return A bool representing the success of the function
bool update_customer_info(int customer_id, std::pair<std::string, std::string> name, 
    std::vector<std::string> address, std::string is_member, bool is_new)
{
    try // Running the query
    {
        SQLite::Database db(get_db_filepath(), SQLite::OPEN_READWRITE);
        if (is_new && address.size() == 6) // use INSERT query
        {
            db.exec("INSERT INTO customer VALUES ('" + std::to_string(customer_id) + "', '" 
                + name.first + "', '" + name.second + "', '" + address.at(0) + "', '"
                + address.at(1) + "', '" + address.at(2) + "', '" + address.at(3) + "', '" 
                + address.at(4) + "', '" + address.at(5) + "', '" + is_member + "')");
        }
        else if (is_new) // use NULL for apt_num because it was optional
        {
            db.exec("INSERT INTO customer VALUES ('" + std::to_string(customer_id) + "', '" 
                + name.first + "', '" + name.second + "', '" + address.at(0) + "', '" 
                + address.at(1) + "', NULL, ', '" + address.at(2) + "', '" 
                + address.at(3) + "', '" + address.at(4) + "', '" + is_member + "')");
        }
        else if (address.size() == 6) // use UPDATE query
        {
            db.exec("UPDATE customer SET name_first = " + name.first + ", name_last = " + name.second 
                + ", street_number = " + address.at(0) + ", street_name = " + address.at(1) 
                + ", apt_number = " + address.at(2) + ", city = " + address.at(3) + ", state = " 
                + address.at(4) + ", zip = " + address.at(5) + ", member = " 
                + is_member + " WHERE customer_id = " + std::to_string(customer_id));
        }
        else // use NULL for apt_num because it was optional
        {
            db.exec("UPDATE customer SET name_first = " + name.first + ", name_last = " + name.second 
                + ", street_number = " + address.at(0) + ", street_name = " + address.at(1) 
                + ", apt_number = NULL, city = " + address.at(2) + ", state = " 
                + address.at(3) + ", zip = " + address.at(4) + ", member = " 
                + is_member + " WHERE customer_id = " + std::to_string(customer_id));
        }
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "SQL failure: " << e.what() << std::endl;
    }
    return false;
}

/// @brief Updates the information of an item in the database
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

#endif