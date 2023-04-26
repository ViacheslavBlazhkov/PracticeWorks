#pragma once
#include<iostream>

using namespace std;

class Product
{
public:
    int product_id;
    string name;
    double weight;
    double price;
    int count;

    Product();
    Product(int id, string name, double weight, double price, int count);
    void Print();
};
