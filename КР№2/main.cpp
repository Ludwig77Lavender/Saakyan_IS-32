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
    //std::locale::global(std::locale("")); � ������� ������������ ������ �����
    //wchar_t rubl = L'\u20BD';

    // �������� �����
    Mall mall("City Mall", "�. 43 ��. �������");

    // ��������
    Store store1("Fashion Store", "������");
    Store store2("Electronics Hub", "�����������");

    // ���������� ��������� � �������� �����
    mall.addStore(store1);
    mall.addStore(store2);

    // ���������� ��� Fashion Store
    Employee emp1("�����", "��������", 50000);
    Employee emp2("������", "��������", 30000);
    store1.addEmployee(emp1);
    store1.addEmployee(emp2);

    // ���������� ��� Electronics Hub
    Employee emp3("����", "�����������", 40000);
    Employee emp4("�������", "������", 45000);
    store2.addEmployee(emp3);
    store2.addEmployee(emp4);

    // ������ � ��������
    Product prod1("��������", 390.00, 100);
    Product prod2("�������", 99900.00, 20);
    Product prod3("��������", 69900.00, 30);
    Product prod4("���������", 159900.00, 15);
    store1.addProduct(prod1);
    store2.addProduct(prod2);
    store2.addProduct(prod3);
    store2.addProduct(prod4);

    // �������
    Customer cust1("���� ������", "ivan@example.com", "123-456-7890");
    Customer cust2("����� �������", "elena@example.com", "987-654-3210");

    // ���������
    Inventory inventory;
    inventory.addProduct(prod1);
    inventory.addProduct(prod2);
    inventory.addProduct(prod3);
    inventory.addProduct(prod4);

    // ������ ������
    SalesRecord sale1("��������", 390.00, "2024-03-15");
    SalesRecord sale2("�������", 99900.00, "2024-03-15");
    SalesRecord sale3("��������", 69900.00, "2024-03-16");
    SalesRecord sale4("���������", 159900.00, "2024-03-16");

    // ������ ��������� ������
    MallServices service1("������", 2000.00);
    MallServices service2("������", 5000.00);

    // ����� ���������� � �������� ������
    std::cout << "���������� � �������� ������:" << std::endl;
    mall.listStores();
    std::cout << std::endl;

    // ���������� � ������ � �������� Fashion Store
    store1.listEmployees();
    std::cout << std::endl;

    // ������ � �������� Fashion Store
    store1.listProducts();
    std::cout << std::endl;

    // ���������� �������� Electronics Hub
    store2.listEmployees();
    std::cout << std::endl;

    // ������ � �������� Electronics Hub
    store2.listProducts();
    std::cout << std::endl;

    // ���������
    inventory.listProducts();
    std::cout << std::endl;

    // ���������� � ��������
    std::cout << "�������:" << std::endl;
    std::cout << sale1.getProductName() << " - " << sale1.getSaleAmount() << " ���." << " - " << sale1.getDate() << std::endl;
    std::cout << sale2.getProductName() << " - " << sale2.getSaleAmount() << " ���." << " - " << sale2.getDate() << std::endl;
    std::cout << sale3.getProductName() << " - " << sale3.getSaleAmount() << " ���." << " - " << sale3.getDate() << std::endl;
    std::cout << sale4.getProductName() << " - " << sale4.getSaleAmount() << " ���." << " - " << sale4.getDate() << std::endl;
    std::cout << std::endl;

    // ������ ��������� ������
    std::cout << "������ ��������� ������:" << std::endl;
    std::cout << service1.getServiceName() << " - " << service1.getCost() << " ���." << std::endl;
    std::cout << service2.getServiceName() << " - " << service2.getCost() << " ���." << std::endl;

    return 0;
}