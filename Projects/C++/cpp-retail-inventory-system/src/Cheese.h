#pragma once
#include "Dairy.h"
#include <string>

class Cheese : public Dairy
{
private:
	int _extras; // number of extras for the cheese

public:
	// constructor
	Cheese(int serial, char row, int shelf, double quantity, int type, int area, const std::string& name, int colors, double fat, int extras);

	// destructor
	virtual ~Cheese();

	double calcPrice(double adFactor) const override;
	void print(std::ostream& os) const override;
};


