#include <iostream>
#include <string>
#include <vector>
#include "UserPrompts.h"
#include "FoodTracker.h"

int main(int argc, char* argv[]) {
    std::string userInput = "";
    int userInput1 = 0;
    userInput = NewOrReturningUser();
    if(userInput == "yes"){
        std::cout << 5;
        setUserInfo(argv[1]);
        std::cout << "Select one of the following options: " << std::endl;
        std::cout << "1) Make a new meal entry" << std::endl;
        std::cout << "2) View a old meal entry" << std::endl;
        std::cout << "3) Exit the food tracking program" << std::endl;
        std::cin >> userInput1;
        nextMove(userInput1);
    } else {
        createNewUser();
        std::cout << "Select one of the following options: " << std::endl;
        std::cout << "1) Make a new meal entry" << std::endl;
        std::cout << "2) View a old meal entry" << std::endl;
        std::cout << "3) Exit the food tracking program" << std::endl;
        std::cout << "Please enter 1,2 or 3 only" << std::endl;
        std::cin >> userInput1;
        nextMove(userInput1);
    }

}
