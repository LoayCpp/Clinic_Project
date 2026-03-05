#pragma once
#include "clsDoctor.h"
<<<<<<< HEAD
#include"clsPerson.h"
class clsPatient :public clsPerson
=======
#include "clsPerson.h"
class clsPatient : public clsPerson
>>>>>>> 762eed2f4c9874c41f108fca5ad99628cbc86151
{
public:
    enum enGender
    {
        eFemale = 0,
        eMale = 1
    };

private:
    string _patientID;
<<<<<<< HEAD
=======

>>>>>>> 762eed2f4c9874c41f108fca5ad99628cbc86151
    enGender _gender;
    clsDate _birthdate;
<<<<<<< HEAD
    clsDoctor _doctor;
    float _bookingFee;

public:
    clsPatient(){}
    clsPatient(string PatientID, string firstName, string secondName, string thirdName, string fourthName, enGender gender, clsDate birthdate, string phone, clsDoctor doctor, float bookingFee) 
        :clsPerson(firstName,secondName,thirdName,fourthName,phone)
        
=======

    clsDoctor _doctor;

    float _bookingFee;

public:
    clsPatient(string PatientID, string firstName, string secondName, string thirdName, string fourthName, enGender gender, clsDate birthdate, string phone, clsDoctor doctor, float bookingFee)
        : clsPerson(firstName, secondName, thirdName, fourthName, phone)

>>>>>>> 762eed2f4c9874c41f108fca5ad99628cbc86151
    {

        _patientID = PatientID;
        _gender = gender;
        _birthdate = birthdate;
        _doctor = doctor;
        _bookingFee = bookingFee;
    };

    string GetPatientID() const
    {
        return _patientID;
    }
    __declspec(property(get = GetPatientID)) string PatientID;

    void SetGender(enGender Gender)
    {
        _gender = Gender;
    }

    enGender GetGender() const
    {
        return _gender;
    }
    __declspec(property(get = GetGender, put = SetGender)) enGender Gender;

    void SetBirthdate(clsDate Birthdate)
    {
        _birthdate = Birthdate;
    }
    clsDate GetBirthdate() const
    {
        return _birthdate;
    }

    __declspec(property(get = GetBirthdate, put = SetBirthdate)) clsDate Birthdate;

    void SetBookingFee(float bookingFee)
    {
        _bookingFee = bookingFee;
    }
    float GetBookingFee() const
    {
        return _bookingFee;
    }
    __declspec(property(get = GetBookingFee, put = SetBookingFee)) float bookingFee;

    clsDoctor GetDoctor() const
    {

        return _doctor;
    }
    clsDoctor SetDoctor(clsDoctor doctor)
    {

        _doctor = doctor;
    }
    __declspec(property(get = GetDoctor, put = SetDoctor)) clsDoctor Doctor;
};
