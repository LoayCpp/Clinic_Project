#include <iostream>
#include "ProjectFiles//Core//clsDoctor.h"
#include"ProjectFiles//Core//clsPatient.h"
#include"ProjectFiles/Core/clsAppointment.h"
#include"ProjectFiles//Screens//MainMenu/clsMainMenu.h"
#include"ProjectFiles//Screens/MainMenu/clsManagePatientMenu.h"
#include"ProjectFiles//Screens/AppointmentMenu/clsAppointmentHelperFunctions.h"
clsDoctor Empty(bool state) {
    return state ? clsDoctor() : clsDoctor::FindDoctor("Doc004");
}
using namespace std;
int main() {

   // clsMainMenu::ShowMenu();
    clsAppointment app = clsAppointment::FindAppointment("Appoin001");
    if (app.Delete()) {
        cout << "Appointment was deleted .\n";
    }

    return 0;
}
