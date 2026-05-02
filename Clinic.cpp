#include <iostream>
#include "ProjectFiles//Core//clsDoctor.h"
#include"ProjectFiles//Core//clsPatient.h"
#include"ProjectFiles/Core/clsAppointment.h"
#include"ProjectFiles//Screens//MainMenu/clsMainMenu.h"
#include"ProjectFiles//Screens/MainMenu/clsManagePatientMenu.h"
#include"ProjectFiles//Screens/AppointmentMenu/clsShowAppointmentTableScreen.h"
using namespace std;
int main() {

   // clsMainMenu::ShowMenu();
	clsShowAppointmentTableScreen::ShowAppoitmentsTable();

   return 0;
}
