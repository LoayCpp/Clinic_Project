#pragma once
#include"../clsHeaderScreen.h"
#include"../..//Libraries/clsInputValidate.h"

class clsManagePatientMenue: protected clsHeaderScreen
{

private:

	enum enManagePatientMenueOption
	{
		eShowAllPatientsScreen=1,
		eAddNewPatient,
		eUpdatePatient,
		eDeletePatient,
		eFindPatient,
		eBackToMainMenue
	};

	static short _ReadManagePatientMenueOption() {
		
		cout << "Enter The Number from [1-6]:";
		return  clsInputValidate::ReadNumberBetween<short>(1, 6);
	}

	static void _BackToMenue() {

		cout << "Press any Key to go to Main Menu\n";
		system("pause>0");
		ShowMenue();
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
	static void _PerformManagePatientMenueOperation(enManagePatientMenueOption option) {


		switch (option)
		{
		case enManagePatientMenueOption::eShowAllPatientsScreen:
			system("cls");
			_ShowAllPatientsScreen();
			_BackToMenue();
			break;

		case enManagePatientMenueOption::eAddNewPatient:
			system("cls");
			_ShowAddNewPatientScreen();
			_BackToMenue();
			break;

		case enManagePatientMenueOption::eUpdatePatient:

			system("cls");
			_ShowUpdatePatienteScreen();
			_BackToMenue();
			break;

		case enManagePatientMenueOption::eDeletePatient:
			system("cls");
			_ShowDeletePatientScreen();
			_BackToMenue();
			break;

		case enManagePatientMenueOption::eFindPatient:
			system("cls");
			_ShowFindPatientScreen();
			_BackToMenue();
			break;

		case enManagePatientMenueOption::eBackToMainMenue:
			return;
		
		}
	}

public:


	static void ShowMenue() {

		system("cls");
		showMainHeader("\tManage Patient Menue Screen");
		string LineSperator = "=============================================\n";

		cout << LineSperator;
		cout << "[1] Show All Patients.\n";
		cout << "[2] Add New Patient.\n";
		cout << "[3] Update Patient.\n";
		cout << "[4] Delete Patient.\n";
		cout << "[5] Find Patient\n";
		cout << "[6] Back To Main Menue\n";
		cout << LineSperator;

		_PerformManagePatientMenueOperation((enManagePatientMenueOption)_ReadManagePatientMenueOption());


	}



};

