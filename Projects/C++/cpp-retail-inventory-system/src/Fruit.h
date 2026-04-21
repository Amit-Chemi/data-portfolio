#pragma once
#include "Agricultural.h"

class Fruit : public Agricultural
{
private:
	int _sugar; // sugar amount per 100g

public:
	// constructor
	Fruit(int serial, char row, int shelf, double quantity, int type, int area, const std::string& name, int seasons, int suppliers, int sugar);

	// destructor
	virtual ~Fruit();

	double calcPrice(double adFactor) const override;
	void print(std::ostream& os) const override;
};

