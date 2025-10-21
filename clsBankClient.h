#pragma once
#include<iostream>
#include"clsPerson.h"
#include<fstream>
#include<vector>
#include<string>
#include"Myc++Libarires/clsString.h"
#include<iomanip>
#include"global.h"
#include"Myc++Libarires/clsDate.h"
class clsBankClient:public clsPerson
{
private:
	enum enMode{enEmpty=0,enUpdate=1,enAddNew=2 };
	enMode _mode;
	string _accNum;
	string _pinCode;
	float _accBalance;
	bool _markedToDelete = false;


	static clsBankClient _convertLinetoClassObject(string line) {
		vector <string>vclsBC = clsString::splitString(line, "#//#");
		return clsBankClient(enMode::enUpdate, vclsBC[0], vclsBC[1], vclsBC[2], vclsBC[3], vclsBC[4], vclsBC[5], stof(vclsBC[6]));
	}


	static clsBankClient _getEmptyClientAccount() {
		return clsBankClient(enMode::enEmpty, "", "", "", "", "", "", 0);
	}


	 static vector <clsBankClient>_loadDataFromFileToVector() {

		vector <clsBankClient> vecClients;

		fstream file;
		file.open("Clients.txt", ios::in);

		if (file.is_open()) {
			string line;
			while (getline(file, line)) {

				clsBankClient client = _convertLinetoClassObject(line);
				vecClients.push_back(client);
			}
			file.close();
			}
		
		return vecClients;
		
	}


	void _update() {
		vector <clsBankClient>vecClients;
		vecClients = _loadDataFromFileToVector();

		for (clsBankClient& c : vecClients) {
			if (c._accNum == this->_accNum) {
				c = *this;
			}
		}
		_saveVectorToFile(vecClients);
	}


	void _saveVectorToFile(vector <clsBankClient>vecClients) {

		fstream file;
		file.open("Clients.txt", ios::out);

		if (file.is_open()) {

			for (clsBankClient& c : vecClients) {
				if(!c.getMarkToDelete())
				file << _convertClassObjectToLine(c)<<'\n';
				
			}
			file.close();
		}

	}


	string _convertClassObjectToLine(clsBankClient client,string seprator="#//#") {

		string line="";
		line += client.getFirstName() + seprator;
		line += client.getLastName() + seprator;
		line += client.getEmail() + seprator;
		line += client.getPhoneNumber() + seprator;
		line += client._accNum + seprator;
		line += client._pinCode + seprator;
		line +=to_string( client._accBalance);

		return line;
		

	}

	void _addNew() {

		_addRecordToFile(_convertClassObjectToLine(*this));
	}

	void _addRecordToFile(string record) {

		fstream file;
		file.open("Clients.txt", ios::app | ios::out);

		if (file.is_open()) {
			file << record << '\n';	
		}
		file.close();
	}

	static string _prepareRecordToSendToTransferFile(clsBankClient source, clsBankClient destenation, double amount) {

		return clsDate::getStringDateAndTimeNow() + "#//#" + source._accNum + "#//#" + destenation._accNum + "#//#" + to_string(amount) + "#//#" +
			to_string(source._accBalance) + "#//#" + to_string(destenation._accBalance) + "#//#" + currentUser.getUserName();
			
	}

	static void _saveTransferToTransferLogFile(clsBankClient source,clsBankClient destenation,double amount) {

		fstream file;

		file.open("TransfersLogFile", ios::out | ios::app);

		if (file.is_open()) {

			file << _prepareRecordToSendToTransferFile(source, destenation, amount) << endl;
		
		}
		file.close();
	}
	

public:
	clsBankClient(enMode mode,string firstName,string lastName,string email,string phoneNumber,string accNum,string pincode,float accBalance) 
		:clsPerson(firstName,lastName,email,phoneNumber)
	{
		_mode = mode;
		_accNum = accNum;
		_pinCode = pincode;
		_accBalance = accBalance;
	}
	bool isEmpty() {
		return (_mode == enMode::enEmpty);
	}

	string getAccNum() {
		return _accNum;
	}


	void setPinCode(string pinCode) {
		_pinCode = pinCode;
	}
	string getPinCode() {
		return _pinCode;
	}

	void setAccBalance(float accBalane) {
		_accBalance = accBalane;
	}
	float getAccBalance() {
		return _accBalance;
	}

