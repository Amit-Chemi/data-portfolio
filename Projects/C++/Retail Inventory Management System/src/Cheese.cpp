#include "Cheese.h"

Cheese::Cheese(int serial, char row, int shelf, double quantity, int type, int area,
	const std::string& name, int colors, double fat, int extras)
	: Dairy(serial, row, shelf, quantity, type, area, type, name, colors, fat),
	_extras(extras)
{
}

Cheese::~Cheese()
{
	// no dynamic memory to release
}

double Cheese::calcPrice(double adFactor) const
{
	double dairyPrice = Dairy::calcPrice(adFactor);
	return dairyPrice + _extras;
}

void Cheese::print(std::ostream& os) const
{
	Dairy::print(os);
	os << " (" << _extras << ")";
}
