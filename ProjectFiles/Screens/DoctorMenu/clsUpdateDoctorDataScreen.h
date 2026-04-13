#pragma once
#include "..//clsHeaderScreen.h"
#include "clsDoctorHelperFunctions .h"
using namespace std;
class clsUpdateDoctorDataScreen :public clsHeaderScreen
{
	
private:
	static void ShowUpdateScreenHeader() {
		string title = clsUtil::Tabs(1) + " Update Doctor's Data Screen";
		ShowMainHeader(title);
	}
	class clsUpdateDoctorDataMenu {


	private:
		class clsUpdateDoctorNameMenu {
		private:
			enum enUpdateDoctorNameMenu
			{
				eUpdateDoctorFirstName = 1,
				eUpdateDoctorSecondName,
				eUpdateDoctorThirdName,
				eUpdateDoctorFourthName,
				eUpdateDoctorFullName,
				
			};
			static short _ReadDoctorNameMenuOption() {

				cout << "Enter The Number from [1-5]:";
				return  clsInputValidate::ReadNumberBetween<short>(1, 5);
			}



			static void _ShowUpdateDoctorFirstName(string lineSperator, clsDoctor& doctor) {
				ShowUpdateScreenHeader();
				cout << lineSperator;
				doctor.FirstName = clsSharedHelperFunctions::ReadFirstName("Doctor`s");
				cout << lineSperator;
			}
			static void _ShowUpdateDoctorSecondName(string lineSperator, clsDoctor& doctor) {

				ShowUpdateScreenHeader();
				cout << lineSperator;
				doctor.SecondName = clsSharedHelperFunctions::ReadSecondName("Doctor`s");
				cout << lineSperator;

			}
			static void _ShowUpdateDoctorThirdName(string lineSperator, clsDoctor& doctor) {
				ShowUpdateScreenHeader();
				cout << lineSperator;
				doctor.ThirdName = clsSharedHelperFunctions::ReadThirdName("Doctor`s");
				cout << lineSperator;
			}
			static void _ShowUpdateDoctorFourthName(string lineSperator, clsDoctor& doctor) {
				ShowUpdateScreenHeader();
				cout << lineSperator;
				doctor.FourthName = clsSharedHelperFunctions::ReadFourthName("Doctor`s");
				cout << lineSperator;
			}
			static void _ShowUpdateDoctorFullName(string lineSperator, clsDoctor& doctor) {
				ShowUpdateScreenHeader();
				cout << lineSperator;
				clsDoctorHelperFunctions::ReadFullName(doctor);
				cout << lineSperator;
			}

			static void _PerformDoctorNameMenuOperation(enUpdateDoctorNameMenu option, string lineSperator, clsDoctor& doctor) {

			
				switch (option)
				{
				case enUpdateDoctorNameMenu::eUpdateDoctorFirstName:

					_ShowUpdateDoctorFirstName(lineSperator, doctor);

					break;

				case enUpdateDoctorNameMenu::eUpdateDoctorSecondName:

					_ShowUpdateDoctorSecondName(lineSperator, doctor);
					break;

				case enUpdateDoctorNameMenu::eUpdateDoctorThirdName:


					_ShowUpdateDoctorThirdName(lineSperator, doctor);
					break;

				case enUpdateDoctorNameMenu::eUpdateDoctorFourthName:

					_ShowUpdateDoctorFourthName(lineSperator, doctor);

					break;

				case enUpdateDoctorNameMenu::eUpdateDoctorFullName:

					_ShowUpdateDoctorFullName(lineSperator, doctor);

					break;
				}

			}

		public:


			static void ShowUpdateDoctorDataMenu(string lineSperator, clsDoctor& doctor) {
				
				ShowUpdateScreenHeader();
				
				string LineSperator = "=============================================\n";
				cout << LineSperator;
				cout << "[1] Update Doctor`s First Name\n";
				cout << "[2] Update Doctor`s Second Name\n";
				cout << "[3] Update Doctor`s Third Name\n";
				cout << "[4] Update Doctor`s Fourth Name\n";
				cout << "[5] Update Doctor`s Full Name\n";
				cout << LineSperator;

				_PerformDoctorNameMenuOperation((enUpdateDoctorNameMenu)_ReadDoctorNameMenuOption(), lineSperator, doctor);
			}


		};
		enum enUpdateDoctorDataMenu
		{
			eUpdateDoctorName = 1,
			eUpdateDoctorGender,
			eUpdateDoctorBirthdate,
			eUpdateDoctorSpecialization,
			eUpdateDoctorPhone,
			eUpdateDoctorFeesRate,

		};

