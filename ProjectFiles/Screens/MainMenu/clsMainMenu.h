#pragma once
#include"..//clsHeaderScreen.h"
#include "..//..//Globlas//Globals.h"
#include"..//..//Libraries//clsInputValidate.h"
#include"clsManagePatientMenu.h"
#include "clsManageDoctorsMenuScreen.h"
#include"clsManageUsersMenuScreen.h"
#include"clsManageAppointmentsMenuScreen.h"
class clsMainMenu: protected clsHeaderScreen
{

private:

	enum enMainMenuOption
	{
		eManagePatientsMenu=1,
		eManageDoctorsMenu,
		eManageUsersMenu,
		eManageAppointmentsMenu,
		eLogout
	};

	static short _ReadMainMenuOption() {
		short num;
		cout  << "Enter The Number from [1-5]:";
		num = clsInputValidate::ReadNumberBetween<short>(1, 5);

		return num;
	}


	static void _ShowManagePatientsMenuScreen() {

		clsManagePatientMenu::ShowMenu();

	}
	static void _ShowManageDoctorMenuScreen() {

		clsManageDoctorMenu::ShowMenu();

	}
	static void _ShowManageUsersMenuScreen() {


		clsManageUsersMenuScreen::ShowMenu();

	}
	static void _ShowManageAppointmentMenuScreen() {

		clsManageAppointmentsMenuScreen::ShowMenu();


	}
	static void _ShowLogoutScreen() {

		CurrentUser = clsUser::GetEmptyObject();

	 }
	static void _PerformMainMenuOperation(enMainMenuOption option) {


		switch (option)
		{
		case clsMainMenu::eManagePatientsMenu:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role ,clsPermissions::enUserPermissionsOption::eManagePatientsMenu)) {
				system("cls");
				_ShowManagePatientsMenuScreen();
			}
		
		
			break;

		case clsMainMenu::eManageDoctorsMenu:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eManageDoctorsMenu)) {
				system("cls");
				_ShowManageDoctorMenuScreen();
			}
			break;
		case clsMainMenu::eManageUsersMenu:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eManageUsersMenu)) {
				system("cls");
				_ShowManageUsersMenuScreen();
			}

			break;
		case clsMainMenu::eManageAppointmentsMenu:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eManageAppointmentsMenu)) {
				system("cls");
				_ShowManageAppointmentMenuScreen();
			}
			break;
		case clsMainMenu::eLogout:
			system("cls");
			_ShowLogoutScreen();
			return;
			break;
		}

		ShowMenu();





	}

public:


	static void ShowMenu() {

		system("cls");

	    ShowMainHeader("\t      Main Menu Screen");


		string LineSperator = "=============================================\n";

		cout << LineSperator;
		

		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eManagePatientsMenu))
			cout << "[1] Manage Patients Menu\n";

		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eManageDoctorsMenu))
			cout << "[2] Manage Doctors Menu\n";

		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eManageUsersMenu))
			cout << "[3] Manage Users Menu\n";

		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eManageAppointmentsMenu))
			cout << "[4] Manage Appointments Menu\n";

		cout << "[5] Log out\n";
		cout << LineSperator;

		_PerformMainMenuOperation((enMainMenuOption)_ReadMainMenuOption());


	}



};

