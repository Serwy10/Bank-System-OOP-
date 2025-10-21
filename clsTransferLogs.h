#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsBankClient.h"
using namespace std;

class clsTransferLogs:protected clsScreen
{

	static void _printLogRecord(clsBankClient::stTranferLog log) {

		cout << setw(23) << log.dateAndTime << setw(15) << log.sAccNum << setw(15) << log.dAccNum << setw(17) << log.amount
			<< setw(17) << log.sAccBalance<< setw(17) << log.dAccBalance << setw(14) << log.UserName << endl;
	}
public:
	static void showTransferLogsScreen() {

		drawScreenHeader("Transfer Logs");

		vector <clsBankClient::stTranferLog> vecLogs = clsBankClient::loadDataFromTransferFile();
		cout << "-------------------------------------------------------------------------------------------------------------------\n";
		cout << setw(23) << "Date&Time " << setw(15) << "S.accNum" << setw(15) << "D.AccNum" << setw(17) << "Amount"
			<< setw(17) << "S.AccBalance" << setw(17) << "D.AccBalance" << setw(14) << "User" << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------\n";
		for (clsBankClient::stTranferLog& l : vecLogs) {
			_printLogRecord(l);
						}
		
		cout << "---------------------------------------------------------------------------------------------------------------------\n";
	}

};

