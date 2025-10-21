#pragma once
#include<iostream>
#include"Myc++Libarires/clsString.h"

class clsPerson
{
private:
	string _firstName;
	string _lastName;
	string _email;
	string _phone;
public:
	clsPerson(string firstname, string lastname, string email, string phone) {

		_firstName = firstname;
		_lastName = lastname;
		_email = email;
		_phone = phone;
	}

	void setFirstName(string firstname) {
		_firstName = firstname;
	}
	string getFirstName() {
		return _firstName;
	}

	void setLastName(string lastName) {
		_lastName = lastName;
	}
	string getLastName() {
		return _lastName;
	}

	void setEmail(string email) {
		_email = email;
	}
	string getEmail() {
		return _email;
	}

	void setPhoneNumber(string phone) {
		_phone = phone;
	}
	string getPhoneNumber() {
		return _phone;
	}

};

