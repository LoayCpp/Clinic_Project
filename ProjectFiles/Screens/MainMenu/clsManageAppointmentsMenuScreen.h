
#pragma once
#include"..//clsHeaderScreen.h"
#include "..//..//Globlas//Globals.h"
#include"..//..//Libraries/clsInputValidate.h"
#include"..//AppointmentMenu//clsAddAppointmentScreen.h"
#include"..//AppointmentMenu//clsDeleteAppointmentScreen.h"
#include"..//AppointmentMenu//clsFindAppointmentScreen.h"
#include"..//AppointmentMenu//clsShowAppointmentTableScreen.h"
#include"..//AppointmentMenu//clsUpdateAppointmentScreen.h"


class clsManageAppointmentsMenuScreen : protected clsHeaderScreen
{

private:

	enum enManageAppointmentMenuOption
	{
		eShowAllAppointmentsScreen = 1,
		eAddNewAppointment,
		eUpdateAppointment,
		eDeleteAppointment,
		eFindAppointment,
		eBackToMainMenu
	};

	static short _ReadManageAppointmentsMenuOption() {

		cout << "Enter The Number from [1-6]:";
		return  clsInputValidate::ReadNumberBetween<short>(1, 6);
	}

	static void _BackToMenu() {

		cout << "Press any Key to back to Main Menu\n";
		system("pause>0");
		ShowMenu();
	}

	static void _ShowAppointmentsListScreen() {

		clsShowAppointmentTableScreen::ShowAppoitmentsTable();

	}
	static void _ShowAddNewAppointmentScreen() {

		clsAddAppointmentScreen::ShowAddAppointment();

	}

	static void _ShowUpdateAppointmentScreen() {


		clsUpdateAppointmentScreen::ShowUpdateAppointmentData();

	}
	static void _ShowDeleteAppointmentScreen() {

		clsDeleteAppointmentScreen::ShowDeleteDoctor();


	}
	static void _ShowFindAppointmentScreen() {

		clsFindAppointmentScreen::ShowFindAppointment();

	}

	static void _PerformManageAppointmentsMenuOperation(enManageAppointmentMenuOption option) {


		switch (option)
		{
		case enManageAppointmentMenuOption::eShowAllAppointmentsScreen:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eShowAllAppointments)) {
				system("cls");
				_ShowAppointmentsListScreen();
				_BackToMenu();
			}
		
			break;

		case enManageAppointmentMenuOption::eAddNewAppointment:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eAddNewAppointment)) {
				system("cls");
				_ShowAddNewAppointmentScreen();
				_BackToMenu();
			}
		
			break;

		case enManageAppointmentMenuOption::eUpdateAppointment:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eUpdateAppointment)) {
				system("cls");
				_ShowUpdateAppointmentScreen();
				_BackToMenu();
			}
		
			break;

		case enManageAppointmentMenuOption::eDeleteAppointment:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eDeleteAppointment)) {
				system("cls");
				_ShowDeleteAppointmentScreen();
				_BackToMenu();
			}
			
			break;

		case enManageAppointmentMenuOption::eFindAppointment:
			if (CurrentUser.Permissions.IsUserHasPermissions(
				CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eFindAppointment)) {
				system("cls");
				_ShowFindAppointmentScreen();
				_BackToMenu();
			}
			
			break;

		case enManageAppointmentMenuOption::eBackToMainMenu:
			return;

		}
	}

public:


	static void ShowMenu() {

		system("cls");
		ShowMainHeader("       Manage Appointment Menu Screen");
		string LineSperator = "=============================================\n";

		cout << LineSperator;
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eShowAllAppointments))
		cout << "[1] Show All Appointments.\n";
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eAddNewAppointment))
		cout << "[2] Add New Appointment.\n";
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eUpdateAppointment))
		cout << "[3] Update Appointment.\n";
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eDeleteAppointment))
		cout << "[4] Delete Appointment.\n";
		if (CurrentUser.Permissions.IsUserHasPermissions(
			CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eFindAppointment))
			cout << "[5] Find Appointment\n";
		cout << "[6] Back To Main Menu\n";
		cout << LineSperator;

		_PerformManageAppointmentsMenuOperation((enManageAppointmentMenuOption)_ReadManageAppointmentsMenuOption());


	}



};

