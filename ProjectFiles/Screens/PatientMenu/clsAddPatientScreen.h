#include "..//clsHeaderScreen.h"
#include "clsPatientHelperFunctions.h"
class clsAddPatientScreen : public clsHeaderScreen {
private:

public:
	static void ShowAddPatient() {
		string title = clsUtil::Tabs(1) + "      Add Patient Screen";
		ShowMainHeader(title);

		clsPatient newPatient = clsPatient::GetNewPatientObject();

		clsPatientHelperFunctions::ReadPatientData(newPatient);
		clsPatientHelperFunctions::PrintPatientInfo(newPatient);

		if (!clsInputValidate::CheckAnswer("Are you sure you want to perform this operation? [Y/N] ")) {
			cout << "Operation was cancelled.\n";

			return;


		}


		clsSharedHelperFunctions::PrintTransactionStatus(newPatient.Save(), "patient", "Added");
	}
};