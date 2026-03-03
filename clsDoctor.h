#pragma once
#include<iostream>
#include "ProjectFiles//Libraries/clsDate.h""
using namespace std;

class clsDoctor
{

public:
    enum enGender {
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
	string _phone;
	clsDate _birthday;
	string _specialization;
	float _feesRate;

public:

    clsDoctor(string doctorID, string firstName,string secondName ,string thirdName,string fourthName,clsDate birthday, enGender gender, float feesRate, string specialization, string phone) {

        _doctorID = doctorID;
        _firstName = firstName;
        _secondName = secondName;
        _thirdName = thirdName;
        _fourthName = fourthName;
        _birthday = birthday;
        _gender = gender;
        _feesRate = feesRate;
        _specialization = specialization;
        _phone = phone;

    };

    string GetDoctorID () const
    {
        return _doctorID;
    }
    __declspec(property(get = GetDoctorID))string DoctorID;

    void SetFirstName(string firstName)
    {
        _firstName = firstName;
    }

    string GetFirstName() const
    {
        return _firstName;
    }

    __declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;

    void SetLastName(string lastName)
    {
        _secondName = lastName;
    }

    string GetLastName() const
    {
        return _secondName;
    }

    __declspec(property(get = GetLastName, put = SetLastName))string LastName;

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
    __declspec(property(get =GetPhone, put = SetPhone))string Phone;


    void SetBirthday(clsDate Birthday)
    {
        _birthday = Birthday;
    }

    clsDate GetBirthday() const
    {
        return _birthday;
    }

    __declspec(property(get = GetBirthday, put = SetBirthday))clsDate BirthDay;

    void SetSpecialization(string Specialization)
    {
        _specialization = Specialization;
    }

    string GetSpecialization() const
    {
        return _specialization;
    }


    __declspec(property(get = GetSpecialization, put = SetSpecialization))string Specialization;



    void SetFeesRate(float FeesRate)
    {
        _feesRate = FeesRate;
    }

    float GetFeesRate() const
    {
        return _feesRate;
    }
    __declspec(property(get = GetFeesRate, put = SetFeesRate))float FeesRate;
};





