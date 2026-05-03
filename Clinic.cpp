#include <iostream>
#include "ProjectFiles//Core//clsDoctor.h"
#include"ProjectFiles//Core//clsPatient.h"
#include"ProjectFiles/Core/clsAppointment.h"
#include"ProjectFiles//Screens//MainMenu/clsMainMenu.h"
#include"ProjectFiles//Screens/MainMenu/clsManagePatientMenu.h"
#include"ProjectFiles//Screens/AppointmentMenu/clsShowAppointmentTableScreen.h"
#include"ProjectFiles//Screens/AppointmentMenu/clsFindAppointmentScreen.h"
#include"ProjectFiles//Screens/AppointmentMenu/clsAddAppointmentScreen.h"
#include "ProjectFiles//Screens/AppointmentMenu//clsUpdateAppointmentScreen.h"
#include"ProjectFiles//Screens//PatientMenu//clsUpdatePaitentsDataScreen.h"
using namespace std;
int main() {

    clsMainMenu::ShowMenu();
	
   return 0;
}
