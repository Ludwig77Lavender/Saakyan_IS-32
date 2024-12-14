#pragma once
#include <string>

class MallServices {
private:
    std::string serviceName;
    double cost;
public:
    MallServices(std::string serviceName, double cost);
    std::string getServiceName();
    double getCost();
};