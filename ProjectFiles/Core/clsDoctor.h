#pragma once
#include "..//Libraries/clsDate.h"
#include"..//Core/clsPerson.h"
#include "..//Database/FilesName.h"
#include<vector>
#include<fstream>
#include"..//Libraries/clsString.h"
#include<map>
#include"clsTemplate.h"
class clsDoctor : public clsPerson
{

public:

    enum enSpecialization
    {
        eDentistry = 1,
        eDermatology,
        eInternalMedicine,
        eENT,
        eSurgery,
        eUnkownSpec
    };
    enum enGender
    {
        eMale = 1,
        eFemale,
        eUnkownGender
    };
private:





    clsTemplate<clsDoctor>::enMode _mode;
    clsTemplate<clsDoctor>::enIsSave _ObjectIsSaved;
    string _doctorID;
    enGender _gender;
    clsDate _birthdate;
    enSpecialization _specialization;
    float _feesRate;

    static   enGender _ConvertFromStringToGender(string gender) {


        return (gender == "male") ? enGender::eMale : enGender::eFemale;
    }
    static enSpecialization _ConvertFromStringToSpecialization(string specialization) {


        if (specialization == "Dentistry")
            return enSpecialization::eDentistry;

        if (specialization == "Dermatology")
            return enSpecialization::eDermatology;

        if (specialization == "Internal Medicine")
            return enSpecialization::eInternalMedicine;

        if (specialization == "ENT")
            return enSpecialization::eENT;

        if (specialization == "Surgery")
            return enSpecialization::eSurgery;

        return enSpecialization::eUnkownSpec;

    }

    static  clsDoctor _ConvertDataLineToDoctor(string DataOfLine, string separators) {

        vector<string>vLines;

        vLines = clsString::SpilitString(DataOfLine, separators);

        clsDoctor Doctor(clsTemplate<clsDoctor>::enMode::eUpadateMode, vLines[0], vLines[1], vLines[2], vLines[3], vLines[4], _ConvertFromStringToGender(vLines[5]), clsDate::StringToDate(vLines[6]), _ConvertFromStringToSpecialization(vLines[7]), vLines[8], stof(vLines[9]));

        return Doctor;

    }
    static  string getID(const clsDoctor& D) {
        return D.DoctorID;
    }

    static map<string, clsDoctor> _LoadDoctorsFromFiles() {
        return clsTemplate<clsDoctor>::LoadObjectsDataFromFiles(DoctorsFile, _ConvertDataLineToDoctor, getID);

    }


    clsTemplate<clsDoctor>::enMode getMode(const clsDoctor& doctor) {

        return doctor._mode;
    }
    string _ConvertGenderToString(enGender doctorGender) {


        return (doctorGender == enGender::eMale) ? "male" :
            (doctorGender == enGender::eFemale) ? "female" : "No Gender";


    }
    string _ConvertFromEnSpecializationToString(enSpecialization doctorSpecialization) {

        short num = (short)doctorSpecialization;
        string specialization[] = { "Unknown Specialization", "Dentistry",
            "Dermatology", "Internal Medicine", "ENT", "Surgery" };

        return specialization[num];
    }
    string _ConvertDoctorToDataLine(const clsDoctor& DoctorInfo, string separator ="#//#") {

        string line;

        line = DoctorInfo.DoctorID + separator;
        line += DoctorInfo.FirstName + separator;
        line += DoctorInfo.SecondName + separator;
        line += DoctorInfo.ThirdName + separator;
        line += DoctorInfo.FourthName + separator;
        line += _ConvertGenderToString(DoctorInfo.Gender) + separator;
        line += clsDate::DateToString(DoctorInfo.BirthDate) + separator;
        line += _ConvertFromEnSpecializationToString(DoctorInfo.Specialization) + separator;

        line += DoctorInfo.Phone + separator;

        line += to_string(DoctorInfo.FeesRate);


        return line;
    }
    void  _SaveDoctorDataToFile(const map<string, clsDoctor>& doctorsDataMap) {

        clsTemplate<clsDoctor>::SaveObjectsDataToFile(DoctorsFile, doctorsDataMap,
            [this](const clsDoctor& tempDoctor)-> clsTemplate<clsDoctor>::enMode { return getMode(tempDoctor); }
        , [this](const clsDoctor& tempDoctor, string sperator = "#//#")-> string {return _ConvertDoctorToDataLine(tempDoctor, sperator); });

    }

