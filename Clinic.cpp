#include <iostream>
#include "ProjectFiles//Core//clsDoctor.h"
#include"ProjectFiles//Core//clsPatient.h"
#include"ProjectFiles/Core/clsAppointment.h"
#include"ProjectFiles//Screens//MainMenu/clsMainMenu.h"
#include"ProjectFiles//Screens/MainMenu/clsManagePatientMenu.h"
#include"ProjectFiles//Screens//PatientMenu//clsFindPatientScreen.h"
#include"ProjectFiles//Screens//PatientMenu//clsShowPatientsTableScreen.h"
using namespace std;
int main() {
    clsShowPatientsTableScreen::ShowPatientsTable();
   // clsMainMenu::ShowMenu();

    return 0;
}
