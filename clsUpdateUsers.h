#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"Myc++Libarires/clsString.h"
#include"Myc++Libarires/clsInputValidate.h"
using namespace std;
class clsUpdateUsers:protected clsScreen
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

	static void readUserInfo(clsUser& user) {
		cout << "enter first name : ";
		user.setFirstName(clsString::readString());
		cout << "enter last name : ";
		user.setLastName(clsString::readString());
		cout << "enter email : ";
		user.setEmail(clsString::readString());
		cout << "enter phone number : ";
		user.setPhoneNumber(clsString::readString());
		cout << "\n enter password : ";
		user.setPassword(clsString::readString());

		user.setPermissions(_readPermissions());
	}

	static short _readPermissions() {
		short per = 0;
		char want = 'n';

		cout << "do you want him to have access to all : ";
			cin >> want;
			if (tolower(want) == 'y')
				per = -1;
			else {
				cout << "do you want him to have access to : \n";
				cout << "Add clients : (y/n) ? ";
					cin >> want;
					if (tolower(want) == 'y')
						per += clsUser::pAdd;
					cout << "Show clients : (y/n) ? ";
					cin >> want;
					if (tolower(want) == 'y')
						per += clsUser::pList;
					cout << "delete clients : (y/n) ? ";
					cin >> want;
					if (tolower(want) == 'y')
						per += clsUser::pDelete;
					cout << "update clients : (y/n) ? ";
					cin >> want;
					if (tolower(want) == 'y')
						per += clsUser::pUpdate;
					cout << "find clients : (y/n) ? ";
					cin >> want;
					if (tolower(want) == 'y')
						per += clsUser::pFind;
					cout << "Transaction OPS : (y/n) ? ";
					cin >> want;
					if (tolower(want) == 'y')
						per += clsUser::pTransactions;
					cout << "manage users : (y/n) ? ";
					cin >> want;
					if (tolower(want) == 'y')
						per += clsUser::pManage;
					cout << "Show Login Registers clients : (y/n) ? ";
					cin >> want;
					if (tolower(want) == 'y')
						per += clsUser::pLoginRegisters;



			}
			return per;
	}

public:

	static void showUpdateUsersScreen() {

		
		drawScreenHeader("Update Users Screen");

		cout << "enter username you want to update : ";
		string username = clsString::readString();

		while (!clsUser::isuserExist(username)) {
			cout << "this user name not existed ,enter another username you want to update : ";
			 username = clsString::readString();
		}

		clsUser user = clsUser::find(username);
		_printUser(user);

		readUserInfo(user);

		clsUser::enSaveResult saveresult = user.save();

		switch (saveresult) {

		case clsUser::svSucceded:
			cout << "user updated succesfuly . \n\n";
			_printUser(user);
			break;

		case clsUser::svFailedEmptyObject:
			cout << "an error occured client didn't updated. \n\n";
		}


	}
};

