#include "..//clsHeaderScreen.h"
#include "clsPatientHelperFunctions.h"
class clsFindPatientScreen : public clsHeaderScreen {

public:
	static void ShowFindPatient() {
		string title = clsUtil::Tabs(1) + "     Find Patient Screen";
		ShowMainHeader(title);
		clsPatient patient = clsPatientHelperFunctions::ReadPatientByID();
		clsPatientHelperFunctions::PrintPatientInfo(patient);
	}

};