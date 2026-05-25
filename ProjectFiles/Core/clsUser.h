#pragma once
#include "clsPerson.h"
#include "clsPermissions.h"
#include "clsTemplate.h"
#include "..//Database/FilesName.h"
#include "..//Libraries/clsString.h"
#include "..//Libraries/clsDate.h"
#include <map>
#include <vector>
#include <fstream>

class clsUser : public clsPerson
{
public:


private:

    string _userID;
    string _userName;
    string _password;
    clsPermissions _permissions;

    clsTemplate<clsUser>::enMode _mode;
    clsTemplate<clsUser>::enIsSave _ObjectIsSaved;

private:



    static string _ConvertUserToDataLine( clsUser& user, string separator = "#//#")
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
        line += user._permissions.StrRole;
  

        return line;
    }

    static clsUser _ConvertDataLineToUser(string line, string separator)
    {
        vector<string> vData;

        vData = clsString::SpilitString(line, separator);

        clsUser user(clsTemplate<clsUser>::enMode::eUpadateMode, vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], vData[6], vData[7], clsPermissions(vData[8]));

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

    clsTemplate<clsUser>::enMode _GetMode(clsUser& user)
    {
        return user._mode;
    }

    void _SaveUsersDataToFile(map<string, clsUser>& usersMap)
    {
        clsTemplate<clsUser>::SaveObjectsDataToFile(UsersFile, usersMap, 
            [this](clsUser& tempUser) -> clsTemplate<clsUser>::enMode { return _GetMode(tempUser); }, 
            [this](clsUser& tempUser, string separator = "#//#") -> string { return _ConvertUserToDataLine(tempUser, separator); });
    }

    void _UpdateUser()
    {
        clsTemplate<clsUser>::UpdateObject(_LoadUsersFromFile, *this, GetID, 
            [this](map<string, clsUser>& usersMap)->void { _SaveUsersDataToFile(usersMap); }, _ObjectIsSaved);
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
        clsTemplate<clsUser>::AddObjectToFile(UsersFile, *this, [this](clsUser& tempUser, string separator = "#//#") -> string { return _ConvertUserToDataLine(tempUser, separator); }, [this]() -> void { _GenerateUserID(); }, _ObjectIsSaved);
    }

    clsUser(clsTemplate<clsUser>::enMode mode, string userID, string firstName, string secondName, string thirdName, string fourthName, string userName, string password, string phone, clsPermissions permissions)
        : clsPerson(firstName, secondName, thirdName, fourthName, phone)
    {
        this->_mode = mode;
        this->_userID = userID;
        this->_userName = userName;
        this->_password = password;
        this->_permissions = permissions;

        this->_ObjectIsSaved = clsTemplate<clsUser>::enIsSave::DataisUnSaved;
    }

public:

    clsUser() : clsUser(clsTemplate<clsUser>::enMode::eEmptyMode, "User00", "", "", "", "", "", "", "", clsPermissions())
    {
    }

    clsUser(clsTemplate<clsUser>::enMode mode, string firstName, string secondName, string thirdName, string fourthName, string userName, string password, string phone, clsPermissions permissions)
        : clsUser(mode, "User00", firstName, secondName, thirdName, fourthName, userName, password, phone, permissions)
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

    void SetPermissions(clsPermissions permissions)
    {
        _permissions = permissions;
    }

    clsPermissions GetPermissions() const
    {
        return _permissions;
    }

    __declspec(property(get = GetPermissions, put = SetPermissions)) clsPermissions Permissions;

   

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
        return clsUser(clsTemplate<clsUser>::enMode::eAddNewMode, "", "", "", "", "", "", "", clsPermissions());
    }

    static clsUser GetEmptyObject()
    {
        return clsUser();
    }

    static clsUser FindUser(string userID)
    {
        return clsTemplate<clsUser>::FindObject(userID, _LoadUsersFromFile, GetEmptyObject);
    }
    static clsUser FindUser(string username,string password)
    {

        map < string, clsUser> mUsers = _LoadUsersFromFile();

        for (auto user : mUsers) {
            if (user.second.UserName == username && user.second.Password == password)
                return user.second;
        }
        return GetEmptyObject();
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
