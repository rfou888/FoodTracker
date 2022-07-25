//
// Created by Ryan Fouzdar on 7/22/22.
//
#include <iostream>
#include <string>
#include <vector>
#include "UserPrompts.h"
#include "FoodTracker.h"


std::string NewOrReturningUser(){ //Finding out if the user is returning or not
    bool prompt = false;
    std::string answer;
    std::cout <<"Hello! Welcome to your food tracking portal!" <<std::endl;
    std::cout<< "Are you a new or returning user?" << std::endl;
    while(!prompt){ //If the user inputs something other than returning or new
        std::cout << "Respond with new or returning: ";
        std::cin >> answer;
        prompt = validAnswer(answer);
    }
    return answer;
}

bool validAnswer(std::string& answer){ //returns a boolean saying whether or not the answer is valid
    for(int i = 0; i < answer.length(); i++){  //makes all the characters in answer lowercase
        answer[i] = std::tolower(answer[i]);
    }
    if(answer == "new" || answer == "returning"){
        return true;
    }
    return false;
}

void nextMove(int userInput){ //Selection menu for the user
    bool end = false;
    while(!end){
        if(userInput == 1){ //Makes a new food log entry
            makeNewEntry();
        }
        else if(userInput == 2){ //Allows user to view an existing entry
            viewExistingEntry();
        } else if(userInput == 3){ //exits the code
            end = true;
            exit(0);
        } else {  //If user enters in an unknown value or number.
            std::cout << "Please enter 1,2 or 3 only" << std::endl;
            std::cin >> userInput;
        }
    }
}


