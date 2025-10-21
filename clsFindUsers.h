#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"Myc++Libarires/clsString.h"
using namespace std;
class clsFindUsers:protected clsScreen
{

private:
	static  void _printUser(clsUser user) {
		cout << "\n USER : \n----------------------------\n";
		cout << "First Name : " << user.getFirstName() << endl;
		cout << "Last Name : " << user.getLastName() << endl;
		cout << "Email : " << user.getEmail() << endl;
		cout << "Phone Number : " << user.getPhoneNumber() << endl;
		cout << "User Name : " << user.getUserName() << endl;
		cout << "PassWord : " << user.getPassword() << endl;
		cout << "Premissions : " << user.getPermissions() << endl;
		cout << "----------------------------------\n";

	}
public:
	static void showFindUsersScreen() {

		drawScreenHeader("Find Users Screen ");

		cout << "enter user name : ";
		string userName = clsString::readString();

		while (!clsUser::isuserExist(userName)) {
			cout << "no user has this user name ,enter another user name : ";
			 userName = clsString::readString();
		}

		clsUser user = clsUser::find(userName);
		_printUser(user);
	}
};

