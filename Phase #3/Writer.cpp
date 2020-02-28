/**
* Writer Function Definition file for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Writer.cpp
*/

#include "Writer.h"
#include <string>

Writer::Writer(){

}

void Writer::WriteToAvailableItemsFile(){

    string buffer;

    outFile.open(AVAILABLE_ITEMS_FILE, ios::app);

        




    outFile.close();
   

}

void Writer::WriteToDailyTransactionFile(){

     string buffer;

    outFile.open(DAILY_TRANSACTION_FILE, ios::app);

        




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
