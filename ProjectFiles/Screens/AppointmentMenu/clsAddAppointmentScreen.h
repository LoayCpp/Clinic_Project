#pragma once
#include "..//clsHeaderScreen.h"
#include "clsAppointmentHelperFunctions.h"
class clsAddAppointmentScreen : public clsHeaderScreen {
private:
	static void _showScreenHeader() {
		string title = clsUtil::Tabs(1) + "   Add Appointment Screen";
		ShowMainHeader(title);
	}
	class clsAddAppointmentMenuScreen {
	private:
		enum enAddAppointmentMenuScreen
		{
			eAddAppointmentForExistingPatient = 1,
			eAddAppointmentForNewPatient

		};
		static short _ReadAddAppointmentMenuOption() {

			cout << "Enter The Number from [1-2]:";
			return  clsInputValidate::ReadNumberBetween<short>(1, 2);
		}



		static clsPatient _ShowAddAppointmentForExistingPatient() {
			_showScreenHeader();
			clsPatient patient =  clsPatientHelperFunctions::ReadPatientByID();
			clsPatientHelperFunctions::PrintPatientInfo(patient);
			patient.HasMultipleAppointments = true;
			return patient;
		}
		static clsPatient _ShowAddAppointmentForNewPatient() {
			_showScreenHeader();
			return clsAppointmentHelperFunctions::ReadPatient();

		}



		static void _PerformPatientNameMenuOperation(enAddAppointmentMenuScreen option, clsAppointment& appointment) {


			switch (option)
			{
			case enAddAppointmentMenuScreen::eAddAppointmentForExistingPatient:

				appointment.Patient = _ShowAddAppointmentForExistingPatient();

				break;

				case enAddAppointmentMenuScreen::eAddAppointmentForNewPatient:

				appointment.Patient = _ShowAddAppointmentForNewPatient();
				break;
	
			}

			appointment.Doctor = clsAppointmentHelperFunctions::ReadDoctor();
			appointment.AppointmentFees = clsAppointmentHelperFunctions::ReadAppointmentFees(appointment.TotalPrice);

		}

	public:


		static void ShowAddAppointmentMenu(clsAppointment& appointment) {



			string LineSperator = "=============================================\n";
			cout << LineSperator;
			cout << "[1] Add Appointment For an Existing Patient.\n";
			cout << "[2] Add Appointment For a New Patient.\n";
			cout << LineSperator;

			_PerformPatientNameMenuOperation((enAddAppointmentMenuScreen)_ReadAddAppointmentMenuOption(), appointment);
		}
	};
public:
	static void ShowAddAppointment() {

		_showScreenHeader();
	
		clsAppointment appointment = clsAppointment::GetNewAppointmentObject();
		clsAddAppointmentMenuScreen::ShowAddAppointmentMenu(appointment);

		if (!clsInputValidate::CheckAnswer("Are you sure you want to perform this operation? [Y/N] ")) {
			cout << "Operation was cancelled.\n";

			return;


		}


		clsSharedHelperFunctions::PrintTransactionStatus(appointment.Save(), "Appointment", "Added");
	}
};