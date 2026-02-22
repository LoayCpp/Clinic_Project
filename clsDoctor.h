#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;
enum enGender
{
    eFemale = 0,
    eMale = 1
};
class clsDoctor
{
private:
	int _ID;
	string _name;
	enGender _gender;
	string _Phone;
	clsDate _birthday;
	string _specialization;
	float _feesRate;

public:
  
    clsDoctor(int ID, string name, clsDate birthday, enGender gender, float feesRate, string specialization, string Phone) {

        _ID = ID;
        _name = name;
        _birthday = birthday;
        _gender = gender;
        _feesRate = feesRate;
        _specialization = specialization;
        _Phone = Phone;

    };

    int GetID()
    {
        return _ID;
    }

    void SetName(string Name)
    {
        _name = Name;
    }

    string GetName() 
    {
        return _name;
    }
    __declspec(property(get = GetName, put = SetName))string Name;

  
    void SetGender(enGender Gender)
    {
        _gender = Gender;
    }

    enGender GetGender() 
    {
        return _gender;
    }

    __declspec(property(get = GetGender, put = SetGender))enGender Gender;

    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    string GetPhone() 
    {
        return _Phone;
    }
    __declspec(property(get =GetPhone, put = SetPhone))string Phone;


    void SetBirthday(clsDate Birthday)
    {
        _birthday = Birthday;
    }

    clsDate GetBirthday() 
    {
        return _birthday;
    }

    __declspec(property(get = GetBirthday, put = SetBirthday))clsDate Date;

    void SetSpecialization(string Specialization)
    {
        _specialization = Specialization;
    }

    string GetSpecialization() 
    {
        return _specialization;
    }


    __declspec(property(get = GetSpecialization, put = SetSpecialization))string specialization;



    void SetFeesRate(float FeesRate)
    {
        _feesRate = FeesRate;
    }

    float GetFeesRate() 
    {
        return _feesRate;
    }
    __declspec(property(get = GetFeesRate, put = SetFeesRate))float feesRate;
};





