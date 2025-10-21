#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"Myc++Libarires/clsString.h"
#include"clsMainMenuScreen.h"
#include"global.h"
#include"Myc++Libarires/clsDate.h"
#include"Myc++Libarires/clsString.h"
using namespace std;
class clsLogin:protected clsScreen
{

private:



	static bool _login() {

		bool failedLogin = false;

		short failedAttempts = 0;
		string userName;
		string password;
		do {

			if (failedLogin) {
				++failedAttempts;
				cout << "\n\t\t\t\tInvalid username or password \n";
				cout << "\t\t\t\tyou have now only : " << 3 - failedAttempts << "trial(s)\n";
			}
			
			if (failedAttempts == 3) {
				cout << "\n\t\t\t\t system locked after 3 failed trials . ";
				return false;
			}
			
			cout << "\t\t\t\tenter UserName : ";
			userName = clsString::readString();
			cout << "\n\t\t\t\t\enter password : ";
			password = clsString::readString();

			currentUser = clsUser::find(userName, password);

			failedLogin = currentUser.isEmpty();
			

		} while (failedLogin);

		currentUser.AddToRegisterLoginFile();
		clsMainMenuScreen::showMainMenuScreen();
		return true;
	}



public:

	static bool showLoginScreen() {

		drawScreenHeader("Login Screen");
		return _login();
		
	}

};

