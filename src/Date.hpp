/*
 * Date.hpp
 *
 *  Created on: Mar 24, 2023
 *      Author: asadshahid
 */

#ifndef DATE_HPP_
#define DATE_HPP_
#include <climits>
#include <string>
#include <vector>
#include <ostream>
#include <iostream>

using namespace std;

//number of days in each month (index value = number of the month + 1), for a common year
const int numDaysPerMonth[12] =
		{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//an array of the names of the month from month 0 (January) to month 11 (December)
const string intToNamePerMonth[12] = { "January", "February", "March", "April",
		"May", "June", "July", "August", "September", "October", "November",
		"December" };

class Date {
public:
	Date();
	virtual ~Date();

	//getters and setters prototypes
	int getDay();
	bool setDay(int Day);
	int getMonth();
	bool setMonth(int Month);
	int getYear();
	bool setYear(int Year);
	string getDate(Date &date);

	//Overloading the operators prototypes
	bool operator++(int x);
	bool operator--(int x);
	bool operator==(Date &rightDate);
	friend ostream& operator <<(ostream &output, const Date &date);
	bool operator<(Date &rightDate);
	bool operator>(Date &rightDate);
	void operator=(const Date &rightDate);

private:
	int day;
	int month;
	int year;
};

#endif /* DATE_HPP_ */
