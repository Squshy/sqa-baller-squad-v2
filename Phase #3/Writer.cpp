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

    outFile.open(DAILY_TRANSACTION_FILE);

    



    outFile.close();

}

void Writer::WriteToDailyTransactionFile(){

}

void Writer::WriteToUserFile(){

}
