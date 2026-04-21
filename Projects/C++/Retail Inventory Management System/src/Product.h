#pragma once
#include <iostream>
#include <ostream>

class Store;

class Product
{
	friend class Store;

private:
	int _serial;      // unique serial number
	char _row;        // row location on the store (A-Z)
	int _shelf;       // shelf number (1-5)
	double _quantity; // total weight in stock (or weight per item for package)
	int _type;        // product type: 1 (agriculture), 2 (dairy), 3 (package)
	int _area;        // exposure area in store: 1 (low), 2 (medium), 3 (high)

public:
	// constructor
	Product(int serial, char row, int shelf, double quantity, int type, int area);

	// destructor (virtual to allow correct deletion through Product*)
	virtual ~Product();

	virtual double calcPrice(double adFactor) const; //calculates the base price
	void changeQuantity(double newQty);              // allows changing the product quantity
	virtual void print(std::ostream& os) const;      // prints product basic information

};

