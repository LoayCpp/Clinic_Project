#include "..//clsHeaderScreen.h"
#include "clsDoctorHelperFunctions .h"
class clsAddDoctorScreen : public clsHeaderScreen {
private:

public:
	static void ShowAddDoctor() {
		string title = clsUtil::Tabs(1) + "      Add Doctor Screen";
		ShowMainHeader(title);

		clsDoctor newDoctor = clsDoctor::GetNewDoctorObject();

		clsDoctorHelperFunctions::ReadDoctorData(newDoctor);
		clsDoctorHelperFunctions::PrintDoctorInfo(newDoctor);

		if (!clsInputValidate::CheckAnswer("Are you sure you want to perform this operation? [Y/N] ")) {
			cout << "Operation was cancelled.\n";

			return;


		}


		clsSharedHelperFunctions::PrintTransactionStatus(newDoctor.Save(), "Doctor", "Added");
	}
};