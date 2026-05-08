#pragma once
#include "..//clsHeaderScreen.h"
#include "clsUserHelperFunctions.h"

class clsFindUserScreen : public clsHeaderScreen
{
public:

    static void ShowFindUser()
    {
        string title = clsUtil::Tabs(1) + "      Find User Screen";
        ShowMainHeader(title);

        clsUser user = clsUserHelperFunctions::ReadUserByID();

        clsUserHelperFunctions::PrintUserInfo(user);
    }
};
