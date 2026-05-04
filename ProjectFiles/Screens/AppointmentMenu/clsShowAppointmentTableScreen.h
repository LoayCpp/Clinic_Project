#pragma once
#include<iostream>
#include<map>
#include<string>
#include<iomanip>
#include"..//..//..//ProjectFiles/Core/clsAppointment.h"
#include"..//..//..//ProjectFiles/Libraries/clsUtil.h"
#include"..//..//..//ProjectFiles/Screens/clsHeaderScreen.h"
using namespace std;

class clsShowAppointmentTableScreen :public clsHeaderScreen
{
private:

	static void DrawTableRow(clsAppointment& appointment) {

		cout << left
			<< "|" << setw(17) << appointment.AppointmentID << "|"
			<< setw(30) << appointment.Patient.FullName << "|"
			<< setw(30) << appointment.Doctor.FullName << "|"
			<< setw(24) << appointment.Doctor.strSpecialization << "|"
			<< setw(21) << appointment.AppointmentFees << "|"
			<< setw(21) << appointment.DateTime << "|" << endl;
	}
	static void	DrawTableBody(const map<string, clsAppointment>& mAppointments) {

		if (mAppointments.empty()) {

			cout << "\n\t\t\t\t\t\t    There are no Appointments in the system\n";
			return;
		}

		for (auto appointment : mAppointments) {


			DrawTableRow(appointment.second);
		}



	}


	static void DrawTableHeader(string lineSeparator) {

		cout << lineSeparator << "\n\n";

		cout << left
			<< setw(17) << "|Appointment`s ID" << " |"
			<< setw(30) << "Patient`s Full Name" << "|"
			<< setw(30) << "Doctor`s Full Name" << "|"
			<< setw(24) << "Doctor`s Specialization" << "|"
			<< setw(21) << "Appointment`s Fees" << "|"
			<< setw(21) << "Date - Time" << "|\n";


		cout << lineSeparator << "\n\n";
	}

	static void DrawTable(const map<string, clsAppointment>& mAppointments) {


		string lineSeparator = clsUtil::UnderScore(29) + "_____";

		DrawTableHeader(lineSeparator);
		DrawTableBody(mAppointments);
		cout << lineSeparator << endl;

	}


public:

	static void ShowAppoitmentsTable() {

		map<string, clsAppointment> mAppointments = clsAppointment::GetAllAppointment();

		string title = clsUtil::Tabs(5) + "		 Show Appoitments Table Screen";
		string subTitle = clsUtil::Tabs(5) + "   List of All Appoitments in the System (" + to_string(mAppointments.size()) + " Appoitments)";

		ShowMainHeader(title, subTitle, 6);
		DrawTable(mAppointments);


	}

};