#include <iostream>
#include <string>
#include <vector>
#include "UserPrompts.h"
#include "FoodTracker.h"

int main(int argc, char* argv[]) {
    std::string userInput, name;
    int userInput1 = 0;
    userInput = NewOrReturningUser(); //Finding out if the user has a previous file or not
    if(userInput == "returning"){
        std::cout << "What is your name?" << std::endl; //Finds out users name and sets it to the name variable in Food Tracker
        std::cin >> name;
        setName(name);
        std::cout << "Select one of the following options: " << std::endl;  //Selection menu
        std::cout << "1) Make a new meal entry" << std::endl;
        std::cout << "2) View a old meal entry" << std::endl;
        std::cout << "3) Exit the food tracking program" << std::endl;
        std::cin >> userInput1;
        nextMove(userInput1);
    } else {
        createNewUser(); //Creates a new user
        std::cout << "Select one of the following options: " << std::endl; //Selection menu
        std::cout << "1) Make a new meal entry" << std::endl;
        std::cout << "2) View a old meal entry" << std::endl;
        std::cout << "3) Exit the food tracking program" << std::endl;
        std::cout << "Please enter 1,2 or 3 only" << std::endl;
        std::cin >> userInput1;
        nextMove(userInput1); //Checks if input is valid and does the action based on what they say
    }

}
