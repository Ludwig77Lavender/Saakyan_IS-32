#pragma once
#include <vector>
#include "Store.h"

class Mall {
private:
    std::string name;
    std::string location;
    std::vector<Store> stores;
public:
    Mall(std::string name, std::string location);
    void addStore(Store store);
    void listStores();
};