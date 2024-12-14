#pragma once
#include <string>

class SalesRecord {
private:
    std::string productName;
    double saleAmount;
    std::string date;
public:
    SalesRecord(std::string productName, double saleAmount, std::string date);
    std::string getProductName();
    double getSaleAmount();
    std::string getDate();
};