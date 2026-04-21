#include "Calender.h"
#include <iostream>
using namespace std;

Calender::Calender()
{
	for (int i = 0; i < 30; i++)
		_dates[i] = nullptr;  // Initialize all pointers to null
	_occ = 0;              // No occupied slots
}

Calender::Calender(const Calender& other)
{
	for (int i = 0; i < 30; i++)
		_dates[i] = nullptr;

	_occ = 0;

	for (int i = 0; i < 30; i++)
		if (other._dates[i] != nullptr) {
			_dates[i] = new MyDate(*other._dates[i]); // Deep copy
			_occ++;                                   // Count occupied
		}
}

Calender::~Calender()
{
	deleteAll();  // Free all allocated MyDate objects
}

Calender& Calender::operator=(const Calender& other)
{
	if (this == &other)  // Protect against self assignment
		return *this;
	
	deleteAll();         // Clear current content

	_occ = other._occ;
	
	// Deep copy
	for (int i = 0; i < 30; i++)
		if (other._dates[i] != nullptr)
			_dates[i] = new MyDate(*other._dates[i]);
		else
			_dates[i] = nullptr;
	
	return *this;
}

void Calender::setDate(int num, const MyDate& other)
{
	if (num < 0 || num >= 30)
		return;                       // Invalid index
	
	if (_dates[num] != nullptr)
		delete _dates[num];           // Replace existing date
	else
		_occ++;                       // Occupy a new slot

	_dates[num] = new MyDate(other);  // Deep copy
}

bool Calender::isFree(int num) const
{
	if (num < 0 || num >= 30)
		return false;                 // Invalid index treated as not free

	return (_dates[num] == nullptr);  // Free if pointer in null
}

int Calender::firstFree() const
{
	for (int i = 0; i < 30; i++)
		if (_dates[i] == nullptr)
			return i; // First empty slot
	
	return -1;        // No free slots 
}

bool Calender::Insert(const MyDate& other)
{
	int open_slot = firstFree();
	
	if (open_slot == -1)
		return false;                       // No space

	_dates[open_slot] = new MyDate(other);  // Deep copy
	_occ++;                                 // Update occupied counter 
	return true;                            // Insert succeeded
}

int Calender::oldest() const
{
	int old = -1;         // Index of oldest date (none yet)

	for (int i = 0; i < 30; i++)
		if (_dates[i] != nullptr)
			if (old == -1 || _dates[i]->isBefore(*_dates[old]))
				old = i;  // Found an older date
	
	return old;           // -1 if Calender is empty
}

int Calender::dateNum() const
{	
	return _occ;  // Number of occupied slots
}

void Calender::deleteAll()
{
	for (int i = 0; i < 30; i++) {
		delete _dates[i];     // Safe even if nullptr
		_dates[i] = nullptr;  // Avoid dangling pointer
	}
	_occ = 0;                 // Reset counter
}

void Calender::remove(int num)
{
	if (num < 0 || num >= 30)
		return;                // Invalid index

	if (_dates[num] != nullptr) {
		delete _dates[num];    // Free the date
		_dates[num] = nullptr; // Mark skot as empty
		_occ--;                // Update counter
	}
}

void Calender::print() const
{
	for (int i = 0; i < 30; i++)
		if (_dates[i] != nullptr) {
			cout << "Slot " << i << ": ";
			_dates[i]->print();  // Print date content
		}
} 
