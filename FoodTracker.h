//
// Created by Ryan Fouzdar on 7/23/22.
//

#ifndef FOODTRACKER_FOODTRACKER_H
#define FOODTRACKER_FOODTRACKER_H
void createNewUser();
void validHeight(int& height);
void validAge(int& age);
void validWeight(double& weight);
void makeNewEntry();
void validResponse(std::string& meal, double& calories, std::string& main_meal);
void setUserInfo(std::string textFile);
void viewExistingEntry();
void setName(std::string& name);
void validCalories(double& calories);
void validMealOfTheDay(std::string& main_meal);
#endif //FOODTRACKER_FOODTRACKER_H
