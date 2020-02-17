/**
* Main function for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @since January 24, 2020
* @version  1.0
* @name main.cpp
*/

#include <iostream>       
#include <istream>
#include <iomanip> 		// for output formatting
#include <stdexcept>	// for invalid_argument
#include <sstream>		// for stringstream
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <limits>
#include "Users.h"

using namespace std;

void Home(Users);
void Menu(Users);
void Title();
void PressEnterToExit();
void ClearScreen();
string error = "";

int main() {
	
	//Declarations
	Users user;

try
{
	
	Home(user);
	PressEnterToExit();	
	
}
// to catch the possible exceptions
catch(const exception& ex) 
	{
		cerr << ex.what(); // display the exception message.
	}
	cout << endl << endl;	
	
	return 0;
}

void Home(Users user){
	
	string choice = "";
	const string exit = "exit";
	const string Exit = "Exit";
	const string transactionlogin = "login";
	const string transactionLogin = "Login";
	bool login;
	bool ifExit = true;
	
	while(ifExit == true){
		Title();
		cout << "\nPlease Type login or exit!";
		cout << "\nEnter Command: ";
		getline(cin, choice);
	
	    if(choice.compare(transactionlogin) == 0 || choice.compare(transactionLogin) == 0){
			ClearScreen();
			Title();
     		login = user.Login();
			 if(login == true){
				 Menu(user);
				 ClearScreen();
			 }else{
				 ClearScreen();
				 error = "\nYour Username or Password were entered incorrectly. Please Try again!\n";
			 }
			
     	}else if(choice.compare(exit) == 0 || choice.compare(Exit) == 0){
     		ifExit = false;
     	}else if(choice.find("/") != std::string::npos || choice.find(" ") != std::string::npos){
     		ClearScreen();
			error = "\nSlashes and Spaces are not Allowed!\n";
			
		}else{
			//ClearScreen();
			error = "\nYou must login before you can access our system\n";
		}
		cout << error;
	}	
	
}

void Menu(Users user){
	string choice = "";
	const string exit = "logout";
	const string Exit = "Logout";
	bool ifLogout = true;
	std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
	Title();
	cout << "\nWelcome " + user.getUserName() + "! Glad to see you are back :)";
	while(ifLogout == true){
		
		
		cout << "\nEnter Command: ";
		getline(cin, choice);

		if(choice.compare(exit) == 0 || choice.compare(Exit) == 0){
			ifLogout = false;
		}

	} 

}

void PressEnterToExit()
  {
  	std::cout << "\nPress ENTER to exit... " << flush;
  	std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
  }

void ClearScreen()
{
	cout << string(100, '\n');
}
  
void Title(){

	cout << "==========================================" << endl
		 	 << "      SQA Baller Squad Auction House" << endl
		 	 << "==========================================" << endl;

}


