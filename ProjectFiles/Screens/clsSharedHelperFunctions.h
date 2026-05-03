#pragma once
#include<iostream>
#include"..//..//ProjectFiles/Libraries/clsInputValidate.h"
using namespace std;
class clsSharedHelperFunctions {

private:
	static string _ReadData(string className, string typeName="") {

		string Name = "";
		cout << "Enter " << className << "`s " << typeName << " : ";
		Name = clsInputValidate::ReadOneWord();
		return Name;
	}

public:
	static string ReadFirstName(string className) {

		return _ReadData(className, "First Name");


	}

	static string ReadSecondName(string className) {

		return _ReadData(className, "Second Name");


	}


	static string ReadThirdName(string className) {

		return _ReadData(className, "Third Name");


	}
	static string ReadFourthName(string className) {

		return _ReadData(className, "Fourth Name");


	}

	static string ReadPhoneNumber(string className) {

		return _ReadData(className, "Phone Number");


	}

	static void PrintTransactionStatus(bool transactionStatus, 
				string className, 
				string transactionName) {

		transactionStatus ? cout << "The " + className + " was " + transactionName + " successfully.\n"
			: cout << "The " + className + " was not " + transactionName + " successfully.\n";


	}

};
