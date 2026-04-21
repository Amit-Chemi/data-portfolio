#include "Store.h"

// constructor: initializes array to nullptr as required
Store::Store(const std::string& name, int adFactor)
	: _name(name), _adFactor(adFactor), _numProducts(0), _products(nullptr)
{
}

// destructor: must delete each product, then the array of pointers itself
Store::~Store()
{
	if (_products != nullptr) {
		for (int i = 0; i < _numProducts; i++) {
			delete _products[i]; // calls the virtual destructor of the specific products
		}
		delete[] _products;
	}
}

// adds a product pointer to the dynamic array
void Store::addProduct(Product* p)
{
	if (p == nullptr) return;

	// allocate a new array with size +1
	Product** temp = new Product * [_numProducts + 1];

	// copy existing pointers to the new array
	for (int i = 0; i < _numProducts; i++) {
		temp[i] = _products[i];
	}

	// add the new product at the end
	temp[_numProducts] = p;

	// delete the old array of pointers
	delete[] _products;

	// update the stores members
	_products = temp;
	_numProducts++;
}

// updates the advertising factor
void Store::setAdFactor(int newFactor)
{
	_adFactor = newFactor;
}

// calculates the sum of all product prices
double Store::calcTotalPrice() const
{
	double total = 0.0;
	for (int i = 0; i < _numProducts; i++) {
		// calls the specific calcProce based on the actual object type
		total += _products[i]->calcPrice(_adFactor);
	}
	return total;
}

// prints store details and all products
void Store::print(std::ostream& os) const
{
	// print store data in the first line
	os << _name << " " << _numProducts << " " << _adFactor << "\n";
	
	//print all products in order
	for (int i = 0; i < _numProducts; i++) {
		_products[i]->print(os);
		os << "\n";
	}
}

// function to check if a product with the given serial already exists
bool Store::isSerialExists(int serial) const
{
	for (int i = 0; i < _numProducts; i++) {
		// accesing _serial directly thank to friend class
		if (_products[i]->_serial == serial) {
			return true; // serial found
		}
	}
	return false; // serial is unique
}