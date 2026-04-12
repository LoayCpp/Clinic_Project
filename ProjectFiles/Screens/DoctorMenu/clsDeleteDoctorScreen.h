#include "..//clsHeaderScreen.h"
#include "clsDoctorHelperFunctions .h"
class clsDeleteDoctorScreen : public clsHeaderScreen {
private:

public:
	static void ShowDeleteDoctor() {
		string title = clsUtil::Tabs(1) + "    Delete Doctor Screen";
		ShowMainHeader(title);

		clsDoctor doctor = clsDoctorHelperFunctions::ReadDoctorByID();
		clsDoctorHelperFunctions::PrintDoctorInfo(doctor);

		if (!clsInputValidate::CheckAnswer("Are you sure you want to perform this operation? [Y/N] ")) {
			cout << "Operation was cancelled.\n";
		}


		clsSharedHelperFunctions::PrintTransactionStatus(doctor.Delete(), "Doctor", "Deleted");
	}
};