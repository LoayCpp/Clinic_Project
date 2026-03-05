#pragma once
#include <iostream>
#include "..//Libraries/clsDate.h"
#include"..//Core/clsPerson.h"
    using namespace std;

class clsDoctor  : public clsPerson
{

public:
    enum enGender
    {
        eFemale = 0,
        eMale = 1
    };

private:
    string _doctorID;

    string _firstName;

    string _secondName;

    string _thirdName;

    string _fourthName;

    enGender _gender;

    clsDate _birthdate;

    string _phone;

    string _specialization;

    float _feesRate;

public:
    clsDoctor() {

    };

    clsDoctor(string doctorID, string firstName, string secondName, string thirdName,
              string fourthName, enGender gender, clsDate birthdate, string specialization, string phone, float feesRate)
        :clsPerson(firstName,secondName,thirdName,fourthName,phone){

        _doctorID = doctorID;
        _birthdate = birthdate;
        _gender = gender;
        _feesRate = feesRate;
        _specialization = specialization;
 
    };

    string GetDoctorID() const
    {
        return _doctorID;
    }
    __declspec(property(get = GetDoctorID)) string DoctorID;

    __declspec(property(get = GetFourthName, put = SetFourthName)) string FourthName;

    void SetGender(enGender Gender)
    {
        _gender = Gender;
    }

    enGender GetGender() const
    {
        return _gender;
    }

    __declspec(property(get = GetGender, put = SetGender)) enGender Gender;

    
    void SetBirthdate(clsDate birthdate)
    {
        _birthdate = birthdate;
    }

    clsDate GetBirthdate() const
    {
        return _birthdate;
    }

    __declspec(property(get = GetBirthdate, put = SetBirthdate)) clsDate BirthDate;

  
    void SetSpecialization(string Specialization)
    {
        _specialization = Specialization;
    }

    string GetSpecialization() const
    {
        return _specialization;
    }

    __declspec(property(get = GetSpecialization, put = SetSpecialization)) string Specialization;

    void SetFeesRate(float FeesRate)
    {
        _feesRate = FeesRate;
    }

    float GetFeesRate() const
    {
        return _feesRate;
    }
    __declspec(property(get = GetFeesRate, put = SetFeesRate)) float FeesRate;
};
