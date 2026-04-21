#include <iostream>
#include "MyDate.h"
#include "Calender.h"
using namespace std;

int main() 
{
	// Create dates
	MyDate d1(2026, 1, 29, "OOP");
	MyDate d2(2000, 5, 15, "Date of birth");
	MyDate d3;      // Default date
	MyDate d4(d1);  // Copy constructor

	// Print dates
	cout << "Dates:" << endl;
	d1.print();
	d2.print();
	d3.print();
	d4.print();
	cout << endl;

	// Create calendar
	Calender cal;

	// Insert dates
	cal.Insert(d1);
	cal.Insert(d2);
	cal.Insert(d3);

	cout << "Calender after insertions:" << endl;
	cal.print();
	cout << endl;

	// Test oldest
	int old = cal.oldest();
	if (old != -1) {
		cout << "Oldest date is in slot " << old << ":" << endl;
		cal.setDate(old, d2);  // Replace date using setDate
		cal.print();
	}
	cout << endl;

	// Test remove
	cal.remove(1);
	cout << "Calender after removing slot 1:" << endl;
	cal.print();
	cout << endl;

	// Test copy assignment
	Calender cal2;
	cal2 = cal;

	cout << "Copied calender:" << endl;
	cal2.print();
	cout << endl;

	// Test deleteAll
	cal.deleteAll();
	cout << "Original calender after deleteAll:" << endl;
	cal.print();

	if (cal.dateNum() == 0)
		cout << "(calendar is empty)" << endl;

	return 0;
}
