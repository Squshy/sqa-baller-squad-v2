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
	
	do {
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
				 cout << "\nYour Username or Password were entered incorrectly. Please Try again!\n";
			 }
			
     	}else if(choice.compare(exit) == 0 || choice.compare(Exit) == 0){
     		break;
     	}else if(choice.find("/") != std::string::npos || choice.find(" ") != std::string::npos){
     		ClearScreen();
			 cout << "\nSlashes and Spaces are not Allowed!" << endl;
			
		}else{
			//ClearScreen();
			cout << "\nYou must login before you can access our system" << endl;

		}
	}while(choice.compare(exit) != 0 && choice.compare(Exit) != 0);	
	
}

void Menu(Users user){
	string choice = "";
	const string exit = "logout";
	const string Exit = "Logout";
	Title();
	cout << "\nWelcome " + user.getUserName() + "! Glad to see you are back :)";
	do {
		
		cout << "Enter Command: ";

		getline(cin, choice);

	}while(choice.compare(exit) != 0 && choice.compare(Exit) != 0); 

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


