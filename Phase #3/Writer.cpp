/**
* Writer Function Definition file for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Writer.cpp
*/

#include "AuctionLib.h"
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



// void Writer::WriteToUserFile(string user, string pwd, string type){

//     string username;
//     string password;
//     string usertype;
//     string credits = "000000.00";
//     username = user;
//     username.append(15 - user.length(), ' ');
//     password = pwd;
//     password.append(12 - pwd.length(), ' ');
//     usertype = type;


//     outFile.open(CURRENT_USER_ACCOUNTS_FILE, ios::app);

        
//         outFile << "\n" + username + " " << password + " " << usertype + " " << credits;



//     outFile.close();

// }

void Writer::GenericWriteToDailyTransactionFile(Users user, string transactionCode){
    fstream File;
    std::stringstream stream;
    if(transactionCode == "00"){
        stream << std::fixed << std::setprecision(2) << fixed << user.getCredits();
    }else{
        stream << std::fixed << std::setprecision(2) << fixed << user.getCreditCount();
    }
    string credHolder = stream.str();
    string code = transactionCode;
    string username = user.getUserName();
    string password = user.getPassword();
    string userType = user.getUserType();
	string cred = credHolder;
    username.append(MAX_USER_NAME_LENGTH - user.getUserName().length(), ' ');
    password.append(MAX_PASSWORD_LENGTH - user.getPassword().length(), ' ');
    cred.insert(cred.begin(), MAX_CREDIT_LENGTH - credHolder.length(), '0');
    

	File.open(DAILY_TRANSACTION_FILE, ios::app); //opening the file
	if (!File) {
        cerr << "Unable to open file";
    }

    File << "\n" << code << " " << username << " " << userType << " " << cred;
    File.close(); //closing the file
}

void Writer::WriteAdvertiseToDailyTransactionFile(Users user, string item, int numDays, float bid) {
    fstream file;
    const string ADVERTISE_CODE = "03";
    std::stringstream bidStream;
    string username, itemName, aucBid = "";

    file.open(DAILY_TRANSACTION_FILE, ios::app); //opening the file
	if (!file) {
        cerr << "Unable to open file";
    }

    bidStream << std::fixed << std::setprecision(2) << fixed << bid;
    username = user.getUserName();
    itemName = item;
    aucBid   = bidStream.str();
    username.append(MAX_USER_NAME_LENGTH - user.getUserName().length(), ' ');
    itemName.append(MAX_ITEM_NAME_LENGTH - itemName.length(), ' ');
    aucBid.insert(aucBid.begin(), MAX_CREDIT_LENGTH - aucBid.length(), '0');

    file << endl 
         << ADVERTISE_CODE << " " 
         << itemName << " " 
         << username << " " 
         << setfill('0') << setw(3) << numDays << " "
         << setprecision(2) << fixed << aucBid;
    file.close();
}
