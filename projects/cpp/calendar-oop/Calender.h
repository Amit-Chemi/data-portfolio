#pragma once
#include "MyDate.h"

class Calender
{
private:

	MyDate* _dates[30];  // Static array of 30 pointers to MyDate
	int _occ;         // Number of occupied slots (0�30)

public:

	Calender();                                 // Default constructor
	Calender(const Calender& other);            // Copy constructor
	~Calender();                                // Destructor
	Calender& operator=(const Calender& other); // Copy assignment operator

	void setDate(int num, const MyDate& other); // Set/replace date at index 'num'
	bool isFree(int num) const;                 // True if slot 'num' is empty
	int firstFree() const;                      // First free index, or -1 if none
	bool Insert(const MyDate& other);           // Insert into first free slot (returns success)
	int oldest() const;                         // Index of earliest date, or -1 if none
	int dateNum() const;                        // Number of occupied dates
	void deleteAll();                           // Delete all dates and clear the calendar
	void remove(int num);                       // Delete slot 'num'
	void print() const;                         // Print calendar content
};
