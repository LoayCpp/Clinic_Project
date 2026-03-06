#pragma once
#include"../clsHeaderScreen.h"
#include"../..//Libraries/clsInputValidate.h"
#include<iomanip>
class clsMainMenu: protected clsHeaderScreen
{

private:

	enum eOption
	{
		eManagePatientsMenu=1,
		eManageDoctorsMenu=2,
		eManageUsersMenu=3,
		eManageAppointmentsMenu=4,
		eLogout=5
	};
	static short _ReadMainMenuOption() {
		short num;
		cout <<setw(45) << left << "" << "Enter The Number from [1-5]:";
		num = clsInputValidate::ReadNumberBetween<short>(1, 5);

		return num;
	}
	static void _BackToMenue() {

		cout << "Press any Key to go to Main Menu\n";
		system("pause>0");
		ShowMenu();
	}

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
	static void _PerformMainMenueOperation(eOption option) {


		switch (option)
		{
		case clsMainMenu::eManagePatientsMenu:
			system("cls");
			_ShowManagePatientsMenueScreen();
			_BackToMenue();
			break;

		case clsMainMenu::eManageDoctorsMenu:
			system("cls");
			_ShowManageDoctorMenueScreen();
			_BackToMenue();
			break;
		case clsMainMenu::eManageUsersMenu:

			system("cls");
			_ShowManageUsersMenueScreen();
			_BackToMenue();

			break;
		case clsMainMenu::eManageAppointmentsMenu:
			system("cls");
			_ShowManageAppointmentMenueScreen();
			_BackToMenue();
			break;
		case clsMainMenu::eLogout:
			system("cls");
			_ShowLogoutScreen();
			_BackToMenue();
			break;
		}







	}

public:


	static void ShowMenu() {

		system("cls");
		showMainHeader("\t\t\t\t\t\t\tMain Menu Screen","",5);

		cout << setw(45) << left << "" << "[1]Manage Patients Menue\n";
		cout << setw(45) << left << "" << "[2]Manage Doctors Menue\n";
		cout << setw(45) << left << "" << "[3]Manage Users Menue\n";
		cout << setw(45) << left << "" << "[4]Manage Appointments Menue\n";
		cout << setw(45) << left << "" << "[5]Log out\n";
		cout << "\t\t\t\t\t======================================\n";
		_PerformMainMenueOperation(eOption(_ReadMainMenuOption()));


	}



};

