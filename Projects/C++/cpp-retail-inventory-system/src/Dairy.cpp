#include "Dairy.h"

// constructor: calls Product constructor and then initializes dairy fields
Dairy::Dairy(int serial, char row, int shelf, double quantity, int type, int area, int kind, const std::string& name, int colors, double fat)
	: Product(serial, row, shelf, quantity, type, area), _kind(kind), _name(name), _colors(colors), _fat(fat)
{
}

Dairy::~Dairy()
{
	// no dynamic memory here
}

double Dairy::calcPrice(double adFactor) const
{
	double basePrice = Product::calcPrice(adFactor);
	return (basePrice + _colors - _fat) * _kind;
}

void Dairy::print(std::ostream& os) const
{
	Product::print(os);
	os << _name << " (" << _kind << "," << _colors << "," << _fat << ") ";
}
