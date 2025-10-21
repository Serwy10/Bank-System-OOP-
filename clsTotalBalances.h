#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsUpdateClients.h"
#include"clsScreen.h"
using namespace std;
class clsTotalBalances:protected clsScreen
{
private:

	static void _printBalances(clsBankClient client) {
		cout << left << setw(15) << client.getAccNum() << '|'
			<< left << setw(20) << client.getFirstName() + client.getLastName() << '|'
			<< left << setw(20) << client.getAccBalance()
			<< endl;

	}

public:


	static void showTotalBalances() {

		drawScreenHeader("Total Balances");

		vector <clsBankClient>clients;
		clients = clsBankClient::getClientsList();
		double totalBalances = clsBankClient::totalBalances();


		cout << "               Clients(" << clients.size() << ")" << endl;
		cout << left << setw(15) << "AccountNumber" << '|'
			<< left << setw(20) << "FullName" << '|'
			<< left << setw(20) << "Account Balance"
			<< endl;
		if (clients.size() == 0)
			cout << "NO Clients Available In System .";
		else
		{
			for (clsBankClient& c : clients) {
				_printBalances(c);
			}
			cout << "\n\n                  Total Blances : " << totalBalances << endl;
			cout << "                   (" << clsUtil::numberToText(totalBalances) << ")" << endl;
		}


	}
};

