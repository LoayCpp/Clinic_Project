#pragma once
#include"..//clsHeaderScreen.h"
#include "..//..//Globlas//Globals.h"
#include"..//..//Libraries/clsInputValidate.h"
#include"ProjectFiles//Screens//DoctorMenu//clsShowDoctorsTableScreen.h"
#include"ProjectFiles//Screens//DoctorMenu//clsAddDoctorScreen.h"
#include"ProjectFiles//Screens//DoctorMenu//clsUpdateDoctorDataScreen.h"
#include"ProjectFiles//Screens//DoctorMenu//clsDeleteDoctorScreen.h"
#include"ProjectFiles//Screens//DoctorMenu//clsFindDoctorScreen.h"
class clsManageDoctorMenu : protected clsHeaderScreen
{

private:

	enum enManageDoctorMenuOption
	{
		eShowAllDoctorsScreen = 1,
		eAddNewDoctor,
		eUpdateDoctor,
		eDeleteDoctor,
		eFindDoctor,
		eBackToMainMenu
	};

	static short _ReadManageDoctorsMenuOption() {

		cout << "Enter The Number from [1-6]:";
		return  clsInputValidate::ReadNumberBetween<short>(1, 6);
	}

	static void _BackToMenu() {

		cout << "Press any Key to back to Main Menu\n";
		system("pause>0");
		ShowMenu();
	}

	static void _ShowDoctorsListScreen() {

		clsShowDoctorsTableScreen::ShowDoctorsTable();

	}
	static void _ShowAddNewDoctorScreen() {

		clsAddDoctorScreen::ShowAddDoctor();

	}
	static void _ShowUpdateDoctorScreen() {

		clsUpdateDoctorDataScreen::ShowUpdateDoctorData();
	}
	static void _ShowDeleteDoctorScreen() {

		clsDeleteDoctorScreen::ShowDeleteDoctor();
	}
	static void _ShowFindDoctorScreen() {

		clsFindDoctorScreen::ShowFindDoctor();
	}

	static void _PerformManageDoctorsMenuOperation(enManageDoctorMenuOption option) {


		switch (option)
		{
		case enManageDoctorMenuOption::eShowAllDoctorsScreen:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eShowAllDoctors)) {
				system("cls");
				_ShowDoctorsListScreen();
				_BackToMenu();
			}
		
			break;

		case enManageDoctorMenuOption::eAddNewDoctor:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eAddNewDoctor)) {
				system("cls");
				_ShowAddNewDoctorScreen();
				_BackToMenu();
			}
		
			break;

		case enManageDoctorMenuOption::eUpdateDoctor:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eUpdateDoctor)) {
				system("cls");
				_ShowUpdateDoctorScreen();
				_BackToMenu();
			}
	
			break;

		case enManageDoctorMenuOption::eDeleteDoctor:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eDeleteDoctor)) {
				system("cls");
				_ShowDeleteDoctorScreen();
				_BackToMenu();
			}
		
			break;

		case enManageDoctorMenuOption::eFindDoctor:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eFindDoctor)) {
				system("cls");
				_ShowFindDoctorScreen();
				_BackToMenu();
			}
	
			break;

		case enManageDoctorMenuOption::eBackToMainMenu:
			return;

		}
	}

public:


	static void ShowMenu() {

		system("cls");
		ShowMainHeader("\t Manage Doctor Menu Screen");
		string LineSperator = "=============================================\n";

		cout << LineSperator;
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eShowAllDoctors))
			cout << "[1] Show All Doctors.\n";
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eAddNewDoctor))
			cout << "[2] Add New Doctor.\n";
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eUpdateDoctor))
			cout << "[3] Update Doctor.\n";
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eDeleteDoctor))
			cout << "[4] Delete Doctor.\n";
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eFindDoctor))
			cout << "[5] Find Doctor\n";
		cout << "[6] Back To Main Menu\n";
		cout << LineSperator;

		_PerformManageDoctorsMenuOperation((enManageDoctorMenuOption)_ReadManageDoctorsMenuOption());


	}



};

