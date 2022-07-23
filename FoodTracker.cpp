//
// Created by Ryan Fouzdar on 7/23/22.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "FoodTracker.h"

std::string name;

void createNewUser(){
    int age = 0;
    double weight;
    int height;
    std::fstream userInfo;
    std::cout <<"What is your first and last name? Enter it with a space between the first and last name." << std::endl;
    std::getline(std::cin, name);
    userInfo.open(name.c_str());
    userInfo << "Name: " << name << std::endl;
    validAge(age);
    userInfo << "Age: " << age << std::endl;
    validWeight(weight);
    userInfo << "Weight: " << weight << std::endl;
    validHeight(height);
    userInfo << "Height: " << height << std::endl;
    userInfo.close();
}
void makeNewEntry(){
    std::fstream userInfo;
    std::string date;
    std::string meal;
    double calories;
    std::string main_meal;
    userInfo.open(name.c_str(), std::fstream::app);
    std::string answer;
    userInfo << "------------------------------------------------" << std::endl;
    std::cout << "Enter the date of the entry." << std::endl;
    std::cin >> date;
    userInfo << "Date: " << date << std::endl;
    userInfo.close();
    validResponse(meal, calories, main_meal);
    userInfo.open(name.c_str(), std::fstream::app);
    userInfo << "------------------------------------------------" << std::endl;
    userInfo.close();
}
void validResponse(std::string& meal, double &calories, std::string& main_meal){
    bool answerValid = false;
    std::fstream userInfo;
    userInfo.open(name.c_str(), std::fstream::app);
    std::string answer;
    std::cout << "What meal did you eat?" << std::endl;
    std::cin >> meal;
    userInfo << "Meal Eaten: " << meal << std::endl;
    std::cout << "How many calories was it?" << std::endl;
    std::cin >> calories;
    userInfo << "Calories: " << calories << std::endl;
    std::cout << "Which meal of the day was it? (Breakfast, Lunch Dinner) " << std::endl;
    std::cin >> main_meal;
    userInfo << "Meal of the Day: " << main_meal << std::endl;
    while(!answerValid){
        for(int i = 0; i < answer.length();i++){
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
            userInfo.close();
        } else{
            std::cout << "Please enter yes or no." << std::endl;
            std::cin >> answer;
        }
    }

}
void validHeight(int& height){
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

void validAge(int& age){
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
void validWeight(double& weight){
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

void viewExistingEntry() {
    std::fstream userInfo;
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

void setUserInfo(std::string textFile) {
    name = textFile;
}
