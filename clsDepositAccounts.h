#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"Myc++Libarires/clsString.h"
#include"Myc++Libarires/clsInputValidate.h"
using namespace std;
class clsDepositAccounts:protected clsScreen
{
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
	static void showDepositeScreen() {
		
		drawScreenHeader("Deposite Screen");

		cout << "enter account number : ";
		string accNum = clsString::readString();
		while (!clsBankClient::isAccountNumberExisted(accNum)) {
			cout << "account number not existed ,enter account number : ";
			string accNum = clsString::readString();
		}

		clsBankClient client = clsBankClient::find(accNum);
		_printClient(client);
		double amount = clsInputValidate::readDbNumber("enter amount you want to deposite : ");

		char c = 'n';
		cout << "are you sure you want deposite that client : (y/n)";
		cin >> c;
		if (tolower(c) == 'y') {
			client.deposite(amount);
			cout << "Account after deposite will be : " << client.getAccBalance() << endl;
		}
		else {
			cout << "error deposite didn't complete right . ";
		}


	}


};

