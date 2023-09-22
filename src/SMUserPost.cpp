/*
 * SMUserPost.cpp
 *
 *  Created on: May 15, 2023
 *      Author: asadshahid
 */

#include "SMUserPost.hpp"
#include <string>
#include <climits>

SMUserPost::SMUserPost() {
	// TODO Auto-generated constructor stub
	this->userID = " ";
	this->dateOfPost = Date();

	this->PostTimeObject.hour = 0;
	this->PostTimeObject.second = 0;
	this->PostTimeObject.minute = 0;

	this->dateOfPost.setYear(10);
	this->dateOfPost.setMonth(10);
	this->dateOfPost.setDay(10);

	this->postText = "Empty!";

}

SMUserPost::~SMUserPost() {
	// TODO Auto-generated destructor stub
}

const Date& SMUserPost::getDateOfPost() const {
	return dateOfPost;
}

void SMUserPost::setDateOfPost(Date &dateOfPost) {
	int day = dateOfPost.getDay();
	int month = dateOfPost.getMonth();
	int year = dateOfPost.getYear();

	Date testDate;
	if (day == 0 || month == 0 || year == 0) {
		throw "Numbers cannot be zero"; }
	else if (testDate.setYear(year) == false) {
		throw "Dates must be valid - Year not set properly!"; }
	else if (testDate.setMonth(month) == false) {
		throw "Dates must be valid - Month not set properly!"; }
	else if (testDate.setDay(day) == false) {
		throw "Dates must be valid - Day not set properly!"; }
	else {
		this->dateOfPost = dateOfPost;
	}
}

const string& SMUserPost::getPostText() const {
	return postText;
}

void SMUserPost::setPostText(const string &postText) {
	unsigned int charSize = postText.length();
	bool isValid = false;
	for (int i = 0; i < charSize; i++) {
		if (!isspace(postText[i])) {
			isValid = true;
			break;
		}
	}
	if (postText.empty())
		{
			isValid = false;
		}
	if (!isValid)
	{
		throw "Strings cannot be blank or be empty!";
	}
	else
	{
		this->postText = postText;
	}
}

const PostTime& SMUserPost::getTimeOfPost() const {
	return PostTimeObject;
}

void SMUserPost::setTimeOfPost(const PostTime &timeOfPost) {
	if (timeOfPost.hour < 0 || timeOfPost.hour > 24)
	{
		cout << "Hour must be valid" << endl;
	}
	if (timeOfPost.minute < 0 || timeOfPost.minute > 60)
	{
		cout << "Minute must be valid" << endl;
	}
	if (timeOfPost.second < 0 || timeOfPost.second > 60)
	{
		cout << "Second must be valid" << endl;
	}
	else {
		PostTimeObject = timeOfPost;
	}
}


string SMUserPost::getUserId() const {
	return userID;
}

bool SMUserPost::setUserId(const string& userId) {
	unsigned int charSize = postText.length();
	bool isValid = false;
	for (int i = 0; i < charSize; i++) {
		if (!isspace(postText[i])) {
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

int SMUserPost::getHour() const {
	return PostTimeObject.hour;
}

bool SMUserPost::setHour(int input_hour) {
	if (input_hour < 0 || input_hour > 23)
		{
			char e[] = {"Hour is not set correctly!"};
			throw e;
			return false;
		}
		else {
			PostTimeObject.hour = input_hour;
			return true;
		}
}

int SMUserPost::getMinute() const {
	return PostTimeObject.minute;
}

bool SMUserPost::setMinute(int input_minute) {
	if (input_minute < 0 || input_minute > 59)
	{
		char e[] = {"Minute is not set correctly!"};
		throw e;
		return false;
	}
	else {
		PostTimeObject.minute = input_minute;
		return true;
	}
}

int SMUserPost::getSecond() const {
	return PostTimeObject.second;
}

bool SMUserPost::setSecond(int user_second) {
	if (user_second < 0 || user_second > 59)
		{
			char e[] = {"Second is not set correctly!"};
			throw e;
			return false;
		}
		else {
			PostTimeObject.second = user_second;
			return true;
		}
}
