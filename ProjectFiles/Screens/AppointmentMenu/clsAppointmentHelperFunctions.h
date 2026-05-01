#pragma once
#include "..//DoctorMenu//clsDoctorHelperFunctions .h"
#include "..//PatientMenu//clsPatientHelperFunctions.h"
#include "..//..//Core//clsAppointment.h"
class clsAppointmentHelperFunctions {
private:

public:
	static clsPatient ReadPatient() {
		clsPatient Patient;
		clsPatientHelperFunctions::ReadPatientData(Patient);
		return Patient;
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

		cout << "\n============== Print sAppointment's Info =================\n";
		cout << "====================================================\n";
		cout << "Patient's Name                : " << appointment.Patient.FullName << endl;
		cout << "Doctor's Name                 : " << appointment.Doctor.FullName << endl;
		cout << "Doctor's Specialization       : " << appointment.Doctor.strSpecialization << endl;
		cout << "Appointment Fees's            : " << appointment.AppointmentFees << endl;
		cout << "====================================================\n";

	}
};