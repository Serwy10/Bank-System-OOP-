#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include<vector>
#include<iomanip>
using namespace std;

class clsListUsers:protected clsScreen
{

	static void _printAllUsers(clsUser user) {

	
		cout  <<setw(15)<<user.getFirstName()<< setw(15)<<user.getLastName()<<setw(23)<<user.getEmail() <<setw(17)<<
		user.getPhoneNumber()<<	setw(15)<<user.getUserName()<< setw(15)<< user.getPassword() <<setw(15)
			<< user.getPermissions() << endl;
	
	}

public:
	static void showListUsers() {

		


		drawScreenHeader("Show All Users Screen ");

		vector<clsUser>vecUsers = clsUser::getUsersData();
		cout   << "-------------------------------------------------------------------------------------------------------------------\n";
		cout << setw(15) << "First Name " << setw(15) << "Last Name" << setw(23) << "Email" << setw(17) << "Phone Number"
			<< setw(15) << "User Name" << setw(15) << "Password" << setw(15) << "Permissions" << endl;
		cout   << "---------------------------------------------------------------------------------------------------------------------\n";

		for (clsUser& u : vecUsers) {
			_printAllUsers(u);
		}
		cout << "---------------------------------------------------------------------------------------------------------------------\n";


	}
};

