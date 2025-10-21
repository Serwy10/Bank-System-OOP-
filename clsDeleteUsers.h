#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"Myc++Libarires/clsString.h"
using namespace std;
class clsDeleteUsers : protected clsScreen
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
	static void showDeleteUsersScreen() {

		

		drawScreenHeader("Delete User Screen");

		cout << "enter user name you want to delete : ";
		string username = clsString::readString();

		while (!clsUser::isuserExist(username) || username=="admin") {

			cout << "enter user name you want to delete : ";
			 username = clsString::readString();

		}
		clsUser user = clsUser::find(username);

		_printUser(user);

		char c = 'n';
		cout << "are you sure you want to delete this user : (y/n) ? ";
		cin >> c;
		if (tolower(c) == 'y') {
			user.Delete();
			cout << "user deleted succesfully . \n";
			_printUser(user);
		}
		else
			cout << "an error has been occured ,user not deleted.\n";

	}
};

