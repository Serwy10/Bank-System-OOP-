#pragma once
#include<iostream>
#include<vector>
#include"clsScreen.h"
#include"clsBankClient.h"
using namespace std;

class clsDeleteClient:protected clsScreen
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
	static void deleteClient() {


		if (!ishavePremissions(clsUser::enPremissions::pDelete)) {
			return;
		}

		drawScreenHeader("Delete Clients Screen");
		string accNum = "";

		cout << "enter account you want to delete : ";
		accNum = clsString::readString();
		while (!clsBankClient::isAccountNumberExisted(accNum)) {
			cout << "accNum not found,enter other account you want to delete : ";
			accNum = clsString::readString();
		}

		clsBankClient client = clsBankClient::find(accNum);
		_printClient(client);

		char c = 'n';
		cout << "are you sure you want to delete this client : (y/n) ? ";
		cin >> c;
		if (tolower(c) == 'y') {
			client.Delete();
			cout << "client deleted succesfully . \n";
			_printClient(client);
		}
		else
			cout << "an error has been occured ,client not deleted.\n";

	}
};

