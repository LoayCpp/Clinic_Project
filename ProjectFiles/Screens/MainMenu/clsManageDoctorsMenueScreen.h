#pragma once
#include"../clsHeaderScreen.h"
#include"../..//Libraries/clsInputValidate.h"

class clsManageDoctorMenue : protected clsHeaderScreen
{

private:

	enum enManageDoctorMenueOption
	{
		eShowAllDoctorsScreen = 1,
		eAddNewDoctor,
		eUpdateDoctor,
		eDeleteDoctor,
		eFindDoctor,
		eBackToMainMenue
	};

	static short _ReadManageDoctorsMenueOption() {

		cout << "Enter The Number from [1-6]:";
		return  clsInputValidate::ReadNumberBetween<short>(1, 6);
	}

	static void _BackToMenue() {

		cout << "Press any Key to go to Main Menu\n";
		system("pause>0");
		ShowMenue();
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

	static void _PerformManageDoctorsMenueOperation(enManageDoctorMenueOption option) {


		switch (option)
		{
		case enManageDoctorMenueOption::eShowAllDoctorsScreen:
			system("cls");
			_ShowDoctorsListScreen();
			_BackToMenue();
			break;

		case enManageDoctorMenueOption::eAddNewDoctor:
			system("cls");
			_ShowAddNewDoctorScreen();
			_BackToMenue();
			break;

		case enManageDoctorMenueOption::eUpdateDoctor:

			system("cls");
			_ShowUpdateDoctorScreen();
			_BackToMenue();
			break;

		case enManageDoctorMenueOption::eDeleteDoctor:
			system("cls");
			_ShowDeleteDoctorScreen();
			_BackToMenue();
			break;

		case enManageDoctorMenueOption::eFindDoctor:
			system("cls");
			_ShowFindDoctorScreen();
			_BackToMenue();
			break;

		case enManageDoctorMenueOption::eBackToMainMenue:
			return;

		}
	}

public:


	static void ShowMenue() {

		system("cls");
		showMainHeader("\tManage Doctor Menue Screen");
		string LineSperator = "=============================================\n";

		cout << LineSperator;
		cout << "[1] Show All Doctors.\n";
		cout << "[2] Add New Doctor.\n";
		cout << "[3] Update Doctor.\n";
		cout << "[4] Delete Doctor.\n";
		cout << "[5] Find Doctor\n";
		cout << "[6] Back To Main Menue\n";
		cout << LineSperator;

		_PerformManageDoctorsMenueOperation((enManageDoctorMenueOption)_ReadManageDoctorsMenueOption());


	}



};

