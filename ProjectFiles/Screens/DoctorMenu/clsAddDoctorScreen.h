#pragma once
#include "..//clsHeaderScreen.h"
#include "clsDoctorHelperFunctions .h"
class clsAddDoctorScreen : public clsHeaderScreen {
private:

public:
	static void ShowAddDoctor() {
		string title = clsUtil::Tabs(1) + "      Add Doctor Screen";
		ShowMainHeader(title);
		map<string, clsDoctor> mDoctors = clsDoctor::GetAllDoctors();
		if (mDoctors.size() !=5) {



			clsDoctor newDoctor = clsDoctor::GetNewDoctorObject();

			clsDoctorHelperFunctions::ReadDoctorData(newDoctor);
			clsDoctorHelperFunctions::PrintDoctorInfo(newDoctor);

			if (!clsInputValidate::CheckAnswer("Are you sure you want to perform this operation? [Y/N] ")) {
				cout << "Operation was cancelled.\n";

				return;


			}


			clsSharedHelperFunctions::PrintTransactionStatus(newDoctor.Save(), "Doctor", "Added");
		}

		else {

			cout << "\n\nYou Cannot add a new doctor because\nThe system already has the maximum\n allowed number of doctors(5).\n" << endl;
		}
	}
};