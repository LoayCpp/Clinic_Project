#pragma once
#include<iostream>
#include<map>
#include<string>
#include<iomanip>
#include"..//..//..//ProjectFiles/Core/clsDoctor.h"
#include"..//..//..//ProjectFiles/Libraries/clsUtil.h"
#include"..//..//..//ProjectFiles/Screens/clsHeaderScreen.h"
using namespace std;

class clsShowDoctorsTableScreen :public clsHeaderScreen
{
private:

	static void DrawTableRow( clsDoctor& doctor) {

		cout << left
			<<setw(10)<<doctor.DoctorID<<"|"
			<< setw(30) << doctor.FullName << "|"
			<< setw(10) << doctor.strGender << "|"
			<< setw(6) << doctor.Age << "|"
			<< setw(20) << doctor.strSpecialization << "|"
			<< setw(15) << doctor.Phone << "|"
			<< setw(10) << doctor.FeesRate <<"|" << endl;
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


	static void DrawTableHeader(string lineSeparator) {

		cout << lineSeparator << endl;

		cout << left
			<<setw(10)<<"DoctorID"<<"|"
			<< setw(30) << "Full Name" << "|"
			<< setw(10) << "Gender" << "|"
			<< setw(6) << "Age" << "|"
			<< setw(20) << "Specialization" << "|"
			<< setw(15) << "Phone" << "|"
			<< setw(10) << "Fees Rate" <<"|" << endl;

		cout << lineSeparator << endl;
	}

	static void DrawTable(const map<string, clsDoctor>& mDoctors) {


		string lineSeparator = clsUtil::UnderScore(19);

		DrawTableHeader(lineSeparator);
		DrawTableBody(mDoctors);
		cout << lineSeparator << endl;

	}


public:

	static void ShowDoctorsTable() {

		map<string, clsDoctor> mDoctors = clsDoctor::GetAllDoctors();

		string title = clsUtil::Tabs(3) + "		 Show Doctors Table Screen";
		string subTitle = clsUtil::Tabs(4) + "List of All Doctors in the System (" + to_string(mDoctors.size()) + " Doctors)";

		ShowMainHeader(title, subTitle,4);
		DrawTable(mDoctors);


	}

};