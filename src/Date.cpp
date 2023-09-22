/*
 * Date.cpp
 *
 *  Created on: Mar 24, 2023
 *      Author: asadshahid
 */

#include "Date.hpp"
#include <climits>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Date::Date() {
	// TODO Auto-generated constructor stub
	this->day = 0;			//default constructor
	this->month = 0;		//default constructor
	this->year = 0;			//default constructor

}

Date::~Date() {
	// TODO Auto-generated destructor stub
}

//Get the day
int Date::getDay() {
	return this->day;
}

//Help make sure the day is set to an appropriate value only if year and month have been set already
bool Date::setDay(int Day) {

	if (this->getYear() == 0) {
		cout << "Error - Year is currently set to 0, please set it to an appropriate value" << endl;
		return false;
	} else if (getMonth() == 0) {
		cout << "Error - Month is currently set to 0, please set it to an appropriate value. Day is now set to 0." << endl;
		this->day = 0;
		return false;
	} else if (Day < 1 || Day > numDaysPerMonth[getMonth()]) {
		cout << "Error - Day cannot be less than 1 or greater than " << numDaysPerMonth[this->getMonth()] << " for the month of " << intToNamePerMonth[this->getMonth()] << endl;
		return false;
	} else {
		this->day = Day;
		return true;
	}
}

//Get the month
int Date::getMonth() {
	return this->month;
}

//Help make sure the month is set to an appropriate value only if year has been set already
bool Date::setMonth(int Month) {
	if (this->getYear() == 0) {
		cout << "Error - You have to set the year first before setting the month!" << endl;
		return false;
	} else if (Month < 1) {
		cout << "Error - You cannot set the month to be less than 1" << endl;
		return false;
	} else if (Month > 12) {
		cout << "Error - You cannot set the month to be over 12" << endl;
		return false;
	} else {
		this->month = Month;
		return true;
	}
}

//get the year
int Date::getYear() {
	return this->year;
}

//Help make sure the year is set to an appropriate value
bool Date::setYear(int Year) {
	if (Year < 1 || Year > 9999) {
		cout << "Error - You cannot set the year to be over 9999 or less than 1" << endl;
		return false;
	} else {
		this->year = Year;
		return true;
	}
}


//Help add one day from the date
bool Date::operator++(int x) {
	if (this->month == 0 || this->day == 0 || this->year == 0) {
		return false;
	} else {
		if ((this->getDay() + 1) > numDaysPerMonth[this->getMonth() - 1]) {
			if ((this->month + 1) > 12) {
				this->setYear(this->getYear() + 1);
				this->setMonth(1);
			} else {
				this->setMonth(this->getMonth() + 1);
			}
			this->setDay(1);
		} else {
			this->setDay(this->day + 1);
		}
		return true;
	}
}

//Help subtract one day from the date
bool Date::operator--(int x) {
	if (this->month == 0 || this->day == 0 || this->year == 0) {
		return false;
	} else {
		if ((this->day - 1) == 0) {
			if ((this->month - 1) == 0) {
				this->setYear(this->year - 1);
				this->setMonth(12);
				this->setDay(int(numDaysPerMonth[this->month - 1]));
			} else {
				this->setMonth(this->month - 1);
				this->setDay(numDaysPerMonth[int(this->month - 2)]);
			}
		} else {
			this->setDay(int(this->day - 1));
		}
		return true;
	}
}
//Help see if the left date is = to the right date
bool Date::operator==(Date &rightDate) {
	return (this->month == rightDate.getMonth()
			&& this->day == rightDate.getDay()
			&& this->year == rightDate.getYear());
}

//Will allow you to set one date object to equal the same day, month, and year as the other date object
void Date::operator=(const Date &rightDate) {
	this->day = rightDate.day;
	this->month = rightDate.month;
	this->year = rightDate.year;
}

//Help print out the date in the format mm/dd/yyyy
ostream& operator <<(ostream &output, const Date &date) {
//	int dayToPrint = date.day;
//	int monthToPrint = date.month;
//
//	if (dayToPrint < 10 && monthToPrint < 10) {
//
//		output << setw(2) << setfill('0') << monthToPrint << '/' << dayToPrint << '/' << date.year;
//	}
//	else if (dayToPrint < 10) {
//		output << setw(2) << setfill('0') << monthToPrint << '/' << dayToPrint << '/' << date.year;
//	}
//	else if (monthToPrint < 10) {
//		output << setw(2) << setfill('0') << monthToPrint << '/' << dayToPrint << '/' << date.year;
//	}
//	else {
//		output << monthToPrint << '/' << dayToPrint << '/' << date.year;
//	}
	output << date.month << '/' << date.day << '/' << date.year;
	return output;
}

string Date::getDate(Date &date) {
	string result = (to_string(this->year) + '/' + to_string(this->month) + '/' + to_string(this->day));
	return result;
}

//Help see if the left date is < than the right date
bool Date::operator<(Date &rightDate) {
	if (this->getYear() < rightDate.getYear()) {
		return true;
	} else if (this->getYear() == rightDate.getYear()) {
		if (this->getMonth() < rightDate.getMonth()) {
			return true;
		} else if (this->getDay() < rightDate.getDay()) {
			return true;
		}
	} else {}
	return false;
}

//Help see if the left date is > than the right date
bool Date::operator>(Date &rightDate) {
	if (this->getYear() > rightDate.getYear()) {
		return true;
	} else if (this->getYear() == rightDate.getYear()) {
		if (this->getMonth() > rightDate.getMonth()) {
			return true;
		} else if (this->getDay() > rightDate.getDay()) {
			return true;
		}
	} else {}
	return false;
}
