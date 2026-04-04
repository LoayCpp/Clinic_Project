#pragma once
#include"../clsHeaderScreen.h"
#include"../..//Libraries/clsInputValidate.h"

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

		cout << "Press any Key to go to Main Menu\n";
		system("pause>0");
		ShowMenu();
	}

	static void _ShowUsersListScreen() {

		cout << "Show All Users is not implemented\n";

	}
	static void _ShowAddNewUserScreen() {

		cout << "Add New User is not implemented\n";

	}

	static void _ShowUpdateUserScreen() {


		cout << "Update Users is not implemented\n";

	}
	static void _ShowDeleteUserScreen() {

		cout << "Delete Users is not implemented\n";


	}
	static void _ShowFindUserScreen() {

		cout << "Find Users is not implemented\n";

	}

	static void _PerformManageUsersMenuOperation(enManageUserMenuOption option) {


		switch (option)
		{
		case enManageUserMenuOption::eShowAllUsersScreen:
			system("cls");
			_ShowUsersListScreen();
			_BackToMenu();
			break;

		case enManageUserMenuOption::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_BackToMenu();
			break;

		case enManageUserMenuOption::eUpdateUser:

			system("cls");
			_ShowUpdateUserScreen();
			_BackToMenu();
			break;

		case enManageUserMenuOption::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_BackToMenu();
			break;

		case enManageUserMenuOption::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_BackToMenu();
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
		cout << "[1] Show All Users.\n";
		cout << "[2] Add New User.\n";
		cout << "[3] Update User.\n";
		cout << "[4] Delete User.\n";
		cout << "[5] Find User\n";
		cout << "[6] Back To Main Menu\n";
		cout << LineSperator;

		_PerformManageUsersMenuOperation((enManageUserMenuOption)_ReadManageUsersMenuOption());


	}



};

