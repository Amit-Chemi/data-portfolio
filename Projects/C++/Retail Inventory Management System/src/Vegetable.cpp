#include "Vegetable.h"

// constructor calls Agricultural constructor first, then sets vitamins
Vegetable::Vegetable(int serial, char row, int shelf, double quantity, int type, int area,
	const std::string& name, int seasons, int suppliers, int vitamins)
	: Agricultural(serial, row, shelf, quantity, type, area, type, name, seasons, suppliers)
	, _vitamins(vitamins)
{
}

Vegetable::~Vegetable()
{
	// no dynamic memory to release
}

// price = Agricultural price + 2 vitamins
double Vegetable::calcPrice(double adFactor) const
{
	double agrPrice = Agricultural::calcPrice(adFactor);
	return agrPrice + (2 * _vitamins);
}

// prints agricultural details first, then adds (vitamins)
void Vegetable::print(std::ostream& os) const
{
	Agricultural::print(os);
	os << "(" << _vitamins << ") ";
}
