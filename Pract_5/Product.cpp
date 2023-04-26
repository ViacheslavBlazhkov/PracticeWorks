#include "Product.h"

Product::Product()
{
    cout << "Ctor without parameters";
}

Product::Product(int id, string name, double weight, double price, int count)
{
    product_id = id;
    this->name = name;
    this->weight = weight;
    this->price = price;
    this->count = count;
}

void Product::Print()
{
    cout << "Product #" << product_id << "\nName: " << name << " | Weight: " << weight << " | Price: " << price << " | Count: " << count << endl;
}
