#pragma once
#include"../clsHeaderScreen.h"
#include"../..//Libraries/clsInputValidate.h"

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

		cout << "Press any Key to go to Main Menu\n";
		system("pause>0");
		ShowMenu();
	}

	static void _ShowDoctorsListScreen() {

		cout << "Show All Doctors is not implemented\n";

	}
	static void _ShowAddNewDoctorScreen() {

		cout << "Add New Doctor is not implemented\n";

	}
	static void _ShowUpdateDoctorScreen() {


		cout << "Update Doctors is not implemented\n";

	}
	static void _ShowDeleteDoctorScreen() {

		cout << "Delete Doctors is not implemented\n";


	}
	static void _ShowFindDoctorScreen() {

		cout << "Find Doctors is not implemented\n";

	}

	static void _PerformManageDoctorsMenuOperation(enManageDoctorMenuOption option) {


		switch (option)
		{
		case enManageDoctorMenuOption::eShowAllDoctorsScreen:
			system("cls");
			_ShowDoctorsListScreen();
			_BackToMenu();
			break;

		case enManageDoctorMenuOption::eAddNewDoctor:
			system("cls");
			_ShowAddNewDoctorScreen();
			_BackToMenu();
			break;

		case enManageDoctorMenuOption::eUpdateDoctor:

			system("cls");
			_ShowUpdateDoctorScreen();
			_BackToMenu();
			break;

		case enManageDoctorMenuOption::eDeleteDoctor:
			system("cls");
			_ShowDeleteDoctorScreen();
			_BackToMenu();
			break;

		case enManageDoctorMenuOption::eFindDoctor:
			system("cls");
			_ShowFindDoctorScreen();
			_BackToMenu();
			break;

		case enManageDoctorMenuOption::eBackToMainMenu:
			return;

		}
	}

public:


	static void ShowMenu() {

		system("cls");
		showMainHeader("\t Manage Doctor Menu Screen");
		string LineSperator = "=============================================\n";

		cout << LineSperator;
		cout << "[1] Show All Doctors.\n";
		cout << "[2] Add New Doctor.\n";
		cout << "[3] Update Doctor.\n";
		cout << "[4] Delete Doctor.\n";
		cout << "[5] Find Doctor\n";
		cout << "[6] Back To Main Menu\n";
		cout << LineSperator;

		_PerformManageDoctorsMenuOperation((enManageDoctorMenuOption)_ReadManageDoctorsMenuOption());


	}



};

