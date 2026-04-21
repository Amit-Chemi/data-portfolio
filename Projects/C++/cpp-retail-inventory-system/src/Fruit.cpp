#include "Fruit.h"

// constructor calls Agricultural constructor first, then sets sugar
Fruit::Fruit(int serial, char row, int shelf, double quantity, int type, int area,
	const std::string& name, int seasons, int suppliers, int sugar)
	: Agricultural(serial, row, shelf, quantity, type, area, type, name, seasons, suppliers)
	, _sugar(sugar)
{
}

Fruit::~Fruit()
{
	// no dynamic memory to release
}

// price = Agricultural price + 1/2 sugar
double Fruit::calcPrice(double adFactor) const
{
	double agrPrice = Agricultural::calcPrice(adFactor);
	return agrPrice + (0.5 * _sugar);
}

// prints agricultural details first, then adds (sugar)
void Fruit::print(std::ostream& os) const
{
	Agricultural::print(os);
	os << "(" << _sugar << ") ";
}

