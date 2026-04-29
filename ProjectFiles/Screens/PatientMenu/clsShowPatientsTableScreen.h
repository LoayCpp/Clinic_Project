#pragma once
#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include "..//..//..//ProjectFiles/Core/clsPatient.h"
#include "..//..//..//ProjectFiles/Libraries/clsUtil.h"
#include "..//..//..//ProjectFiles/Screens/clsHeaderScreen.h"
using namespace std;

class clsShowPatientsTableScreen : public clsHeaderScreen
{
private:
	static void DrawTableRow(clsPatient& patient)
	{

		cout << left
			<< "|" << setw(10) << patient.PatientID << "|"
			<< setw(30) << patient.FullName << "|"
			<< setw(10) << patient.strGender << "|"
			<< setw(6) << patient.Age << "|"
			<< setw(15) << patient.Phone << "|" << endl;
		
	}
	static void DrawTableBody(const map<string, clsPatient>& mPatient)
	{

		if (mPatient.empty())
		{

			cout << "\nThere are no registered doctors in the system\n";
			return;
		}

		for (auto patient : mPatient)
		{

			DrawTableRow(patient.second);
		}
	}

	static void DrawTableHeader(string lineSeparator)
	{

		cout << lineSeparator << endl;

		cout << left
			<< setw(10) << "|PatientID" << " |"
			<< setw(30) << "Full Name" << "|"
			<< setw(10) << "Gender" << "|"
			<< setw(6) << "Age" << "|"
			<< setw(15) << "Phone" << "|"<<endl;
			

		cout << lineSeparator << endl;
	}

	static void DrawTable(const map<string, clsPatient>& mPatient)
	{

		string lineSeparator = clsUtil::UnderScore(15) + "__";

		DrawTableHeader(lineSeparator);
		DrawTableBody(mPatient);
		cout << lineSeparator << endl;
	}

public:
	static void ShowPatientsTable()
	{

		map<string, clsPatient> mPatient = clsPatient::GetAllPatients();

		string title = clsUtil::Tabs(3) + "		 Show Patient Table Screen";
		string subTitle = clsUtil::Tabs(4) + "List of All Patient in the System (" + to_string(mPatient.size()) + " Patients)";

		ShowMainHeader(title, subTitle, 4);
		DrawTable(mPatient);
	}
};