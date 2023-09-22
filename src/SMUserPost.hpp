/*
 * SMUserPost.hpp
 *
 *  Created on: May 15, 2023
 *      Author: asadshahid
 */

#ifndef SMUSERPOST_HPP_
#define SMUSERPOST_HPP_
#include <string>
#include <cctype>
#include <climits>
#include "Date.hpp"

//a structure named PostTime defined in your SMUserPost class
struct PostTime
{
	int hour;    //an integer using 24-hour format
	int minute;  //an integer
	int second;  //an integer

};

class SMUserPost {
public:

	SMUserPost();
	virtual ~SMUserPost();
	const Date& getDateOfPost() const;
	void setDateOfPost(Date &dateOfPost);
	const string& getPostText() const;
	void setPostText(const string &postText);
	bool setHour(int input_hour);
	int getHour() const;
	int getMinute() const;
	bool setMinute(int input_minute);
	int getSecond() const;

	const PostTime& getTimeOfPost() const;
	void setTimeOfPost(const PostTime &timeOfPost);

	string getUserId() const;
	bool setUserId(const string& userId);
	bool setSecond(int user_second);



private:
	string userID;
	Date dateOfPost;
	string postText;
	PostTime PostTimeObject; //need getter and setter

};

#endif /* SMUSERPOST_HPP_ */
