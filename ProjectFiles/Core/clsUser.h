#pragma once
#include "..//Core/clsPerson.h"
#include "..//Database/FilesName.h"
#include "..//Libraries/clsString.h"
#include "..//Libraries/clsDate.h"
#include "clsTemplate.h"
#include <map>
#include <vector>
#include <fstream>

class clsUser : public clsPerson
{
public:

    enum enClinicRole
    {
        eSuperAdmin = 1,
        eAdmin,
        eReceptionist,
        eUnknownRole
    };

private:

    string _userID;
    string _userName;
    string _password;
    enClinicRole _role;

    clsTemplate<clsUser>::enMode _mode;
    clsTemplate<clsUser>::enIsSave _ObjectIsSaved;

private:

    static string _ConvertRoleToString(enClinicRole role)
    {
        return (role == enClinicRole::eSuperAdmin) ? "SuperAdmin" :
            (role == enClinicRole::eAdmin) ? "Admin" :
            (role == enClinicRole::eReceptionist) ? "Receptionist" :
            "Unknown";
    }

    static enClinicRole _ConvertStringToRole(string role)
    {
        return (role == "SuperAdmin") ? enClinicRole::eSuperAdmin :
            (role == "Admin") ? enClinicRole::eAdmin :
            (role == "Receptionist") ? enClinicRole::eReceptionist :
            enClinicRole::eUnknownRole;
    }

    static string _ConvertUserToDataLine(const clsUser& user, string separator = "#//#")
    {
        string line = "";

        line += user._userID + separator;
        line += user.FirstName + separator;
        line += user.SecondName + separator;
        line += user.ThirdName + separator;
        line += user.FourthName + separator;
        line += user._userName + separator;
        line += user._password + separator;
        line += user.Phone + separator;
        line += _ConvertRoleToString(user.Role);

        return line;
    }

    static clsUser _ConvertDataLineToUser(string line, string separator)
    {
        vector<string> vData;

        vData = clsString::SpilitString(line, separator);

        clsUser user(clsTemplate<clsUser>::enMode::eUpadateMode, vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], vData[6], vData[7], _ConvertStringToRole(vData[8]));

        return user;
    }

    static string GetID(const clsUser& user)
    {
        return user.UserID;
    }

    static map<string, clsUser> _LoadUsersFromFile()
    {
        return clsTemplate<clsUser>::LoadObjectsDataFromFiles(UsersFile, _ConvertDataLineToUser, GetID);
    }

    clsTemplate<clsUser>::enMode _GetMode(const clsUser& user)
    {
        return user._mode;
    }

    void _SaveUsersDataToFile(const map<string, clsUser>& usersMap)
    {
        clsTemplate<clsUser>::SaveObjectsDataToFile(UsersFile, usersMap, [this](const clsUser& tempUser) -> clsTemplate<clsUser>::enMode { return _GetMode(tempUser); }, [this](const clsUser& tempUser, string separator = "#//#") -> string { return _ConvertUserToDataLine(tempUser, separator); });
    }

    void _UpdateUser()
    {
        clsTemplate<clsUser>::UpdateObject(_LoadUsersFromFile, *this, GetID, [this](const map<string, clsUser>& usersMap) { _SaveUsersDataToFile(usersMap); }, _ObjectIsSaved);
    }

    string _GetUserNumber()
    {
        return clsTemplate<clsUser>::GetEndNumberFromFile(_LoadUsersFromFile, 6);
    }

    void _GenerateUserID()
    {
        this->_userID += _GetUserNumber();
    }

    void _AddUserToFile()
    {
        clsTemplate<clsUser>::AddObjectToFile(UsersFile, *this, [this](const clsUser& tempUser, string separator = "#//#") -> string { return _ConvertUserToDataLine(tempUser, separator); }, [this]() -> void { _GenerateUserID(); }, _ObjectIsSaved);
    }

    clsUser(clsTemplate<clsUser>::enMode mode, string userID, string firstName, string secondName, string thirdName, string fourthName, string userName, string password, string phone, enClinicRole role)
        : clsPerson(firstName, secondName, thirdName, fourthName, phone)
    {
        this->_mode = mode;
        this->_userID = userID;
        this->_userName = userName;
        this->_password = password;
        this->_role = role;

        this->_ObjectIsSaved = clsTemplate<clsUser>::enIsSave::DataisUnSaved;
    }

public:

    clsUser() : clsUser(clsTemplate<clsUser>::enMode::eEmptyMode, "User00", "", "", "", "", "", "", "", enClinicRole::eUnknownRole)
    {
    }

    clsUser(clsTemplate<clsUser>::enMode mode, string firstName, string secondName, string thirdName, string fourthName, string userName, string password, string phone, enClinicRole role)
        : clsUser(mode, "User00", firstName, secondName, thirdName, fourthName, userName, password, phone, role)
    {
    }

public:

    string GetUserID() const
    {
        return _userID;
    }

    __declspec(property(get = GetUserID)) string UserID;

    void SetUserName(string userName)
    {
        _userName = userName;
    }

    string GetUserName() const
    {
        return _userName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string password)
    {
        _password = password;
    }

    string GetPassword() const
    {
        return _password;
    }

    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetRole(enClinicRole role)
    {
        _role = role;
    }

    enClinicRole GetRole() const
    {
        return _role;
    }

    __declspec(property(get = GetRole, put = SetRole)) enClinicRole Role;

    string RoleToString()
    {
        return _ConvertRoleToString(_role);
    }

    __declspec(property(get = RoleToString)) string strRole;

    bool IsEmpty()
    {
        return (_mode == clsTemplate<clsUser>::enMode::eEmptyMode);
    }

    static map<string, clsUser> GetAllUsers()
    {
        return _LoadUsersFromFile();
    }

    static clsUser GetNewUserObject()
    {
        return clsUser(clsTemplate<clsUser>::enMode::eAddNewMode, "", "", "", "", "", "", "", enClinicRole::eUnknownRole);
    }

    static clsUser GetEmptyObject()
    {
        return clsUser();
    }

    static clsUser FindUser(string userID)
    {
        return clsTemplate<clsUser>::FindObject(userID, _LoadUsersFromFile, GetEmptyObject);
    }

    bool Delete()
    {
        return clsTemplate<clsUser>::DeleteObject(*this, this->_mode, this->_ObjectIsSaved, [this]() { _UpdateUser(); }, GetEmptyObject);
    }

    bool Save()
    {
        return clsTemplate<clsUser>::Save(_mode, [this]() { _UpdateUser(); }, [this]() { _AddUserToFile(); }, _ObjectIsSaved);
    }
};
