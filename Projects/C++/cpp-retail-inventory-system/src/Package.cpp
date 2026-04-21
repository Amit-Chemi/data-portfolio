#include "Package.h"

// constructor: calls Product constructor and copies the names array
Package::Package(int serial, char row, int shelf, double quantity, int type, int area, int numProducts,
	const std::string* names, int colors)
	: Product(serial, row, shelf, quantity, type, area), _numProducts(numProducts), _productNames(nullptr), _colors(colors)
{
	// allocate and copy product names
	if (numProducts > 0 && names != nullptr) {
		_productNames = new std::string[numProducts];
		for (int i = 0; i < numProducts; i++) {
			_productNames[i] = names[i];
		}
	}
}

// destructor: release dynamic array
Package::~Package()
{
	delete[] _productNames;
}

// copy constructor: makes a real copy of the dynamic array
Package::Package(const Package& other)
	: Product(other), _numProducts(other._numProducts), _productNames(nullptr), _colors(other._colors)
{
	if (_numProducts > 0 && other._productNames != nullptr) {
		_productNames = new std::string[_numProducts];
		for (int i = 0; i < _numProducts; i++) {
			_productNames[i] = other._productNames[i];
		}
	}
}

// assignment operator: handles self assignment and copies the dynamic array
Package& Package::operator=(const Package& other)
{
	// check for self assignment
	if (this == &other) {
		return *this;
	}
	// copy base class part
	Product::operator=(other);
	
	// release old memory
	delete[] _productNames;
	_productNames = nullptr;

	// copy new data
	_numProducts = other._numProducts;
	_colors = other._colors;

	// allocate and copy the dynamic array
	if (_numProducts > 0 && other._productNames != nullptr) {
		_productNames = new std::string[_numProducts];
		for (int i = 0; i < _numProducts; i++) {
			_productNames[i] = other._productNames[i];
		}
	}
	return *this;
}

// price formula for package: 2 base price * products number * 1/3 colors
double Package::calcPrice(double adFactor) const
{
	double basePrice = Product::calcPrice(adFactor);
	return (2 * basePrice) * _numProducts + (_colors / 3.0);
}

// prints package data: base product + name list + (numProducts, colors)
void Package::print(std::ostream& os) const
{
	Product::print(os);
	os << " ";
	// print names:
	for (int i = 0; i < _numProducts; i++) {
		os << _productNames[i];
		if (i < _numProducts - 1) {
			os << ", ";
		}
	}
	os << " (" << _numProducts << "," << _colors << ")";
}
