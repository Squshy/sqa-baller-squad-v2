/**
* Bid Function Definition file for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Bid.cpp
*/

#include "Bid.h"
#include <string>
#include "AuctionLib.h"
#include "Writer.h"

Bid::Bid(){

}

float Bid::CalculateLowestBid(float currentPrice){
    return (currentPrice * MINIMUM_BID_PERCENT);
}

void Bid::BidOnItem(string** items, int itemCount, Users user){
const short MAX_ITEM_NAME_LENGTH = 19;
    const float MAX_BID = 999.99f;
    string itemName = "";
    string buffer = "";
    bool itemCheck = false;
    bool itemMatch = false;
    bool itemSelectCheck = false;
    bool initialBidConfirmation = false;
    bool bidCheck = false;
    bool alphanumericCheck = false;
    bool bidAlphanumericCheck = false;
    int itemSelect = 0;
    int itemLength = 0;
    float minimumPrice = 0.0;
    float theBid = 0.0;
    int j = 0; // itterates the bidlist for each match
    string itemNameListCut;
    string** bidList;
    int bidListCount = 0;
    //Don't show any items that belong to user in the list?
    //Loop until user finishes bid 
    //While loop until user to inputs valid item name
    std::cout << "\nType \"exit\" to return to main menu";
    while (itemMatch == false){
        itemName = "";
        while (itemCheck == false){
            std::cout << "\nEnter an Item name: ";
            getline(cin, itemName);
            if (exitCmd(itemName)){
                std::cout << "Hi " << exitCmd(itemName);
                break;
            }
            // std::cout << exitCmd(itemName);
            //Item name has to be 19 characters or fewer
            if (itemName.length() > MAX_ITEM_NAME_LENGTH){
                std::cout << "\nItem Name must be 19 characters or fewer";
            }
            else{
                itemCheck = true;
            }
        }

        //Get the first number of characters based on the length of input of itemName and see if they match
        //So if someone types Ham 
        //Ham, Hammer, Hamster gets sent into bidList and is counted, while han,hanmster,chammer doesn't
        //TODO: This needs to ignore case sensitivity

        //Compare input to the item file in a loop and add it into an array if matches
        itemLength = itemName.length();
        //Gets the total number of matching items, which will be used for the array
        for (int i = 0; i < itemCount; i++){
            itemNameListCut = items[i][1].substr(0,itemLength);
            if(itemName.compare(itemNameListCut) == 0){
                bidListCount++;
            }
        }

        //If itemCount is 0 then that means there are no matches and will prompt user to start over
        if (bidListCount == 0){
            std::cout << "\nThere are no matching results. Please enter a new item name.";
            itemCheck = false; //reset itemNameCheck
        }else{
            itemMatch = true;
        }
    } cout << "\nPast bidlistCount"; // Breaks for runite   
        std::cout << bidListCount;
        // 2D array for the bidlist to contain item name and current bid on it
        bidList = new string*[bidListCount];
        for (int i = 0; i < bidListCount; i++){
            bidList[i] = new string[4];
        }
        cout << "\nPast bidlist\n";
        //Now we can put the item name, seller's name, remaining days and current bid inside with this defined array
        for (int i = 0; i < itemCount; i++){
            itemNameListCut = items[i][1].substr(0,itemLength);

            //Get Item name, seller's name, remaining days and current bid when it matches
            //TODO: Check if seller's name is same as current user and don't add it in bidList
            if(itemName.compare(itemNameListCut) == 0){ //We need i on the items array but we want to increment 
                bidList[j][0] = items[i][1]; //Item Name
                bidList[j][1] = items[i][2]; //Seller's name
                bidList[j][2] = items[i][4]; //Remaining days
                bidList[j][3] = items[i][5]; //Current Bid
                j++;
            }
        }
        //Do another for loop and print out each item with a cooresponding number for user to input, the name and the current bid per line
        // Calculates the number of elements inside an array
        for (int i = 0; i < bidListCount; i++){
            std::cout << "\n" << i << ". " << bidList[i][0] << " " << bidList[i][1] << " " << bidList[i][2] << " " << bidList[i][3];
        }
        // Prompt user to select a number from a list and to exit type -1
        // Check if the item belongs to a user as they cannot bid on their own items and boot them back to item list
        while(itemSelectCheck == false){
            buffer = "";
            while(alphanumericCheck == false){
                std::cout << "\nEnter a number from the list: ";
                getline(cin, buffer);
                
                if (exitCmd(buffer) == true){
                    break;
                }
                if(IsInteger(buffer)){
                    itemSelect = std::stoi(buffer);
                    alphanumericCheck = true;
                }else {
                    std::cout << "\nError: Input needs to be numeric: ";
                }
            }
            // Need to validate against alphabetic characters first then convert to integer
            if(itemSelect < bidListCount && itemSelect >= 0){
                std::cout << "\nYou have selected from List number: " << buffer;
                itemSelectCheck = true;
            } 
            else {
                std::cout << "error: input needs to be between 0 and " << bidListCount << " and numeric only, please try again";
                alphanumericCheck = false;
            }
        }
        minimumPrice = (std::stof(bidList[itemSelect][3]));
        minimumPrice =  CalculateLowestBid(minimumPrice);
        //Display current bid price
        std::cout << "\nCurrent Price: " << bidList[itemSelect][3];
        std::cout << "\nMinimum Bid Price: " << minimumPrice;
        std::cout << "\nWould you like to bid on this? (Yes/No): ";

        //Ask user if they would like to bid on it
        while (initialBidConfirmation == false){
            buffer = "";
            getline(cin, buffer);
            if (exitCmd(buffer) == true){
                break;
            }
            if (buffer == "Yes" || buffer == "yes"){
                //Do the bid
                cout << "Confirmation confirmed";
                initialBidConfirmation = true;
            } else if(buffer == "No" || buffer == "no"){
                cout << "Kicking you back to main";
                break;
            }
            else{
                cout << "Error: Invalid bid input, Please input \"Yes\" or \"No: ";
            }
        } 
        std::cout << "\nHow much would you like to bid (Min Bid: " << minimumPrice << "): ";
        while (bidCheck == false){
            buffer = "";
            if (exitCmd(buffer) == true){
                break;
            }
            while(bidAlphanumericCheck == false){
                getline(cin, buffer);
                if(IsDecimalNumber(buffer)){
                    theBid = stof(buffer);
                    cout << "Bid offer: " << theBid;
                    bidAlphanumericCheck = true;
                } else{
                    std::cout << "\nError: input must be numeric";
                }
            }   
            if (theBid < minimumPrice){
                std::cout << "\nError: New bid must be 5% higher than current price";
                bidAlphanumericCheck = false;
            } else if(theBid > MAX_BID){
                std::cout << "\nError: The maximum bid you can bid is $" << MAX_BID;
                bidAlphanumericCheck = false;
            } else {
                Writer writer;
                //Item Name, Seller's name, buyer's name, new bid all in string
                cout << bidList[itemSelect][0] << bidList[itemSelect][1] << user.getUserName(), buffer;
                writer.BidWriteToDailyTransactionFile(bidList[itemSelect][0], bidList[itemSelect][1], user.getUserName(), buffer);
                bidCheck = true;
            }
        }
        std::cout << "Success!";
}

bool Bid::exitCmd(string buffer){
    if (ToLower(buffer).compare(EXIT) == 0){
        return true;
    }else {
        return false;
    }
}
