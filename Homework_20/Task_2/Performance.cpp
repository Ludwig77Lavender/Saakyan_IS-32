#include "Performance.h"
#include <iostream>

Performance::Performance(std::string title, int duration) : title(title), duration(duration) {}

void Performance::displayInfo() {
    std::cout << "Спектакль: " << title << ", Продолжительность: " << duration << " минут" << std::endl;
}