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

inline void UserNotFound(std::string user) {
    LightHighlight();
    std::cout << Spaces(12)
                << "User " << user << " does not exist.";
    Highlight();
}

void Admin::AddCredits(){

};

void Admin::DeleteUser(std::string** users, int numUsers){
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
    userFound = MatchUser(users, numUsers, username);

    // If a user was found that matches the username
    if(userFound == false) {
        UserNotFound(username);
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

void Admin::Update(string** users, int numUsers){
    string buffer = "";
    std::cout << "Would you like to enable or disable a user?: ";
    getline(cin, buffer);
    if(ToLower(buffer).compare(DISABLE) == 0) DisableUser(users, numUsers);
    else if(ToLower(buffer).compare(ENABLE) == 0) EnableUser(users, numUsers);
    else {
        LightHighlight();
        std::cout << Spaces(18) << "Invalid option";
        Highlight();
    }
}

void Admin::EnableUser(string** users, int numUsers){
    string buffer = "";
    Users user;
    bool userFound, confirm = false;
    std::cout << endl
              << "Which user would you like to enable?: ";
    getline(cin, buffer);

    for(int i = 0; i < numUsers; i++) {
        if(users[i][0] == buffer) {
            userFound = true;
            user.setUserName(users[i][0]);
            user.setUserType(users[i][2]);
        } 
    } 

    if(!userFound) {
        UserNotFound(buffer);
    } else {
        if(user.getUserType().compare(DISABLED_CODE) != 0) {
            LightHighlight();
            std::cout << endl
                      << user.getUserName()
                      << "'s account is already enabled.";
            Highlight();
        } else {
            std::cout << endl
                  << "Do you want to enable this user? (Yes/No): ";
            getline(cin, buffer);
            if(ToLower(buffer).compare(YES) == 0) {
                LightHighlight();
                std::cout << user.getUserName() << "'s account has been enabled!";
                Highlight();
                // Enable the man
            } else if(ToLower(buffer).compare(NO) == 0) {
                LightHighlight();
                std::cout << user.getUserName() << "'s account was not enabled!";
                Highlight();
            } else {
                LightHighlight();
                std::cout << "Invalid option.  Please type \"yes\" or \"no\".";
                Highlight();
            }
        }
        
    }
}

void Admin::DisableUser(string** users, int numUsers){
    string buffer = "";
    Users user;
    bool userFound, confirm = false;
    std::cout << endl
              << "Which user would you like to disable?: ";
    getline(cin, buffer);

    for(int i = 0; i < numUsers; i++) {
        if(users[i][0] == buffer) {
            userFound = true;
            user.setUserName(users[i][0]);
            user.setUserType(users[i][2]);
        } 
    } 

    if(!userFound) {
        UserNotFound(buffer);
    } else {
        if(user.getUserType().compare(DISABLED_CODE) == 0) {
            LightHighlight();
            std::cout << endl
                      << user.getUserName()
                      << "'s account is already disabled.";
            Highlight();
        } else {
            while(confirm == false) {
                std::cout << endl
                        << "Do you want to disable this user? (Yes/No): ";
                getline(cin, buffer);
                if(ToLower(buffer).compare(YES) == 0) {
                    LightHighlight();
                    std::cout << user.getUserName() << "'s account has been disabled!";
                    Highlight();
                    confirm = true;
                    // Delete the man
                } else if(ToLower(buffer).compare(NO) == 0) {
                    LightHighlight();
                    std::cout << user.getUserName() << "'s account was not disabled!";
                    Highlight();
                    confirm = true;
                } else {
                    LightHighlight();
                    std::cout << "Invalid option.  Please type \"yes\" or \"no\".";
                    Highlight();
                }
            }
        }
    }
}  

void Admin::Refund(Items) {

}