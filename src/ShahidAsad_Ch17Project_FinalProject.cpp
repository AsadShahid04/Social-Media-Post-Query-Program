//*******
//Project Name: ShahidAsad_Ch17Project_FinalProject.cpp

//Project Description:

//Project Author: Shahid, Asad

//Is this an extra credit Project:  No

//Date completed: 05/15/2023

//Operating system used: OSx

//IDE Used:  Eclipse
//*******

#include <iostream>
#include <climits>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <cctype>
#include <string>
#include "SMUser.hpp"
#include "SMUserPost.hpp"
#include "ErrorClass.hpp"
#include "Date.hpp"

using namespace std;

//a structure for errors (NOT USING)
struct ErrorThrown {
	string msg;
	int rerturnCode;
	string instructions;

};

//a function which helps with cin.ignore() and cin.clear(). We call it after a CIN into a numeric variable
void clearCIN() {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}


int main() {
	map<string, SMUser*> mySMUsersMap;	//a Map of SMUser pointers with the key for that map being the User ID in the SMUser class
	map<string, SMUser*>::iterator sm_MapIT;
	pair<string, SMUser*> sm_Map;
	SMUser *userPtr;
	SMUserPost *userPostPtr;
//	userPtr = new SMUser();					//a dummy SMUser used to hold the information we are scraping from the csv file, and later to pass into the mySMUsersMap


	ifstream inputFile;
	inputFile.open("SMUsers.csv");
	if (!inputFile) {
		cout << "Error - Cannot find the file SMUsers.csv" << endl;
		return 1;//If the file doesn’t exist, display an error message and end the program
	}

	else {
		ofstream outputFile;
		outputFile.open("UserErrors.txt");

		if (!outputFile) {
			cout << "Error - Cannot find the file UserErrors.txt" << endl;
		}
		else {
			string tempString;
			string inputRecord;
			while (!inputFile.eof()) {

//				SMUser *userPtr;
				userPtr = new SMUser();					//a dummy SMUser used to hold the information we are scraping from the csv file, and later to pass into the mySMUsersMap

				//bool flag;							//a bool checking if we have any errors or not within the data
				Date tempDate;
				getline(inputFile, inputRecord);

				if (inputRecord.empty()) {
					continue;
				} else {}

				stringstream strStream(inputRecord);
				getline(strStream, tempString, ',');
				try {
					userPtr->setUserId(tempString);
//					if (!userPtr->setUserId(tempString)) {
//						cout << "Error! Need to Throw!" << endl;
//						flag = true;
//						throw (tempString);
//					} else {}
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}

				getline(strStream, tempString, ',');
				try {
					userPtr->setUserFirstName(tempString);
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}
//				if (!userPtr->setUserFirstName(tempString)) {
//					cout << "Error! Need to Throw!" << endl;
//					flag = true;
//				} else {}

				getline(strStream, tempString, ',');
				try {
					userPtr->setUserLastName(tempString);
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}
//				if (!userPtr->setUserLastName(tempString)) {
//					cout << "Error! Need to Throw!" << endl;
//					flag = true;
//				} else {}

				getline(strStream, tempString, ',');
				try {
					tempDate.setYear(stoi(tempString));
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}

				getline(strStream, tempString, ',');
				try {
					tempDate.setMonth(stoi(tempString));
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}

				getline(strStream, tempString, ',');
				try {
					tempDate.setDay(stoi(tempString));
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}

				try {
					userPtr->setDateOfMembership(tempDate);
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}

				//mySMUsersMap.insert(make_pair(userPtr->getUserId(), userPtr));							//Inserting into map
				if (mySMUsersMap.insert(make_pair(userPtr->getUserId(), userPtr)).second == false)		//If
				{
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: User ID already exists. Cannot place into map." << endl;
					outputFile << "-------------------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
					delete userPtr;
					userPtr = nullptr;
				}
				else {
					//cout << "User inserted correctly into SMUsers Map!" << endl;
				}
			}
		    inputFile.close();
		    outputFile.close();
		    delete userPtr;
		    userPtr = nullptr;
		}
	}

	inputFile.close();

	//READING THE SMUsersPosts.csv FILE INTO MULTI-MAP of SMUserPosts POINTERS//
	multimap<string, SMUserPost*> mySMUserPostsMultiMap;	//a Multi Map of SMUserPosts pointers with the key for that map being the User ID in the SMUser class
	multimap<string, SMUserPost*>::iterator sm_PostsMultiMapIT;
	pair<string, SMUser*> sm_MultiMap;


	inputFile.open("SMUserPosts.csv");
	if (!inputFile) {
		cout << "Error - Cannot find the file SMUserPosts.csv" << endl;
		return 1;//If the file doesn’t exist, display an error message and end the program
	} else {
		//cout << "Opened SMUsersPosts.csv Properly!" << endl;

		ofstream outputFile;
		outputFile.open("PostErrors.txt");
		if (!outputFile) {
			cout << "Error - Cannot find the file PostErrors.txt" << endl;
		}
		else {
			string tempString;
			string inputRecord;

			while (!inputFile.eof()) {

//				SMUserPost *userPostPtr;		//a dummy SMUserPosts used to hold the information we are scraping from the csv file, and later to pass into the mySMUserPostsMultiMap
				userPostPtr = new SMUserPost();
				Date anotherTempDate;
				int temp_year_holder;

				//bool flag;										//a bool checking if we have any errors or not within the data
				getline(inputFile, inputRecord);

				if (inputRecord.empty()) {
					continue;
				} else {}

				stringstream strStream(inputRecord);

				getline(strStream, tempString, ',');

				try {
					userPostPtr->setUserId(tempString);
//					cout << "UserID: " << tempString << endl;
//					if (!userPtr->setUserId(tempString)) {
//						cout << "Error! Need to Throw!" << endl;
//						flag = true;
//						throw (tempString);
//					} else {}
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}

				//Get the Date of the Post:
				getline(strStream, tempString, ',');

				try {
					temp_year_holder = stoi(tempString);
					anotherTempDate.setYear(stoi(tempString));

				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}

				getline(strStream, tempString, ',');

				try {
					anotherTempDate.setMonth(stoi(tempString));
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}

				getline(strStream, tempString, ',');

				try {
					anotherTempDate.setDay(stoi(tempString));
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}

				try {
					userPostPtr->setDateOfPost(anotherTempDate);
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}


				getline(strStream, tempString, ',');

				try {
					userPostPtr->setHour(stoi(tempString));
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}

				getline(strStream, tempString, ',');

				try {
					userPostPtr->setMinute(stoi(tempString));
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}

				getline(strStream, tempString, ',');

				try {
					userPostPtr->setSecond(stoi(tempString));
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
				}

				getline(strStream, tempString, ',');

				try {
					userPostPtr->setPostText(tempString);
				}
				catch (char* const e) {
					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: " << e << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;

				}

				auto userIterator = mySMUsersMap.find(userPostPtr->getUserId());
				if (userIterator != mySMUsersMap.end()) {
					mySMUserPostsMultiMap.insert(make_pair(userPostPtr->getUserId(), userPostPtr));
				}
				else {

					outputFile << "ERROR --> User Info Below <-- ERROR" << endl;
					outputFile << "===================================" << endl;
					outputFile << inputRecord << endl;
					outputFile << "ERROR MESSAGE: User does not exist in the SMUser Map." << endl;
					outputFile << "-----------------------------------------------------" << endl;
					outputFile << endl;
					outputFile << endl;
					delete userPostPtr;
					userPostPtr = nullptr;
					//outputFile << "User ID w/ Year:" << anotherTempDate.getYear() << " with an ID: " << userPostPtr->getUserId() << " does not exist in the SMUser Map." << '\t' << "Post: " << userPostPtr->getPostText() << endl;
				}
				//sm_MapIT = mySMUsersMap.insert(make_pair(userPostPtr->getUserId(), userPostPtr));										//Inserting into multi-map

//				if (sm_MapIT.second == false)				//If
//				{
//					outputFile << inputRecord << endl;
//					outputFile << "User ID already exists. Cannot place into map." << endl;
//				}
//				else {
//					cout << "User inserted correctly." << endl;
//				}
			}
		    inputFile.close();
		    outputFile.close();

		}
	}



char userInput = '\0';
while (userInput != '5') {
	cout << endl;
	cout << "Main Menu" << endl;
	cout << "---------" << endl;
	cout << "1. Display All Users" << endl;
	cout << "2. Display a Specific User" << endl;
	cout << "3. Display all Posts" << endl;
	cout << "4. Display Posts from a Specific User" << endl;
	cout << "5. Exit the program" << endl;
	cout << "Please pick one: ";
	cin >> userInput;
	clearCIN();

	switch (userInput) {
		case '1': {
			/*
			When the user selects option #1, in a range-based for loop, print the user ID, User
			Name (both), Date of membership (using your Date classes operator<< overload
			function) and total number of posts which the user has (from the Multi-Map) in
			a nicely formatted report (using iomanip) and go back to the main menu.
			 */

			//cout << "Range Based For Loop Version: " << endl;

			cout << "All Users:" << endl;
			cout << "        --------------------------------------------------------------------------------------------        " << endl;
			cout << setw(15) << "User ID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(25) << "Date of Membership" << setw(30) << "Total Number of Posts:" << endl;
			cout << "        --------------------------------------------------------------------------------------------        " << endl;

			for (auto x: mySMUsersMap) {
				int postCount = mySMUserPostsMultiMap.count(x.second->getUserId());		//counting the number of objects in the mySMUserPostsMultiMap with the same userID
				cout << setw(15) << right << x.second->getUserId()
				 << setw(15) << x.second->getUserFirstName()
				 << setw(15) << x.second->getUserLastName()
				 << setw(13) << x.second->getDateOfMembership()
				 << setw(25) << postCount << endl;
			}
			 cout << endl;
			 cout << endl;
			break;
		}
		case '2': {
			/*
			 When the user select option #2:
				1. Ask the user to type an SMUser ID. If that ID does not exist in the SMUser map, display an error message and go back to the menu
				2. If the user does exist in the SMUser map, print the same information for that user as you did for all users when option #1 was selected from the menu
				3. Go back to the main menu
			 */

			string user_input_for_ID;
			cout << "Please enter a SMUser ID: ";
			getline(cin, user_input_for_ID);

			sm_MapIT = mySMUsersMap.find(user_input_for_ID);
			if (sm_MapIT != mySMUsersMap.end())
			{
				SMUser* foundUser = sm_MapIT->second;
				int postCount = mySMUserPostsMultiMap.count(sm_MapIT->second->getUserId());
				cout << "Showing Information Regarding To " << user_input_for_ID << ": " << endl;
				cout << "        --------------------------------------------------------------------------------------------        " << endl;
				cout << setw(15) << right << "User ID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(25) << "Date of Membership" << setw(30) << "Total Number of Posts:" << endl;
				cout << "        --------------------------------------------------------------------------------------------        " << endl;

				cout << setw(15) << right << sm_MapIT->second->getUserId()
				 << setw(15) << sm_MapIT->second->getUserFirstName()
				 << setw(15) << sm_MapIT->second->getUserLastName()
				 << setw(13) << sm_MapIT->second->getDateOfMembership()
				 << setw(25) << postCount << endl;
			}
			else {
				cout << "Sorry, user not found!" << endl;
			}

			cout << endl;
			cout << endl;
			break;
		}
		case '3': {
			/*
			 When the user selects option #3, in a range-based for loop, print the user ID, date
			of (using your Date’s overloaded operator<< function), time of and the text of
			the post in a nicely formatted report (using iomanip).
			 */
			cout << "Displaying All Posts: " << endl;
			cout << "        --------------------------------------------------------------------------------------------------------------------        " << endl;
			cout << setw(15) << "User ID" << setw(25) << "Date of Post" << setw(20) << "Time Of Post" << setw(40) << "Post" << endl;
			cout << "        --------------------------------------------------------------------------------------------------------------------        " << endl;

			for (auto x: mySMUserPostsMultiMap) {
				cout << setw(15) << right << x.second->getUserId()
				 << setw(15) << x.second->getDateOfPost()
				 << setw(15) << x.second->getHour() << ":" << x.second->getMinute() << ":" << x.second->getSecond()
				 << setw(65) << right << x.second->getPostText() << endl;
			}

			cout << endl;
			cout << endl;
			break;
		}
		case '4': {
			string user_input_for_ID;
			cout << "Please enter a SMUser ID: ";
			getline(cin, user_input_for_ID);

			sm_MapIT = mySMUsersMap.find(user_input_for_ID);
			if (sm_MapIT != mySMUsersMap.end())
			{
				int postCount = mySMUserPostsMultiMap.count(sm_MapIT->second->getUserId());
				cout << "Showing Information Regarding To " << user_input_for_ID << ": " << endl;;
				cout << "=================================";
				for (int i = 0; i <= (sm_MapIT->second->getUserId()).length(); i++)
				{
					cout << "=";
				}
				cout << endl;
				cout << "        -------------------------------------------------------------------        " << endl;
				cout << setw(15) << right << "User ID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(30) << "Total Number of Posts:" << endl;
				cout << "        --------------------------------------------------------------------        " << endl;

				cout << setw(15) << right << sm_MapIT->second->getUserId()
				 << setw(15) << sm_MapIT->second->getUserFirstName()
				 << setw(15) << sm_MapIT->second->getUserLastName()
				 << setw(25) << postCount << endl;

				//Retrieve range of posts for the user ID using equal_range()
				auto postRange = mySMUserPostsMultiMap.equal_range(sm_MapIT->second->getUserId());

				//Check if the range is empty and print "No Posts Found" if it is
				if (postRange.first == postRange.second) {
			    	cout << endl;
			    	cout << endl;
				    cout << "No Posts Found" << endl;
				} else {
					cout << endl;
					cout << endl;
					cout << "All the Posts from userID: " << sm_MapIT->second->getUserId() << endl;
					cout << "==========================";
					for (int i = 0; i <= (sm_MapIT->second->getUserId()).length(); i++)
					{
						cout << "=";
					}
			    	cout << endl;
			    	cout << endl;
				    if (postRange.first == postRange.second) {
				    	cout << "No Posts Found" << endl;
				    }
				    else {
				    	//Iterate over the range and print the posts in a nicely formatted report
						for (auto postIterator = postRange.first; postIterator != postRange.second; postIterator++) {
							cout << "--->" << setw(10) << (*postIterator).second->getPostText() << endl;
						}
				    }
				}
			}
			else {
				cout << "Sorry, user not found!" << endl;
			}

			cout << endl;
			cout << endl;
			break;
		}
		case '5': {
//			cout << "Message User Errors Log:" << endl;
//			//TODO: print log here!
//
//			cout << "Message Posting Errors Log:" << endl;
//			//TODO: print log here!
//
//			cout << endl;
//			cout << endl;
//			cout << "Program ending, have a nice day!" << endl;
//			inputFile.close();
//			//outputFile.close(); I believe it closes on itself when this ofstream gets out of its scope. The destructor will close it.



			//Iterate through the SMUserPostMultiMap and delete each SMUserPost pointer
			for (auto it = mySMUserPostsMultiMap.begin(); it != mySMUserPostsMultiMap.end(); it++) {
				delete it->second;
				it->second = nullptr;
			}

			//Iterate through the SMUserMap and delete each SMUser pointer
			for (auto it = mySMUsersMap.begin(); it != mySMUsersMap.end(); it++) {
			    delete it->second;
			    it->second = nullptr;
			}

			//Clear both the SMUserMap and the SMUserPostMultiMap
			mySMUsersMap.clear();
			mySMUserPostsMultiMap.clear();

			cout << endl;
			cout << endl;

			//Open and display errors from UserErrors.txt
			ifstream userErrorsFile;
			userErrorsFile.open("UserErrors.txt");
			if (!userErrorsFile.fail()) {
			    string error;
			    cout << "Message User Errors Log:" << endl;
			    cout << "========================" << endl;
			    while (!userErrorsFile.eof()) {
			    	getline(userErrorsFile, error);
			        cout << error << endl;
			    }
			} else {
			    cout << "Error - Unable to open UserErrors.txt" << endl;
			}


			cout << endl;
			cout << endl;

			//Open and display errors from Posterrors.txt
			ifstream postErrorsFile;
			postErrorsFile.open("PostErrors.txt");
			if (!postErrorsFile.fail()) {
				string error;
				cout << "Message Posting Errors Log:" << endl;
				cout << "===========================" << endl;
				while (!postErrorsFile.eof()) {
					getline(postErrorsFile, error);
					cout << error << endl;
				}
			} else {
				cout << "Error - Unable to open PostErrors.txt" << endl;
			}

			userErrorsFile.close();
			postErrorsFile.close();

			cout << endl;
			cout << endl;

			//Print farewell message
			cout << "Program ending. Have a nice day!" << endl;
			break;
		}
		default: {
			cout << "* Error: Invalid menu choice, please try again..." << endl;}

		cout << endl;
		cout << endl;
		}//switch
	}

} // main
