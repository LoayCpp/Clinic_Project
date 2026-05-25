#include <iostream>
#include"ProjectFiles//Screens//MainMenu//clsMainMenu.h"
using namespace std;
void LoginHeaderScreen() {
	string LineSperator = clsUtil::UnderScore(9) + "";

	cout << LineSperator << "\n\n";
	cout << "\t\tLogin Screen" << "\n";
	cout << LineSperator << "\n";
}
clsUser ReadUser(bool UserDoesNotExists = false) {
	system("cls");
	LoginHeaderScreen();
	if (UserDoesNotExists) {
		cout << "Invalid Username/Password..!\n";
	}
	string Username = clsUserHelperFunctions::ReadUserName();
	string Password = clsUserHelperFunctions::ReadPassword();

	return clsUser::FindUser(Username, Password);
}
void LoginScreen() {

	CurrentUser = ReadUser();
	while (CurrentUser.IsEmpty()) {
		CurrentUser = ReadUser(true);
	}
	clsMainMenu::ShowMenu();
}
void StartProgram() {
	while (true)
		LoginScreen();
}
int main() {

	StartProgram();
   return 0;
}
