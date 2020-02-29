/**
* Function declarations for functions to be used in multiple files
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @since February 26, 2020
* @version  1.2
* @name AuctionLib.h
*/

#include <string>
#include "Users.h"

#ifndef _AUCTIONLIB_H
#define _AUCTIONLIB_H

// Constants
const std::string YES = "yes";
const std::string NO = "no";
const std::string DISABLE = "disable";
const std::string ENABLE = "enable";
const std::string DISABLED_CODE = "DS";
const short MAX_ITEM_NAME_LENGTH = 19;
const short MAX_USER_NAME_LENGTH = 15;
const short MAX_PASSWORD_LENGTH = 12;
const short MAX_CREDIT_LENGTH = 9;

std::string ToLower(std::string str);
std::string Spaces(int numSpaces);

bool IsDecimalNumber(std::string str);
bool IsInteger(std::string str);
bool MatchUser(std::string** users, int numUsers, std::string name);

void Highlight();
void LightHighlight();

#endif