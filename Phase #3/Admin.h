/**
* @brief Admin Header File for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Admin.h
*/

#ifndef _ADMIN_H
#define _ADMIN_H

#include <iostream> 	
#include <iomanip>		
#include <sstream>		
#include <stdexcept>	
#include <cstdio> 	
#include <cstdlib>
#include <string>
#include <fstream>
#include "Users.h"
#include "Items.h"

using namespace std;

/** @brief Admin Class for special users with Admin access
 * @description:      
 * 
 * 
 */
class Admin : public Users{


    public:
        /**
         * Default Constructor for Admin Class
         */ 
        Admin();
        /**
         * Method to delete a chosen user
         */ 
        void DeleteUser(std::string** users, int numUsers, Users self);
        /**
         * Method enable a disabled user account
         */ 
        void EnableUser();
        /**
         * Method to disable a current user   
         */
        void DisableUser();
        /**
         * Method to refund a user from a transaction
         */ 
        void Refund(Items);
        /**
         * Overloaded function to add credits to a users account
         */ 
        void AddCredits();

};



#endif