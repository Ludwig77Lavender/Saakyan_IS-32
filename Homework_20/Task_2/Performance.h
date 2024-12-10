#pragma once
#include <string>

class Performance {
private:
    std::string title;
    int duration;
public:
    Performance(std::string title, int duration);
    void displayInfo();
};