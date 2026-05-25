#pragma once
#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include "..//..//..//ProjectFiles/Core/clsUser.h"
#include "..//..//..//ProjectFiles/Libraries/clsUtil.h"
#include "..//..//..//ProjectFiles/Screens/clsHeaderScreen.h"

using namespace std;

class clsShowUsersTableScreen : public clsHeaderScreen
{
private:

    static void DrawTableRow(clsUser& user)
    {
        cout << left
            << "|" << setw(10) << user.UserID << "|"
            << setw(30) << user.FullName << "|"
            << setw(20) << user.UserName << "|"
            << setw(20) << user.Password << "|"
            << setw(15) << user.Phone << "|"
            << setw(15) << user.strRole << "|" << endl;
    }

    static void DrawTableBody(const map<string, clsUser>& mUsers)
    {
        if (mUsers.empty())
        {
            cout << "\nThere are no registered users in the system\n";
            return;
        }

        for (auto user : mUsers)
        {
            DrawTableRow(user.second);
        }
    }

    static void DrawTableHeader(string lineSeparator)
    {
        cout << lineSeparator << "\n\n";

        cout << left
            << setw(10) << "|UserID" << " |"
            << setw(30) << "Full Name" << "|"
            << setw(20) << "User Name" << "|"
            << setw(20) << "Password" << "|"
            << setw(15) << "Phone" << "|"
            << setw(15) << "Role" << "|" << endl;

        cout << lineSeparator << "\n\n";
    }

    static void DrawTable(const map<string, clsUser>& mUsers)
    {
        string lineSeparator = clsUtil::UnderScore(23) + "___";

        DrawTableHeader(lineSeparator);
        DrawTableBody(mUsers);
        cout << lineSeparator << endl;
    }

public:

    static void ShowUsersTable()
    {
        map<string, clsUser> mUsers = clsUser::GetAllUsers();

        string title = clsUtil::Tabs(4) + "         Show Users Table Screen";
        string subTitle = clsUtil::Tabs(4) + "List of All Users in the System (" + to_string(mUsers.size()) + " Users)";

        ShowMainHeader(title, subTitle, 4);
        DrawTable(mUsers);
    }
};
