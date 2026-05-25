#pragma once
#include "..//clsHeaderScreen.h"
#include "clsUserHelperFunctions.h"
#include "..//..//Globlas//Globals.h"
class clsDeleteUserScreen : public clsHeaderScreen {
private:

public:
	static void ShowDeleteDoctor() {
		string title = clsUtil::Tabs(1) + "    Delete User Screen";
		ShowMainHeader(title);

		clsUser user = clsUserHelperFunctions::ReadUserByID();
		clsUserHelperFunctions::PrintUserInfo(user);

		if (!clsInputValidate::CheckAnswer("Are you sure you want to perform this operation? [Y/N] ")) {
			cout << "Operation was cancelled.\n";
			return;
		}


		clsSharedHelperFunctions::PrintTransactionStatus(user.Delete(), "User", "Deleted");
	}
};
