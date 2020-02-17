/**
* Users Header File for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Users.h
*/

#ifndef _USERS_H
#define _USERS_H

#include <iostream> 	// for console I/O
#include <iomanip>		// for output stream formatting
#include <sstream>		// for stringstream
#include <stdexcept>	// for standard exceptions
#include <cstdio> 	
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

/** @brief Users Class for user specific methods
 * Description:   
 * 
 * 
 */
class Users{
	
	private:
		/** Private Attribute for User Name */
		string userName;
		/** Private Attribute for Users password */
		string password;
		/** Private Attribute for User type */
		string userType;
		/** Private Attribute for Users credits */
		float credits;

	public:
		/**
		 * Default Constructor for the Users Class
		 * */
		Users(); 	

		/**
		 * Setter for User Name private attribute
		 */
		void setUserName(string name){
			userName = name;
		}
		/**
		 * Getter for User Name private attribute
		 */
		string getUserName(){
			return userName;
		}
		/**
		 * Setter for password private attribute
		 */
		void setPassword(string name){
			password = name;
		}
		/**
		 * Getter for password private attribute
		 */
		string getPassword(){
			return password;
		}
		/**
		 * Setter for User Type private attribute
		 */
		void setUserType(string type){
			userType = type;
		}
		/**
		 * Getter for User Type private attribute
		 */
		string getUserType(){
			return userType;
		}
		/**
		 * Setter for setting User Credits private attribute
		 */
		void setCredits(float cred){
			credits = cred;
		}
		/**
		 * Getter for getting User Credits private attribute
		 */
		float getCredits(){
			return credits;
		}
		
		/**
		 * Users Class Method for Login
		 */ 
		bool Login();
		/**
		 * Users Class Method for validating their credentials on login
		 */ 
		bool ValidateCredentials();
		/**
		 * Users Class Method for Logout
		 */ 
		void Logout();
		/**
		 * Users Class Method to change the user password
		 */ 
		void ChangePassword();
		/**
		 * Users Class Method for creating an account
		 */ 
		void Create();
		/**
		 * Users Class Method to add credits to a user account
		 */ 
		void AddCredits();

};



#endif



