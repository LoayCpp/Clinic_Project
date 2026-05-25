#pragma once
#include "..//clsHeaderScreen.h"
#include "clsUserHelperFunctions.h"
#include "..//..//Globlas//Globals.h"
using namespace std;

class clsUpdateUsersDataScreen : public clsHeaderScreen
{
private:

    static void ShowUpdateScreenHeader()
    {
        string title = clsUtil::Tabs(1) + " Update User's Data Screen";
        ShowMainHeader(title);
    }

    class clsUpdateUserDataMenu
    {
    private:

        class clsUpdateUserNameMenu
        {
        private:

            enum enUpdateUserNameMenu
            {
                eUpdateUserFirstName = 1,
                eUpdateUserSecondName,
                eUpdateUserThirdName,
                eUpdateUserFourthName,
                eUpdateUserFullName,
            };

            static short _ReadUserNameMenuOption()
            {
                cout << "Enter The Number from [1-5]:";
                return clsInputValidate::ReadNumberBetween<short>(1, 5);
            }

            static void _ShowUpdateUserFirstName(string lineSperator, clsUser& user)
            {
                ShowUpdateScreenHeader();
                cout << lineSperator;
                user.FirstName = clsSharedHelperFunctions::ReadFirstName("User`s");
                cout << lineSperator;
            }

            static void _ShowUpdateUserSecondName(string lineSperator, clsUser& user)
            {
                ShowUpdateScreenHeader();
                cout << lineSperator;
                user.SecondName = clsSharedHelperFunctions::ReadSecondName("User`s");
                cout << lineSperator;
            }

            static void _ShowUpdateUserThirdName(string lineSperator, clsUser& user)
            {
                ShowUpdateScreenHeader();
                cout << lineSperator;
                user.ThirdName = clsSharedHelperFunctions::ReadThirdName("User`s");
                cout << lineSperator;
            }

            static void _ShowUpdateUserFourthName(string lineSperator, clsUser& user)
            {
                ShowUpdateScreenHeader();
                cout << lineSperator;
                user.FourthName = clsSharedHelperFunctions::ReadFourthName("User`s");
                cout << lineSperator;
            }

            static void _ShowUpdateUserFullName(string lineSperator, clsUser& user)
            {
                ShowUpdateScreenHeader();
                cout << lineSperator;
                clsUserHelperFunctions::ReadFullName(user);
                cout << lineSperator;
            }

            static void _PerformUserNameMenuOperation(enUpdateUserNameMenu option, string lineSperator, clsUser& user)
            {
                switch (option)
                {
                case enUpdateUserNameMenu::eUpdateUserFirstName:
                    _ShowUpdateUserFirstName(lineSperator, user);
                    break;

                case enUpdateUserNameMenu::eUpdateUserSecondName:
                    _ShowUpdateUserSecondName(lineSperator, user);
                    break;

                case enUpdateUserNameMenu::eUpdateUserThirdName:
                    _ShowUpdateUserThirdName(lineSperator, user);
                    break;

                case enUpdateUserNameMenu::eUpdateUserFourthName:
                    _ShowUpdateUserFourthName(lineSperator, user);
                    break;

                case enUpdateUserNameMenu::eUpdateUserFullName:
                    _ShowUpdateUserFullName(lineSperator, user);
                    break;
                }
            }

        public:

            static void ShowUpdateUserDataMenu(string lineSperator, clsUser& user)
            {
                ShowUpdateScreenHeader();

                string LineSperator = "=============================================\n";
                cout << LineSperator;
                cout << "[1] Update User`s First Name\n";
                cout << "[2] Update User`s Second Name\n";
                cout << "[3] Update User`s Third Name\n";
                cout << "[4] Update User`s Fourth Name\n";
                cout << "[5] Update User`s Full Name\n";
                cout << LineSperator;

                _PerformUserNameMenuOperation((enUpdateUserNameMenu)_ReadUserNameMenuOption(), lineSperator, user);
            }
        };

