#include "OtherDairy.h"

// constructor: calls Dairy constructor, then copies the names array
OtherDairy::OtherDairy(int serial, char row, int shelf, double quantity, int type, int area,
	const std::string& name, int colors, double fat, int nonDairy, const std::string* names)
	: Dairy(serial, row, shelf, quantity, type, area, type, name, colors, fat), _nonDairy(nonDairy), _ND_names(nullptr)
{
	// allocate and copy ingredient names
	if (nonDairy > 0) {
		_ND_names = new std::string[nonDairy];
		for (int i = 0; i < nonDairy; i++) {
			_ND_names[i] = names[i];
		}
	}
}
// copy constructor: makes a real copy of the dynamic array
OtherDairy::OtherDairy(const OtherDairy& other)
	: Dairy(other), _nonDairy(other._nonDairy), _ND_names(nullptr) {
	if (_nonDairy > 0) {
		_ND_names = new std::string[_nonDairy];
		for (int i = 0; i < _nonDairy; i++) {
			_ND_names[i] = other._ND_names[i];
		}
	}
}

// assignment operator: handles self assignment and copies the dynamic array
OtherDairy& OtherDairy::operator=(const OtherDairy& other) {
	if (this == &other)
		return *this;

	Dairy::operator=(other);

	delete[] _ND_names;
	_ND_names = nullptr;

	_nonDairy = other._nonDairy;

	if (_nonDairy > 0) {
		_ND_names = new std::string[_nonDairy];
		for (int i = 0; i < _nonDairy; i++) {
			_ND_names[i] = other._ND_names[i];
		}
	}
	return *this;
}

// destructor: releases the dynamic array
OtherDairy::~OtherDairy()
{
	delete[] _ND_names;
}

// price = dairy price + 5 non dairy
double OtherDairy::calcPrice(double adFactor) const
{
	double dairyPrice = Dairy::calcPrice(adFactor);
	return dairyPrice + (5 * _nonDairy);
}

// print: dairy print + ingredient list + non dairy
void OtherDairy::print(std::ostream& os) const
{
	Dairy::print(os);
	os << " ";

	for (int i = 0; i < _nonDairy; i++) {
		os << _ND_names[i];
		if (i < _nonDairy - 1)
			os << ", ";
	}
	os << " (" << _nonDairy << ")";
}

