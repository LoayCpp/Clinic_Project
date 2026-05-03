#pragma once
#include<iostream>
#include"..//..//..//ProjectFiles/Libraries/clsInputValidate.h"
#include"..//..//..//ProjectFiles/Core/clsPatient.h"
#include"..//..//..//ProjectFiles/Libraries/clsDate.h"
#include"..//clsSharedHelperFunctions.h"
using namespace std;
class clsPatientHelperFunctions
{

public:
	static clsPatient::enGender ReadGender() {
		short num = 0;

		cout << "\nPatient's Gender Choices :\n";
		cout << "[1] Male \n[2] Female \n";
		cout << "Enter User`s choice (1-2) :> ";

		num = clsInputValidate::ReadNumberBetween<short>(1, 2, "Invalid input, please enter a number between[1 - 2] :> ");

		return (clsPatient::enGender)num;
	}

	static clsDate ReadBirthdate() {

		cout << "Enter Patient's Birthdate :\n";
		clsDate fromDate(1, 1, 1965);
		clsDate tODate(31, 3, 2026);

		clsDate Date = clsInputValidate::ReadDateBetween(fromDate, tODate, "Invalid input, please enter a Date from 1965/1/1 To 20026/3/31 :> ");

		return Date;
	}

	
	static void ReadFullName(clsPatient& Patient) {
		string className = "Patient";
		Patient.FirstName = clsSharedHelperFunctions::ReadFirstName(className);
		Patient.SecondName = clsSharedHelperFunctions::ReadSecondName(className);
		Patient.ThirdName = clsSharedHelperFunctions::ReadThirdName(className);
		Patient.FourthName = clsSharedHelperFunctions::ReadFourthName(className);
	}

	static void ReadPatientData(clsPatient& Patient) {

		ReadFullName(Patient);
		Patient.Gender = ReadGender();
		Patient.Birthdate = ReadBirthdate();
		Patient.Phone = clsSharedHelperFunctions::ReadPhoneNumber("Patient");

	}
	static clsPatient ReadPatientByID() {

		string PatientID = clsInputValidate::ReadOneWord("Enter Patient's ID :> ");
		clsPatient Patient = clsPatient::FindPatient(PatientID);
		while (Patient.IsEmpty()) {

			PatientID = clsInputValidate::ReadOneWord("Invalid input , Enter Patient's ID :> ");
			Patient = clsPatient::FindPatient(PatientID);

		}


		return Patient;
	}
	static void PrintPatientInfo(clsPatient& Patient) {

		cout << "\n============== Print Patient's Info ================\n";
		cout << "====================================================\n";
		cout << "Patient's Name            : " << Patient.FullName << endl;
		cout << "Patient's Gender          : " << Patient.strGender << endl;
		cout << "Patient's Age             : " << Patient.Age << endl;
		cout << "Patient's Phone           : " << Patient.Phone << endl;
		cout << "====================================================\n";

	}
};
