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
bool add_item_to_order(std::string item_id, std::string item_amount, std::string order_id, std::string order_type, std::string customer_id)
{
    std::string query1 = "SELECT order_id FROM cust_order WHERE order_id = " + order_id;
    std::string query2 = "INSERT INTO cust_order VALUES (" + order_id + ", " + order_type + ", " + customer_id + ", Waiting to be Processed);";
    std::string query3 = "SELECT order_id FROM prod_order WHERE order_id = " + order_id +" AND product_id = " + item_id;
    std::string query4 = "INSERT INTO prod_order VALUES (" + item_id + ", " + order_id + ", " + item_amount +");";
    std::string query5 = "UPDATE prod_order set quantity_ordered = quantity_ordered + " + item_amount + " WHERE order_id = " + order_id +" AND product_id = " + item_id;
    try
    {
        //checks if the order already exists
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

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
bool remove_item_from_order(std::string item_id, std::string order_id)
{
    std::string query1 = "DELETE FROM prod_order WHERE product_id = " + item_id + "order_id = "+ order_id;
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

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
bool view_order(std::string order_id)
{
    std::string query1 = "SELECT product_id, quantity_ordered FROM prod_order WHERE order_id = " + order_id;

    try
    {
        std::cout << "Order " << order_id << "Consists of " << std::endl;
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

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
bool cancel_order(std::string order_id, std::string customer_id)
{
    std::string query1 = "DELETE FROM prod_order WHERE order_id = " + order_id +" AND customer_id = " + customer_id;
    std::string query2 = "DELETE FROM cust_order WHERE order_id = " + order_id +" AND customer_id = " + customer_id;
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

/// @brief TODO: Add overview text for this function here
/// @param id TODO: Add param description here
/// @return TODO: Add return description here
bool checkout_order(std::string order_id)
{
    std::string query1 = "SELECT sum(price * quantity_ordered) FROM product NATURAL JOIN (SELECT product_id, quantity_orderd FROM prod_order WHERE order_id = "+order_id+")";
    std::string query2 = "UPDATE cust_order SET status = Completed WHERE order_id = " + order_id;
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