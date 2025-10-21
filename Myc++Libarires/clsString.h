#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class clsString
{
private:
	string _value;
	char _char;
	vector<string>_vSt;


public:
	clsString() {
		_value = "";
	}
	clsString(string value) {
		_value = value;
	}
	void setVectorOfString(vector <string>vSt) {
		_vSt = vSt;
	}
	void getVectorOfString() {
		for (string& s : _vSt) {
			cout << s << ' ';
		}
		cout << endl;
	}

	void setChar(char c) {
		_char = c;
	}
	char getChar() {
		return _char;
	}

	void setString(string value) {
		_value = value;
	}
	string getString() {
		return _value;
	}


	static void printFirstLetterInEachWordInString(string st,string delim =" ") {

		bool isDelim = true;
		for (int i = 0; i < st.length(); i++) {
			if (st[i] != ' ' && isDelim)
				cout << st[i] << endl;
			isDelim = (st[i] == ' ') ? true : false;
		}

	}
	void printFirstLetterInEachWordInString() {
		printFirstLetterInEachWordInString(_value);
	}


	static string upperFirstLetterInString(string st, string delim = " ") {

		bool isDelim = true;
		for (int i = 0; i < st.length(); i++) {
			if (st[i] != ' ' && isDelim)
				st[i] = toupper(st[i]);
			isDelim = (st[i] == ' ') ? true : false;
		}
		return st;
	}
	string upperFirstLetterInString() {
	  return upperFirstLetterInString(_value);
	}

	static string lowerFirstLetterInString(string st, string delim = " ") {

		bool isDelim = true;
		for (int i = 0; i < st.length(); i++) {
			if (st[i] != ' ' && isDelim)
				st[i] = tolower(st[i]);
			isDelim = (st[i] == ' ') ? true : false;
		}
		return st;
	}
	string lowerFirstLetterInString() {
	  return lowerFirstLetterInString(_value);
	}


	static string lowerLettersInString(string st, string delim = " ") {

		
		for (int i = 0; i < st.length(); i++) {
			if (st[i] != ' ')
				st[i] = tolower(st[i]);

		}
		return st;
	}
	string lowerLettersInString() {
		return lowerLettersInString(_value);
	}
	

	static string upperLettersInString(string st, string delim = " ") {


		for (int i = 0; i < st.length(); i++) {
			if (st[i] != ' ')
				st[i] = toupper(st[i]);

		}
		return st;
	}
	string upperLettersInString() {
		return upperLettersInString(_value);
	}

	static short countString(string st) {

		short counter = 0;
		for (short i = 0; i < st.length(); i++) {
			++counter;
		}
		return counter;
	}
	short countString() {
		return countString(_value);
	}

	static short countUpperLetterInString(string st) {
		short counter = 0;
		for (short i = 0; i < st.length(); i++) {
			if (isupper(st[i]))
				++counter;
		}
		return counter;

	}
	short countUpperLetterInString() {
		return countUpperLetterInString(_value);
	}


	static short countLowerLetterInString(string st) {
		short counter = 0;
		for (short i = 0; i < st.length(); i++) {
			if (islower(st[i]))
				++counter;
		}
		return counter;

	}
	short countLowerLetterInString() {
		return countLowerLetterInString(_value);
	}


	static short countSpecificCharInString(string st,char c) {

		short counter = 0;
		for(short i=0;i<st.length();i++){
			if (st[i] == c)
				++counter;
		}
		return counter;
	}
	short countSpecificCharInString() {
		return countSpecificCharInString(_value, _char);
	}

	static short countSpecificCharInStringMatchCase(string st,char c) {

		short counter = 0;
		for (short i = 0; i < st.length(); i++) {
			if (tolower(st[i]) == tolower(c))
				++counter;
		}
		return counter;
	}
	short countSpecificCharInStringMatchCase() {
		return countSpecificCharInStringMatchCase(_value, _char);
	}

	static bool isVowel(char c) {
		c = tolower(c);
		return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
	}

	static short countVowelInString(string st) {

		short counter = 0;

		for (short i = 0; i < st.length(); i++) {
			if (isVowel(st[i]))
				++counter;
		}
		return counter;
	}
	short countVowelInString() {
		return countVowelInString(_value);
	}

	static void printVowelsInString(string st) {

		for (short i = 0; i < st.length(); i++) {
			if (isVowel(st[i]))
				cout<<st[i]<<' ';
		}
		cout << endl;
	}
	void printVowelsInString() {
		printVowelsInString(_value);
	}

	static vector <string>splitString(string st, string delim = " ") {

		vector <string>splited;
		int pos = 0;
		string subs;
		while ((pos = st.find(delim)) != std::string::npos) {

			subs = st.substr(0, pos);
			if (subs != "")
				splited.push_back(subs);

			st.erase(0, pos + delim.length());
		}
		if (st != "")
			splited.push_back(st);
		return splited;
	}
	vector <string>splitString(string delim=" ") {
		return splitString(_value,delim);
	}



	static short countWordsInString(string st, string delim = " ") {

		
		int pos = 0;
		short counter = 0;
		string subs;
		while ((pos = st.find(delim)) != std::string::npos) {
			subs = st.substr(0, pos);
			if (subs != "")
				++counter;

			st.erase(0, pos + delim.length());
		}
		if (st != "")
			++counter;
		return counter;
	}
	short countWordsInString(string delim=" ") {
		return countWordsInString(_value,delim);
	}

	static string trimLeft(string st) {

		for (int i = 0; i < st.length(); i++) {
			if (st[i] != ' ')
				return st.substr(i, st.length() - i);
		}
		return st;
	}
	string trimLeft()
	{
		return trimLeft(_value);
	}


	static string trimRight(string st) {
		for (int i = st.length() - 1; i >= 0; i--) {
			if(st[i]!=' ')
			return st.substr(0, i+1);
		}
		return st;
	}
	string trimRight() {
		trimRight(_value);
	}

	static string trim(string st) {
		return trimRight(trimLeft(st));
	}
	string trim() {
		return trim(_value);
	}


	static string joinString(vector <string>vSt,string delim=" ") {
		string st = "";
		for (string& s : vSt) {
			st += s + delim;
		}
		return st.substr(0, st.length() - delim.length());
	}
	string joinString(string delim=" ") {
		return joinString(_vSt, delim);
	}

	static string reverseString(string st,string delim=" ") {
	 
		vector <string>vSt=splitString(st,delim);
		vector <string>::iterator iter;
		string rSt="";
		iter = vSt.end();
		while (iter!=vSt.begin()){
			--iter;   //you should make decrment before but the value in rSt because vector.end() points to the value after the last value in vector.
			rSt += *iter+" ";
			
		}
		return rSt.substr(0,rSt.length()-delim.length());
	}

	string reverseString(string delim=" ") {
		return reverseString(_value, delim);
	}

	static string replaceWordInString(string st,string wordtoreplace,string reblacedWord,bool matchCase=true) {

		int pos = 0;

		if (matchCase) {
			while ((pos = st.find(wordtoreplace)) != std::string::npos) {
				
				st = st.replace(pos, wordtoreplace.length(), reblacedWord);

			}
			return st;
		}
		else {
			for (short i = 0; i <st.length(); i++) {
				st[i] = tolower(st[i]);
			}
			for (short i = 0; i < wordtoreplace.length(); i++) {
				wordtoreplace[i] = tolower(wordtoreplace[i]);
			}
			while ((pos = st.find(wordtoreplace)) != std::string::npos) {

				st = st.replace(pos, wordtoreplace.length(), reblacedWord);

			}
			return st;
		}
		
	}
	string replaceWordInString( string wordtoreplace, string reblacedWord,bool matchCase=true) {
		return replaceWordInString(_value, wordtoreplace, reblacedWord,matchCase);
	}


    static string removeAllPunctuationsFromString(string st) {
		string rSt="";
		for (int i = 0; i < st.length(); i++) {
			if (!ispunct(st[i]))
				rSt += st[i];
		}
		return rSt;
	}
	string removeAllPunctuationsFromString()
	{
		return removeAllPunctuationsFromString(_value);
	}

	static string readString() {
		string s1 = "";
		getline(cin >> ws, s1);
		return s1;
	}
	
};


