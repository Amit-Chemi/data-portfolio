#include "MyDate.h"
#include <iostream>
#include <cstring>
using namespace std;

MyDate::MyDate()
	: _comment(nullptr)       // Initialize pointer to safe value
{
	setMyDate(2020, 1, 1);    // Set default date 
	setComment("No comment"); // Set default comment
}

MyDate::MyDate(int year, int month, int day, const char* comment)
	: _comment(nullptr)          //Initialize pointer before using setComment
{
	setMyDate(year, month, day); // Update full date using setters
	setComment(comment);         // Deep copy the comment
}

MyDate::MyDate(const MyDate& other)
	: _comment(nullptr)  // Start with nullptr to allow delete[] safely
{
	setMyDate(other._year, other._month, other._day); // Copy date fields
	setComment(other._comment);                       // Deep copy the dynamic comment
}

MyDate::~MyDate() 
{
	delete[] _comment; // Free dynamic memory
}

MyDate& MyDate::operator=(const MyDate& other)
{
	if (this == &other)  // Protect against self-assignment
		return *this;
	
	setMyDate(other._year, other._month, other._day); // Copy date
	setComment(other._comment);                       // Deep copy comment
	 
	return *this;  // Allow chained assignment
}

int MyDate::getDay() const
{
	return _day;  // Return day
}

int MyDate::getMonth() const
{
	return _month;  // Return month
}

int MyDate::getYear() const
{
	return _year;  // Return year
}

const char* MyDate::getComment() const
{
	return _comment; // Return pointer to internal C-string
}

void MyDate::setMyDate(int year, int month, int day)
{
	setYear(year);   // Set year
	setMonth(month); // Set month
	setDay(day);     // Set day
}

void MyDate::setDay(int day)
{
	int last_day = 31; // Default max days
	
	if (_month == 2)
		last_day = 28; // February last day

	else if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
		last_day = 30; // 30 days month
	
	if (day >= 1 && day <= last_day)
		_day = day;    // Valid day
	else
		_day = 1;      // Default day
}

void MyDate::setMonth(int month)
{
	if (month >= 1 && month <= 12)
		_month = month; // Valid month
	else
		_month = 1;     // Default month
}

void MyDate::setYear(int year)
{
	if (year > 0)
		_year = year; // Valid year
	else
		_year = 1;    // Default year
}

void MyDate::setComment(const char* comment)
{
	delete[] _comment;   // Free the old comment
	_comment = nullptr;  // Reset pointer

	if (comment != nullptr) {
		_comment = new char[strlen(comment) + 1]; // Allocate memory
		strcpy_s(_comment, strlen(comment) + 1, comment);                // Copy content
	}
}

void MyDate::inc()
{
	// Handle 30 day months
	if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
		if (_day == 30) {
			_day = 1;
			_month = _month + 1;
		}
		else
			_day = _day + 1;
	// Handle February
	else if (_month == 2)
		if (_day == 28) {
			_day = 1;
			_month = 3;
		}
		else
			_day = _day + 1;
	
	// Handle December 
	else if (_month == 12)
		if (_day == 31) {
			_day = 1;
			_month = 1;
			_year = _year + 1;
		}
		else
			_day = _day + 1;

	// Handle 31 day months
	else if (_day == 31) {
		_day = 1;
		_month = _month + 1;
	}
	else
		_day = _day + 1;
}

void MyDate::init()
{
	_day = 4;     // Submission day
	_month = 1;   // Submission month
	_year = 2026; // Submission year
}

bool MyDate::isBefore(const MyDate& other) const
{
	if (_year < other._year)             // Compare year
		return true;

	else if (_year == other._year) {
		if (_month < other._month)       // Compare month
			return true;
		else if (_month == other._month)
			if (_day < other._day)       // Compare day
				return true;
			else
				return false;
		else
			return false;
	}
	else
		return false;
}

void MyDate::changeComment(const char* newcomment)
{
	setComment(newcomment); // Reuse setter for deep copy
}

void MyDate::print() const
{
	cout << _day << "/" << _month << "/" << _year; // Print date
	if (_comment != nullptr)                       
		cout << " " << _comment;                   // Print comment if exists
	
	cout << endl;
}
