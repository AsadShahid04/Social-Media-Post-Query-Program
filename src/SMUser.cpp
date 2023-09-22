/*
 * SMUser.cpp
 *
 *  Created on: May 15, 2023
 *      Author: asadshahid
 */

#include "SMUser.hpp"
#include <string>
#include <cctype>
#include <climits>

SMUser::SMUser() {
	// TODO Auto-generated constructor stub

}

SMUser::~SMUser() {
	// TODO Auto-generated destructor stub
}

const Date& SMUser::getDateOfMembership() const {
	return dateOfMembership;
}

void SMUser::setDateOfMembership(const Date &dateOfMembership) {
	try {
		this->dateOfMembership = dateOfMembership;
	}
	catch (char* const e) { throw e; }
}

const string& SMUser::getUserFirstName() const {
	return userFirstName;
}

bool SMUser::setUserFirstName(const string &userFirstName) {
	this->userFirstName = userFirstName;
	return true;
}

const string& SMUser::getUserId() const {
	return userID;
}

bool SMUser::setUserId(const string &userId) {
	unsigned int charSize = userId.length();
	bool isValid = false;
	for (int i = 0; i < charSize; i++) {
		if (!isspace(userId[i])) {
			isValid = true;
			break;
		}
	}
	if (userId.empty())
	{
		isValid = false;
	}
	if (!isValid)
	{
		throw "Strings cannot be blank or be empty!";
	}
	else
	{
		this->userID = userId;
	}
	return isValid;
}

const string& SMUser::getUserLastName() const {
	return userLastName;
}

void SMUser::setUserLastName(const string &userLastName) {
	this->userLastName = userLastName;
}
