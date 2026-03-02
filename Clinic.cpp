

#include <iostream>
#include"clsDoctor.h"
#include"clsDate.h"
using namespace std;

string ConvertEnGenderToString(enGender Gender) {


	return (Gender == enGender::eMale) ? "Male" : "Female";

}
void PrintInformation(clsDoctor Doctor) {

	cout << "ID             :" << Doctor.GetID() << endl;
	cout << "Name           :" << Doctor.Name << endl;
	cout << "Date           :" << clsDate::CalculateMyAgeInDays(Doctor.Date) << endl;
	cout << "Gender         :" << ConvertEnGenderToString(Doctor.Gender) << endl;
	cout << "Rete           :" << Doctor.feesRate << endl;
	cout << "specialization :" << Doctor.specialization << endl;
	cout << "Phone          :" << Doctor.Phone << endl;



}
int main()
{

	clsDoctor Doctor(10, "LUAI", clsDate(21, 2, 2003), enGender::eMale, 10, "Dentist", "777111222");

	PrintInformation(Doctor);

	system("pause");
}

