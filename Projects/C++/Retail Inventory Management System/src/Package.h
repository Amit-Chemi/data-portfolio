#pragma once
#include "Product.h"
#include <string>

class Package : public Product
{
private:
	int _numProducts;           // number of products inside the package
	std::string* _productNames; // dynamic array of product names
	int _colors;                // number of colors in the packge design

public:
	// constructor
	Package(int serial, char row, int shelf, double quantity, int type, int area, int numProducts, const std::string* names, int colors);

	// destructor
	virtual ~Package();

	// we must implement copy constructor and operator= since this class uses a dynamic array
	Package(const Package& other);
	Package& operator=(const Package& other);

	double calcPrice(double adFactor) const override;
	void print(std::ostream& os) const override;
};

