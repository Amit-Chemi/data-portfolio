#pragma once
#include "Dairy.h"
#include <string>

class OtherDairy : public Dairy
{
private:
	int _nonDairy;          // number of "Pareve" non dairy ingridients
	std::string* _ND_names; // dynamic array of ND (non dairy) ingridients names

public:
	// constructor
	OtherDairy(int serial, char row, int shelf, double quantity, int type, int area, const std::string& name,
			   int colors, double fat, int nonDairy, const std::string* ND_names);

	// we must implement copy constructor and operator= since this class uses a dynamic array
	OtherDairy(const OtherDairy& other);
	OtherDairy& operator=(const OtherDairy& other);
	
	// destructor
	virtual ~OtherDairy();

	double calcPrice(double adFactor) const override;
	void print(std::ostream& os) const override;
};

