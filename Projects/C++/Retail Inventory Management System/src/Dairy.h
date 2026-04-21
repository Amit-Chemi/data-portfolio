#pragma once
#include "Product.h"
#include <string>

class Dairy : public Product
{
private:
	int _kind;         // 1 (beverage), 2 (yogurt), 3 (cheese), 4 (other)
	std::string _name; // dairy product name
	int _colors;       // number of colors in the design
	double _fat;       // precentage of fat in the product

public:
	// constructor
	Dairy(int serial, char row, int shelf, double quantity, int type, int area, int kind, const std::string& name, int colors, double fat);

	// destructor
	virtual ~Dairy();

	double calcPrice(double adFactor) const override;
	void print(std::ostream& os) const override;
};

