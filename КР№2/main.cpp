#include <iostream>
#include <string>
#include "Mall.h"
#include "Store.h"
#include "Employee.h"
#include "Product.h"
#include "Customer.h"
#include "Inventory.h"
#include "SalesRecord.h"
#include "MallServices.h"
//#include <locale>
//#include <codecvt>

int main() {
    setlocale(LC_ALL, "RU");
    //std::locale::global(std::locale("")); Я пытался использовать символ рубля
    //wchar_t rubl = L'\u20BD';

    // Торговый центр
    Mall mall("City Mall", "д. 43 ул. Пушкина");

    // Магазины
    Store store1("Fashion Store", "Одежда");
    Store store2("Electronics Hub", "Электроника");

    // Добавление магазинов в торговый центр
    mall.addStore(store1);
    mall.addStore(store2);

    // Сотрудники для Fashion Store
    Employee emp1("Алина", "Менеджер", 50000);
    Employee emp2("Виктор", "Продавец", 30000);
    store1.addEmployee(emp1);
    store1.addEmployee(emp2);

    // Сотрудники для Electronics Hub
    Employee emp3("Анна", "Консультант", 40000);
    Employee emp4("Дмитрий", "Техник", 45000);
    store2.addEmployee(emp3);
    store2.addEmployee(emp4);

    // Товары в магазины
    Product prod1("Футболка", 390.00, 100);
    Product prod2("Ноутбук", 99900.00, 20);
    Product prod3("Смартфон", 69900.00, 30);
    Product prod4("Телевизор", 159900.00, 15);
    store1.addProduct(prod1);
    store2.addProduct(prod2);
    store2.addProduct(prod3);
    store2.addProduct(prod4);

    // Клиенты
    Customer cust1("Иван Иванов", "ivan@example.com", "123-456-7890");
    Customer cust2("Елена Петрова", "elena@example.com", "987-654-3210");

    // Инвентарь
    Inventory inventory;
    inventory.addProduct(prod1);
    inventory.addProduct(prod2);
    inventory.addProduct(prod3);
    inventory.addProduct(prod4);

    // Запись продаж
    SalesRecord sale1("Футболка", 390.00, "2024-03-15");
    SalesRecord sale2("Ноутбук", 99900.00, "2024-03-15");
    SalesRecord sale3("Смартфон", 69900.00, "2024-03-16");
    SalesRecord sale4("Телевизор", 159900.00, "2024-03-16");

    // Услуги торгового центра
    MallServices service1("Уборка", 2000.00);
    MallServices service2("Охрана", 5000.00);

    // Вывод информации о торговом центре
    std::cout << "Информация о торговом центре:" << std::endl;
    mall.listStores();
    std::cout << std::endl;

    // Сотрудники и товары в магазине Fashion Store
    store1.listEmployees();
    std::cout << std::endl;

    // Товары в магазине Fashion Store
    store1.listProducts();
    std::cout << std::endl;

    // Сотрудники магазине Electronics Hub
    store2.listEmployees();
    std::cout << std::endl;

    // Товары в магазине Electronics Hub
    store2.listProducts();
    std::cout << std::endl;

    // Инвентарь
    inventory.listProducts();
    std::cout << std::endl;

    // Информация о продажах
    std::cout << "Продажи:" << std::endl;
    std::cout << sale1.getProductName() << " - " << sale1.getSaleAmount() << " руб." << " - " << sale1.getDate() << std::endl;
    std::cout << sale2.getProductName() << " - " << sale2.getSaleAmount() << " руб." << " - " << sale2.getDate() << std::endl;
    std::cout << sale3.getProductName() << " - " << sale3.getSaleAmount() << " руб." << " - " << sale3.getDate() << std::endl;
    std::cout << sale4.getProductName() << " - " << sale4.getSaleAmount() << " руб." << " - " << sale4.getDate() << std::endl;
    std::cout << std::endl;

    // Услуги торгового центра
    std::cout << "Услуги торгового центра:" << std::endl;
    std::cout << service1.getServiceName() << " - " << service1.getCost() << " руб." << std::endl;
    std::cout << service2.getServiceName() << " - " << service2.getCost() << " руб." << std::endl;

    return 0;
}