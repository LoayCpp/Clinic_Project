#pragma once
#include <iostream>
#include "..//..//..//ProjectFiles//Libraries//clsInputValidate.h"
#include "..//..//..//ProjectFiles//Core//clsUser.h"
#include "..//clsSharedHelperFunctions.h"
#include "..//..//Core//clsUser.h"
#include "..//..//Globlas//Globals.h"
using namespace std;

class clsUserHelperFunctions
{
public:

    static clsPermissions ReadPermissions()
    {
        short num = 0;

        cout << "\nUser's Role Choices :\n";
        cout << "[1] Super Admin \n";
        cout << "[2] Admin \n";
        cout << "[3] Receptionist \n";
        cout << "Enter User`s choice (1-3) :> ";

        num = clsInputValidate::ReadNumberBetween<short>(1, 3, "Invalid input, please enter a number between[1 - 3] :> ");

        return clsPermissions((clsPermissions::enClinicRole)num);
    }

    static void ReadFullName(clsUser& user)
    {
        string className = "User";

        user.FirstName = clsSharedHelperFunctions::ReadFirstName(className);
        user.SecondName = clsSharedHelperFunctions::ReadSecondName(className);
        user.ThirdName = clsSharedHelperFunctions::ReadThirdName(className);
        user.FourthName = clsSharedHelperFunctions::ReadFourthName(className);
    }

    static string ReadUserName()
    {
        return clsInputValidate::ReadOneWord("Enter User Name :> ");
    }

    static string ReadPassword()
    {
        return clsInputValidate::ReadOneWord("Enter Password :> ");
    }

    static void ReadUserData(clsUser& user)
    {
        ReadFullName(user);
        user.UserName = ReadUserName();
        user.Password = ReadPassword();
        user.Phone = clsSharedHelperFunctions::ReadPhoneNumber("User");
        user.Permissions = ReadPermissions();
    }

    static clsUser ReadUserByID()
    {
        string userID = clsInputValidate::ReadOneWord("Enter User's ID :> ");

        clsUser user = clsUser::FindUser(userID);

        while (user.IsEmpty())
        {
            userID = clsInputValidate::ReadOneWord("Invalid input, Enter User's ID :> ");
            user = clsUser::FindUser(userID);
        }

        return user;
    }

    static void PrintUserInfo(clsUser& user)
    {
        cout << "\n============== Print User's Info =================\n";
        cout << "==================================================\n";
        cout << "User's Name     : " << user.FullName << endl;
        cout << "User Name       : " << user.UserName << endl;
        cout << "Password        : " << user.Password << endl;
        cout << "User's Phone    : " << user.Phone << endl;
        cout << "User's Role     : " << user.Permissions.StrRole << endl;
        cout << "==================================================\n";
    }
};
