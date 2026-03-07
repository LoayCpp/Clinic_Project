#pragma once
#include"../clsHeaderScreen.h"
#include"../..//Libraries/clsInputValidate.h"
#include<iomanip>
class clsMainMenu: protected clsHeaderScreen
{

private:

	enum enMainMenueOption
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

	/*static void _BackToMenue() {

		cout << "Press any Key to go to Main Menu\n";
		system("pause>0");
		ShowMenu();
	}*/

	static void _ShowManagePatientsMenueScreen() {

		cout << "Mange Patient not implement\n";

	}
	static void _ShowManageDoctorMenueScreen() {

		cout << "Mange Docotr not implement\n";

	}
	static void _ShowManageUsersMenueScreen() {


		cout << "Mange Users not implement\n";

	}
	static void _ShowManageAppointmentMenueScreen() {

		cout << "Mange Appointment not implement\n";


	}
	static void _ShowLogoutScreen() {

		cout << "Mange logout not implement\n";

	 }
	static void _PerformMainMenueOperation(enMainMenueOption option) {


		switch (option)
		{
		case clsMainMenu::eManagePatientsMenu:
			system("cls");
			_ShowManagePatientsMenueScreen();
		
			break;

		case clsMainMenu::eManageDoctorsMenu:
			system("cls");
			_ShowManageDoctorMenueScreen();
	
			break;
		case clsMainMenu::eManageUsersMenu:

			system("cls");
			_ShowManageUsersMenueScreen();
			

			break;
		case clsMainMenu::eManageAppointmentsMenu:
			system("cls");
			_ShowManageAppointmentMenueScreen();
		
			break;
		case clsMainMenu::eLogout:
			system("cls");
			_ShowLogoutScreen();
		
			break;
		}

		ShowMenu();





	}

public:


	static void ShowMenu() {

		system("cls");
		showMainHeader("\t\tMain Menu Screen");

		cout << "[1]Manage Patients Menue\n";
		cout << "[2]Manage Doctors Menue\n";
		cout << "[3]Manage Users Menue\n";
		cout << "[4]Manage Appointments Menue\n";
		cout << "[5]Log out\n";
		cout << "======================================\n";
		_PerformMainMenueOperation((enMainMenueOption)_ReadMainMenuOption());


	}



};

