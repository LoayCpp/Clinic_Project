#include <iostream>
#include "ProjectFiles//Core//clsDoctor.h"
using namespace std;

string ConvertEnGenderToString(clsDoctor::enGender Gender)
{
	return (Gender == clsDoctor::enGender::eMale) ? "Male" : "Female";
}

void PrintInformation(clsDoctor Doctor)
{
	cout << "ID             : " << Doctor.DoctorID << endl;
	cout << "Name           : " << Doctor.FirstName << " " << Doctor.LastName << " " << Doctor.ThirdName << " " << Doctor.FourthName << endl;
	cout << "Age (Days)     : " << clsDate::CalculateMyAgeInDays(Doctor.BirthDate) << endl;
	cout << "Gender         : " << ConvertEnGenderToString(Doctor.Gender) << endl;
	cout << "Fees Rate      : " << Doctor.FeesRate << endl;
	cout << "Specialization : " << Doctor.Specialization << endl;
	cout << "Phone          : " << Doctor.Phone << endl;

}

int main()
{
	
	clsDoctor Doctor("10", "Luai", "Anwar", "Fesail", "Ahemd", clsDoctor::enGender::eMale, clsDate(21, 2, 2003),"231321", "Dentist", 10.02);



	PrintInformation(Doctor);

	return 0;
}