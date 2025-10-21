#pragma once
#include<iostream>
#include"clsScreen.h"
#include"Myc++Libarires/clsString.h"
#include"clsUser.h"
#include"Myc++Libarires/clsInputValidate.h"
using namespace std;

class clsAddUsers:protected clsScreen
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

	static void showAddUsersScreen() {
		

		

		drawScreenHeader("Add Users Screen");

		cout << "enter user name you want to add : ";
		string username = clsString::readString();

		while (clsUser::isuserExist(username)) {
			cout << "you can't use this user name ,enter another user name you want to add : ";
			 username = clsString::readString();
		}

		clsUser newUser = clsUser::getNewObject(username);

		readUserInfo(newUser);

	 clsUser::enSaveResult saveresult=newUser.save();



	 switch (saveresult) {
	 case clsUser::enSaveResult::svFailedEmptyObject:
		 cout << "an error happened user didn't saved . \n";
		 break;
	 case clsUser::enSaveResult::svSucceded:
		 cout << "new user added sussesfully . \n ";
		 _printUser(newUser);
	 }


	}


};

