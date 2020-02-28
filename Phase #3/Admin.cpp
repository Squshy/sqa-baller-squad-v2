/**
* Admin function definition for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Admin.cpp
*/

#include "Admin.h"
#include "Users.h"
#include "Writer.h"
#include "AuctionLib.h"
#include <string>

Admin::Admin(){
    
}

void Admin::AddCredits(){

};

void Admin::DeleteUser(std::string** users, int numUsers, Users self){
    string username, buffer = "";
    bool userFound, confirm = false;
    Writer writer;
    Users user;
    string userType;
    string credits;
    const string code = "02";

    std::cout << "\nEnter username: ";
    getline(cin, username);

    // Loops through the users to see if the usernames match
    for(int i = 0; i < numUsers; i++) if(users[i][0] == username){
         userFound = true;
         userType = users[i][2];
         credits = users[i][3];
    }

    // If a user was found that matches the username
    if(userFound == false) {
        LightHighlight();
        std::cout << Spaces(12)
                  << "User " << username << " does not exist.";
        Highlight();
    } else {
        while(confirm == false) {
            std::cout << "\nAre you sure you want to delete user " << username << "?"
                    << endl
                    << "(Yes/No): ";
            getline(cin, buffer);
            // User confirms to delete the user
            if(ToLower(buffer).compare(YES) == 0) {
                LightHighlight();
                
                std::cout << Spaces(12)
                        << username << " has been successfully deleted!";
                Highlight();
                user.setUserName(username);
                user.setUserType(userType);
                writer.GenericWriteToDailyTransactionFile(user, code);
                confirm = true;
            } else if(ToLower(buffer).compare(NO) == 0) {
                LightHighlight();
                std::cout << Spaces(16)
                        << "Delete process aborted."
                        << endl << Spaces(12)
                        << username << " was not deleted.";
                Highlight();
                confirm = true;
            } else {
                LightHighlight();
                std::cout << Spaces(18)
                        << username << "Invalid Confirmation.";
                Highlight();
            }
        }
    }
}

void Admin::EnableUser(){

}

void Admin::DisableUser(){

}

void Admin::Refund(Items){

}