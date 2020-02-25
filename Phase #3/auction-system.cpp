/**
* Main Class for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @since January 24, 2020
* @version  1.0
* @name main.cpp
*/

#include <iostream>       
#include <istream>
#include <iomanip> 		
#include <stdexcept>	
#include <sstream>		
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <limits>
#include <fstream>
#include "Users.h"

using namespace std;

void Home(Users);
void readInitialFiles(string, string);
void Menu(Users);
void Title();
void PressEnterToExit();
void ClearScreen();
string error = "";
string currentAccounts = "";
string availableItems = "";
string trans = "";
string** accounts;
string** items; 

/**
 * Main Function Definition
 */ 
int main(int argc, char *argv[]) {
	
	//Declarations
	Users user;
	if (argc != 4){
		printf("You need 3 arguments to start the program\n");
	}else{
		currentAccounts = argv[1];
		availableItems = argv[2];
		trans = argv[3];
	}

try
{
	readInitialFiles(currentAccounts, availableItems);
	//Home(user);
	//PressEnterToExit();	
	
}
// to catch the possible exceptions
catch(const exception& ex) 
	{
		cerr << ex.what(); // display the exception message.
	}
	cout << endl << endl;	
	
	return 0;
}

/**
 * Home screen when someone first comes on to the application
 * It will ask the user to login or exit the application
 */ 
void Home(Users user){
	
	string choice = "";
	const string exit = "exit";
	const string Exit = "Exit";
	const string transactionlogin = "login";
	const string transactionLogin = "Login";
	bool login;
	bool ifExit = true;
	
	while(ifExit == true){
		
		
		cout << error;
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
			if(error.empty()){
				error = "\nYou must login before you can access our system\n";
			}
		}
		ClearScreen();
		
	}	
	
}

/**
 * Function for after the user has logged in showing the menu screen 
 * This is where the user will enter in transactions and navigate the application
 */ 
void Menu(Users user){
	string choice = "";
	const string exit = "logout";
	const string Exit = "Logout";
	const string fullstandardUser = "FS";
	const string buyStandardUser = "BS";
	const string admin = "AA";
	const string sellStandardUser = "SS";
	bool ifLogout = true;
	ClearScreen();
	std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
	Title();
	cout << "\nWelcome " + user.getUserName() + "! Glad to see you are back :)";
	while(ifLogout == true){

		if(user.getUserType().compare(fullstandardUser) == 0){

			cout << "\nEnter Command: ";
			getline(cin, choice);

		}else if(user.getUserType().compare(buyStandardUser) == 0){
			cout << "\nEnter Command: ";
			getline(cin, choice);

		}else if(user.getUserType().compare(sellStandardUser) == 0){
			cout << "\nEnter Command: ";
			getline(cin, choice);

		}else if(user.getUserType().compare(admin) == 0){
			cout << "\nEnter Command: ";
			getline(cin, choice);

		}

		if(choice.compare(exit) == 0 || choice.compare(Exit) == 0){
			
			ifLogout = false;
			
		}
		//std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );

	} 

}

/**
 * Delay for the user to hit enter to close the console
 */ 
void PressEnterToExit()
  {
  	std::cout << "\nPress ENTER to exit... " << flush;
  	std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
  }

/**
 * Clears the screen 
 */ 
void ClearScreen()
{
	cout << string(100, '\n');
}

/**
 * Title for our Application
 */  
void Title(){

	cout << "==========================================" << endl
		 	 << "      SQA Baller Squad Auction House" << endl
		 	 << "==========================================" << endl;

}

void readInitialFiles(string curr, string avail){

	ifstream File;
	int i = 0;
	string hi;
	string getUser, getPwd, getType;
	float getCred;
	int count = 0;
	File.open(curr); //opening the file
	if (!File) {
    cerr << "Unable to open file";
    exit(1);   // call system to stop
}
	while (!File.eof()){
		getline(File, hi);
		count++;
	}

	accounts = new string*[count];
	for(int i = 0; i < count; i++){
    accounts[i] = new string[4];
	}
	File.clear();
	File.seekg(0, ios::beg);
	while (File >> getUser >> getPwd >> getType >> getCred) {
			
			//cout << " " + getUser;
			accounts[i][0] = getUser;
			accounts[i][1] = getPwd;
			accounts[i][2] = getType;
			accounts[i][3] = to_string(getCred);
			cout << accounts[i][0] + " " + accounts[i][1] + " " + accounts[i][2] + " " + accounts[i][3] + "\n";
			i++;

	}
	File.close(); //closing the file

	File.open(avail); //opening the file
	if (!File) {
    cerr << "Unable to open file";
    exit(1);   // call system to stop
}
	while (!File.eof()){
		getline(File, hi);
		count++;
	}

	accounts = new string*[count];
	for(int i = 0; i < count; i++){
    accounts[i] = new string[4];
	}
	File.clear();
	File.seekg(0, ios::beg);
	while (File >> getUser >> getPwd >> getType >> getCred) {
			
			//cout << " " + getUser;
			accounts[i][0] = getUser;
			accounts[i][1] = getPwd;
			accounts[i][2] = getType;
			accounts[i][3] = to_string(getCred);
			cout << accounts[i][0] + " " + accounts[i][1] + " " + accounts[i][2] + " " + accounts[i][3] + "\n";
			i++;

	}
	File.close(); //closing the file

}


