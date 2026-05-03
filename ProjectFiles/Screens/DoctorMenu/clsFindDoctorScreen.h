#pragma once
#include "..//clsHeaderScreen.h"
#include "clsDoctorHelperFunctions .h"
class clsFindDoctorScreen : public clsHeaderScreen {

public:
	static void ShowFindDoctor() {
		string title = clsUtil::Tabs(1) + "      Find Doctor Screen";
		ShowMainHeader(title);
		clsDoctor doctor = clsDoctorHelperFunctions::ReadDoctorByID();
		clsDoctorHelperFunctions::PrintDoctorInfo(doctor);
	}
	
};