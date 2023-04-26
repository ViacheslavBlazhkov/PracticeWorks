#include <iostream>
#include <list>
#include "Product.h"
#include "Storage.h"

using namespace std;

int main()
{
	Storage storage(1, "Main storage");
	Product prod1(1, "Banana", 0.5, 1.2, 3);
	Product prod2(2, "Potato", 0.8, 2.4, 5);

	storage.AddProduct(prod1);
	storage.AddProduct(prod2);
	storage.UpdateProduct(1, "Apple", 0.5, 1.2, 3);
	storage.FindByName("Apple");
}