#pragma once
#include "ProjectFiles//Core//clsDoctor.h"
class clsPatient
{
public:
    enum enGender {
        eFemale = 0,
        eMale = 1
    };

private:


    string _patientID;

    string _firstName;
    string _secondName;
    string _thirdName;
    string _fourthName;

    enGender _gender;

    clsDate _brithdate;

    string _phone;

    clsDoctor _doctor;

  
    float _bookingFee;

public:

    clsPatient(string PatientID, string firstName, string secondName, string thirdName, string fourthName, enGender gender, clsDate brithdate, string phone, clsDoctor doctor, float bookingFee) {

        _patientID = PatientID;
        _firstName = firstName;
        _secondName = secondName;
        _thirdName = thirdName;
        _fourthName = fourthName;
        _gender = gender;
        _brithdate = brithdate;
        _phone = phone;
        _doctor = doctor;
        _bookingFee = bookingFee;

    };

    string GetPatientID() const
    {
        return _patientID;
    }
    __declspec(property(get = GetPatientID))string PatientID;

    void SetFirstName(string firstName)
    {
        _firstName = firstName;
    }
    string GetFirstName() const
    {
        return _firstName;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;

    void SetSecondName(string secondName)
    {
        _secondName = secondName;
    }
    string GetSecondName() const
    {
        return _secondName;
    }
    __declspec(property(get = GetSecondName, put = SetSecondName))string SecondName;

    void SetThirdName(string thirdName)
    {
        _thirdName = thirdName;
    }
    string GetThirdName() const
    {
        return _thirdName;
    }
    __declspec(property(get = GetThirdName, put = SetThirdName))string ThirdName;

    void SetFourthName(string fourthName)
    {
        _fourthName = fourthName;
    }
    string GetFourthName() const
    {
        return _fourthName;
    }
    __declspec(property(get = GetFourthName, put = SetFourthName))string FourthName;

    void SetGender(enGender Gender)
    {
        _gender = Gender;
    }
    enGender GetGender() const
    {
        return _gender;
    }
    __declspec(property(get = GetGender, put = SetGender))enGender Gender;

    void SetPhone(string Phone)
    {
        _phone = Phone;
    }
    string GetPhone() const
    {
        return _phone;
    }
    __declspec(property(get = GetPhone, put = SetPhone))string Phone;


    void SetBrithdate(clsDate Brithdate)
    {
        _brithdate = Brithdate;
    }
    clsDate GetBirthdate() const
    {
        return _brithdate;
    }
    __declspec(property(get = GetBirthdate, put = SetBrithdate))clsDate Brithdate;


    void SetBookingFee(float bookingFee)
    {
        _bookingFee = bookingFee;
    }
    float GetBookingFee() const
    {
        return _bookingFee;
    }
    __declspec(property(get = GetBookingFee, put = SetBookingFee))float bookingFee;
};

