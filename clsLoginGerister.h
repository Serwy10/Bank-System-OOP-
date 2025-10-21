#pragma once
#include<iostream>
#include"Myc++Libarires/clsString.h"
#include"clsUser.h"
#include<vector>
#include<iomanip>
#include"clsScreen.h"
using namespace std;
class clsLoginRegister:public clsScreen
{

private:

	static void _showRecord(clsUser::stLoginsRegisters r) {

		cout << setw(20) << r.dateAndTime<< setw(15) << r.username << setw(15) << r.password << setw(17) << r.permissions
			<< endl;

	}

public:

	static void showGegisterLoginsScreen() {

		if (!ishavePremissions(clsUser::enPremissions::pLoginRegisters)) {
			return;
		}

		drawScreenHeader("Register Logins Screen ");

		vector <clsUser::stLoginsRegisters>vecRe =clsUser::getLoginRegisersData();

		cout << "-------------------------------------------------------------------------------------------------------------------\n";
		cout << setw(20) << "Date&Time " << setw(15) << "User Name" << setw(15) << "Password" << setw(17) << "Permissions"
			<<  endl;
		cout << "---------------------------------------------------------------------------------------------------------------------\n";

		for (clsUser::stLoginsRegisters& u : vecRe) {
			_showRecord(u);
		}
		cout << "---------------------------------------------------------------------------------------------------------------------\n";


	}
};