    string  _GetDoctorNumber() {
        return clsTemplate<clsDoctor>::GetEndNumberFromFile(_LoadDoctorsFromFiles);

    }

    string _GeneratingIDForObject() {

        return this->DoctorID + _GetDoctorNumber();
    }

    void _UpdateDoctor() {

        clsTemplate<clsDoctor>::UpdateObject(_LoadDoctorsFromFiles, *this, getID, 
            [this](const map<string, clsDoctor>& doctorsDataMap)->void {_SaveDoctorDataToFile(doctorsDataMap); }, 
            _ObjectIsSaved);

    }

    void _AddDoctorToFile() {

        this->_doctorID = _GeneratingIDForObject();
        clsTemplate<clsDoctor>::AddObjectToFile(DoctorsFile, *this, 
        [this](const clsDoctor& tempDoctor, string sperator = "#//#")-> string {return _ConvertDoctorToDataLine(tempDoctor, sperator); }
        , _ObjectIsSaved);
    }

    clsDoctor(clsTemplate<clsDoctor>::enMode mode, string doctorID, string firstName, string secondName, string thirdName,
        string fourthName, enGender gender, clsDate birthdate, enSpecialization specialization, string phone, float feesRate)
        : clsPerson(firstName, secondName, thirdName, fourthName, phone) {
        _mode = mode;
        _doctorID = doctorID;
        _birthdate = birthdate;
        _gender = gender;
        _feesRate = feesRate;
        _specialization = specialization;

    };


public:
    clsDoctor() {}

    clsDoctor(clsTemplate<clsDoctor>::enMode mode, string firstName, string secondName, string thirdName,
        string fourthName, enGender gender, clsDate birthdate, enSpecialization specialization, string phone, float feesRate)
        :clsPerson(firstName, secondName, thirdName, fourthName, phone) {
        _doctorID = "Doc00";
        _mode = mode;
        _ObjectIsSaved = clsTemplate<clsDoctor>::enIsSave::DataisUnSaved;
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


    void SetSpecialization(enSpecialization specialization)
    {
        _specialization = specialization;
    }
    enSpecialization GetSpecialization() const
    {
        return _specialization;
    }
    __declspec(property(get = GetSpecialization, put = SetSpecialization)) enSpecialization Specialization;

    void SetFeesRate(float FeesRate)
    {
        _feesRate = FeesRate;
    }
    float GetFeesRate() const
    {
        return _feesRate;
    }
    __declspec(property(get = GetFeesRate, put = SetFeesRate)) float FeesRate;

    string SpecializationToString() {
        return _ConvertFromEnSpecializationToString(this->_specialization);
    }
    __declspec(property(get = SpecializationToString)) string strSpecialization;

    string GenderToString() {
        return _ConvertGenderToString(this->_gender);
    }
    __declspec(property(get = GenderToString)) string strGender;

    bool IsEmpty() {

        return (_mode == clsTemplate<clsDoctor>::enMode::eEmptyMode);
    }

    static   map<string, clsDoctor> GetAllDoctors() {
        return _LoadDoctorsFromFiles();
    }
    static clsDoctor GetNewDoctorObject() {

        return clsDoctor(clsTemplate<clsDoctor>::enMode::eAddNewMode, "", "", "",
            "", enGender::eUnkownGender, clsDate(0, 0, 0), enSpecialization::eUnkownSpec, "", 0.0);
    }
    static clsDoctor GetEmptyObject() {
        return  clsDoctor(clsTemplate<clsDoctor>::enMode::eEmptyMode, "", "", "", "",
            enGender::eUnkownGender, clsDate(0, 0, 0), enSpecialization::eUnkownSpec, "", 0.0);
    }
    static clsDoctor FindDoctor(string doctorID) {

        return   clsTemplate<clsDoctor>::FindObject(doctorID, _LoadDoctorsFromFiles, GetEmptyObject);

    }

    bool Delete() {

        return   clsTemplate<clsDoctor>::DeleteObject(*this, this->_mode, 
            this->_ObjectIsSaved, [this]() { _UpdateDoctor(); }, GetEmptyObject);

    }
    bool Save() {

        return clsTemplate<clsDoctor>::Save(_mode, [this]() { _UpdateDoctor(); }, 
            [this]() { _AddDoctorToFile(); }, _ObjectIsSaved);

    }
};
