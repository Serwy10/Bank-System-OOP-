#pragma once
#include<iostream>
#include<vector>
#include"Myc++Libarires/clsString.h"
#include<fstream>
#include"clsPerson.h"
#include"Myc++Libarires/clsDate.h"
#include"Myc++Libarires/clsUtil.h"
using namespace std;
class clsUser:public clsPerson
{
private:
	static enum enMode{enUpdate=1,enEmpty=2,enAdd=3};
	string _userName;
	string _password;
	 enMode _mode;
	 short _permissions=0;
	 bool _deleted = false;
	
	static clsUser _convertLineToObject(string line) {

		vector <string>vecUser = clsString::splitString(line, "#//#");
		return clsUser(enUpdate,vecUser[0], vecUser[1],vecUser[2],vecUser[3],vecUser[4], clsUtil::decryptText(vecUser[5],5),stoi(vecUser[6]));
	}
	static clsUser _getEmptyObject() {
		return clsUser(enEmpty, "", "","","","","",0);
	}

	static vector <clsUser>_loadDataFromFileToVector() {

		vector <clsUser>vecUsers;
		fstream file;
		file.open("Users.txt", ios::in);

		if (file.is_open()) {
			string line = "";
			while (getline(file, line)) {
				clsUser user = _convertLineToObject(line);
				vecUsers.push_back(user);
			}
			file.close();
		}
		return vecUsers;
	}

	  string _convertObjectToLine(string delim="#//#") {
		string st = "";

		st += getFirstName() + delim;
		st += getLastName() + delim;
		st += getEmail() + delim;
		st += getPhoneNumber() + delim;
		st += _userName + delim;
		st +=clsUtil::encryptText( _password,5) + delim;
		st +=to_string( _permissions);
		return st;
	}

	   void _addNewLineToFile(string line) {

		fstream file;
		file.open("Users.txt", ios::app | ios::out);

		if (file.is_open()) {
			file << line << endl;
		}
		file.close();
	}

	void _add() {

		_addNewLineToFile(_convertObjectToLine());
	}

	void _savevectorToFile(vector <clsUser>vecUsers) {

		fstream file;
		file.open("Users.txt", ios::out);

		if (file.is_open()) {

			for (clsUser& u : vecUsers) {

				if (!u._deleted) {
					file << u._convertObjectToLine() << endl;
				}
			}
		}
		file.close();
	}

	void _update() {

		vector <clsUser>vecUsers = _loadDataFromFileToVector();

		for (clsUser& u : vecUsers) {
			if (u._userName == _userName) {
				u = *this;
				break;
			}
		}
		_savevectorToFile(vecUsers);
	}

public:
	struct stLoginsRegisters {
		string dateAndTime;
		string username;
		string password;
		short permissions;
	};


	static stLoginsRegisters _convertLineToGegisterObject(string line) {

		vector<string>vecRe;
		vecRe = clsString::splitString(line, "#//#");

		stLoginsRegisters reg;
		reg.dateAndTime = vecRe[0];
		reg.username = vecRe[1];
		reg.password =clsUtil::decryptText( vecRe[2],5);
		reg.permissions = stoi(vecRe[3]);

		return  reg;

	}

	static vector<stLoginsRegisters>_loadDataFromRegisterFile() {

		vector <stLoginsRegisters>registers;
		fstream file;

		file.open("registerLogin.txt", ios::in);

		if (file.is_open()) {

			string line = "";

			while (getline(file, line)) {

				stLoginsRegisters reges = _convertLineToGegisterObject(line);
				registers.push_back(reges);
			}

		}
		file.close();
		return registers;
	}
	





	enum enPremissions{pList=1,pAdd=2,pDelete=4,pUpdate=8,pFind=16,pTransactions=32,pManage=64,pLoginRegisters=128};

	clsUser(enMode mode,string firstname,string lastname,string email,string phone,string username, string password,short premissions) :
	clsPerson(firstname,lastname,email,phone){
		_mode = mode;
		_userName = username;
		_password = password;
		_permissions = premissions;
	}

	

	
	void setuserName(string username) {
		_userName = username;
	}
	string getUserName() {
		return _userName;
	}

	void setPassword(string password) {
		_password = password;
	}
	string getPassword() {
		return _password;
	}

	void setPermissions(short permissions) {

		_permissions = permissions;
	}

	short getPermissions() {
		return _permissions;
	}

	bool isEmpty() {
		return _mode == enMode::enEmpty;
	}


	static clsUser find(string username) {

		fstream file;
		file.open("Users.txt", ios::in);

		if (file.is_open()) {
			string line = "";
			
			while (getline(file, line)) {
				clsUser user=_convertLineToObject(line);
				if (username == user._userName) {
					file.close();
					return user;
				}
			}
			file.close();

		}
		return _getEmptyObject();
	}


	static clsUser find(string username,string password) {

		fstream file;
		file.open("Users.txt", ios::in);

		if (file.is_open()) {
			string line = "";

			while (getline(file, line)) {
				clsUser user = _convertLineToObject(line);
				if (username == user._userName && password==user._password) {
					file.close();
					return user;
				}
			}
			file.close();

		}
		return _getEmptyObject();
	}


	static bool isuserExist(string userName) {
		return !find(userName).isEmpty();
	}

	static vector<clsUser> getUsersData() {
		return  _loadDataFromFileToVector();
	}

	enum enSaveResult{svSucceded=1,svFailedEmptyObject=2,svFailedExistingObject=3};

	enSaveResult save() {
		switch (_mode) {
		case enEmpty:
			return svFailedEmptyObject;
		case enUpdate:
			_update();
			return svSucceded;
		case enAdd:
			if (isuserExist(_userName))
				return svFailedExistingObject;
			else {
				_add();
				_mode = enUpdate;
				return svSucceded;
			}
		}
	}

	static clsUser getNewObject(string username) {

		return clsUser(enAdd,"","","","", username, "", 0);
	}

	void Delete() {
		vector <clsUser>vecusers = _loadDataFromFileToVector();
		if (this->_userName == "admin")
			return;
		for (clsUser& u : vecusers) {
			if (u._userName == this->_userName)
				u._deleted = true;
		}

		*this = _getEmptyObject();
		_savevectorToFile(vecusers);
	}

	bool checkApplyPremissions(enPremissions premission) {

		if (this->_permissions == -1)
			return true;
		else if ((this->_permissions & premission) == premission)
			return true;
		else
			return false;

	}


	 void AddToRegisterLoginFile() {


		time_t t = time(0);
		tm* nownow = localtime(&t);

		string today = clsDate::dateToString(clsDate());

		fstream file;

		file.open("registerLogin.txt", ios::app | ios::out);

		if (file.is_open()) {

			file << today << '-' << nownow->tm_hour << ":" << nownow->tm_min << ":" << nownow->tm_sec
				<< "#//#" << getUserName() << "#//#" << clsUtil::encryptText( getPassword(),5) << "#//#" << getPermissions() << endl;


		}
		file.close();
	}

	 static vector<stLoginsRegisters>getLoginRegisersData(){
		 return _loadDataFromRegisterFile();
	 }

};

