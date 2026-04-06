#pragma once
#include"../clsHeaderScreen.h"
#include"../..//Libraries/clsInputValidate.h"

class clsManagePatientMenu: protected clsHeaderScreen
{

private:

	enum enManagePatientMenuOption
	{
		eShowAllPatientsScreen=1,
		eAddNewPatient,
		eUpdatePatient,
		eDeletePatient,
		eFindPatient,
		eBackToMainMenu
	};

	static short _ReadManagePatientMenuOption() {
		
		cout << "Enter The Number from [1-6]:";
		return  clsInputValidate::ReadNumberBetween<short>(1, 6);
	}

	static void _BackToMenu() {

		cout << "Press any Key to back to Main Menu\n";
		system("pause>0");
		ShowMenu();
	}

	static void _ShowAllPatientsScreen() {

		cout << "Show All Patients is not implemented\n";

	}
	static void _ShowAddNewPatientScreen() {

		cout << "Add New Patient is not implemented\n";

	}
	static void _ShowUpdatePatienteScreen() {


		cout << "Update Patients is not implemented\n";

	}
	static void _ShowDeletePatientScreen() {

		cout << "Delete Patients is not implemented\n";


	}
	static void _ShowFindPatientScreen() {

		cout << "Find Patients is not implemented\n";

	 }
	static void _PerformManagePatientMenuOperation(enManagePatientMenuOption option) {


		switch (option)
		{
		case enManagePatientMenuOption::eShowAllPatientsScreen:
			system("cls");
			_ShowAllPatientsScreen();
			_BackToMenu();
			break;

		case enManagePatientMenuOption::eAddNewPatient:
			system("cls");
			_ShowAddNewPatientScreen();
			_BackToMenu();
			break;

		case enManagePatientMenuOption::eUpdatePatient:

			system("cls");
			_ShowUpdatePatienteScreen();
			_BackToMenu();
			break;

		case enManagePatientMenuOption::eDeletePatient:
			system("cls");
			_ShowDeletePatientScreen();
			_BackToMenu();
			break;

		case enManagePatientMenuOption::eFindPatient:
			system("cls");
			_ShowFindPatientScreen();
			_BackToMenu();
			break;

		case enManagePatientMenuOption::eBackToMainMenu:
			return;
		
		}
	}

public:


	static void ShowMenu() {

		system("cls");
		ShowMainHeader("\tManage Patient Menu Screen");
		string LineSperator = "=============================================\n";

		cout << LineSperator;
		cout << "[1] Show All Patients.\n";
		cout << "[2] Add New Patient.\n";
		cout << "[3] Update Patient.\n";
		cout << "[4] Delete Patient.\n";
		cout << "[5] Find Patient\n";
		cout << "[6] Back To Main Menu\n";
		cout << LineSperator;

		_PerformManagePatientMenuOperation((enManagePatientMenuOption)_ReadManagePatientMenuOption());


	}



};

