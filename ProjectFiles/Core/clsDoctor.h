#pragma once
#include "..//Libraries/clsDate.h"
#include"..//Core/clsPerson.h"
#include "..//Database/FilesName.h"
#include<vector>
#include<fstream>
#include"..//Libraries/clsString.h"
#include<map>
class clsDoctor : public clsPerson
{

public:
    enum enGender
    {
        eeUnkown=1,
        eFemale ,
        eMale
    };

    enum enSpecialization
    {
        eUnkownSpecialization=1,
        eDentistry ,
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
    enSpecialization _specialization;
    float _feesRate;


    enGender _ConvertFromStringToGender(string gender) {


        return (gender == "male") ? enGender::eMale : enGender::eFemale;
    }


        enSpecialization _ConvertFromStringToEnSpecialization(string specialization) {

            if (specialization == "Dentistry")
                return enSpecialization::eDentistry;

            if (specialization == "Dermatology")
                return enSpecialization::eDermatology;

            if (specialization == "InternalMedicine")
                return enSpecialization::eInternalMedicine;

            if (specialization == "ENT")
                return enSpecialization::eENT;

            if (specialization == "Surgery")
                return enSpecialization::eSurgery;



            return enSpecialization::eUnkownSpecialization;
        

    }

    clsDoctor _convertDataToLine(string DataOfLine,string separators) {

        vector<string>vLines;

        vLines = clsString::SpilitString(DataOfLine,separators);

        clsDoctor Doctor(enMode::eUpadateMode, vLines[0], vLines[1], vLines[2], vLines[3], vLines[4], _ConvertFromStringToGender(vLines[5]), clsDate::StringToDate(vLines[6]),_ConvertFromStringToEnSpecialization( vLines[7]), vLines[8], stof(vLines[9]));

        return Doctor;

    }
    map<string, clsDoctor> _LoadDoctorsFromFiles() {

        map<string, clsDoctor> mDoctors;

        fstream fileOfDoctor;




        fileOfDoctor.open(DoctorsFile, ios::in);

        string dataOfLine;
        if (fileOfDoctor.is_open()) {

            while (getline(fileOfDoctor, dataOfLine)) {



                clsDoctor doctor = _convertDataToLine(dataOfLine,"#//#");


                mDoctors[doctor.DoctorID] = doctor;

            }
            fileOfDoctor.close();
        }
        else {

            cout << "\nfile it is not open\n";
        }

        return mDoctors;

    }


    string  _GetDoctorNumber() {


        map<string, clsDoctor> mDoctor = _LoadDoctorsFromFiles();


        if (mDoctor.empty())
            return "1";

        auto mEndDoctors = mDoctor.rbegin();

        string WordId = mEndDoctors->first;


        string id = WordId.substr(5);



        return to_string(stoi(id) + 1);

    }


    string _GeneratingIDForObject() {





        return this->DoctorID + _GetDoctorNumber();

    }


    clsDoctor(enMode mode, string doctorID, string firstName, string secondName, string thirdName,
        string fourthName, enGender gender, clsDate birthdate, enSpecialization specialization, string phone, float feesRate)
        : clsPerson(firstName, secondName, thirdName, fourthName, phone) {

        _doctorID = doctorID;
        _birthdate = birthdate;
        _gender = gender;
        _feesRate = feesRate;
        _specialization = specialization;

    };

public:
    clsDoctor() {}

    clsDoctor(enMode mode, string firstName, string secondName, string thirdName,
        string fourthName, enGender gender, clsDate birthdate, enSpecialization specialization, string phone, float feesRate)
        :clsPerson(firstName, secondName, thirdName, fourthName, phone) {
        _doctorID = "Doc00";
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


    void SetSpecialization(enSpecialization Specialization)
    {
        _specialization = Specialization;
    }

    enSpecialization GetSpecialization() const
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