		static short _ReadDoctorDataMenuOption() {

			cout << "Enter The Number from [1-6]:";
			return  clsInputValidate::ReadNumberBetween<short>(1, 6);
		}



		static void _ShowUpdateDoctorName(string lineSperator, clsDoctor& doctor) {
			clsUpdateDoctorNameMenu::ShowUpdateDoctorDataMenu(lineSperator, doctor);
		}
		static void _ShowUpdateDoctorGender(string lineSperator, clsDoctor& doctor) {
			 
			ShowUpdateScreenHeader();
			 cout << lineSperator;
			 doctor.Gender = clsDoctorHelperFunctions::ReadGender();
			 cout << lineSperator;

		}
		static void _ShowUpdateDoctorBirthdate(string lineSperator,clsDoctor& doctor) {
			ShowUpdateScreenHeader();
			cout << lineSperator;
			doctor.BirthDate = clsDoctorHelperFunctions::ReadBirthdate();
			cout << lineSperator;
		}
		static void _ShowUpdateDoctorSpecialization(string lineSperator, clsDoctor& doctor) {
			ShowUpdateScreenHeader();
			cout << lineSperator;
			doctor.Specialization = clsDoctorHelperFunctions::ReadSpecialization();
			cout << lineSperator;
		}
		static void _ShowUpdateDoctorPhone(string lineSperator,clsDoctor& doctor) {
			ShowUpdateScreenHeader();
			cout << lineSperator;
			doctor.Phone = clsSharedHelperFunctions::ReadPhoneNumber("Doctor`s");
			cout << lineSperator;
		}
		static void _ShowUpdateDoctorFeesRate(string lineSperator, clsDoctor& doctor) {
			ShowUpdateScreenHeader();
			cout << lineSperator;
			doctor.FeesRate = clsDoctorHelperFunctions::ReadFeesRate();
			cout << lineSperator;
		}

		static void _PerformDoctorDataMenuOperation(enUpdateDoctorDataMenu option, clsDoctor& doctor) {

			string lineSperator = "=============================================\n";
			switch (option)
			{
			case enUpdateDoctorDataMenu::eUpdateDoctorName:

				_ShowUpdateDoctorName(lineSperator,doctor);

				break;

			case enUpdateDoctorDataMenu::eUpdateDoctorGender:

				_ShowUpdateDoctorGender(lineSperator, doctor);
				break;

			case enUpdateDoctorDataMenu::eUpdateDoctorBirthdate:


				_ShowUpdateDoctorBirthdate(lineSperator, doctor);
				break;

			case enUpdateDoctorDataMenu::eUpdateDoctorSpecialization:

				_ShowUpdateDoctorSpecialization(lineSperator, doctor);

				break;

			case enUpdateDoctorDataMenu::eUpdateDoctorPhone:

				_ShowUpdateDoctorPhone(lineSperator, doctor);

				break;

			case enUpdateDoctorDataMenu::eUpdateDoctorFeesRate:
				_ShowUpdateDoctorFeesRate(lineSperator, doctor);
				break;
			}

		}

	public:


		static void ShowUpdateDoctorDataMenu(clsDoctor& doctor) {
			ShowUpdateScreenHeader();

			string LineSperator = "=============================================\n";
			
			cout << LineSperator;
			cout << "[1] Update Doctor`s Name\n";
			cout << "[2] Update Doctor`s Gender\n";
			cout << "[3] Update Doctor`s Brithdate\n";
			cout << "[4] Update Doctor`s Specialization\n";
			cout << "[5] Update Doctor`s Phone\n";
			cout << "[6] Update Doctor`s Fees Rate\n";
			
			cout << LineSperator;

			_PerformDoctorDataMenuOperation((enUpdateDoctorDataMenu)_ReadDoctorDataMenuOption(),doctor);
		}


	};

public:
	static void ShowUpdateDoctorData() {
		ShowUpdateScreenHeader();
		clsDoctor doctor = clsDoctorHelperFunctions::ReadDoctorByID();
		clsDoctorHelperFunctions::PrintDoctorInfo(doctor);

		if (!clsInputValidate::CheckAnswer("Are you sure you want to update this doctors? [Y/N] ")) {

			cout << "Operation was cancelled.\n";
			return;
		}

		clsUpdateDoctorDataMenu::ShowUpdateDoctorDataMenu(doctor);

		clsSharedHelperFunctions::PrintTransactionStatus(doctor.Save(), "Doctor", "update");
	}

};