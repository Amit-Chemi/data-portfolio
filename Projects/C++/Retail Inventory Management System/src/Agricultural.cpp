#include "Agricultural.h"

Agricultural::Agricultural(int serial, char row, int shelf, double quantity, int type, int area, int kind,
	const std::string& name, int seasons, int suppliers)
	: Product(serial, row, shelf, quantity, type, area), _kind(kind), _name(name), _seasons(seasons), _suppliers(suppliers)
{
	// base class is initialized first, then agricultural fields
}

Agricultural::~Agricultural()
{
	// no dynamic memory to release
}

double Agricultural::calcPrice(double adFactor) const
{
	double basePrice = Product::calcPrice(adFactor);
	return 3 * basePrice * (5 - _seasons) + (5 * _suppliers) + _kind;
}

void Agricultural::print(std::ostream& os) const
{
	Product::print(os);
	os << _name << " (" << _kind << "," << _seasons << "," << _suppliers << ") ";
}