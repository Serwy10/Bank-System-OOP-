#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"Myc++Libarires/clsString.h"
#include"clsScreen.h"
#include"Myc++Libarires/clsInputValidate.h"
using namespace std;
class clsWithdrawAccounts:protected clsScreen
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
	static void showWithDrawScreen() {
		drawScreenHeader("WithDraw Screen");

		cout << "enter account number : ";
		string accNum = clsString::readString();
		while (!clsBankClient::isAccountNumberExisted(accNum)) {
			cout << "account number not existed ,enter account number : ";
			string accNum = clsString::readString();
		}

		clsBankClient client = clsBankClient::find(accNum);
		_printClient(client);
		double amount = clsInputValidate::readDbNumber("enter amount you want to with draw : ");

		char c = 'n';
		cout << "are you sure you want withdraw from that acoount : (y/n)";
		cin >> c;
		if (tolower(c) == 'y') {
			if (client.withDraw(amount)) {
				cout << "with draw completed succesfully . \n";
				cout << "Account after withdraw will be : " << client.getAccBalance() << endl;
			}
			else {
				cout << "error the amount you want to withdraw is bigger than your account balance . ";
			}
		}
		else {
			cout << "error withdraw didn't complete right . ";
		}
		

	}
};

