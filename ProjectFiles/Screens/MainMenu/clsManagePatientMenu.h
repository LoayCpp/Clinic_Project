#pragma once
#include"../clsHeaderScreen.h"
#include"../..//Libraries/clsInputValidate.h"
#include"..//PatientMenu/clsFindPatientScreen.h"
#include"..//PatientMenu/clsShowPatientsTableScreen.h"
#include"..//PatientMenu/clsUpdatePaitentsDataScreen.h"
class clsManagePatientMenu: protected clsHeaderScreen
{

private:

	enum enManagePatientMenuOption
	{
		eShowAllPatientsScreen=1,
		eUpdatePatient,
		eFindPatient,
		eBackToMainMenu
	};

	static short _ReadManagePatientMenuOption() {
		
		cout << "Enter The Number from [1-4]:";
		return  clsInputValidate::ReadNumberBetween<short>(1, 4);
	}

	static void _BackToMenu() {

		cout << "Press any Key to back to Main Menu\n";
		system("pause>0");
		ShowMenu();
	}

	static void _ShowAllPatientsScreen() {

		clsShowPatientsTableScreen::ShowPatientsTable();

	}

	static void _ShowUpdatePatienteScreen() {


		clsUpdatePaitentsDataScreen::ShowUpdatePatientData();

	}

	static void _ShowFindPatientScreen() {

		clsFindPatientScreen::ShowFindPatient();

	 }
	static void _PerformManagePatientMenuOperation(enManagePatientMenuOption option) {


		switch (option)
		{
		case enManagePatientMenuOption::eShowAllPatientsScreen:
			system("cls");
			_ShowAllPatientsScreen();
			_BackToMenu();
			break;

		

		case enManagePatientMenuOption::eUpdatePatient:

			system("cls");
			_ShowUpdatePatienteScreen();
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
		cout << "[2] Update Patient.\n";
		cout << "[3] Find Patient\n";
		cout << "[4] Back To Main Menu\n";
		cout << LineSperator;

		_PerformManagePatientMenuOperation((enManagePatientMenuOption)_ReadManagePatientMenuOption());


	}



};

