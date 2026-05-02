#pragma once
#include "..//Libraries/clsDate.h"
#include"..//Core/clsPerson.h"
#include "..//Database/FilesName.h"
#include<vector>
#include<fstream>
#include"..//Libraries/clsString.h"
#include<map>
#include"clsTemplate.h"
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
    clsTemplate<clsPatient>::enMode _mode;
    clsTemplate<clsPatient>::enIsSave  _ObjectIsSaved;
    bool _hasMultipleAppointments;


    string _ConvertGenderToString(enGender patientGender) {


        return (patientGender == enGender::eMale) ? "male" :
            (patientGender == enGender::eFemale) ? "female" : "No Gender";
    }
    string _ConvertPatientToDataLine(const clsPatient& patientInfo, string separator = "#//#") {

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

        clsPatient patient(
            clsTemplate<clsPatient>::enMode::eUpadateMode,
            vLines[0],
            vLines[1],
            vLines[2],
            vLines[3],
            vLines[4],
            _ConvertFromStringToGender(vLines[5]),
            clsDate::StringToDate(vLines[6]),
            vLines[7] 
        );
       
        return patient;

    }
    static  string getID(const clsPatient& p) {
        return p.PatientID;
    }
    static map<string, clsPatient> _LoadPatientFromFiles() {
        return clsTemplate<clsPatient>::LoadObjectsDataFromFiles(PatientsFile, _ConvertDataLineToPatient, getID);

    }
    clsTemplate<clsPatient>::enMode getMode(const clsPatient& patient) {

        return patient._mode;
    }
    void _SavePatientDataToFile(const map<string, clsPatient>& patientDataMap) {

        clsTemplate<clsPatient>::SaveObjectsDataToFile(PatientsFile, patientDataMap,
            [this](const clsPatient& tempPatient)-> clsTemplate<clsPatient>::enMode { return getMode(tempPatient); }
        , [this](const clsPatient& tempPatient, string sperator = "#//#")-> string {return _ConvertPatientToDataLine(tempPatient, sperator); });

    }
    void _UpdatePatient() {

        clsTemplate<clsPatient>::UpdateObject(_LoadPatientFromFiles, *this, getID,
            [this](const map<string, clsPatient>& patientDataMap)->void {_SavePatientDataToFile(patientDataMap); },
            _ObjectIsSaved);

    }
    string  _GetPatientNumber() {
        return clsTemplate<clsPatient>::GetEndNumberFromFile(_LoadPatientFromFiles,9);

    }
    void _GeneratingIDForObject() {

        this->_patientID += _GetPatientNumber();
    }


    void _AddPatientToFile() {

        clsTemplate<clsPatient>::AddObjectToFile(PatientsFile, *this,
            [this](const clsPatient& tempPatient, string sperator = "#//#")-> string {return _ConvertPatientToDataLine(tempPatient, sperator); }
        , [this](void)->void {_GeneratingIDForObject(); }, _ObjectIsSaved);
    }
    clsPatient(clsTemplate<clsPatient>::enMode mode,string patientID ,string firstName, string secondName, string thirdName, string fourthName, enGender gender, clsDate birthdate, string phone) 
    :clsPerson(firstName, secondName, thirdName, fourthName, phone){
        this->_patientID = patientID;
        this->_mode = mode;
        this->_gender = gender;
        this->_birthdate = birthdate;
        this->_hasMultipleAppointments = false;
        this->_ObjectIsSaved = clsTemplate<clsPatient>::enIsSave::DataisUnSaved;
    }
public:
    clsPatient() :clsPatient(clsTemplate<clsPatient>::enMode::eEmptyMode,"Patient00", "", "", "", "", enGender::eUnkownGender, clsDate(0, 0, 0), "") {
    }

    
    
    clsPatient(clsTemplate<clsPatient>::enMode mode, string firstName, string secondName, string thirdName, string fourthName, enGender gender, clsDate birthdate, string phone)
        :clsPatient(mode, "Patient00", firstName, secondName, thirdName, fourthName, gender, birthdate, phone)
    {}

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

    void SetHasMultipleAppointments(bool HasMultipleAppointments){
        
        this->_hasMultipleAppointments = HasMultipleAppointments;
    }
    bool GetHasMultipleAppointments() const
    {
        return this->_hasMultipleAppointments;
    }
    __declspec(property(get = GetHasMultipleAppointments, put = SetHasMultipleAppointments))bool HasMultipleAppointments;

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
        return  clsPatient();
    }
    static clsPatient FindPatient(string patientID) {

        return   clsTemplate<clsPatient>::FindObject(patientID, _LoadPatientFromFiles, GetEmptyObject);

    }
    bool Delete() {

        return   clsTemplate<clsPatient>::DeleteObject(*this, this->_mode,
            this->_ObjectIsSaved, [this]() { _UpdatePatient(); }, GetEmptyObject);

    }
    bool Save() {

        return clsTemplate<clsPatient>::Save(_mode, [this]() { _UpdatePatient(); },
            [this]() { _AddPatientToFile(); }, _ObjectIsSaved);

    }

};

