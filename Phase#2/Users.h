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
		/** Private Attributes */
		string userName;
		string password;
		string userType;
		float credits;

	public:
	/**
	 * Default Constructor for the Users Class
	 * */
		Users(); 	

		void setUserName(string name){
			userName = name;
		}
		string getUserName(){
			return userName;
		}

		void setPassword(string name){
			password = name;
		}
		string getPassword(){
			return password;
		}

		void setUserType(string type){
			userType = type;
		}
		string getUserType(){
			return userType;
		}

		void setCredits(float cred){
			credits = cred;
		}
		float getCredits(){
			return credits;
		}
		
		bool Login();
		bool ValidateCredentials();
		void Logout();
		void ChangePassword();
		void Create();
		void AddCredits();

};



#endif



