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
	cout << "Age (Days)     : " << clsDate::CalculateMyAgeInDays(Doctor.BirthDay) << endl;
	cout << "Gender         : " << ConvertEnGenderToString(Doctor.Gender) << endl;
	cout << "Fees Rate      : " << Doctor.FeesRate << endl;
	cout << "Specialization : " << Doctor.Specialization << endl;
	cout << "Phone          : " << Doctor.Phone << endl;

}

int main()
{
	clsDoctor Doctor("10", "Luai", "Anwar", "Fesail", "Ahemd", clsDate(21, 2, 2003), clsDoctor::enGender::eMale, 10.02, "Dentist", "777111222");



	PrintInformation(Doctor);

	return 0;
}