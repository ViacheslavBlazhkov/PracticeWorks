#pragma once
#include<iostream>
#include<list>
#include "Product.h"

using namespace std;

class Storage
{
private:
    int inventory_id;
    string title;
    list<Product> products;
public:
    Storage(int id, string title, list<Product> products = list<Product>()) :
        inventory_id(id), title(title), products(products) {}

    void AddProduct(Product product);
    void FindByName(string name);
    void UpdateProduct(int id_to_update, string new_name, double new_weight, double new_price, double new_count);
    void RemoveProduct(int id_to_remove);
    void PrintAll();
};
