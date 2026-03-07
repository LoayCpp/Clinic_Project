#pragma once
#include"../clsHeaderScreen.h"
#include"../..//Libraries/clsInputValidate.h"
#include"clsManagePatientMenu.h"
#include"clsManageDoctorsMenueScreen.h"
class clsMainMenu: protected clsHeaderScreen
{

private:

	enum enMainMenueOption
	{
		eManagePatientsMenu=1,
		eManageDoctorsMenue,
		eManageUsersMenue,
		eManageAppointmentsMenue,
		eLogout
	};

	static short _ReadMainMenueOption() {
		short num;
		cout  << "Enter The Number from [1-5]:";
		num = clsInputValidate::ReadNumberBetween<short>(1, 5);

		return num;
	}

	/*static void _BackToMenue() {

		cout << "Press any Key to go to Main Menu\n";
		system("pause>0");
		ShowMenue();
	}*/

	static void _ShowManagePatientsMenueScreen() {

		clsManagePatientMenue::ShowMenue();

	}
	static void _ShowManageDoctorMenueScreen() {

		clsManageDoctorMenue::ShowMenue();

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

		case clsMainMenu::eManageDoctorsMenue:
			system("cls");
			_ShowManageDoctorMenueScreen();
	
			break;
		case clsMainMenu::eManageUsersMenue:

			system("cls");
			_ShowManageUsersMenueScreen();
			

			break;
		case clsMainMenu::eManageAppointmentsMenue:
			system("cls");
			_ShowManageAppointmentMenueScreen();
		
			break;
		case clsMainMenu::eLogout:
			system("cls");
			_ShowLogoutScreen();
		
			break;
		}

		ShowMenue();





	}

public:


	static void ShowMenue() {

		system("cls");
		showMainHeader("\t\tMain Menu Screen");

		string LineSperator = "=============================================\n";

		cout << LineSperator;
		cout << "[1] Manage Patients Menue\n";
		cout << "[2] Manage Doctors Menue\n";
		cout << "[3] Manage Users Menue\n";
		cout << "[4] Manage Appointments Menue\n";
		cout << "[5] Log out\n";
		cout << LineSperator;

		_PerformMainMenueOperation((enMainMenueOption)_ReadMainMenueOption());


	}



};

