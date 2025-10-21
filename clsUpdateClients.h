#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"Myc++Libarires/clsInputValidate.h"
class clsUpdateClients:protected clsScreen
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
	static void updateClient() {

		if (!ishavePremissions(clsUser::enPremissions::pUpdate)) {
			return;
		}


		drawScreenHeader("Update Client Screen");
		string accNum = "";
		cout << "enter account number : ";
		cin >> accNum;
		while (!clsBankClient::isAccountNumberExisted(accNum)) {
			cout << "enter account number : ";
			cin >> accNum;
		}
		clsBankClient client = clsBankClient::find(accNum);
		_printClient(client);
		cout << "-----------------------\n";
		cout << "  Update Client : \n";
		cout << "-----------------------\n";
		_readClientInfo(client);

		clsBankClient::enSaveResult saveResult = client.save();

		switch (saveResult) {
		case clsBankClient::enSaveResult::svFailedEmptyObject:
			cout << "mission failed . \n";
			break;
		case clsBankClient::enSaveResult::svSucceded:
			cout << "your account updated . \n";
			_printClient(client);
			break;
		}
	}

};

