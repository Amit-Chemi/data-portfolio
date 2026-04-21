#pragma once
#include "Product.h"
#include <string>
#include <ostream>

class Store
{
private:
	std::string _name;    // store name
	int _adFactor;        // advertising factor (assumed to be integer
	int _numProducts;     // number of products currently in the store
	Product** _products;  // dynamic array of pointers to products (for polymorphism)

public:
	// constructor
	Store(const std::string& name, int adFctor);

	// destructor: releases the array and all the products inside it
	~Store();

	void addProduct(Product* p);           // adds a new product pointer to the array
	void setAdFactor(int newFactor);       // changes the ad factor
	double calcTotalPrice() const;         // calculates total proce of all products
	void print(std::ostream& os) const;    // prints store details and all products
	bool isSerialExists(int serial) const; // check if a product with this serial already exists
};