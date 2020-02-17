/**
* Main function for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Users.cpp
*/

#include "Users.h"
#include <string>

/**
* Default Constructor for the Users Class
* */
Users::Users(){}

/**
 * * Users Class Method for Login
*/ 
bool Users::Login(){
	string username = "";
	string password = "";
	bool validation = false;
		
     	cout << "\nUsername: ";
     	cin >> username;
    	cout << "\nPassword: ";
     	cin >> password;
		setUserName(username);
		setPassword(password);
		validation = Users::ValidateCredentials();

		return validation;
     	
}
/**
* Users Class Method for validating their credentials on login
*/ 
bool Users::ValidateCredentials(){

	ifstream File;
	string getUser, getPwd, getType;
	float getCred;

	File.open("current_user_accounts_file.txt"); //opening the file
	bool exists = false;
	//getting the user info from the file
	while (File >> getUser >> getPwd >> getType >> getCred) {
		if (getUserName().compare(getUser) == 0 && getPassword().compare(getPwd) == 0){
			exists = true;
			break;
		}

	}

	File.close(); //closing the file

	if(exists == true){
		return true;
	}else{
		return false;
	}

}


