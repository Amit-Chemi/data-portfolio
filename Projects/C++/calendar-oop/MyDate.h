#pragma once

class MyDate
{
private:

	int _day;
	int _month;
	int _year;
	char* _comment; // Dynamic C-string

public:

	// Constructors & Destructors:
	MyDate();                                                  // Default constructor
	MyDate(int year, int month, int day, const char* comment); // Regular constructor
	MyDate(const MyDate& other);                               // Copy constructor
	~MyDate();                                                 // Destructor
	MyDate& operator=(const MyDate& other);                    // Copy assignment operator

	// Getters:
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	const char* getComment() const;

	// Setters:
	void setMyDate(int year, int month, int day);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setComment(const char* comment);
	
	// Functions:
	void inc();                                 // Advances the date by one day
	void init();                                // Initializes the date to the exercise submission date
	bool isBefore(const MyDate& other) const;   // Check if the date is before or after the given date
	void changeComment(const char* newcomment); // Replaces the current comment with a new one

	// Print:
	void print() const;

};

