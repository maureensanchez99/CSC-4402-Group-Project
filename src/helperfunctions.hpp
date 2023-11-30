#ifndef HELPERFUNCTIONS_HPP
#define HELPERFUNCTIONS_HPP

/// @brief Retrieves the full path to the `plant_store` database on the current user's system
/// @return A string containing the path to the `plant_store` database
std::string get_db_filepath()
{
    std::string current_file = std::source_location::current().file_name();
    return current_file.substr(0, current_file.length() - 
        std::string("src/helperfunctions.hpp").length()) + 
        "database/plant_store.db";
}

/// @brief Generates a border of a set length out of '='
/// \param length The length of the border to be 
/// generated; this value is set to 100 by default
/// @return A string containing the finished border
std::string generate_border(int length = 100)
{
    std::string border;
    for (int i = 0; i < length; ++i)
    {
        border += '=';
    }
    return border;
}

/// @brief Takes a string and breaks it into individual words
/// @param raw The original string of text to be broken apart
/// @return A vector containing all of the words from `raw`
std::vector<std::string> word_breaker(std::string raw)
{
    std::vector<std::string> words;
    std::string temp;
    for (auto x : raw) // Iterate through each character in `raw`
    {
        if (x == ' ') // If whitespace is encountered, the current word is finished
        {   
            if (temp != "")
            {
                words.insert(words.end(), temp); // Add stored current word to the end of `words`
            }
            temp = "";
        }
        else 
        {
            temp = temp + x; // If the char isn't a whitespace, add it to the end of `temp`
        }
    }
    words.insert(words.end(), temp); // Add anything left from `temp` to `words`
    return words;
}

/// \brief Concatenates strings from a vector into lines
/// of a specified size to be sent to the terminal
/// @param words The vector containing all of the strings to be wrapped
/// \param wrap_size The maximum length of each line sent to the 
/// terminal by `word_wrapper`; this value is set to 100 by default
void word_wrapper(std::vector<std::string> words, int wrap_size = 100)
{
    std::string current_line;
    for (auto x: words) // Iterate through each string in `words`
    {
        if (x.length() + current_line.length() > wrap_size)
        { // If the current string + `current_line` exceeds `wrap_size`, output and reset the string
            std::cout << current_line << std::endl;
            current_line = x + " "; // Reset `current_line` to be equal to the next word, then add a space
        }
        else // Add string to `current_line` if it doesn't exceed `wrap_size`, then add a space
        {
            current_line = current_line + x + " ";
        }
    }

    if (!current_line.empty() && current_line != " ")
    {
        std::cout << current_line << std::endl; // Ensures the last line is always sent (if it exists)
    }

    std::cout << generate_border() << std::endl; // Printing the lower border
}

/// @brief Prompts the user for input and stores their response
/// @return A string containing the user's input in all lowercase
std::string get_input(bool is_inline = false)
{
    std::string input;
    if (!is_inline)
    {
        std::cout << "> ";
    }
    getline(std::cin, input); // Reads input until a newline character is reached

    std::transform(input.begin(), input.end(), input.begin(), ::tolower); // Convert input to all lowercase
    return input;
}

/// @brief Outputs a message prompting the user to try again after an invalid value
/// @param value The type of invalid message; by default, is set to "input"
/// \param add_border Boolean value determining if the function 
/// should also output a border; by default, is set to "true" 
void invalid_msg(std::string value = "input", bool add_border = true)
{
    std::cout << "Invalid " + value + ". Please try again." << std::endl;
    if (add_border)
    {
        std::cout << generate_border() << std::endl;
    }
}

/// \brief Sends the name of the company (as ASCII art)
/// to the terminal, surrounded by borders
void title_card()
{
    const std::string ascii_title = 
    "  /$$$$$$                                          /$$$$$$$                                  /$$    \n"
    " /$$__  $$                                        | $$__  $$                                | $$    \n"
    "| $$  \\__/  /$$$$$$   /$$$$$$  /$$  /$$  /$$      | $$  \\ $$  /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$  \n"
    "| $$ /$$$$ /$$__  $$ /$$__  $$| $$ | $$ | $$      | $$  | $$ /$$__  $$ /$$__  $$ /$$__  $$|_  $$_/  \n"
    "| $$|_  $$| $$  \\__/| $$  \\ $$| $$ | $$ | $$      | $$  | $$| $$$$$$$$| $$  \\ $$| $$  \\ $$  | $$    \n"
    "| $$  \\ $$| $$      | $$  | $$| $$ | $$ | $$      | $$  | $$| $$_____/| $$  | $$| $$  | $$  | $$ /$$\n"
    "|  $$$$$$/| $$      |  $$$$$$/|  $$$$$/$$$$/      | $$$$$$$/|  $$$$$$$| $$$$$$$/|  $$$$$$/  |  $$$$/\n"
    " \\______/ |__/       \\______/  \\_____/\\___/       |_______/  \\_______/| $$____/  \\______/    \\___/  \n"
    "                                                                      | $$                          \n"
    "                                                                      | $$                          \n"
    "                                                                      |__/                          \n";
    std::cout << generate_border() << std::endl << ascii_title << generate_border() << std::endl;
}

/// @brief
/// @param num_string 
/// @return 
int convert_string_to_number(std::string num_string)
{
    if (num_string.empty())
    {
        return -2;
    }
    try
    {
        return std::stoi(num_string);
    }
    catch(std::invalid_argument)
    {
        std::cout << "ERROR: Input must be a number." << std::endl;
        return -1;
    }
}

#endif