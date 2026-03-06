#include <iostream>
#include "ProjectFiles//Core//clsDoctor.h"
#include"ProjectFiles//Core//clsPatient.h"
#include"ProjectFiles/Core/clsAppointment.h"
#include"ProjectFiles//Screens//MainMenu/clsMainMenu.h"
using namespace std;

string ConvertEnGenderToStringDoctor(clsDoctor::enGender Gender)
{
	return (Gender == clsDoctor::enGender::eMale) ? "Male" : "Female";
}

string ConvertEnGenderToStringPatient(clsPatient::enGender Gender)
{
	return (Gender == clsPatient::enGender::eMale) ? "Male" : "Female";
}
void PrintDoctorInformation(clsDoctor doctor)
{
	cout << "ID             : " << doctor.DoctorID << endl;
	cout << "Name           : " << doctor.FirstName << " " << doctor.SecondName << " " << doctor.ThirdName << " " << doctor.FourthName << endl;
	cout << "Age (Days)     : " << clsDate::CalculateMyAgeInDays(doctor.BirthDate) << endl;
	cout << "Gender         : " << ConvertEnGenderToStringDoctor(doctor.Gender) << endl;
	cout << "Fees Rate      : " << doctor.FeesRate << endl;
	cout << "Specialization : " << doctor.Specialization << endl;
	cout << "Phone          : " << doctor.Phone << endl;

}

void PrintPaitentInformation(clsPatient patient)
{
	cout << "ID             : " << patient.PatientID << endl;
	cout << "Name           : " << patient.FirstName << " " << patient.SecondName << " " << patient.ThirdName << " " << patient.FourthName << endl;
	cout << "Age (Days)     : " << clsDate::CalculateMyAgeInDays(patient.Birthdate) << endl;
	cout << "Gender         : " << ConvertEnGenderToStringPatient(patient.Gender) << endl;
	cout << "BookingFee     : " << patient.bookingFee << endl;
	cout << "Phone          : " << patient.Phone << endl;
	cout << "\n============================\n";
	cout << "Doctor`s Patient Info :\n";
	cout << "============================\n";
	PrintDoctorInformation(patient.Doctor);
	cout << "============================\n";


}
int main()
{

	/*clsDoctor doctor("120", "Luai", "Anwar", "Fesail", "Ahemd", clsDoctor::enGender::eMale, clsDate(21, 2, 2003), "Dentist", "777184509", 10.02f);
	clsPatient patient("11", "Amr", "Ahmed", "khaled", "Smai", clsPatient::enGender::eMale, clsDate(2, 3, 2022), "932974927", doctor, 1200);

	cout << "Here class Docotor:\n";
	PrintDoctorInformation(doctor);
	cout << "===========================\n";
	cout << "\nHere class Patient:\n";
	PrintPaitentInformation(patient);*/
	clsMainMenu::ShowMenu();

	return 0;
}