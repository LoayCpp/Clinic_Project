#pragma once
#include"../clsHeaderScreen.h"
#include"../..//Libraries/clsInputValidate.h"

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

		cout << "Press any Key to go to Main Menu\n";
		system("pause>0");
		ShowMenu();
	}

	static void _ShowAppointmentsListScreen() {

		cout << "Show All Appointments is not implemented\n";

	}
	static void _ShowAddNewAppointmentScreen() {

		cout << "Add New Appointment is not implemented\n";

	}

	static void _ShowUpdateAppointmentScreen() {


		cout << "Update Appointments is not implemented\n";

	}
	static void _ShowDeleteAppointmentScreen() {

		cout << "Delete Appointments is not implemented\n";


	}
	static void _ShowFindAppointmentScreen() {

		cout << "Find Appointments is not implemented\n";

	}

	static void _PerformManageAppointmentsMenuOperation(enManageAppointmentMenuOption option) {


		switch (option)
		{
		case enManageAppointmentMenuOption::eShowAllAppointmentsScreen:
			system("cls");
			_ShowAppointmentsListScreen();
			_BackToMenu();
			break;

		case enManageAppointmentMenuOption::eAddNewAppointment:
			system("cls");
			_ShowAddNewAppointmentScreen();
			_BackToMenu();
			break;

		case enManageAppointmentMenuOption::eUpdateAppointment:

			system("cls");
			_ShowUpdateAppointmentScreen();
			_BackToMenu();
			break;

		case enManageAppointmentMenuOption::eDeleteAppointment:
			system("cls");
			_ShowDeleteAppointmentScreen();
			_BackToMenu();
			break;

		case enManageAppointmentMenuOption::eFindAppointment:
			system("cls");
			_ShowFindAppointmentScreen();
			_BackToMenu();
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
		cout << "[1] Show All Appointments.\n";
		cout << "[2] Add New Appointment.\n";
		cout << "[3] Update Appointment.\n";
		cout << "[4] Delete Appointment.\n";
		cout << "[5] Find Appointment\n";
		cout << "[6] Back To Main Menu\n";
		cout << LineSperator;

		_PerformManageAppointmentsMenuOperation((enManageAppointmentMenuOption)_ReadManageAppointmentsMenuOption());


	}



};

