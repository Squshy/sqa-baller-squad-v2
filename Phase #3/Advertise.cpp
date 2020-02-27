/**
* Advertise Function Definition file for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.1
* @name Advertise.cpp
*/

#include "Advertise.h"
#include "AuctionLib.h"
#include <string>

Advertise::Advertise(){
    string itemName, buffer = "";
    float minBid = 0.0f;
    short numDays = 0;

    while(1)
    {
        std::cout << "\nPlease enter an item name: ";
        getline(cin, itemName);

        std::cout << "\nPlease enter the minimum bid: $";
        getline(cin, buffer);

        std::cout << "\nIs input a number?: " << IsNumber(buffer);
    }
    



}

void Advertise::AdvertiseItem(){

}
