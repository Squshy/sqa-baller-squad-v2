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

Bid::Bid(string** items, int itemCount){
    const short MAX_ITEM_NAME_LENGTH = 19;
    const float MAX_BID = 999.99f;

    string itemName = "";
    string buffer = "";
    bool itemCheck = false;
    bool itemMatch = false;
    bool itemSelectCheck = false;
    bool initialBidConfirmation = false;
    int itemSelect = 0;
    int itemLength = 0;
    int j = 0; // itterates the bidlist for each match
    string itemNameListCut;
    string** bidList;
    int bidListCount = 0;
    //Don't show any items that belong to user in the list?
    //Loop until user finishes bid 
    //While loop until user to inputs valid item name
    std::cout << "\nType \"exit\" to return to main menu";
    while (itemMatch == false){
        while (itemCheck == false){
            std::cout << "\nEnter an Item name:";
            getline(cin, itemName);

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
        // std::cout << "\nItem Count Test in Bid cpp: " << itemCount; // Only 1 item in so far
        for (int i = 0; i < itemCount; i++){
            itemNameListCut = items[i][1].substr(0,itemLength);
            // std::cout << "\nItem Name List Cut Test in Bid cpp: " << itemNameListCut;
            if(itemName.compare(itemNameListCut) == 0){
                bidListCount++;
                // std::cout << "\nOutputting Items: "+ items[i][1];
            }
            // std::cout << "\noof";
        }

        // std::cout << "BidListCount Test in Bid cpp:asdasd " << bidListCount;
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
            // std::cout << "\n" << itemNameListCut; 
            //Get Item name and current bid for it and if it matches
            //TODO: Check if seller's name is same as current user and don't add it in bidList
            if(itemName.compare(itemNameListCut) == 0){ //We need i on the items array but we want to increment 
                bidList[j][0] = items[i][1]; //Item Name
                bidList[j][1] = items[i][2]; //Seller's name
                bidList[j][2] = items[i][4]; //Remaining days
                bidList[j][3] = items[i][5]; //Current Bid
	            // cout << bidList[i][0] + bidList[i][1] + bidList[i][2] + bidList[i][3] + "\n";
                j++;
            }
        }
    
        //Do another for loop and print out each item with a cooresponding number for user to input, the name and the current bid per line
        // Calculates the number of elements inside an array
        for (int i = 0; i < bidListCount; i++){
            std::cout << "\n" << i << ". " << bidList[i][0] << " " << bidList[i][1] << " " << bidList[i][2] << " " << bidList[i][3];
        }
        cout << "\nPast Displaying results";
        //Prompt user to select a number from a list and to exit type -1
        //Check if the item belongs to a user as they cannot bid on their own items and boot them back to item list
        while(itemSelectCheck == false){
            std::cout << "\nEnter a number from the list: "; // Something catastrophic is happening here
            getline(cin, buffer); // getline only takes in string not integers
            
            itemSelect = std::stoi(buffer);
            if(itemSelect < bidListCount || itemSelect >= 0){
                std::cout << "You have selected from List number : %i", buffer;
                itemSelectCheck = true;
            } 
            else {
                std::cout << "error: input needs to be between 1 and %i and numeric only, please try again", bidListCount;
            }
        }
        //Display current bid price
        std::cout << ("\nCurrent Price: %f", bidList[itemSelect][3]);
        //Ask user if they would like to bid on it
        std::cout << "\nWould you like to bid on this? (Yes/No)";
        // while (initialBidConfirmation = 0){
        //     cin >> userPrompt;
            
        //     if (userPrompt == "Yes" || "yes"){
        //         //Do the bid
        //         initialBidConfirmation =1;
        //     } else if(userPrompt == "No" || "no"){
        //         cout << "Kicking you back to main";
        //     }
        //     else{
        //         cout << "Error: Invalid bid input, Please input \"Yes\" or \"No\"";
        //     }
        // } 
        // while ()
        //If no, boot user back somewhere
        //If yes, prompt user to input
        //Check for negative number, letters, 
        //end the main while loop
}

float Bid::CalculateLowestBid(){

}

void Bid::BidOnItem(){
    
}
