#pragma once
#include "Agricultural.h"

class Vegetable : public Agricultural
{
private:
	int _vitamins; // number of vitamins in the veg

public:
	// constructor
	Vegetable(int serial, char row, int shelf, double quantity, int type, int area, const std::string& name, int seasons, int suppliers, int vitamins);

	// destructor
	virtual ~Vegetable();

	double calcPrice(double adFactor) const override;
	void print(std::ostream& os) const override;
};

