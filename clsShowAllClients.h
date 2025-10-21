#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include<vector>
using namespace std;

class clsShowAllClients:protected clsScreen
{
private:
	static void _printClientRecord(clsBankClient client) {
		cout << left << setw(15) << client.getAccNum() << '|'
			<< left << setw(20) << client.getFirstName() + client.getLastName() << '|'
			<< left << setw(13) << client.getPhoneNumber() << '|'
			<< left << setw(20) << client.getEmail() << '|'
			<< left << setw(20) << client.getAccBalance()
			<< endl;
	}
public:
	static void showAllClients() {

		if (!ishavePremissions(clsUser::enPremissions::pList)) {
			return;
		}

		string title = "List All Clients";
		vector<clsBankClient>clients = clsBankClient::getClientsList();
		string subTitle = to_string(clients.size())+"Clients";

		drawScreenHeader(title,subTitle);
		
		cout << "           Clients : " << clients.size() << endl;
		cout << left << setw(15) << "AccountNumber" << '|'
			<< left << setw(20) << "FullName" << '|'
			<< left << setw(13) << "PhoneNum" << '|'
			<< left << setw(20) << "Email" << '|'
			<< left << setw(20) << "Account Balance"
			<< endl;
		if (clients.size() == 0)
			cout << "NO Clients Available In System .";
		else
		{
			for (clsBankClient& c : clients) {
				_printClientRecord(c);
			}
		}
	}
};

