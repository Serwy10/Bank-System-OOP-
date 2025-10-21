#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"Myc++Libarires/clsString.h"
#include"Myc++Libarires/clsInputValidate.h"
class clsTransfer:protected clsScreen
{
	static void _printClient(clsBankClient client) {
		cout << "Client : " << '\n';
		cout << "-------------------------------\n";
		cout << "FullName        : " << client.getFirstName() + client.getLastName() << endl;
		cout << "Account number  : " << client.getAccNum() << endl;
		cout << "Account Balance : " << client.getAccBalance() << endl;
	
		cout << "-------------------------------\n";

	}




	static void _transfer() {

		cout << "enter account number you want transfer from : ";
		string accNum = clsString::readString();

		while (!clsBankClient::isAccountNumberExisted(accNum)) {
			cout << "acc not found ,enter another account number you want transfer from : ";
			 accNum = clsString::readString();

		}

		clsBankClient TransferFrom = clsBankClient::find(accNum);
		_printClient(TransferFrom);

		cout << "\nenter account number you want transfer to : ";
		 accNum = clsString::readString();

		while (!clsBankClient::isAccountNumberExisted(accNum)) {
			cout << "acc not found ,enter another account number you want transfer to : ";
			accNum = clsString::readString();

		}

		clsBankClient transferTo = clsBankClient::find(accNum);
		_printClient(transferTo);

		
		 double  amount = clsInputValidate::readDbNumber("enter amount you want to send : ");

		char want;
		cout << "are you sure you want to do this operation ? (y/n) : ";
		cin >> want;
		if (tolower(want) == 'y') {

			while (!clsBankClient::transfer(TransferFrom, transferTo, amount)) {
				amount = clsInputValidate::readDbNumber("amount exceeds the available balance enter another amount, enter amount bigger than zero : ");
			}

			cout << "the transfer is finished succedded . \n";

			_printClient(TransferFrom);
			_printClient(transferTo);

		}
		else {
			cout << "operation cancelled . \n";
		}

	}

public:

	static void showTransferScreen() {

		drawScreenHeader("Transfer Screen");
		_transfer();

	}

};

