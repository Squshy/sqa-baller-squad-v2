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
    string itemName = "";
    bool itemCheck = 0;
    bool itemMatch = 0;
    bool initialBidConfirmation = 0;
    string userPrompt = "";
    int itemSelect = 0;
    int itemLength = 0;
    string itemNameListCut;
    string** bidList;
    int bidListCount;
    bool itemSelectCheck = 0;
    //Don't show any items that belong to user in the list?
    //Loop until user finishes bid 
    //While loop until user to inputs valid item name
    cout << "\nType \"exit\" to return to main menu";
    while (itemMatch == true){
        while (itemCheck = true){
            cout << "\nEnter an Item name:";
            getline(cin, itemName);

            //Item name has to be 19 characters or fewer
            if (itemName.length() > 19){
                cout << "\nItem Name must be 19 characters or fewer";
            }
            else{
                itemCheck = false;
            }
        }

        //Get the first number of characters based on the length of input of itemName and see if they match
        //So if someone types Ham 
        //Ham, Hammer, Hamster gets sent into input, han,hanmster,chammer doesn't

        //Compare input to the item file in a loop and add it into an array if matches
        itemLength = itemName.length();
        //Gets the total number of matching items, which will be used for the array
        for (int i = 0; i < itemCount; i++){
            itemNameListCut = items[i][1].substr(0,itemLength);
            if(itemName.compare(itemNameListCut) == 1){
                bidListCount++;
            }
        }

        // 2D array for the bidlist to contain item name and current bid on it
        bidList = new string*[bidListCount];
        for (int i = 0; i < bidListCount; i++){
            bidList[i] = new string[4];
        }

        //Now we can put the item name, seller's name, remaining days and current bid inside with this defined array
        for (int i = 0; i < itemCount; i++){
            itemNameListCut = items[i][1].substr(0,itemLength);
            //Get Item name and current bid for it and if it matchess
            if(itemName.compare(itemNameListCut) == 1){
                bidList[i][0] = items[i][1]; //Item Name
                bidList[i][1] = items[i][2]; //Seller's name
                bidList[i][2] = items[i][4]; //Remaining days
                bidList[i][3] = items[i][5]; //Current Bid
            }
        }
        
        //If there are no matching results tell user and boot them back to input name and reset the itemCheck to 0
        //If Itemresult element size = 0 then itemCheck = 0;
        //If there are matching result then break while loop by changing itemMatch to 1
        itemMatch = false;
    }
        //Do another loop and print out each item with a cooresponding number for user to input, the name and the current bid per line
        // Calculates the number of elements inside an array
        int arraySize = (sizeof(bidList)/sizeof( bidList[0]));
        for (int i = 0; i < arraySize; i++){
            cout << ("%i. %s %s %s %s", bidList[i][0], bidList[i][1], bidList[i][2], bidList[i][3]) << endl;
        }
        //Prompt user to select a number from a list and to exit type -1
        //Check if the item belongs to a user as they cannot bid on their own items and boot them back to item list
        while(itemSelectCheck = 0){
            cout << "\nEnter a number from the list: ";
            // getline(cin, itemSelect);

            if(itemSelect < bidListCount || itemSelect >= -1){
                cout << "error input is not from list, pleae try again";
            } else {
                itemSelectCheck = 1;
            }
        }
        //Display current bid price
        cout << ("\nCurrent Price: %f", bidList[itemSelect][3]);
        //Ask user if they would like to bid on it
        cout << "\nWould you like to bid on this? (Yes/No)";
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