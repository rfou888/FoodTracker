//
// Created by Ryan Fouzdar on 7/23/22.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "FoodTracker.h"
#include "UserPrompts.h"

std::string name; // global variable for the name of the user

void createNewUser(){ //Creates file for user and names it after what they put their name as
    int age = 0, height;
    double weight;
    std::fstream userInfo;
    std::cout <<"What is your first name?" << std::endl;
    std::cin >> name; //sets name
    userInfo.open(name.c_str(), std::fstream::app); //Opening and creating file in cmake-build-debug folder
    userInfo << "Name: " << name << std::endl;
    validAge(age); //checks if age is valid and then writes it to the file
    userInfo << "Age: " << age << std::endl;
    validWeight(weight); //checks if weight is valid and then writes it to the file
    userInfo << "Weight: " << weight << std::endl;
    validHeight(height); //checks if height is valid and then writes it to the file
    userInfo << "Height: " << height << std::endl;
    userInfo.close(); //closing the file after every function
}
void makeNewEntry(){ //makes a new entry for the date asked
    std::fstream userInfo;
    std::string date, meal, main_meal, answer;
    double calories;
    userInfo.open(name.c_str(), std::fstream::app);
    userInfo << "------------------------------------------------" << std::endl;
    std::cout << "Enter the date of the entry." << std::endl;
    std::cin >> date;
    userInfo << "Date: " << date << std::endl;
    userInfo.close();
    validResponse(meal, calories, main_meal);
    userInfo.close();

}
void validResponse(std::string& meal, double &calories, std::string& main_meal){ //Checks that the response and answers are valid
    bool answerValid = false;
    int userInput1;
    std::fstream userInfo;
    std::string answer;
    userInfo.open(name.c_str(), std::fstream::app); //opening file at end of file so it does not overwrite current info
    std::cout << "What meal did you eat? If more than one word, enter it as hyphenated string." << std::endl;
    std::cin >> meal;
    userInfo << "Meal Eaten: " << meal << std::endl;
    validCalories(calories); //checks calories are valid
    userInfo << "Calories: " << calories << std::endl;
    validMealOfTheDay(main_meal); //checks meal of the day is valid
    userInfo << "Meal of the Day: " << main_meal << std::endl;
    while(!answerValid){
        std::cout << "Do you want to continue adding entries to this date?" << std::endl;
        std::cout << "Please enter yes or no." << std::endl;
        std::cin >> answer;
        for(int i = 0; i < answer.length();i++){ //makes answer lowercase
            std::tolower(answer[i]);
        }
        if(answer == "yes"){ //adds another entry to the same date
            userInfo << "Next Meal Eaten of the Day:" << std::endl;
            std::cout << "What meal did you eat? If more than one word, enter it as hyphenated string." << std::endl;
            std::cin >> meal;
            userInfo << "Meal Eaten: " << meal << std::endl;
            validCalories(calories);
            userInfo << "Calories: " << calories << std::endl;
            validMealOfTheDay(main_meal);
            userInfo << "Meal of the Day: " << main_meal << std::endl;
        } else if(answer == "no") { //Goes to selection menu if you are done adding meals for that date
            userInfo << "------------------------------------------------" << std::endl;
            userInfo.close();
            std::cout << "Select one of the following options: " << std::endl;
            std::cout << "1) Make a new meal entry" << std::endl;
            std::cout << "2) View a old meal entry" << std::endl;
            std::cout << "3) Exit the food tracking program" << std::endl;
            std::cout << "Please enter 1,2 or 3 only" << std::endl;
            std::cin >> userInput1;
            nextMove(userInput1);
            answerValid = true;
        } else{ //If you enter something invalid
            std::cout << "Please enter yes or no." << std::endl;
            std::cin >> answer;
        }
    }

}

void viewExistingEntry() { //Views any existing entries
    std::fstream userInfo;
    int userInput1;
    std::string date_wanted, line, word;
    userInfo.open(name.c_str(),std::ios::in|std::ios::out);
    std::cout << "Enter the date that you want to view." << std::endl;
    std::cin >> date_wanted;
    while(!userInfo.eof()){
        userInfo >> word; //checking each word of the file to see if it matches the date wanted
        if(word == date_wanted){ //if it matches, code gets all the lines until it reaches the end of the entry
            std::cout << "------------------------------------------------"<< std::endl;
            std::cout << word;
            while(line != "------------------------------------------------" ){
                std::getline(userInfo, line);
                std::cout << line<< std::endl;
            }
            break;
        } else if(userInfo.eof()) { //Date does not exist and it exits the program
            std::cout << "Date is entered wrong or does not exist. Exiting program.";
            exit(0);
        }
    }//Selection menu
    std::cout << "Select one of the following options: " << std::endl;
    std::cout << "1) Make a new meal entry" << std::endl;
    std::cout << "2) View a old meal entry" << std::endl;
    std::cout << "3) Exit the food tracking program" << std::endl;
    std::cout << "Please enter 1,2 or 3 only" << std::endl;
    std::cin >> userInput1;
    nextMove(userInput1);

}

void setName(std::string &name1) { //sets the returning user's name to our global variable name
    name = name1;
}
void validMealOfTheDay(std::string& main_meal){ //Checks meal of the day is valid
    bool main_meal_valid = false;
    std::cout << "Which meal of the day was it? (Breakfast, Lunch, Dinner) " << std::endl;
    std::cin >> main_meal;
    while(!main_meal_valid){
        for(int i = 0; i < main_meal.length(); i++){
            main_meal[i] = std::tolower(main_meal[i]);
        }
        if(main_meal == "dinner" || main_meal == "lunch" || main_meal == "breakfast"){
            main_meal_valid = true;
        }
        else{
            std::cout << "Invalid meal of the day. Please enter it again." << std::endl;
            std::cout << "Which meal of the day was it? (Breakfast, Lunch, Dinner) " << std::endl;
            std::cin >> main_meal;
        }
    }
}
void validCalories(double& calories){ //Checks calories is valid
    bool caloriesValid = false;
    std::cout << "How many calories was it? ";
    std::cout << "Enter a number between 0 and 10,000." << std::endl;
    std::cin >> calories;
    while(!caloriesValid){
        if(calories < 0 || calories > 10000){
            std::cout << "Please enter a number between 0 and 10,000. " << std::endl;
            std::cin >> calories;
        } else {
            caloriesValid = true;
        }
    }
}
void validHeight(int& height){ //Checks if the height of the user is valid
    bool heightValid = false;
    std::cout << "What is your height in inches?";
    std::cout << " Enter a number between 48 and 96. " << std::endl;
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

void validAge(int& age){ //Checks if the age of the user is valid
    bool ageValid = false;
    std::cout<< "What is your age?";
    std::cout <<  " Enter a number from 10 to a 100." << std::endl;
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
void validWeight(double& weight){ //Checks if the weight of the user is valid
    bool weightValid = false;
    std::cout << "What is your weight?";
    std::cout <<  " Enter a number from 75lbs to 500lbs." << std::endl;
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

