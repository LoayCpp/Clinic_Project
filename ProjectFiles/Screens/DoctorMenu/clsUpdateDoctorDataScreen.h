#pragma once
#include "..//clsHeaderScreen.h"
#include "clsDoctorHelperFunctions .h"
#include"..//clsSharedHelperFunctions.h"
using namespace std;
class clsUpdateDoctorDataScreen :public clsHeaderScreen
{
	

	class clsUpdateDoctorDataMenu {





	public:


		static void ShowUpdateDoctorDataMenu(string title, clsDoctor& doctor) {



		}


	};



public:
	static void ShowUpdateDoctorData() {

		string title = clsUtil::Tabs(1) + "     Update Doctor's Data Screen";
		ShowMainHeader(title);
		clsDoctor doctor = clsDoctorHelperFunctions::ReadDoctorByID();
		clsDoctorHelperFunctions::PrintDoctorInfo(doctor);

		if (!clsInputValidate::CheckAnswer("Are you sure you want to update this doctors? [Y/N] ")) {

			cout << "update was cancelled.\n";

			return;


		}
		clsUpdateDoctorDataMenu::ShowUpdateDoctorDataMenu(title, doctor);

		clsSharedHelperFunctions::PrintTransactionStatus(doctor.Save(), "Doctor", "update");
	}

};