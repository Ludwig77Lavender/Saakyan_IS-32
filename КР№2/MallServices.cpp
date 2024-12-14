#include "MallServices.h"

MallServices::MallServices(std::string serviceName, double cost)
    : serviceName(serviceName), cost(cost) {
}

std::string MallServices::getServiceName() {
    return serviceName;
}

double MallServices::getCost() {
    return cost;
}