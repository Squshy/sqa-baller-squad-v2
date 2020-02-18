/**
* Users Function Definition file for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Users.cpp
*/

#include "Users.h"
#include <string>


Users::Users(){}


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

bool Users::ValidateCredentials(){

	//Declarations
	ifstream File;
	string getUser, getPwd, getType;
	float getCred;
	bool exists = false;

	File.open("current_user_accounts_file.txt"); //opening the file
	
	//getting the user info from the file
	while (File >> getUser >> getPwd >> getType >> getCred) {


		if (getUserName().compare(getUser) == 0 && getPassword().compare(getPwd) == 0){
			exists = true;
			setUserType(getType);
			setCredits(getCred);
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

void Users::ChangePassword(){

}

void Users::Create(){

}

void Users::AddCredits(){

}

void Users::ReadUsersFile(){
	
}

