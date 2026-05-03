#pragma once
#pragma once
#include "..//clsHeaderScreen.h"
#include "clsAppointmentHelperFunctions.h"
#include "..//PatientMenu//clsUpdatePaitentsDataScreen.h"
using namespace std;
class clsUpdateAppointmentScreen :public clsHeaderScreen
{

private:
	static void ShowUpdateScreenHeader() {
		string title =  "      Update Appointment's Data Screen";
		ShowMainHeader(title);
	}
	class clsUpdateAppointmentMenuScreen {

	private:
		enum enUpdateAppointmentMenuScreen
		{
			eUpdatePatientDataForAppointment = 1,
			eUpdatePatientDoctor

		};
		static short _ReadUpdateAppointmentMenuOption() {

			cout << "Enter The Number from [1-2]:";
			return  clsInputValidate::ReadNumberBetween<short>(1, 2);
		}



		static void _ShowUpdatePatientDataForAppointment(clsAppointment& appointment) {
		
			clsPatient Patient = appointment.Patient;
			clsUpdatePaitentsDataScreen::ShowUpdatePatientData(Patient);
			appointment.Patient = Patient;
			
		}
		static void _ShowUpdatePatientDoctor(clsAppointment& appointment) {
			ShowUpdateScreenHeader();
			appointment.Doctor = clsAppointmentHelperFunctions::ReadDoctor();
			appointment.AppointmentFees = clsAppointmentHelperFunctions::ReadAppointmentFees(appointment.TotalPrice);

		}



		static void _PerformPatientNameMenuOperation(enUpdateAppointmentMenuScreen option, clsAppointment& appointment) {


			switch (option)
			{
			case enUpdateAppointmentMenuScreen::eUpdatePatientDataForAppointment:

				_ShowUpdatePatientDataForAppointment(appointment);

				break;

			case enUpdateAppointmentMenuScreen::eUpdatePatientDoctor:

				_ShowUpdatePatientDoctor(appointment);
				break;

			}


		}

	public:


		static void ShowAddAppointmentMenu(clsAppointment& appointment) {

			ShowUpdateScreenHeader();

			string LineSperator = "=============================================\n";
			cout << LineSperator;
			cout << "[1] Update Appointment`s Patient.\n";
			cout << "[2] Update Appointment`s Doctor.\n";
			cout << LineSperator;

			_PerformPatientNameMenuOperation((enUpdateAppointmentMenuScreen)_ReadUpdateAppointmentMenuOption(), appointment);
		}
	};
	
	
public:
	static void ShowUpdateAppointmentData() {
		ShowUpdateScreenHeader();
		clsAppointment appointment = clsAppointmentHelperFunctions::ReadAppointmentByID();
		clsAppointmentHelperFunctions::PrintAppointmentInfo(appointment);
		if (!clsInputValidate::CheckAnswer("Are you sure you want to perform this operation? [Y/N] ")) {

			cout << "Operation was cancelled.\n";
			return;
		}
		
		clsUpdateAppointmentMenuScreen::ShowAddAppointmentMenu(appointment);

		clsSharedHelperFunctions::PrintTransactionStatus(appointment.Save(), "Appointment", "Updated");
	}

};