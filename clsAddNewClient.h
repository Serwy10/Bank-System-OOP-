#pragma once
#include<iostream>
#include<vector>
#include"clsBankClient.h"
#include"Myc++Libarires/clsInputValidate.h"
#include"clsScreen.h"

class clsAddNewClient:protected clsScreen
{
private:
	static void _readClientInfo(clsBankClient& client) {

		cout << "enter first name : ";
		client.setFirstName(clsString::readString());
		cout << "enter last name : ";
		client.setLastName(clsString::readString());
		cout << "enter email : ";
		client.setEmail(clsString::readString());
		cout << "phone number : ";
		client.setPhoneNumber(clsString::readString());
		cout << "PIN code : ";
		client.setPinCode(clsString::readString());
		client.setAccBalance(clsInputValidate::readDbNumber("account balance : "));


	}

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
	static void addNewClient() {

		if (!ishavePremissions(clsUser::enPremissions::pAdd)) {
			return;
		}


		drawScreenHeader("Add New Client Screen");
		string accNum = "";
		cout << "enter account number : ";
		accNum = clsString::readString();
		while (clsBankClient::isAccountNumberExisted(accNum)) {
			cout << "the account number is usable ,enter another account number : ";
			accNum = clsString::readString();
		}

		cout << "-----------------------\n";
		cout << "  Add New Client :-\n";
		cout << "-----------------------\n";
		clsBankClient newClient = clsBankClient::getNewClientObject(accNum);
		_readClientInfo(newClient);

		clsBankClient::enSaveResult saveResult = newClient.save();

		switch (saveResult) {

		case clsBankClient::enSaveResult::svFailedClientExisting:
			cout << "can't added because account number is already existing . \n";
			break;
		case clsBankClient::enSaveResult::svSucceded:
			cout << "your account was added,thank you . \n";
			_printClient(newClient);
			break;

		}
	}
};

