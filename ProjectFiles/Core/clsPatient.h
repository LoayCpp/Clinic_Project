#pragma once
#include "clsDoctor.h"
#include"clsPerson.h"
class clsPatient :public clsPerson
{
public:
    enum enGender
    {
        eMale = 1,
        eFemale,
        eUnkownGender
    };

private:


    string _patientID;
    enGender _gender;
    clsDate _birthdate;
    clsDoctor _doctor;
    clsTemplate<clsPatient>::enMode _mode;
    clsTemplate<clsPatient>::enIsSave  _ObjectIsSaved;



    string _ConvertGenderToString(enGender doctorGender) {


        return (doctorGender == enGender::eMale) ? "male" :
            (doctorGender == enGender::eFemale) ? "female" : "No Gender";


    }
    string _ConvertDoctorToDataLine(const clsPatient& patientInfo, string separator = "#//#") {

        string line;

        line = patientInfo.PatientID + separator;
        line += patientInfo.FirstName + separator;
        line += patientInfo.SecondName + separator;
        line += patientInfo.ThirdName + separator;
        line += patientInfo.FourthName + separator;
        line += _ConvertGenderToString(patientInfo.Gender) + separator;
        line += clsDate::DateToString(patientInfo.Birthdate) + separator;

        line += patientInfo.Phone;

    


        return line;
    }
    static   enGender _ConvertFromStringToGender(string gender) {


        return (gender == "male") ? enGender::eMale : enGender::eFemale;
    }

    static  clsPatient _ConvertDataLineToPatient(string DataOfLine, string separators) {

        vector<string>vLines;

        vLines = clsString::SpilitString(DataOfLine, separators);

        clsPatient patient(clsTemplate<clsPatient>::enMode::eUpadateMode, vLines[0], vLines[1], vLines[2], vLines[3], _ConvertFromStringToGender(vLines[5]), clsDate::StringToDate(vLines[6]), vLines[8]);

        return patient;

    }
    static  string getID(const clsPatient& p) {
        return p.PatientID;
    }
    static map<string, clsPatient> _LoadPatientFromFiles() {
        return clsTemplate<clsPatient>::LoadObjectsDataFromFiles(PatientFile, _ConvertDataLineToPatient, getID);

    }
    clsTemplate<clsPatient>::enMode getMode(const clsPatient& patient) {

        return patient._mode;
    }
    void _SaveDoctorDataToFile(const map<string, clsPatient>& patientDataMap) {

        clsTemplate<clsPatient>::SaveObjectsDataToFile(PatientFile, patientDataMap,
            [this](const clsPatient& tempPatient)-> clsTemplate<clsPatient>::enMode { return getMode(tempPatient); }
        , [this](const clsPatient& tempPatient, string sperator = "#//#")-> string {return _ConvertDoctorToDataLine(tempPatient, sperator); });

    }
    void _UpdateDoctor() {

        clsTemplate<clsPatient>::UpdateObject(_LoadPatientFromFiles, *this, getID,
            [this](const map<string, clsPatient>& patientDataMap)->void {_SaveDoctorDataToFile(patientDataMap); },
            _ObjectIsSaved);

    }
    string  _GetPatientNumber() {
        return clsTemplate<clsPatient>::GetEndNumberFromFile(_LoadPatientFromFiles);

    }
    string _GeneratingIDForObject() {

        return this->_patientID + _GetPatientNumber();
    }
    void _AddDoctorToFile() {

        this->_patientID = _GeneratingIDForObject();
        clsTemplate<clsPatient>::AddObjectToFile(DoctorsFile, *this,
            [this](const clsPatient& tempPatient, string sperator = "#//#")-> string {return _ConvertDoctorToDataLine(tempPatient, sperator); }
        , _ObjectIsSaved);
    }
public:
    clsPatient(){
        this->_mode = clsTemplate <clsPatient> ::enMode::eEmptyMode;
        this->_ObjectIsSaved = clsTemplate<clsPatient>::enIsSave::DataisUnSaved;
        this->_patientID = "Patient00";
        this->_birthdate = clsDate(0, 0, 0);
    
    }
    clsPatient(clsTemplate<clsPatient>::enMode mode, string firstName, string secondName, string thirdName, string fourthName, enGender gender, clsDate birthdate, string phone)
        :clsPerson(firstName,secondName,thirdName,fourthName,phone)
        
    {

        _patientID = "Patient00";
        _mode = mode;
        _ObjectIsSaved = clsTemplate<clsPatient>::enIsSave::DataisUnSaved;
        _gender = gender;
        _birthdate = birthdate;
      
    };

    string GetPatientID() const
    {
        return _patientID;
    }
    __declspec(property(get = GetPatientID))string PatientID;

    void SetGender(enGender Gender)
    {
        _gender = Gender;
    }

    enGender GetGender() const
    {
        return _gender;
    }
    __declspec(property(get = GetGender, put = SetGender))enGender Gender;

    void SetBirthdate(clsDate Birthdate)
    {
        _birthdate = Birthdate;
    }
    clsDate GetBirthdate() const
    {
        return _birthdate;
    }

    __declspec(property(get = GetBirthdate, put = SetBirthdate))clsDate Birthdate;

    string GetDateforYears() {
        return to_string(Birthdate.CalculateMyAgeInDays() / 365);
    }
    __declspec(property(get = GetDateforYears)) string Age;

    string GenderToString() {
        return _ConvertGenderToString(this->_gender);
    }
    __declspec(property(get = GenderToString)) string strGender;
    bool IsEmpty() {

        return (_mode == clsTemplate<clsPatient>::enMode::eEmptyMode);
    }
    static   map<string, clsPatient> GetAllPatients() {
        return _LoadPatientFromFiles();
    }

    static clsPatient GetNewPatientObject() {

        return clsPatient(clsTemplate<clsPatient>::enMode::eAddNewMode, "", "", "",
            "", enGender::eUnkownGender, clsDate(0, 0, 0),"");
    }

    static clsPatient GetEmptyObject() {
        return  clsPatient(clsTemplate<clsPatient>::enMode::eEmptyMode, "", "", "", "",
            enGender::eUnkownGender, clsDate(0, 0, 0), "");
    }
    static clsPatient FindDoctor(string patientID) {

        return   clsTemplate<clsPatient>::FindObject(patientID, _LoadPatientFromFiles, GetEmptyObject);

    }
    bool Delete() {

        return   clsTemplate<clsPatient>::DeleteObject(*this, this->_mode,
            this->_ObjectIsSaved, [this]() { _UpdateDoctor(); }, GetEmptyObject);

    }
    bool Save() {

        return clsTemplate<clsPatient>::Save(_mode, [this]() { _UpdateDoctor(); },
            [this]() { _AddDoctorToFile(); }, _ObjectIsSaved);

    }

};

