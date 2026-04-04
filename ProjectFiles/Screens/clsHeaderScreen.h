#pragma once
#include<iostream>
#include<string>
#include "..//Libraries/clsUtil.h"
class clsHeaderScreen
{
protected:
	static void ShowMainHeader(string title, string subTitle = "", short TabNumber = 0) {
		system("cls");
		string LineSperator = clsUtil::UnderScore(9) + "";
		string Tab = "";

		if (TabNumber != 0) {
			Tab = clsUtil::Tabs(TabNumber);
		}

		cout << Tab << LineSperator << "\n\n";

		cout << title << "\n";

		if (subTitle != "") {
			cout << subTitle << "\n";
		}

		cout << Tab << LineSperator << "\n";
	}
	
};

