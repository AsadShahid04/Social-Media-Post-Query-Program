/*
 * ErrorClass.hpp
 *
 *  Created on: Apr 17, 2023
 *      Author: asadshahid
 */

#ifndef ERRORCLASS_HPP_
#define ERRORCLASS_HPP_
#include <string>
#include <climits>

class ErrorClass {
public:
	ErrorClass();
	virtual ~ErrorClass();

	std::string msg;
	int returnCode;
	std::string instructions;

};

#endif /* ERRORCLASS_HPP_ */
