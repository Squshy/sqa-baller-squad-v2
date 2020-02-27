/**
* Library for functions to be used in multiple files 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @since February 26, 2020
* @version  1.0
* @name AuctionLib.cpp
*/

#include "AuctionLib.h"
#include <algorithm>
#include <cctype>
#include <string>

/**
 * Converts a string all to lowercase
 */
std::string ToLower(std::string str) {
    std::string newString = str;

    std::transform(newString.begin(), newString.end(), newString.begin(),
        [](unsigned char c){ return std::tolower(c); });

    return newString;
}

/**
 * Checks to see if the string is a valid number
 */
bool IsNumber(std::string str) {
    std::string newString = str;
    bool hasDecimal = false;

    for(int i = 0; i < newString.length(); i++){
        if(!isdigit(str[i])) {
            if(str[i] == '.' && hasDecimal == false) hasDecimal = true; // If the character is a decimal and the loop has not already encountered a decimal: 1.000
            else if(str[i] == '.' && hasDecimal == true) return false;  // If the character is a decimal and the loop has encountered a decimal: 1.0.00
            else return false;  // Character is not a digit or a decimal: 10ab
        }
    }
    return true;
}