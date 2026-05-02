#pragma once
#include "..//DoctorMenu//clsDoctorHelperFunctions .h"
#include "..//PatientMenu//clsPatientHelperFunctions.h"
#include "..//..//Core//clsAppointment.h"
#include "..//..//Libraries//clsUtil.h"
#include <iomanip>
class clsAppointmentHelperFunctions {
private:


	static void DrawTableHeader(string lineSeparator) {

	

		cout << left
			<< setw(10) << "DoctorID" << "|"
			<< setw(30) << "Full Name" << "|"
			<< setw(20) << "Specialization" << "\n";


		cout << lineSeparator << "\n\n";
	}
	static void	DrawTableBody(const map<string, clsDoctor>& mDoctors) {

		if (mDoctors.empty()) {

			cout << "\nThere are no registered doctors in the system\n";
			return;
		}

		for (auto doctor : mDoctors) {


			DrawTableRow(doctor.second);
		}

	}
	static void DrawTableRow(clsDoctor& doctor) {

		cout << left
			<< setw(10) << doctor.DoctorID << "|"
			<< setw(30) << doctor.FullName << "|"
			<< setw(20) << doctor.strSpecialization << "\n";

	}
	static void DrawTable(const map<string, clsDoctor>& mDoctors) {


		string lineSeparator = clsUtil::UnderScore(11) + "__";

		DrawTableHeader(lineSeparator);
		DrawTableBody(mDoctors);
		cout << lineSeparator << endl;

	}

public:
	static clsPatient ReadPatient() {

		cout << "Enter Patient`s Data :\n";
		cout << "----------------------\n";
		clsPatient Patient = clsPatient::GetNewPatientObject();
		clsPatientHelperFunctions::ReadPatientData(Patient);
		return Patient;
	}
	static clsDoctor ReadDoctor() {

		cout << "\nEnter Patient`s Doctor :\n\n";
	
		map<string, clsDoctor> mDoctors = clsDoctor::GetAllDoctors();
		DrawTable(mDoctors);
		return clsDoctorHelperFunctions::ReadDoctorByID();
	}
	static float ReadAppointmentFees(float totalPrice) {

		cout << "\n";
		string TotalPrice = "[ " + to_string(totalPrice) + " ]";
		string Message = "Enter Appointment's Fees " + TotalPrice + " :> ";
		string alternativeMessage = "Please Enter Appointment's Fees Up To " + TotalPrice + " :> ";

		float fees = clsInputValidate::ReadPositiveNumber<float>(Message);
		while (fees != totalPrice) {
			fees = clsInputValidate::ReadPositiveNumber<float>(alternativeMessage);
		}
		
		return fees;
		
	}
	static clsAppointment ReadAppointmentByID() {

		string appointmentID = clsInputValidate::ReadOneWord("Enter Appointment's ID :> ");
		clsAppointment appointment = clsAppointment::FindAppointment(appointmentID);
		while (appointment.IsEmpty()) {

			appointmentID = clsInputValidate::ReadOneWord("Invalid input , Enter Appointment's ID :> ");
			appointment = clsAppointment::FindAppointment(appointmentID);

		}


		return appointment;
	}

	static void PrintAppointmentInfo(clsAppointment& appointment) {
	
		cout << "\n=============== Print sAppointment's Info ==================\n";
		cout << "============================================================\n";
		cout << "Patient's Name                : " << appointment.Patient.FullName << endl;
		cout << "Doctor's Name                 : " << appointment.Doctor.FullName << endl;
		cout << "Doctor's Specialization       : " << appointment.Doctor.strSpecialization << endl;
		cout << "Appointment Fees's            : " << appointment.AppointmentFees << endl;
		cout << "Date - Time	               : " << appointment.DateTime << endl;
		cout << "============================================================\n";

	}
};