	void setMarkToDelete(bool mark) {
		_markedToDelete = mark;
	}
	bool getMarkToDelete() {
		return _markedToDelete;
	}


	
	static clsBankClient find(string accNum) {

		fstream file;
		file.open("Clients.txt", ios::in);
		if (file.is_open()) {

			string line = "";
			while (getline(file, line)) {
				clsBankClient client=_convertLinetoClassObject(line);
				if (client._accNum == accNum) {
					file.close();
					return client;
				}
			}
			file.close();
			return _getEmptyClientAccount();
		}
	}
	static clsBankClient find(string accNum,string pinCode) {

		fstream file;
		file.open("Clients.txt", ios::in);
		if (file.is_open()) {

			string line = "";
			while (getline(file, line)) {
				clsBankClient client=_convertLinetoClassObject(line);
				if ( accNum== client._accNum&&pinCode==client._pinCode ) {
					file.close();
					return client;
				}
			}
			file.close();
			return _getEmptyClientAccount();
		}
	}

	static bool isAccountNumberExisted(string accNum) {
		clsBankClient client1=clsBankClient::find(accNum);
		return (!client1.isEmpty());
	}

	enum enSaveResult{svFailedEmptyObject=0,svSucceded=1,svFailedClientExisting};

	 enSaveResult save() {
		 switch (_mode) {
		 case enMode::enEmpty:
			 return enSaveResult::svFailedEmptyObject;
		 case enMode::enUpdate:
			 _update();
			 return enSaveResult::svSucceded;

		 case enMode::enAddNew:
			 if (isAccountNumberExisted(_accNum))
				 return enSaveResult::svFailedClientExisting;
			 else {
				 _addNew();
				 _mode = enMode::enUpdate;
				 return enSaveResult::svSucceded;
			 }
		 }
	}

	 static clsBankClient getNewClientObject(string accNum) {

		 return clsBankClient(enMode::enAddNew, "", "", "", "", accNum, "", 0);
	 }

	 void Delete() {
		 vector <clsBankClient>vecCls = _loadDataFromFileToVector();
		 for (clsBankClient& c : vecCls) {
			 if (c._accNum == this->_accNum) {
				 c.setMarkToDelete(true);
				 break;
			 }
		 }
		 _saveVectorToFile(vecCls);
		 *this = _getEmptyClientAccount();
	 }


	 static vector <clsBankClient> getClientsList() {

		 return _loadDataFromFileToVector();
	}

	 static double totalBalances() {
		 vector <clsBankClient>clients = _loadDataFromFileToVector();
		 double total = 0;
		 for (clsBankClient& c : clients) {
			 total += c._accBalance;
		 }
		 return total;
	 }

	 void deposite(double amount) {

		 this->_accBalance += amount;
		 save();
	 }

	 bool withDraw(double amount) {
		 if (amount > _accBalance) {
			 return false;
		 }
		 else {
			 this->_accBalance -= amount;
			 save();
		 }
	 }

	 static bool transfer(clsBankClient& from,clsBankClient& to,int amount) {

		 if (amount <= 0)
			 return false;
		 if (!from.withDraw(amount))
			 return false;
		 else {
			 to.deposite(amount);
			 _saveTransferToTransferLogFile(from, to, amount);
			 return true;
		 }
	 }

	 struct stTranferLog {
		 string dateAndTime = "";
		 string dAccNum;
		 string sAccNum;
		 double amount;
		 double sAccBalance;
		 double dAccBalance;
		 string UserName;
	 };

	 static stTranferLog convertLineToStTransferLogs(string line, string seprator = "#//#") {

		 vector <string> vecSplited = clsString::splitString(line, seprator);

		 stTranferLog log;
		 log.dateAndTime = vecSplited[0];
		 log.sAccNum = vecSplited[1];
		 log.dAccNum = vecSplited[2];
		 log.amount = stod(vecSplited[3]);
		 log.sAccBalance = stod(vecSplited[4]);
		 log.dAccBalance = stod(vecSplited[5]);
		 log.UserName = vecSplited[6];

		 return log;
	 }

	 static vector <stTranferLog>loadDataFromTransferFile() {
		 vector <stTranferLog> vecLogs;
		 fstream file;		 
		 file.open("TransfersLogFile", ios::in);

		 if (file.is_open()) {
			 string line = "";
			 stTranferLog transferInfo;
			 while (getline(file, line)) {
				 transferInfo = convertLineToStTransferLogs(line);
				 vecLogs.push_back(transferInfo);
			 }
		 }
		 file.close();
		 return vecLogs;
	 }
};

