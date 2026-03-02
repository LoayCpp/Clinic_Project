#pragma once
#include"clsDate.h"
class clsInputValidate {

public:

	static int ReadIntNumber(string Message, string alternativeMessage) {

		int num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static int ReadIntNumber(string alternativeMessage = "InValid input, Enter again :") {

		int num = 0;


		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}

	static float ReadFloatNumber(string Message, string alternativeMessage) {

		float num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static float ReadFloatNumber(string alternativeMessage = "InValid input, Enter again :") {

		float num = 0;

		
		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}

	static double ReadDoubleNumber(string Message, string alternativeMessage) {

		double num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static double ReadDoubleNumber(string alternativeMessage = "InValid input, Enter again :") {

		double num = 0;


		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}

	static short ReadShortNumber(string Message, string alternativeMessage) {

		short num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static short ReadShortNumber(string alternativeMessage = "InValid input, Enter again :") {

		short num = 0;


		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}

	static bool ReadBoolen(string Message, string alternativeMessage) {

		bool num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static bool ReadBoolen(string alternativeMessage = "InValid input, Enter again :") {

		bool num = 0;


		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}

	static char ReadCharacter(string Message, string alternativeMessage) {

		char Char = ' ';

		cout << Message;
		cin >> Char;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> Char;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return Char;
	}
	static char ReadCharacter(string alternativeMessage = "InValid input, Enter again :") {

		char Char = ' ';


		cin >> Char;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> Char;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return Char;
	}

	static string ReadString(string Message) {

		string sString = "";

		cout << Message;
		getline(cin >> ws, sString);

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return sString;
	}
	static string ReadString() {

		string sString = "";
		getline(cin >> ws, sString);

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return sString;
	}


	static int ReadIntNumberBetween(string Message, string alternativeMessage, int From, int To) {

		int num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || !(num >= From && num <= To)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static float ReadFloatNumberBetween(string Message, string alternativeMessage, float From, float To) {

		float num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || !(num >= From && num <= To)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static double ReadDoubleNumberBetween(string Message, string alternativeMessage, double From, double To) {

		double num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || !(num >= From && num <= To)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static short ReadShortNumberBetween(string Message, string alternativeMessage, short From, short To) {

		short num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || !(num >= From && num <= To)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static char ReadCharacterBetween(string Message, string alternativeMessage, char From, char To) {

		char Char = 0;

		cout << Message;
		cin >> Char;

		while (cin.fail() || !(Char >= From && Char <= To)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> Char;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return Char;
	}
	static int ReadIntPositiveNumber(string Message, string alternativeMessage) {


		int num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || (num <= 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static float ReadFloatPositiveNumber(string Message, string alternativeMessage) {


		float num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || (num <= 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static double ReadDoublePositiveNumber(string Message, string alternativeMessage) {


		double num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || (num <= 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static short ReadShortPositiveNumber(string Message, string alternativeMessage) {


		short num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || (num <= 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static int ReadIntNegtiveNumber(string Message, string alternativeMessage) {


		int num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || (num > 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static float ReadFloatNegtiveNumber(string Message, string alternativeMessage) {


		float num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || (num > 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static double ReadDoubleNegtiveNumber(string Message, string alternativeMessage) {


		double num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || (num > 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static short ReadShortNegtiveNumber(string Message, string alternativeMessage) {


		short num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || (num > 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static bool IsNumberBetween(int Num, int From, int To) {
		return (Num >= From && Num <= To);
	}
	static bool IsNumberBetween(float Num, float From, float To) {
		return (Num >= From && Num <= To);
	}
	static bool IsNumberBetween(short Num, short From, short To) {
		return (Num >= From && Num <= To);
	}
	static bool IsNumberBetween(double Num, double From, double To) {
		return (Num >= From && Num <= To);
	}
	static bool IsCharacterBetween(char Char, char From, char To) {
		return (Char >= From && Char <= To);
	}
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
		if (Date >= From && Date <= To) {
			return true;
		}
		if (Date >= To && Date <= From) {
			return true;
		}
		return false;
	}
	static bool IsValidDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}
	static bool CheckAnswer(string Message) {
		char YourAnswer = ReadCharacter(Message, "Invalid Input, Please Enter Character : ");
		return (toupper(YourAnswer) == 'Y');
	}


};

