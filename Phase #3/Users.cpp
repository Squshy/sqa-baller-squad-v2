/**
* Users Function Definition file for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Users.cpp
*/

#include "Users.h"
#include "Writer.h"
#include <string>


Users::Users(){}


bool Users::Login(string** users, int userCount){
	string username = "";
	string password = "";
	bool validation = false;
	setCreditCount(0.0);
		
     	cout << "\nUsername: ";
     	cin >> username;
    	cout << "\nPassword: ";
     	cin >> password;
		setUserName(username);
		setPassword(password);
		for(int i = 0; i < userCount; i++){
			cout << users[i][0];
			if (getUserName().compare(users[i][0]) == 0 && getPassword().compare(users[i][1]) == 0){
			//exists = true;
			setUserType(users[i][2]);
			setCredits(stof(users[i][3]));
			validation = true;
			break;
		}

		}
	
		return validation;
     	
}

void Users::ChangePassword(Users user){
	string username, buffer = "";
	std::cout << endl
              << "Enter new Password: ";
    getline(cin, buffer);
	

}

void Users::Create(string** users, int userCount){

	Writer writer;
	Users user;
	string username;
	string password;
	string userType;
	bool validation = false;
	const string BUY_STANDARD = "BS";
	const string SELL_STANDARD = "SS";
	const string FULL_STANDARD = "FS";
	const string code = "01";
	
while(validation == false){
	cout << "Enter Username: ";
	getline(cin, username);
	for(int i = 0; i < userCount; i++){
		if (username.compare(users[i][0]) == 0){
			cout << "Username already exists";
			break;
		}
	}
	cout << "Enter Password: ";
	getline(cin, password);

	cout << "Please type the user type you want: BS - Buy Standard, SS - Sell Standard, FS - Full Standard: ";
	getline(cin, userType);

	if(username.length() > 15){
		cout << "\nUsername is too long and must be 15 characters or fewer";
		
	}else if (username.length() <= 0){
		cout << "\nUsername is blank";
		
	}else if(password.length() > 12){
		cout << "\nPassword is too long and must be 12 characters or fewer";
		
	}else if (password.length() <= 0){
		cout << "\nPassword is blank";
		
	}else if(userType.length() > 2 || userType.length() < 0){
		cout << "User Type must be one of the 2 character options above";
		
	}else if(userType.compare(BUY_STANDARD) != 0 && userType.compare(SELL_STANDARD) != 0 && userType.compare(FULL_STANDARD) != 0){
		cout << "User Type must be one of the 2 character options above";
		
	}else{
		cout << "User Successfully Created\n";
		user.setUserName(username);
		user.setPassword(password);
		user.setUserType(userType);
		writer.GenericWriteToDailyTransactionFile(user, code);
		validation = true;
	}
}

}

void Users::AddCredits(Users user){

	string credit;
	float sum;
	Writer writer;
	const string code = "06";

	cout << "\nHow much Credit do you want to add to your account: ";
	getline(cin, credit);
	float cred = stof(credit);
	sum = user.getCreditCount() + cred;
	if(sum > SESSION_CREDIT_LIMIT){
		cout << "Error! You have exceeded your credit limit";
	}else{
		user.setCreditCount(sum);
	}
	
	writer.GenericWriteToDailyTransactionFile(user, code);

}

void Users::EndSession(Users user){
	const string code = "00";
	Writer writer;
	writer.GenericWriteToDailyTransactionFile(user, code);

}