        enum enUpdateUserDataMenu
        {
            eUpdateUserName = 1,
            eUpdateUserNameLogin,
            eUpdateUserPassword,
            eUpdateUserPhone,
            eUpdateUserRole,
        };

        static short _ReadUserDataMenuOption()
        {
            cout << "Enter The Number from [1-5]:";
            return clsInputValidate::ReadNumberBetween<short>(1, 5);
        }

        static void _ShowUpdateUserName(string lineSperator, clsUser& user)
        {
            clsUpdateUserNameMenu::ShowUpdateUserDataMenu(lineSperator, user);
        }

        static void _ShowUpdateUserNameLogin(string lineSperator, clsUser& user)
        {
            ShowUpdateScreenHeader();
            cout << lineSperator;
            user.UserName = clsUserHelperFunctions::ReadUserName();
            cout << lineSperator;
        }

        static void _ShowUpdateUserPassword(string lineSperator, clsUser& user)
        {
            ShowUpdateScreenHeader();
            cout << lineSperator;
            user.Password = clsUserHelperFunctions::ReadPassword();
            cout << lineSperator;
        }

        static void _ShowUpdateUserPhone(string lineSperator, clsUser& user)
        {
            ShowUpdateScreenHeader();
            cout << lineSperator;
            user.Phone = clsSharedHelperFunctions::ReadPhoneNumber("User`s");
            cout << lineSperator;
        }

        static void _ShowUpdateUserRole(string lineSperator, clsUser& user)
        {
            ShowUpdateScreenHeader();
            cout << lineSperator;
            user.Permissions = clsUserHelperFunctions::ReadPermissions();
            cout << lineSperator;
        }

        static void _PerformUserDataMenuOperation(enUpdateUserDataMenu option, clsUser& user)
        {
            string lineSperator = "=============================================\n";

            switch (option)
            {
            case enUpdateUserDataMenu::eUpdateUserName:
                _ShowUpdateUserName(lineSperator, user);
                break;

            case enUpdateUserDataMenu::eUpdateUserNameLogin:
                _ShowUpdateUserNameLogin(lineSperator, user);
                break;

            case enUpdateUserDataMenu::eUpdateUserPassword:
                _ShowUpdateUserPassword(lineSperator, user);
                break;

            case enUpdateUserDataMenu::eUpdateUserPhone:
                _ShowUpdateUserPhone(lineSperator, user);
                break;

            case enUpdateUserDataMenu::eUpdateUserRole:
                if (CurrentUser.Permissions.IsUserHasPermissions(
                    CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eUpdateUsersPermissions))
                    _ShowUpdateUserRole(lineSperator, user);
                break;
            }
        }

    public:

        static void ShowUpdateUserDataMenu(clsUser& user)
        {
            ShowUpdateScreenHeader();

            string LineSperator = "=============================================\n";

            cout << LineSperator;
            cout << "[1] Update User`s Name\n";
            cout << "[2] Update User Name\n";
            cout << "[3] Update User`s Password\n";
            cout << "[4] Update User`s Phone\n";
            if (CurrentUser.Permissions.IsUserHasPermissions(
                CurrentUser.Permissions.Role, clsPermissions::enUserPermissionsOption::eUpdateUsersPermissions))
                cout << "[5] Update User`s Role\n";
            cout << LineSperator;

            _PerformUserDataMenuOperation((enUpdateUserDataMenu)_ReadUserDataMenuOption(), user);
        }
    };

public:

    static void ShowUpdateUserData()
    {
        ShowUpdateScreenHeader();

        clsUser user = clsUserHelperFunctions::ReadUserByID();

        clsUserHelperFunctions::PrintUserInfo(user);

        if (!clsInputValidate::CheckAnswer("Are you sure you want to perform this operation? [Y/N] "))
        {
            cout << "Operation was cancelled.\n";
            return;
        }

        clsUpdateUserDataMenu::ShowUpdateUserDataMenu(user);

        clsSharedHelperFunctions::PrintTransactionStatus(user.Save(), "User", "Updated");
    }
};
