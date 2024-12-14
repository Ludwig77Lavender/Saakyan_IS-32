#include "SalesRecord.h"

SalesRecord::SalesRecord(std::string productName, double saleAmount, std::string date)
    : productName(productName), saleAmount(saleAmount), date(date) {
}

std::string SalesRecord::getProductName() {
    return productName;
}

double SalesRecord::getSaleAmount() {
    return saleAmount;
}

std::string SalesRecord::getDate() {
    return date;
}