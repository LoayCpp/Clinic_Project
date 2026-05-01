#pragma once
#include "clsPatient.h"
class clsAppointment
{
private:

    clsTemplate<clsAppointment>::enMode  _mode;
    clsTemplate<clsAppointment>::enIsSave _objectIsSaved;
    string _appointmentID;
    clsDoctor _doctor;
    clsPatient _patient;
    string _dateTime;

    float _appointmentFees;
    float _basePrice;
    static clsAppointment _ConvertDataLineToAppointment(string dataLine, string separator = "#//#") {

        vector<string> vLine = clsString::SpilitString(dataLine, separator);
        //Appoin001#//#Patien001#//#Doc004#//#11200#//#4/22/2026 - 2:03

        return clsAppointment(clsTemplate<clsAppointment>::enMode::eUpadateMode,
            vLine[0], clsPatient::FindPatient(vLine[1]), clsDoctor::FindDoctor(vLine[2]), stof(vLine[3]), vLine[4]);
    }
    string _ConvertAppointmentToDataLine(const clsAppointment& appointment, string separator = "#//#") {
        string line = "";

        line = appointment._appointmentID + separator;
        line += appointment._patient.PatientID + separator;
        line += appointment._doctor.DoctorID + separator;
        line += to_string(appointment._appointmentFees) + separator;
        line += appointment._dateTime;

        return line;
    }
    static string _GetAppointmentID(const clsAppointment& appointment) {
        return appointment._appointmentID;
    }
    clsTemplate<clsAppointment>::enMode _GetAppointmentMode(const clsAppointment& appointment) {
        return appointment._mode;
    }
    static map<string, clsAppointment> _loadAppointmentDataFromFile() {
        return clsTemplate<clsAppointment>::LoadObjectsDataFromFiles(AppointmentsFile, _ConvertDataLineToAppointment, _GetAppointmentID);
    }
    void _SaveAppointmentDataToFile(const map<string, clsAppointment>& mAppointments) {

        clsTemplate<clsAppointment>::SaveObjectsDataToFile(AppointmentsFile, mAppointments,
            [this](const clsAppointment& appointment) -> clsTemplate<clsAppointment>::enMode {return _GetAppointmentMode(appointment); },
            [this](const clsAppointment& appointment, string separator = "#//#") -> string
            {return _ConvertAppointmentToDataLine(appointment, separator); });
    }
    string _GetNextAppointmentNumber() {
        //Appoin00 ---> 8 
        return clsTemplate<clsAppointment>::GetEndNumberFromFile(_loadAppointmentDataFromFile,8);
    }
    void _GenerateAppointmentID() {
        this->_appointmentID += _GetNextAppointmentNumber();
    }
    void _AddAppointmentToFile() {
        clsTemplate<clsAppointment>::AddObjectToFile(AppointmentsFile, *this, 
            [this](const clsAppointment& appointment, string separator = "#//#") -> string
            {return _ConvertAppointmentToDataLine(appointment, separator); },
            [this]() -> void {_GenerateAppointmentID(); },
            this->_objectIsSaved);
    }
    void _UpdateAppointment() {
        clsTemplate<clsAppointment>::UpdateObject(_loadAppointmentDataFromFile, *this, _GetAppointmentID,
            [this](const map<string, clsAppointment>& mAppointments)-> void {_SaveAppointmentDataToFile(mAppointments); }, this->_objectIsSaved
        );
    }

    clsAppointment(clsTemplate<clsAppointment>::enMode mode,
        string appointmentID, clsPatient patient, clsDoctor doctor, float appointmentFees,string dateTime) {

        this->_mode = mode;
        this->_appointmentID = appointmentID;

        this->_patient = patient;
        this->_doctor = doctor;
        
        this->_appointmentFees = appointmentFees;
        this->_dateTime = dateTime;
        this->_basePrice = 3500;
        this->_objectIsSaved = clsTemplate<clsAppointment>::enIsSave::DataisUnSaved;
    }
public:

    clsAppointment() :
        clsAppointment(clsTemplate<clsAppointment>::enMode::eEmptyMode, "Appoin00", clsPatient(), clsDoctor(), 0.0, clsDate::GetLocalDatetime()) {}

    clsAppointment(clsTemplate<clsAppointment>::enMode mode,
        clsPatient patient, clsDoctor doctor, float appointmentFees)
        : clsAppointment(mode,"Appoin00", patient, doctor, appointmentFees, clsDate::GetLocalDatetime())
    {   }

   
    string GetAppointmentID() const {
        return _appointmentID;
    }
    __declspec(property(get = GetAppointmentID)) string AppointmentID;


    
    clsDoctor GetDoctor() const 
    {
        return _doctor;
    }
    void SetDoctor(clsDoctor doctor)
    {
        _doctor = doctor;
    }
    __declspec(property(get = GetDoctor, put = SetDoctor)) clsDoctor Doctor;



    clsPatient GetPatient() const
    {
        return _patient;
    }
    void SetPatient(clsPatient patient)
    {
        _patient = patient;
    }
    __declspec(property(get = GetPatient, put = SetPatient)) clsPatient Patient;

    float GetBasePrice() const  {
        return this->_basePrice;
    }
    void SetBasePrice(float basePrice) {
        this->_basePrice = basePrice;
    }
    __declspec(property(get = GetBasePrice, put = SetBasePrice)) float BasePrice;

    float GetTotalPrice() const {
        return this->_basePrice * (1 + this->_doctor.FeesRate / 100);
    }
    __declspec(property(get = GetTotalPrice)) float TotalPrice;

    float GetAppointmentFees() const {
        return this->_appointmentFees;
    }
    void SetAppointmentFees(float appointmentFees) {

        this->_appointmentFees = appointmentFees;
    }
    __declspec(property(get = GetAppointmentFees, put = SetAppointmentFees)) float AppointmentFees;

    bool IsAppointmentFeesEqualTotalPrice() {
        return this->_appointmentFees == TotalPrice;
    }
    bool IsEmpty() {
        return this->_mode == clsTemplate<clsAppointment>::enMode::eEmptyMode;
    }
    static clsAppointment GetEmptyAppointmentObject() {
        return clsAppointment();
    }
    static clsAppointment GetNewAppointmentObject() {
        return clsAppointment(clsTemplate<clsAppointment>::enMode::eAddNewMode,clsPatient(),clsDoctor(),0.0);
    }
    static map<string, clsAppointment> GetAllAppointment() {
        return  _loadAppointmentDataFromFile();
    }
    static clsAppointment FindAppointment(string appointmentID) {
        return clsTemplate<clsAppointment>::FindObject(appointmentID, _loadAppointmentDataFromFile, GetEmptyAppointmentObject);
    }
    bool Delete() {
      
        if (this->_patient.Delete()) {
            bool state = clsTemplate<clsAppointment>::DeleteObject(*this,
                this->_mode, this->_objectIsSaved,
                [this]()-> void {_UpdateAppointment(); },
                GetEmptyAppointmentObject);


            return state ? true : this->_patient.Delete(), false;
        }


        return false;
         
    }
    bool Save() {
    
        if (this->_patient.Save()){
            bool state = clsTemplate<clsAppointment>::Save(
                this->_mode, [this]()-> void {_UpdateAppointment(); },
                [this]()-> void {_AddAppointmentToFile(); }, this->_objectIsSaved);

         
            return state ? true : this->_patient.Delete(), false;
        }

    
        return false;
         
    
    }
};