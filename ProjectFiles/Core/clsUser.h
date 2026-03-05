#pragma once
#include "clsPerson.h"
class clsUser: public clsPerson
{
private:
	string _userID;
	string _userName;
	string _password;

public:
	clsUser(string firstName, string secondName, string thirdName,
		string fourthName, string userName, string password, string phone)
		:clsPerson(firstName, secondName, thirdName, fourthName, phone)
	{
		this->_userName = userName;
		this->_password = password;
	}

	string GetUserID() const {
		return this->_userID;
	}
	__declspec(property(get = GetUserID)) string UserID;


	void SetUserName(string userName)  {
		 this->_userName = userName;
	}
	string GetUserName() const {
		return this->_userName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string userName) {
		this->_userName = userName;
	}
	string GetPassword() const {
		return this->_userName;
	}
	__declspec(property(get = GetUserName, put = SetPassword)) string Password;
};