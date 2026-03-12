#pragma once
#include "..//Libraries/clsDate.h"
#include"..//Core/clsPerson.h"
class clsDoctor  : public clsPerson
{

public:
    enum enGender
    {
        eFemale = 0,
        eMale
    };
    enum enMajor
    {
        eDentistry = 1,
        eDermatology,
        eInternalMedicine,
        eENT,
        eSurgery
    };
private:

    enum enMode {
        eUpadateMode = 1,
        eEmptyMode,
        eAddNewMode
    };
    enum enIsSave {
        DataisSaved = 1,
        DataisUnSaved
    };

    enMode _mode;
    enIsSave _ObjectIsSaved;
    string _doctorID;
    enGender _gender;
    clsDate _birthdate;
    string _specialization;
    float _feesRate;

public:
    clsDoctor(){}

    clsDoctor(enMode mode, string doctorID, string firstName, string secondName, string thirdName,
              string fourthName, enGender gender, clsDate birthdate, string specialization, string phone, float feesRate)
        :clsPerson(firstName,secondName,thirdName,fourthName,phone){

        _mode = mode;
        _ObjectIsSaved = enIsSave::DataisUnSaved;
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
