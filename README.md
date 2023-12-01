# CSC4402 Group Project by Group Five

Welcome to the GitHub repository for the CSC4402 Group Project by Group Five! 

Instructions on how to interact with this repo and access files can be found below.

## Installing the Project (and the User Interface)

A note before we begin: the installation instructions below have been written for Linux users, but everything in this project is cross-platform compatible, so you should be able to install the program on macOS and Windows as well (like some of our team members have done). You'll just need to ignore some Linux-specific commands and replace them with equivalent ones for your platform of choice.

Also, for those using Windows (or Linux, but don't want to install anything), we've included pre-compiled versions of the user interface alongside the rest of the project files. The steps below will accomplish the same task of giving you access to all parts of our project, but if you'd rather download a zip file containing all of the files in this repo, you can click the 'Code' button on the main page of this repository and then the 'Download ZIP' drop-down.

A direct link to the zip file is available [here](https://github.com/maureensanchez99/CSC-4402-Group-Project/archive/refs/heads/main.zip).

### Part One: Downloading the Required Files

The first step is to clone the project repo using [git](https://git-scm.com/). This can be done by running the following command in your terminal of choice:
```Shell
git clone https://github.com/maureensanchez99/CSC-4402-Group-Project.git
```
Next, you'll need to move into the new directory, and then install the dependencies for this project; this can be accomplished via the following commands:
```Shell
cd CSC-4402-Group-Project
git submodule update --init --recursive
```
The external library we used for our project is SQLiteCpp version 3.1.1 from [here](https://github.com/SRombauts/SQLiteCpp/tree/sqlitecpp-release-3.3.1).

To quote the repo's description: "SQLiteC++ (SQLiteCpp) is a lean and easy to use C++ SQLite3 wrapper."

We used this wrapper in order to easily access our database in C++ and focus more on writing our user interface rather than spending time trying to make the original C library provided by the SQLite developers work.

### Part Two: Compiling the User Interface

To compile and run the user interface, you'll need a C++ compiler and [CMake](https://cmake.org/). 
The process for installing these components depends on your platform, so we won't dive into the specifics here. Please feel free to contact us though if you have any problems getting past this step.

Once you've installed a C++ compiler and CMake, you'll need to install [Visual Studio Code](https://code.visualstudio.com/); again, installation specifcs depend on your platform, but Microsoft have a long list of tutorials and documentation to get you started [here](https://code.visualstudio.com/docs). 

However, assuming you have VSCode installed and all of the neccessary C++ extensions installed (including the official [CMake Tools extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)), it should be as easy as opening up the folder containing our project in VSCode and building the `project` executable via CMake Tools.

## Interacting with the User Interface

The user interface for our project is completely terminal-based; as in, it only runs in the terminal. Therefore, all inputs for our program go through the terminal, and you'll only need to type to interact with the program.

To test the program out as a customer, type `N` when prompted to login as an employee on startup, and you'll then be asked to input an ID. Any `customer_id` from the `customer` table will work, so if you're using the default populated database, valid IDs will consist of all integers between 1 and 4. If you want to test the program out as an employee, you'll need to restart the program and type `Y` on startup instead. Here, you'll receieve the same ID prompt, and like with the customers, any `employee_id` from the `employee` table will work. 

In order to access the Administrator options of this program, however, you'll need to login with the ID of a manager; managers are employees from the `employee` table that have the `manager` value of 1 instead of 0. With the default populated database, the numbers 3 and 6 are valid manager IDs that you can input to access the Admin Options menu.

Once you've logged in and reached the main menu, all you need to do to select an option is type in the corresponding number located next to the option; for example, if you wanted to view all available items, you'd type in the number 1 and then press enter. Every action, once finished, will bring you back to the main menu. If you want to quit the program, simply type in the number 0 on the main menu and the program will close for you.

## Running the Database without the User Interface

Our database was made using SQLite, so if you'd like to bypass our user interface and use a real client to access the database, we recommend using [DB Browser for SQLite](https://sqlitebrowser.org/).

Also, in case you can't find the .db file, it's located within the `documents` folder of this repository.

### Executing Test Queries on the Database

Running queries will depend on the client you use to access our database, but if you're using the DB Browser we recommended above, you can load the database and then head over to the `Execute SQL` tab. Here, you can type in SQL queries or open .sql files that will run on our database.
