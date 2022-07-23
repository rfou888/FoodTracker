//
// Created by Ryan Fouzdar on 7/22/22.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "FoodLogger.h"
#include "UserPrompts.h"


std::string NewOrReturningUser(){
    bool prompt = false;
    std::string answer = "";
    std::cout <<"Hello! Welcome to your food tracking portal!" <<std::endl;
    std::cout<< "Are you a new or returning user?" << std::endl;
    while(prompt == false){
        std::cout << "Respond yes or no: " << std::endl;
        std::cin >> answer;
        prompt = validAnswer(answer);
    }
    return answer;
}

bool validAnswer(std::string answer){
    for(int i = 0; i < answer.length(); i++){
        std::tolower(answer[i]);
    }
    if(answer == "yes" || answer == "no"){
        return true;
    }
    return false;
}

void nextMove(int userInput, FoodLogger person){
    bool end = false;
    while(!end){
        if(userInput == 1){
            person.FoodLogger::makeNewEntry();
        }
        else if(userInput == 2){
            person.FoodLogger::viewExistingEntry();
        } else if(userInput == 3){
            end = true;
        } else {
            std::cout << "Please enter 1,2 or 3 only" << std::endl;
            std::cin >> userInput;
        }
    }
}


