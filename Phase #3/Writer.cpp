/**
* Writer Function Definition file for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Writer.cpp
*/

#include "Writer.h"
#include "Users.h"
#include <string>
#include <limits>
#include <sstream>

Writer::Writer(){

}

void Writer::WriteToAvailableItemsFile(string id, string item, string seller, string bidder, string days, string bid){

    string itemId;
    string itemName;
    string sellerName;
    string bidderName;
    string remainingDays;
    string currentBid;

    itemId = id;
    itemId.append(4 - id.length(), ' ');
    itemName = item;
    itemName.append(15 - item.length(), ' ');
    sellerName = seller;
    sellerName.append(12 - seller.length(), ' ');
    bidderName = bidder;
    bidderName.append(12 - bidder.length(), ' ');
    remainingDays = days;
    remainingDays.insert(remainingDays.begin(), 3 - days.length(), ' ');
    currentBid = bid;
    currentBid.insert(remainingDays.begin(), 9 - days.length(), '0');

    outFile.open(AVAILABLE_ITEMS_FILE, ios::app);

        outFile << "\n" + itemId + " " << itemName + " " << sellerName + " " << bidderName + " " << remainingDays + " " << currentBid;



    outFile.close();
   

}

void Writer::BidWriteToDailyTransactionFile(string itemName, string sellerName, string buyerName, string bid){

    string buffer;
    outFile.open(DAILY_TRANSACTION_FILE, ios::app);
    outFile << "\n02 " + itemName + " " + sellerName + " " + buyerName + " " + bid; 




    outFile.close();

}

void Writer::WriteToUserFile(string user, string pwd, string type){

    string username;
    string password;
    string usertype;
    string credits = "000000.00";
    username = user;
    username.append(15 - user.length(), ' ');
    password = pwd;
    password.append(12 - pwd.length(), ' ');
    usertype = type;

    outFile.open(CURRENT_USER_ACCOUNTS_FILE, ios::app);

        
        outFile << "\n" + username + " " << password + " " << usertype + " " << credits;



    outFile.close();

}

void Writer::AddCreditToUser(Users user){
    fstream File;
	int fileNumber;
    int i = 0;
    string getUser;
    string getPwd;
    string getType;
    float getCred;
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << fixed << user.getCredits();
    string credHolder = stream.str();
    string username;
    string password;
    string userType;
	string cred;
     username = user.getUserName();
     username.append(15 - user.getUserName().length(), ' ');
     password = user.getPassword();
     password.append(12 - user.getPassword().length(), ' ');
     userType = user.getUserType();
     cred = credHolder;
     cred.insert(cred.begin(), 9 - credHolder.length(), '0');

	File.open(CURRENT_USER_ACCOUNTS_FILE); //opening the file
	if (!File) {
        cerr << "Unable to open file";
    }
		
	//cout << username;
	while (File >> getUser >> getPwd >> getType >> getCred) {
			
			if(user.getUserName().compare(getUser) == 0){
                fileNumber = i;
            }
			i++;

	}
     File.clear();
	 File.seekg(0, ios::beg);
    //for(int i = 0; i < fileNumber; i++){
    //      File.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //}
    // Position the put pointer -- switching from reading to writing.
    File.seekp(fileNumber * 43);

     File << username << " " << password << " " << userType << " " << cred << endl;
	 File.close(); //closing the file


}
