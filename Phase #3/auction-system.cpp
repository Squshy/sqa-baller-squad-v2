/**
* Main Class for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @since January 24, 2020
* @version  1.0
* @name auction-system.cpp
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
#include "Advertise.h"
#include "Admin.h"
#include "AuctionLib.h"
#include "Bid.h"

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
int userCount; 
int itemCount = 0;

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

/**
 * Home screen when someone first comes on to the application
 * It will ask the user to login or exit the application
 */ 
void Home(Users user){
	
	string choice = "";
	const string CREATE = "create";
	const string EXIT = "exit";
	const string LOGIN = "login";
	bool login;
	bool ifExit = true;
	
	while(ifExit == true){
		
		ClearScreen();
		cout << error;
		Title();
		cout << "\nPlease Type login, create or exit!";
		cout << "\nEnter Command: ";
		getline(cin, choice);
	
	    if(ToLower(choice).compare(LOGIN) == 0){
			ClearScreen();
			Title();
     		login = user.Login(accounts, userCount);
			 if(login == true){
				 Menu(user);
				 ClearScreen();
			 }else{
				 //ClearScreen();
				 error = "\nYour Username or Password were entered incorrectly. Please Try again!\n";
			 }
			
     	}else if(choice.compare(CREATE) == 0){

			user.Create(accounts, userCount);
			readInitialFiles(currentAccounts, availableItems);

     	}else if(ToLower(choice).compare(EXIT) == 0){
     		ifExit = false;
     	}else if(choice.find("/") != std::string::npos || choice.find(" ") != std::string::npos){
     		//ClearScreen();
			error = "\nSlashes and Spaces are not Allowed!\n";
			
		}else{
			if(error.empty()){
				error = "\nYou must login before you can access our system\n";
			}
		}
		
		
	}	
	
}

/**
 * Function for after the user has logged in showing the menu screen 
 * This is where the user will enter in transactions and navigate the application
 */ 
void Menu(Users user){
	string choice = "";
	const string LOGOUT = "logout";
	const string FULL_STANDARD = "FS";
	const string BUY_STANDARD = "BS";
	const string ADMIN = "AA";
	const string SELL_STANDARD = "SS";
    const string ADVERTISE = "advertise";
	bool ifLogout = true;
	ClearScreen();
	std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
	Title();
	cout << "\nWelcome " + user.getUserName() + "! Glad to see you are back :)";
	while(ifLogout == true){
//Commented out for testing bid
		// if(user.getUserType().compare(fullstandardUser) == 0){

		if(user.getUserType().compare(FULL_STANDARD) == 0){

			cout << "\nFS Enter Command: ";
			getline(cin, choice);
			if(ToLower(choice) == "ADVERTISE") {
                Advertise ad;
                ad.AdvertiseItem();
            }else if(ToLower(choice).compare("addcredit") == 0){
				user.AddCredits(user);

			
			}else if(ToLower(choice).compare("bid") == 0){
				std::cout << "Item Count Test: " << itemCount;
				//itemCount is not being sent in correctly
				Bid(items, itemCount);
			}
		}else if(user.getUserType().compare(BUY_STANDARD) == 0){
			cout << "\nBS Enter Command: ";
			getline(cin, choice);
			if(ToLower(choice).compare("bid") == 0){
				
			}
		}else if(user.getUserType().compare(SELL_STANDARD) == 0){
			cout << "\nSS Enter Command: ";
			getline(cin, choice);
            if(ToLower(choice).compare("advertise") == 0){

			}
		}else if(user.getUserType().compare(ADMIN) == 0){
			cout << "\nAA Enter Command: ";
			getline(cin, choice);
			if(ToLower(choice).compare("bid") == 0) {
				
			}else if(ToLower(choice).compare("advertise") == 0) {

			}else if(ToLower(choice).compare("addcredit") == 0) {
				
			}else if(ToLower(choice).compare("delete") == 0) {
                Admin admin;
                admin.DeleteUser(accounts, userCount, user);
			}else if(ToLower(choice).compare("refund") == 0) {
				
			}else if(ToLower(choice).compare("update") == 0) {

			}else if(ToLower(choice).compare("changepassword") == 0) {
				
			}

		}

		if(ToLower(choice).compare(LOGOUT) == 0){
			
			ifLogout = false;
			
		}
		

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

	cout     << "==========================================" << endl
		 	 << "      SQA Baller Squad Auction House"       << endl
		 	 << "==========================================" << endl;

}

void readInitialFiles(string curr, string avail){

	ifstream File;
	int i = 0;
	int j = 0;
	string dump;
	string temp;
	string getUser, getPwd, getType;
	float getCred;

	File.open(curr); //opening the file
	if (!File) {
    cerr << "Unable to open file";
    
}
	while (!File.eof()){
		getline(File, dump);
		userCount++;
	}

	accounts = new string*[userCount];
	for(int x = 0; x < userCount; x++){
    accounts[x] = new string[4];
	}
	File.clear();
	File.seekg(0, ios::beg);
	while (File >> getUser >> getPwd >> getType >> getCred) {
			
			//cout << " " + getUser;
			accounts[i][0] = getUser;
			accounts[i][1] = getPwd;
			accounts[i][2] = getType;
			accounts[i][3] = to_string(getCred);
			//cout << accounts[i][0] + " " + accounts[i][1] + " " + accounts[i][2] + " " + accounts[i][3] + "\n";
			i++;

	}
	File.close(); //closing the file

	File.open(avail); //opening the file
	if (!File) {
    cerr << "Unable to open file";
       // call system to stop
}
	while (!File.eof()){
		getline(File, dump);
		itemCount++;
	}

	items = new string*[itemCount];
	for(int z = 0; z < itemCount; z++){
    items[z] = new string[6];
	}
	File.clear();
	File.seekg(0, ios::beg);
	while (!File.eof()) {

		getline(File, temp);
			items[j][0] = temp.substr(0, 4); // Item ID
			items[j][1] = temp.substr(5, 19); // Item Name
			items[j][2] = temp.substr(24, 16); // Seller name
			items[j][3] = temp.substr(40, 15);  // Current Bidder's name
			items[j][4] = temp.substr(55, 3); // Remaining days
			items[j][5] = temp.substr(59, 8); // Current bid
			j++;

	}
	//cout << items[0][0] + items[0][1] + items[0][2] + items[0][3] + items[0][4] + items[0][5] + "\n";

	File.close(); //closing the file
}


