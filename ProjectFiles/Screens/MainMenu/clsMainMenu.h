#pragma once
#include"../clsHeaderScreen.h"
#include"../..//Libraries/clsInputValidate.h"
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

	/*static void _BackToMenu() {

		cout << "Press any Key to go to Main Menu\n";
		system("pause>0");
		ShowMenu();
	}*/

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

		cout << "Mange logout not implement\n";

	 }
	static void _PerformMainMenuOperation(enMainMenuOption option) {


		switch (option)
		{
		case clsMainMenu::eManagePatientsMenu:
			system("cls");
			_ShowManagePatientsMenuScreen();
		
			break;

		case clsMainMenu::eManageDoctorsMenu:
			system("cls");
			_ShowManageDoctorMenuScreen();
	
			break;
		case clsMainMenu::eManageUsersMenu:

			system("cls");
			_ShowManageUsersMenuScreen();
			

			break;
		case clsMainMenu::eManageAppointmentsMenu:
			system("cls");
			_ShowManageAppointmentMenuScreen();
		
			break;
		case clsMainMenu::eLogout:
			system("cls");
			_ShowLogoutScreen();
<<<<<<< HEAD
			
=======

			return;

>>>>>>> d8490447f09c03fa6d859dae0087b108e535cbff
			break;
		}

		ShowMenu();





	}

public:


	static void ShowMenu() {

		system("cls");
<<<<<<< HEAD
		showMainHeader("\t      Main Menu Screen");
=======
	    showMainHeader("\t      Main Menu Screen");
>>>>>>> d8490447f09c03fa6d859dae0087b108e535cbff

		string LineSperator = "=============================================\n";

		cout << LineSperator;
		cout << "[1] Manage Patients Menu\n";
		cout << "[2] Manage Doctors Menu\n";
		cout << "[3] Manage Users Menu\n";
		cout << "[4] Manage Appointments Menu\n";
		cout << "[5] Log out\n";
		cout << LineSperator;

		_PerformMainMenuOperation((enMainMenuOption)_ReadMainMenuOption());


	}



};

