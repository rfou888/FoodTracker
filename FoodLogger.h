//
// Created by Ryan Fouzdar on 7/22/22.
//

#ifndef FOODTRACKER_FOODLOGGER_H
#define FOODTRACKER_FOODLOGGER_H


class FoodLogger {
public:
    void setUserInfo(std::string textFile);
    FoodLogger();
    void validAge();
    void validWeight();
    void validHeight();
    void makeNewEntry();
    void viewExistingEntry();
    void validResponse();
private:
    std::string name;
    double weight{};
    int age{};
    int height{};
    std::fstream userInfo;
    static double calories;
    std::string meal;
    std::string main_meal;
    std::string date;
};


#endif //FOODTRACKER_FOODLOGGER_H
