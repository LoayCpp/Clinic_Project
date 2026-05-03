#pragma once
#include<iostream>
#include"..//..//..//ProjectFiles/Libraries/clsInputValidate.h"
#include"..//..//..//ProjectFiles/Core/clsDoctor.h"
#include"..//..//..//ProjectFiles/Libraries/clsDate.h"
#include"..//clsSharedHelperFunctions.h"
using namespace std;
class clsDoctorHelperFunctions 
{

public:
	static clsDoctor::enGender ReadGender() {
		short num = 0;
		
		cout << "\nDoctor's Gender Choices :\n";
		cout << "[1] Male \n[2] Female \n";
		cout << "Enter User`s choice (1-2) :> ";

		num = clsInputValidate::ReadNumberBetween<short>(1, 2, "Invalid input, please enter a number between[1 - 2] :> ");

		return (clsDoctor::enGender)num;
	}

	static clsDate ReadBirthdate() {

		cout << "Enter Doctor's Birthdate :\n";
		clsDate fromDate(1, 1, 1965);
		clsDate tODate(31, 12, 2000);

		clsDate Date = clsInputValidate::ReadDateBetween(fromDate, tODate, "Invalid input, please enter a Date from 1965/1/1 To 2000/12/31 :> ");

		return Date;
	}

	static clsDoctor::enSpecialization ReadSpecialization() {

		short num = 0;
		cout << "Doctor's Specialization Choices :\n";
		cout << "[1] Dentistry\n";
		cout << "[2] Dermatology\n";
		cout << "[3] Internal Medicine\n";
		cout << "[4] ENT\n";
		cout << "[5] Surgery\n";
		cout << "Enter User`s choice (1-5) :> ";

		num = clsInputValidate::ReadNumberBetween<short>(1, 5, "Invalid input, please enter a number between[1 - 5] :> ");

		return (clsDoctor::enSpecialization)num;
	}
	static float ReadFeesRate() {

		float num = 0;
		cout << "Enter Doctor's Fees Rate Between (0 - 100) :> ";
		num = clsInputValidate::ReadNumberBetween<float>(1, 100, "Invalid input, please enter a valid percentage [0 - 100] :> ");

		return num;
	}
	static void ReadFullName(clsDoctor& doctor) {
		string className = "Doctor";
		doctor.FirstName = clsSharedHelperFunctions::ReadFirstName(className);
		doctor.SecondName = clsSharedHelperFunctions::ReadSecondName(className);
		doctor.ThirdName = clsSharedHelperFunctions::ReadThirdName(className);
		doctor.FourthName = clsSharedHelperFunctions::ReadFourthName(className);
	}

	static void ReadDoctorData(clsDoctor& doctor) {

		ReadFullName(doctor);
		doctor.Gender = ReadGender();
		doctor.BirthDate = ReadBirthdate();
		doctor.Specialization = ReadSpecialization();
		doctor.Phone = clsSharedHelperFunctions::ReadPhoneNumber("Doctor");
		doctor.FeesRate = ReadFeesRate();

	}
	static clsDoctor ReadDoctorByID() {

		string doctorID = clsInputValidate::ReadOneWord("Enter Doctor's ID :> ");
		clsDoctor doctor= clsDoctor::FindDoctor(doctorID);
		while (doctor.IsEmpty()) {

			doctorID = clsInputValidate::ReadOneWord("Invalid input , Enter Doctor's ID :> ");
			doctor = clsDoctor::FindDoctor(doctorID);

		}
		

		return doctor;
	}
	static void PrintDoctorInfo(clsDoctor& doctor) {

		cout << "\n============== Print Doctor's Info =================\n";
		cout << "====================================================\n";
		cout << "Doctor's Name            : " << doctor.FullName << endl;
		cout << "Doctor's Gender          : " << doctor.strGender << endl;
		cout << "Doctor's Age             : " << doctor.Age << endl;
		cout << "Doctor's Specialization  : " << doctor.strSpecialization << endl;
		cout << "Doctor's Phone           : " << doctor.Phone << endl;
		cout << "Doctor's Fees Rate       : " << doctor.FeesRate << endl;
		cout << "====================================================\n";

	}
};
