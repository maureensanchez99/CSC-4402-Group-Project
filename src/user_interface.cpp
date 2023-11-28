#include <iostream>
#include <algorithm>
#include <string>

std::string generate_border(int wrap_size = 88)
{
    std::string border;
    for (int i = 0; i < wrap_size; ++i)
    {
        border += '=';
    }
    return border;
}

std::vector<std::string> word_breaker(std::string raw)
{
    std::vector<std::string> words;
    std::string temp;
    for (auto x : raw) // Iterate through each character in `raw`
    {
        if (x == ' ') // If a whitespace is encountered, the current word is finished
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


void word_wrapper(std::vector<std::string> words, int wrap_size = 88)
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


const std::string title_card = 
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

void TitleCard()
{
    std::cout << generate_border() << std::endl;
    std::cout << title_card << std::endl;
    std::cout << generate_border() << std::endl;
}
