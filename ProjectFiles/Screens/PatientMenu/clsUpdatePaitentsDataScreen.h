#pragma once
#include "..//clsHeaderScreen.h"
#include "clsPatientHelperFunctions.h"
using namespace std;
class clsUpdatePaitentsDataScreen :public clsHeaderScreen
{

private:
	static void ShowUpdateScreenHeader() {
		string title = clsUtil::Tabs(1) + " Update Patient's Data Screen";
		ShowMainHeader(title);
	}
	class clsUpdatePatientDataMenu {


	private:
		class clsUpdatePatientNameMenu {
		private:
			enum enUpdatePatientNameMenu
			{
				eUpdatePatientFirstName = 1,
				eUpdatePatientSecondName,
				eUpdatePatientThirdName,
				eUpdatePatientFourthName,
				eUpdatePatientFullName,

			};
			static short _ReadPatientNameMenuOption() {

				cout << "Enter The Number from [1-5]:";
				return  clsInputValidate::ReadNumberBetween<short>(1, 5);
			}



			static void _ShowUpdatePatientFirstName(string lineSperator, clsPatient& Patient) {
				ShowUpdateScreenHeader();
				cout << lineSperator;
				Patient.FirstName = clsSharedHelperFunctions::ReadFirstName("Patient`s");
				cout << lineSperator;
			}
			static void _ShowUpdatePatientSecondName(string lineSperator, clsPatient& Patient) {

				ShowUpdateScreenHeader();
				cout << lineSperator;
				Patient.SecondName = clsSharedHelperFunctions::ReadSecondName("Patient`s");
				cout << lineSperator;

			}
			static void _ShowUpdatePatientThirdName(string lineSperator, clsPatient& Patient) {
				ShowUpdateScreenHeader();
				cout << lineSperator;
				Patient.ThirdName = clsSharedHelperFunctions::ReadThirdName("Patient`s");
				cout << lineSperator;
			}
			static void _ShowUpdatePatientFourthName(string lineSperator, clsPatient& Patient) {
				ShowUpdateScreenHeader();
				cout << lineSperator;
				Patient.FourthName = clsSharedHelperFunctions::ReadFourthName("Patient`s");
				cout << lineSperator;
			}
			static void _ShowUpdatePatientFullName(string lineSperator, clsPatient& Patient) {
				ShowUpdateScreenHeader();
				cout << lineSperator;
				clsPatientHelperFunctions::ReadFullName(Patient);
				cout << lineSperator;
			}

			static void _PerformPatientNameMenuOperation(enUpdatePatientNameMenu option, string lineSperator, clsPatient& Patient) {


				switch (option)
				{
				case enUpdatePatientNameMenu::eUpdatePatientFirstName:

					_ShowUpdatePatientFirstName(lineSperator, Patient);

					break;

				case enUpdatePatientNameMenu::eUpdatePatientSecondName:

					_ShowUpdatePatientSecondName(lineSperator, Patient);
					break;

				case enUpdatePatientNameMenu::eUpdatePatientThirdName:


					_ShowUpdatePatientThirdName(lineSperator, Patient);
					break;

				case enUpdatePatientNameMenu::eUpdatePatientFourthName:

					_ShowUpdatePatientFourthName(lineSperator, Patient);

					break;

				case enUpdatePatientNameMenu::eUpdatePatientFullName:

					_ShowUpdatePatientFullName(lineSperator, Patient);

					break;
				}

			}

		public:


			static void ShowUpdatePatientDataMenu(string lineSperator, clsPatient& Patient) {

				ShowUpdateScreenHeader();

				string LineSperator = "=============================================\n";
				cout << LineSperator;
				cout << "[1] Update Patient`s First Name\n";
				cout << "[2] Update Patient`s Second Name\n";
				cout << "[3] Update Patient`s Third Name\n";
				cout << "[4] Update Patient`s Fourth Name\n";
				cout << "[5] Update Patient`s Full Name\n";
				cout << LineSperator;

				_PerformPatientNameMenuOperation((enUpdatePatientNameMenu)_ReadPatientNameMenuOption(), lineSperator, Patient);
			}


		};
		enum enUpdatePatientDataMenu
		{
			eUpdatePatientName = 1,
			eUpdatePatientGender,
			eUpdatePatientBirthdate,
			eUpdatePatientPhone,
			

		};

		static short _ReadPatientDataMenuOption() {

			cout << "Enter The Number from [1-4]:";
			return  clsInputValidate::ReadNumberBetween<short>(1, 4);
		}



		static void _ShowUpdatePatientName(string lineSperator, clsPatient& Patient) {
			clsUpdatePatientNameMenu::ShowUpdatePatientDataMenu(lineSperator, Patient);
		}
		static void _ShowUpdatePatientGender(string lineSperator, clsPatient& Patient) {

			ShowUpdateScreenHeader();
			cout << lineSperator;
			Patient.Gender = clsPatientHelperFunctions::ReadGender();
			cout << lineSperator;

		}
		static void _ShowUpdatePatientBirthdate(string lineSperator, clsPatient& Patient) {
			ShowUpdateScreenHeader();
			cout << lineSperator;
			Patient.Birthdate = clsPatientHelperFunctions::ReadBirthdate();
			cout << lineSperator;
		}
	
		static void _ShowUpdatePatientPhone(string lineSperator, clsPatient& Patient) {
			ShowUpdateScreenHeader();
			cout << lineSperator;
			Patient.Phone = clsSharedHelperFunctions::ReadPhoneNumber("Patient`s");
			cout << lineSperator;
		}
	

		static void _PerformPatientDataMenuOperation(enUpdatePatientDataMenu option, clsPatient& Patient) {

			string lineSperator = "=============================================\n";
			switch (option)
			{
			case enUpdatePatientDataMenu::eUpdatePatientName:

				_ShowUpdatePatientName(lineSperator, Patient);

				break;

			case enUpdatePatientDataMenu::eUpdatePatientGender:

				_ShowUpdatePatientGender(lineSperator, Patient);
				break;

			case enUpdatePatientDataMenu::eUpdatePatientBirthdate:


				_ShowUpdatePatientBirthdate(lineSperator, Patient);
				break;

	

			case enUpdatePatientDataMenu::eUpdatePatientPhone:

				_ShowUpdatePatientPhone(lineSperator, Patient);

				break;
			}

		}

	public:


		static void ShowUpdatePatientDataMenu(clsPatient& Patient) {
			ShowUpdateScreenHeader();

			string LineSperator = "=============================================\n";

			cout << LineSperator;
			cout << "[1] Update Patient`s Name\n";
			cout << "[2] Update Patient`s Gender\n";
			cout << "[3] Update Patient`s Brithdate\n";
			cout << "[4] Update Patient`s Phone\n";
		

			cout << LineSperator;

			_PerformPatientDataMenuOperation((enUpdatePatientDataMenu)_ReadPatientDataMenuOption(), Patient);
		}


	};

public:
	static void ShowUpdatePatientData() {
		ShowUpdateScreenHeader();
		clsPatient Patient = clsPatientHelperFunctions::ReadPatientByID();
		clsPatientHelperFunctions::PrintPatientInfo(Patient);

		if (!clsInputValidate::CheckAnswer("Are you sure you want to update this Patients? [Y/N] ")) {

			cout << "Operation was cancelled.\n";
			return;
		}

		clsUpdatePatientDataMenu::ShowUpdatePatientDataMenu(Patient);

		clsSharedHelperFunctions::PrintTransactionStatus(Patient.Save(), "Patient", "update");
	}

};