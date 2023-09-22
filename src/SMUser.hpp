/*
 * SMUser.hpp
 *
 *  Created on: May 15, 2023
 *      Author: asadshahid
 */

#ifndef SMUSER_HPP_
#define SMUSER_HPP_
#include <climits>
#include <cctype>
#include "Date.hpp"

class SMUser {
public:
	SMUser();
	virtual ~SMUser();
	const Date& getDateOfMembership() const;
	void setDateOfMembership(const Date &dateOfMembership);
	const string& getUserFirstName() const;
	bool setUserFirstName(const string &userFirstName);
	const string& getUserId() const;
	bool setUserId(const string &userId);
	const string& getUserLastName() const;
	void setUserLastName(const string &userLastName);

private:
	string userID;
	string userFirstName;
	string userLastName;
	Date dateOfMembership;

};

#endif /* SMUSER_HPP_ */
