#pragma once
#include "..//Libraries/clsDate.h"
#include"..//Core/clsPerson.h"
#include "..//Database/FilesName.h"
#include<vector>
#include<fstream>
#include"..//Libraries/clsString.h"
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

     vector<string> _LoadDoctorsFromFiles() {

        vector<string> vDoctors;
        fstream fileOfDoctor;
        string dataOfLine;
        fileOfDoctor.open(DoctorsFile, ios::in);

        if (fileOfDoctor.is_open()) {

            while (getline(fileOfDoctor, dataOfLine)) {


                vDoctors.push_back(dataOfLine);


            }
            fileOfDoctor.close();
        }
        else {

            cout << "\nfile it is not open\n";
        }

        return vDoctors;


    }



     int  _GetDoctorNumber() {


        vector<string> vDoctors = _LoadDoctorsFromFiles();
        //Doc001#//#Amr Siaf Ahmed Ali#//#1975-2-23#//#male#//#50#//#Dentistry#//#7383199920
        //Doc002#//#Luai Anwar Fesial#//#2004-3-12#//#male#//#18#//#Dermatology#//#777123456


        vector<string> vLineFromEndDoctor = clsString::SpilitString(vDoctors.back(), "#//#");

        //Doc002 
        //Luai Anwar Fesial
        //2004-3-12


        vector<string>vId = clsString::SpilitString(vLineFromEndDoctor.at(0), "Doc00");
        //First Doc002 
        //Second Doc00 to split 

        // End 2 in to vId index[0]

        int id = stoi(vId.at(0));

        //convert number from string to int 

        return id;


    }

     string _GeneratingIDForObject() {


        const string doctorIdWord = "Doc00";
        int doctorIdNum = _GetDoctorNumber();
        ++doctorIdNum;

        return doctorIdWord + to_string(doctorIdNum);

    }


public:
    clsDoctor(){}

    clsDoctor(enMode mode, string firstName, string secondName, string thirdName,
              string fourthName, enGender gender, clsDate birthdate, string specialization, string phone, float feesRate)
        :clsPerson(firstName,secondName,thirdName,fourthName,phone){
        _doctorID = _GeneratingIDForObject();
        _mode = mode;
        _ObjectIsSaved = enIsSave::DataisUnSaved;
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
