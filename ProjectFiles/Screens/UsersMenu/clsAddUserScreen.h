#pragma once
#include "..//clsHeaderScreen.h"
#include "clsUserHelperFunctions.h"

class clsAddUserScreen : public clsHeaderScreen
{
private:

public:

    static void ShowAddUser()
    {
        string title = clsUtil::Tabs(1) + "      Add User Screen";
        ShowMainHeader(title);

        map<string, clsUser> mUsers = clsUser::GetAllUsers();

        clsUser newUser = clsUser::GetNewUserObject();

        clsUserHelperFunctions::ReadUserData(newUser);
        clsUserHelperFunctions::PrintUserInfo(newUser);

        if (!clsInputValidate::CheckAnswer("Are you sure you want to perform this operation? [Y/N] "))
        {
            cout << "Operation was cancelled.\n";

            return;
        }

        clsSharedHelperFunctions::PrintTransactionStatus(newUser.Save(), "User", "Added");
    }
};
