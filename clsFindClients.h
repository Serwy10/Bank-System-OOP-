#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"Myc++Libarires/clsString.h"
class clsFindClients:protected clsScreen
{
private:

	static void _printClient(clsBankClient client) {
		cout << "Client : " << '\n';
		cout << "-------------------------------\n";
		cout << "FullName        : " << client.getFirstName() + client.getLastName() << endl;
		cout << "Account number  : " << client.getAccNum() << endl;
		cout << "Account Balance : " << client.getAccBalance() << endl;
		cout << "Email           : " << client.getEmail() << endl;
		cout << "Phone Number      : " << client.getPhoneNumber() << endl;
		cout << "-------------------------------\n";

	}
public:

	static void findClient() {

		if (!ishavePremissions(clsUser::enPremissions::pFind)) {
			return;
		}


		drawScreenHeader("Find Client Screen");

		cout << "enter account number : ";
		string accNum = clsString::readString();
		while (!clsBankClient::isAccountNumberExisted(accNum)) {
			string accNum = clsString::readString();
		}
		clsBankClient client = clsBankClient::find(accNum);
		_printClient(client);

	}
};

