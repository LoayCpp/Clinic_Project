#pragma once
#include"iostream"
#include"..//..//Core//clsUser.h"
#include"..//..//Libraries//clsUtil.h"
#include"..//..//Screens//UsersMenu//clsUserHelperFunctions.h"
#include"clsMainMenu.h"

using namespace std;

class clsLoginScreen
{


	static void LoginHeaderScreen() {
		string LineSperator = clsUtil::UnderScore(9) + "";

		cout << LineSperator << "\n\n";
		cout << "\t\tLogin Screen" << "\n";
		cout << LineSperator << "\n";
	}
	static  clsUser ReadUser(bool UserDoesNotExists = false) {
		system("cls");
		LoginHeaderScreen();
		if (UserDoesNotExists) {
			cout << "Invalid Username/Password..!\n";
		}
		string Username = clsUserHelperFunctions::ReadUserName();
		string Password = clsUserHelperFunctions::ReadPassword();

		return  clsUser::FindUser(Username, Password);
	}



public:
	static void ShowLoginScreen() {

		CurrentUser = ReadUser();
		while (CurrentUser.IsEmpty()) {
			CurrentUser = ReadUser(true);
		}
		clsMainMenu::ShowMenu();
		
	}

};
