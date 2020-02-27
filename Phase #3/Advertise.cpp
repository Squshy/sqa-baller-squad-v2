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

Advertise::Advertise(){}
void AdTitle();

void Advertise::AdvertiseItem(){
    const float MAX_BID = 999.99f;
    const float MIN_BID = 0.01f;
    const short MAX_NAME_LENGTH = 25;
    const short MAX_AUC_DAYS = 100;
    const short MIN_AUC_DAYS = 1;

    string itemName, buffer = "";
    float minBid = 0.0f;
    int numDays = 0;
    bool validAd = false;

    AdTitle();
    while(validAd == false)
    {
        std::cout << "\nItem name: ";
        getline(cin, buffer);
        if(buffer.length() > MAX_NAME_LENGTH) {
            LightHighlight();
            std::cout << "Item name must be 25 characters or less.";
            Highlight();
        } else {
            itemName = buffer;
            buffer = "";
            std::cout << "\nMinimum bid: $";
            getline(cin, buffer);

            if(IsDecimalNumber(buffer)) {
                minBid = std::stof(buffer);
                if(minBid > MAX_BID) {
                    LightHighlight();
                    std::cout << "           "
                              << "Maximum bid must be $" << MAX_BID << " or less.";
                    Highlight();
                } else if(minBid < MIN_BID) {
                    LightHighlight();
                    std::cout << "           "
                              << "Minimum bid must be at least $" << MIN_BID << ".";
                    Highlight();
                } else {
                    buffer = "";
                    std::cout << "\nNumber of days to auction: ";
                    getline(cin, buffer);
                    if(IsInteger(buffer)){
                        numDays = std::stoi(buffer);
                        if(numDays > MAX_AUC_DAYS) {
                            LightHighlight();
                            std::cout << "       "
                                      << "You can only auction an item up to 100 days.";
                            Highlight();
                        } else if(numDays < MIN_AUC_DAYS) {
                            LightHighlight();
                            std::cout << "           "
                                      << "There must be a minimum of 1 day "
                                      << endl
                                      << "                 "
                                      << "to auction the item.";
                            Highlight();
                        } else {
                            LightHighlight();
                            std::cout << "            "
                                      << "You have put up " << itemName << "." << endl       
                                      << "        "
                                      << "This item will be auctioned for " << numDays << " days" << endl
                                      << "            "
                                      << "with a minimum bid of $"<< setprecision(2) << fixed << minBid << "!";
                            Highlight();
                            validAd = true;
                        }
                    } else {
                        LightHighlight();
                        std::cout << "  "
                                  << "You must enter a number between 1 and 100 inclusively.";
                        Highlight();
                    }
                }
            } else {
                LightHighlight();
                std::cout << "            "
                          << "A bid must be numeric and can only"
                          << "\n         "
                          << "be between $" << MIN_BID << " and $" << MAX_BID << " inclusively.";
                Highlight();
            }
        }

        
    }
}

void AdTitle() {
    Highlight();
    std::cout << "                        ADVERTISE";
    Highlight();
}
