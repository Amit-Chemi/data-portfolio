#pragma once
#include "Product.h"
#include <string>


class Agricultural : public Product
{
private:
	int _kind;         // 1 (vegetable), 2 (fruit)
	std::string _name; // Product name
	int _seasons;      // numbers of seasons available
    int _suppliers;    // number of suppliers

public:
	// construcor
	Agricultural(int serial, char row, int shelf, double quantity, int type, int area, int kind, const std::string& name,
				 int seasons, int suppliers);

	// destructor
	virtual ~Agricultural();

	// // ensures this functions overrides a base class virtual function
	double calcPrice(double adFactor) const override;
	void print(std::ostream& os) const override;

};

