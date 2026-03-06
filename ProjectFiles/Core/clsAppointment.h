#pragma once
#include "ProjectFiles//Core//clsPatient.h"

class clsAppointment
{
private:
    string _appointmentID;
    clsDoctor _doctor;
    clsPatient _patient;
    clsDate _dateTime;

public:

    clsAppointment(string appointmentID, clsPatient patient, clsDoctor doctor, clsDate dateTime)
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


    
    clsDate GetDateTime()
    {
        return _dateTime;
    }

    void SetDateTime(clsDate dateTime)
    {
        _dateTime = dateTime;
    }

    __declspec(property(get = GetDateTime, put = SetDateTime)) clsDate DateTime;
};