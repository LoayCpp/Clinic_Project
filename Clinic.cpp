#include <iostream>
#include "ProjectFiles//Core//clsDoctor.h"
#include"ProjectFiles//Core//clsPatient.h"
#include"ProjectFiles/Core/clsAppointment.h"
#include"ProjectFiles//Screens//MainMenu/clsMainMenu.h"
#include"ProjectFiles//Screens/MainMenu/clsManagePatientMenu.h"

using namespace std;
//
//string ConvertEnGenderToStringDoctor(clsDoctor::enGender Gender)
//{
//	return (Gender == clsDoctor::enGender::eMale) ? "Male" : "Female";
//}
//
//string ConvertEnGenderToStringPatient(clsPatient::enGender Gender)
//{
//	return (Gender == clsPatient::enGender::eMale) ? "Male" : "Female";
//}
//void PrintDoctorInformation(clsDoctor doctor)
//{
//	cout << "ID             : " << doctor.DoctorID << endl;
//	cout << "Name           : " << doctor.FirstName << " " << doctor.SecondName << " " << doctor.ThirdName << " " << doctor.FourthName << endl;
//	cout << "Age (Days)     : " << clsDate::CalculateMyAgeInDays(doctor.BirthDate) << endl;
//	cout << "Gender         : " << ConvertEnGenderToStringDoctor(doctor.Gender) << endl;
//	cout << "Fees Rate      : " << doctor.FeesRate << endl;
//	cout << "Specialization : " << doctor.Specialization << endl;
//	cout << "Phone          : " << doctor.Phone << endl;
//
//}
//
//void PrintPaitentInformation(clsPatient patient)
//{
//	cout << "ID             : " << patient.PatientID << endl;
//	cout << "Name           : " << patient.FirstName << " " << patient.SecondName << " " << patient.ThirdName << " " << patient.FourthName << endl;
//	cout << "Age (Days)     : " << clsDate::CalculateMyAgeInDays(patient.Birthdate) << endl;
//	cout << "Gender         : " << ConvertEnGenderToStringPatient(patient.Gender) << endl;
//	cout << "BookingFee     : " << patient.bookingFee << endl;
//	cout << "Phone          : " << patient.Phone << endl;
//	cout << "\n============================\n";
//	cout << "Doctor`s Patient Info :\n";
//	cout << "============================\n";
//	PrintDoctorInformation(patient.Doctor);
//	cout << "============================\n";
//
//
//}


void readDoctor(clsDoctor& Doctor) {

    cout << "First Name   : ";
    Doctor.FirstName = clsInputValidate::ReadString();

    cout << "Second Name    : ";
    Doctor.SecondName = clsInputValidate::ReadString();


    cout << "ThirdName        : ";
    Doctor.ThirdName = clsInputValidate::ReadString();

    cout << "FourthName        : ";
    Doctor.FourthName = clsInputValidate::ReadString();

    cout << "Gender      : ";

    Doctor.Gender = (clsDoctor::enGender)clsInputValidate::ReadNumberBetween<int>(1, 2);

    cout << "Date        :";
    Doctor.BirthDate = clsInputValidate::ReadDate();

    cout << "Specialization        :";
    Doctor.Specialization = (clsDoctor::enSpecialization)clsInputValidate::ReadNumberBetween<int>(1, 5);

    cout << "Phone        :";
    Doctor.Phone = clsInputValidate::ReadString();

    cout << "FeesRate        :";
    Doctor.FeesRate = clsInputValidate::ReadNumber<float>();


}

void printDoctor(const clsDoctor& Doctor)
{
    cout << "-----------------------------\n";

    cout << "First Name       : " << Doctor.FirstName << "\n";
    cout << "Second Name      : " << Doctor.SecondName << "\n";
    cout << "Third Name       : " << Doctor.ThirdName << "\n";
    cout << "Fourth Name      : " << Doctor.FourthName << "\n";

    cout << "Gender           : "
        << (Doctor.Gender == clsDoctor::enGender::eMale ? "Male" : "Female") << "\n";

    cout << "Birth Date       : " << clsDate::DateToString(Doctor.BirthDate) << "\n";



    cout << "Phone            : " << Doctor.Phone << "\n";

    cout << "Fees Rate        : " << Doctor.FeesRate << "\n";
    cout << "-----------------------------\n";
}

int main()
{

    //Add Docotr

  /*  clsDoctor Doctor = clsDoctor::GetAddDoctor();
    readDoctor(Doctor);
    if (Doctor.Save()) {


        cout << "\nSuccesfully\n";

        printDoctor(Doctor);
    }
    else {

        cout << "\n Not Succesfully\n";


    }*/

    //Update Docotr
   
     /* string id = "";
         cout << "Enter the id :";
         cin >> id;
         clsDoctor Doctor = clsDoctor::FindDoctor(id);
         printDoctor(Doctor);
         cout << "Edit :\n --------------------\n";

         readDoctor(Doctor);
         if (Doctor.Save()) {
             cout << "\nSuccefully\n";
             printDoctor(Doctor);

         }
         else {

             cout << "Empty\n";
         }*/


         //Delete Doctor;

        /* string id = "";
         cout << "Enter the id :";
         cin >> id;

         clsDoctor Doctor = clsDoctor::FindDoctor(id);
         printDoctor(Doctor);
       if (Doctor.IsEmpty()) {

           cout << "Doctor is empty\n";
      }
       else {
           printDoctor(Doctor);
           if (Doctor.DeleteDoctor()) {


               cout << "yeeeeeeeeeeeeeeeeees";

           }
           else {

               cout << "nooooooooooooooooooooooooo\n";
           }

       }*/
      

    return 0;
}