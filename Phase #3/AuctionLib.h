/**
* Function declarations for functions to be used in multiple files
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @since February 26, 2020
* @version  1.0
* @name AuctionLib.h
*/

#include <string>

#ifndef _AUCTIONLIB_H
#define _AUCTIONLIB_H

// Constants
const std::string YES = "yes";
const std::string NO = "no";

std::string ToLower(std::string str);
std::string Spaces(int numSpaces);

bool IsDecimalNumber(std::string str);
bool IsInteger(std::string str);

void Highlight();
void LightHighlight();

#endif