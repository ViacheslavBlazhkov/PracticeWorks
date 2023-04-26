#include "Storage.h"

void Storage::AddProduct(Product product)
{
    products.push_back(product);
}

void Storage::FindByName(string name)
{
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->name == name) {
            it->Print();
            break;
        }
    }
}

void Storage::UpdateProduct(int id_to_update, string new_name, double new_weight, double new_price, double new_count)
{
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->product_id == id_to_update) {
            it->name = new_name;
            it->weight = new_weight;
            it->price = new_price;
            it->count = new_count;
            break;
        }
    }
}

void Storage::RemoveProduct(int id_to_remove)
{
    for (auto it = products.begin(); it != products.end();) {
        if (it->product_id == id_to_remove) {
            it = products.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Storage::PrintAll()
{
    for (auto it = products.begin(); it != products.end(); ++it) {
        cout << "Product #" << it->product_id << "\nName: " << it->name
            << " | Weight: " << it->weight << " | Price: " << it->price
            << " | Count: " << it->count << endl;
    }
}
