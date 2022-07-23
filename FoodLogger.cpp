//
// Created by Ryan Fouzdar on 7/22/22.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "FoodLogger.h"
FoodLogger::FoodLogger(){
    std::cout <<"What is your first and last name? Enter it with a space between the first and last name." << std::endl;
    std::getline(std::cin, name);
    userInfo.open(name.c_str());
    userInfo << "Name: " << name << std::endl;
    validAge();
    userInfo << "Age: " << age << std::endl;
    validWeight();
    userInfo << "Weight: " << weight << std::endl;
    validHeight();
    userInfo << "Height: " << height << std::endl;
    userInfo.close();
}
void FoodLogger::makeNewEntry(){
    userInfo.open(name.c_str(), std::fstream::app|std::ios::in);
    std::string answer;
    userInfo << "------------------------------------------------" << std::endl;
    std::cout << "Enter the date of the entry." << std::endl;
    std::cin >> date;
    std::cout << "What meal did you eat?" << std::endl;
    std::cin >> meal;
    userInfo << "Meal Eaten: " << meal << std::endl;
    std::cout << "How many calories was it?" << std::endl;
    std::cin >> calories;
    userInfo << "Calories: " << calories << std::endl;
    std::cout << "Which meal of the day was it? (Breakfast, Lunch Dinner) " << std::endl;
    std::cin >> main_meal;
    userInfo << "Meal of the Day: " << main_meal << std::endl;
    validResponse();
    userInfo << "------------------------------------------------" << std::endl;
    userInfo.close();
}
void FoodLogger::validResponse(){
    bool answerValid = false;
    std::string answer;
    while(!answerValid){
        std::cout << "Do you have more meals to enter in?";
        std::cout << "Enter yes or no." << std::endl;
        std::cin >> answer;
        for(int i = 0; i < answer.length(); i++){
            std::tolower(answer[i]);
        }
        if(answer == "yes"){
            std::cout << "What meal did you eat?" << std::endl;
            std::cin >> meal;
            userInfo << "Meal Eaten: " << meal << std::endl;
            std::cout << "How many calories was it?" << std::endl;
            std::cin >> calories;
            userInfo << "Calories: " << calories << std::endl;
            std::cout << "Which meal of the day was it? (Breakfast, Lunch Dinner) " << std::endl;
            std::cin >> main_meal;
            userInfo << "Meal of the Day: " << main_meal << std::endl;
        } else if(answer == "no") {
            answerValid = true;
        }
    }
}
void FoodLogger::validHeight(){
    bool heightValid = false;
    std::cout << "What is your height in inches?";
    std::cout << "Enter a number between 48 and 96. " << std::endl;
    std::cin >> height;
    while(!heightValid){
        if(height < 48 || height > 96){
            std::cout << "Enter a number between 48 and 96. " << std::endl;
            std::cin >> height;
        } else {
            heightValid = true;
        }
    }
}

void FoodLogger::validAge(){
    bool ageValid = false;
    std::cout<< "What is your age? ";
    std::cout <<  "Enter a number from 10 to a 100." << std::endl;
    std::cin >> age;
    while(!ageValid){
        if(age > 100 || age < 10){
            std::cout <<  "Enter a number from 10 to a 100." << std::endl;
            std::cin >> age;
        } else{
            ageValid = true;
        }
    }
}
void FoodLogger::validWeight(){
    bool weightValid = false;
    std::cout << "What is your weight?";
    std::cout <<  "Enter a number from 75lbs to 500lbs." << std::endl;
    std::cin >> weight;
    while(!weightValid){
        if(weight > 500.00 || weight < 75.00){
            std::cout <<  "Enter a number from 75lbs to 500lbs." << std::endl;
            std::cin >> weight;
        } else{
            weightValid = true;
        }
    }
}

void FoodLogger::viewExistingEntry() {
    userInfo.open(name.c_str(),std::ios::in|std::ios::out);
    std::string date1;
    std::string line;
    std::string word;
    std::cout << "Enter the date that you want to view." << std::endl;
    std::cin >> date1;
    while(userInfo.is_open()){
        std::getline(userInfo, line);
        if(line == ("Date and Time: " + date1)){
            std::getline(userInfo, line);
            while(line.substr(0,3) !=  "Date"){
                std::cout << line << std::endl;
                std::getline(userInfo, line);
            }
            userInfo.close();
        }

    }

}

void FoodLogger::setUserInfo(std::string textFile) {
    name = textFile;
    userInfo.open(name.c_str(), std::ios::in|std::ios::out);
}



