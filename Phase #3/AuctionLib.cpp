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

std::string ToLower(std::string str) {
    std::string newString = str;
    std::transform(newString.begin(), newString.end(), newString.begin(),
        [](unsigned char c){ return std::tolower(c); });
    return newString;
}