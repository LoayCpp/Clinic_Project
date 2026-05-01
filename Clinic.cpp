#include <iostream>
#include "ProjectFiles//Core//clsDoctor.h"
#include"ProjectFiles//Core//clsPatient.h"
#include"ProjectFiles/Core/clsAppointment.h"
#include"ProjectFiles//Screens//MainMenu/clsMainMenu.h"
#include"ProjectFiles//Screens/MainMenu/clsManagePatientMenu.h"
#include"ProjectFiles//Screens/AppointmentMenu/clsAppointmentHelperFunctions.h"

using namespace std;
int main() {

   // clsMainMenu::ShowMenu();
    clsAppointment app;
 
    float fees;
    cin >> fees;
 
    while ( !(app.AppointmentFees = fees)) {
        cin >> fees;
    }
   // clsAppointmentHelperFunctions::PrintAppointmentInfo(app);
    /*
    
    app.save()
        addNew
        if(patient.save()) --->Update
              bool sate clsTemplate<clsAppointment>::Save(
        this->_mode, [this]()-> void {_UpdateAppointment(); },
            [this]()-> void {_AddAppointmentToFile(); },this->_objectIsSaved);

            if(state) 
                return true
             else
               patient.delete()
            return false
        else
        patient.delete()
        return false

     Num    ID          Specialization      Fees
     1      Doc001       A                   50
     2      Doc002       B                   40
     3      Doc003       C                   20
     4      Doc004       D                   55
     5      Doc005       E                   30
     
     map ---> mDocrors
     if(1) return 
     1   ----> Doc001
     2   ----> Doc002
     3   ----> Doc005
     4   ----> Doc004
     5   ----> Doc005


     Doctors For Every Specialization
        Enter ur choi


     Save
    */
    return 0;
}
