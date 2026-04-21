#include "Product.h"

Product::Product(int serial, char row, int shelf, double quantity, int type, int area)
	: _serial(serial), _row(row), _shelf(shelf), _quantity(quantity), _type(type), _area(area)
{
	// Initialize all basic product data through initialization list
}

Product::~Product()
{
	// no dynamic memory to release
}

// calculates the base price using the formula: quantity * area * advertising factor
double Product::calcPrice(double adFactor) const
{
	return _quantity * _area * adFactor;
}

// updates the quantity of the product
void Product::changeQuantity(double newQty)
{
	_quantity = newQty;
}

// prints the product details in the required format
void Product::print(std::ostream& os) const
{
	os << _serial << " " << _row << " " << _shelf << " " << "(" << _quantity << "," << _type << "," << _area << ") ";
}
