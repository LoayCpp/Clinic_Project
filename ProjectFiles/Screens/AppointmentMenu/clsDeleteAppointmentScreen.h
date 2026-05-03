#pragma once
#include "..//clsHeaderScreen.h"
#include "clsAppointmentHelperFunctions.h"
class clsDeleteAppointmentScreen : public clsHeaderScreen {
private:

public:
	static void ShowDeleteDoctor() {

		string title = clsUtil::Tabs(1) + "  Delete Appointment Screen";
		ShowMainHeader(title);

		clsAppointment appointment = clsAppointmentHelperFunctions::ReadAppointmentByID();
		clsAppointmentHelperFunctions::PrintAppointmentInfo(appointment);

		if (!clsInputValidate::CheckAnswer("Are you sure you want to perform this operation? [Y/N] ")) {
			cout << "Operation was cancelled.\n";
			return;
		}


		clsSharedHelperFunctions::PrintTransactionStatus(appointment.Delete(), "Appointment", "Deleted");
	}
};