#pragma once
#include"..//clsHeaderScreen.h"
#include "..//..//Globlas//Globals.h"
#include"..//..//Libraries//clsInputValidate.h"
#include "..//UsersMenu//clsShowUsersTableScreen.h"
#include "..//UsersMenu//clsAddUserScreen.h"
#include "..//UsersMenu//clsUpdateUsersDataScreen.h"
#include "..//UsersMenu//clsDeleteUserScreen.h"
#include "..//UsersMenu//clsFindUserScreen.h"

class clsManageUsersMenuScreen : protected clsHeaderScreen
{

private:

	enum enManageUserMenuOption
	{
		eShowAllUsersScreen = 1,
		eAddNewUser,
		eUpdateUser,
		eDeleteUser,
		eFindUser,
		eBackToMainMenu
	};

	static short _ReadManageUsersMenuOption() {

		cout << "Enter The Number from [1-6]:";
		return  clsInputValidate::ReadNumberBetween<short>(1, 6);
	}

	static void _BackToMenu() {

		cout << "Press any Key to back to Main Menu\n";
		system("pause>0");
		ShowMenu();
	}

	static void _ShowUsersListScreen() {

		clsShowUsersTableScreen::ShowUsersTable();

	}
	static void _ShowAddNewUserScreen() {

		clsAddUserScreen::ShowAddUser();

	}

	static void _ShowUpdateUserScreen() {


		clsUpdateUsersDataScreen::ShowUpdateUserData();

	}
	static void _ShowDeleteUserScreen() {

		clsDeleteUserScreen::ShowDeleteDoctor();


	}
	static void _ShowFindUserScreen() {

		clsFindUserScreen::ShowFindUser();

	}

	static void _PerformManageUsersMenuOperation(enManageUserMenuOption option) {


		switch (option)
		{
		case enManageUserMenuOption::eShowAllUsersScreen:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eShowAllUsers)) {
				system("cls");
				_ShowUsersListScreen();
				_BackToMenu();
			}
	
			break;

		case enManageUserMenuOption::eAddNewUser:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eAddNewUser)) {
				system("cls");
				_ShowAddNewUserScreen();
				_BackToMenu();
			}
			
			break;

		case enManageUserMenuOption::eUpdateUser:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eUpdateUser)) {
				system("cls");
				_ShowUpdateUserScreen();
				_BackToMenu();
			}
	
			break;

		case enManageUserMenuOption::eDeleteUser:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eDeleteUser)) {
				system("cls");
				_ShowDeleteUserScreen();
				_BackToMenu();
			}
		
			break;

		case enManageUserMenuOption::eFindUser:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eFindUser)) {
				system("cls");
				_ShowFindUserScreen();
				_BackToMenu();
			}
			
			break;

		case enManageUserMenuOption::eBackToMainMenu:
			return;

		}
	}

public:


	static void ShowMenu() {

		system("cls");
		ShowMainHeader("\t   Manage User Menu Screen");
		string LineSperator = "=============================================\n";

		cout << LineSperator;
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eShowAllUsers))
			cout << "[1] Show All Users.\n";
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eAddNewUser))
			cout << "[2] Add New User.\n";
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eUpdateUser))
			cout << "[3] Update User.\n";
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eDeleteUser))
			cout << "[4] Delete User.\n";
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eFindUser))
			cout << "[5] Find User\n";
	
		cout << "[6] Back To Main Menu\n";
		cout << LineSperator;

		_PerformManageUsersMenuOperation((enManageUserMenuOption)_ReadManageUsersMenuOption());


	}



};

