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


bool Users::Login(string** users, int userCount){
	string username = "";
	string password = "";
	bool validation = false;
		
     	cout << "\nUsername: ";
     	cin >> username;
    	cout << "\nPassword: ";
     	cin >> password;
		setUserName(username);
		setPassword(password);
		for(int i = 0; i < userCount; i++){
			cout << users[i][0];
			if (getUserName().compare(users[i][0]) == 0 && getPassword().compare(users[i][1]) == 0){
			//exists = true;
			setUserType(users[i][2]);
			setCredits(stof(users[i][3]));
			validation = true;
			break;
		}

		}
	
		return validation;
     	
}

void Users::ChangePassword(){

}

void Users::Create(){

}

void Users::AddCredits(){

}

void Users::ReadUsersFile(){
	
}

