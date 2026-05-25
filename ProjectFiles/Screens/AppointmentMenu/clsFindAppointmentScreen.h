#pragma once
#include "..//clsHeaderScreen.h"
#include "clsAppointmentHelperFunctions.h"
#include "..//..//Globlas//Globals.h"
class clsFindAppointmentScreen : public clsHeaderScreen {

public:
	static void ShowFindAppointment() {
		string title = clsUtil::Tabs(1) + "    Find Appointment Screen";
		ShowMainHeader(title);
		clsAppointment appointment = clsAppointmentHelperFunctions::ReadAppointmentByID();
		clsAppointmentHelperFunctions::PrintAppointmentInfo(appointment);
	}

};