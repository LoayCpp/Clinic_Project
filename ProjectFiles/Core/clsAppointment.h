#pragma once
#include "clsPatient.h"

class clsAppointment
{
private:
    string _appointmentID;
    clsDoctor _doctor;
    clsPatient _patient;
     string _dateTime;

public:

    clsAppointment(string appointmentID, clsPatient patient, clsDoctor doctor, string dateTime)
    {
        _appointmentID = appointmentID;
        _patient = patient;
        _doctor = doctor;
        _dateTime = dateTime;
    }

   
    string GetAppointmentID()
    {
        return _appointmentID;
    }

    __declspec(property(get = GetAppointmentID)) string AppointmentID;


    
    clsDoctor GetDoctor()
    {
        return _doctor;
    }

    void SetDoctor(clsDoctor doctor)
    {
        _doctor = doctor;
    }

    __declspec(property(get = GetDoctor, put = SetDoctor)) clsDoctor Doctor;



    clsPatient GetPatient()
    {
        return _patient;
    }

    void SetPatient(clsPatient patient)
    {
        _patient = patient;
    }

    __declspec(property(get = GetPatient, put = SetPatient)) clsPatient Patient;


    
    string GetDateTime()
    {
        return _dateTime;
    }

    void SetDateTime(string dateTime)
    {
        _dateTime = dateTime;
    }

    __declspec(property(get = GetDateTime, put = SetDateTime)) string DateTime;
};