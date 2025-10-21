#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsString.h"
using namespace std;
class clsUtil
{
public:
	enum enCharTypes { CapitalLetters = 1, smallLetters = 2, Digits = 3, mixChars = 4 };

	static void Srand() {
		srand(unsigned(time(0)));
	}
	static int getRandomNumber(int from, int to) {

		int random = 0;
		return random = rand() % (to - from - 1) + from;
	}
	static char getRandomChar(enCharTypes enchar) {

		if (enchar == enCharTypes::mixChars) {            //important method.
			enchar = (enCharTypes)getRandomNumber(1, 3);
		}
		switch (enchar) {
		case enCharTypes::CapitalLetters:
			return char(getRandomNumber(65, 90));
		case enCharTypes::smallLetters:
			return char(getRandomNumber(97, 122));
		case enCharTypes::Digits:
			return char(getRandomNumber(48, 57));
		default:
			return char(getRandomNumber(65, 90));

		}
	}

	static string generateWord(enCharTypes charType, short numOfLetters) {

		string word = "";
		for (short i = 1; i <= numOfLetters; i++) {
			word += getRandomChar(charType);
		}
		return word;
	}
	static string generateKey(enCharTypes charType) {
		string key = "";
		for (short i = 1; i <= 4; i++) {
			key = generateWord(charType, 8) + '-';

		}
		return key.substr(0, key.length() - 1);
	}
	static void generateKeys(enCharTypes charType, short numOfKeys) {
		for (short i = 1; i <= numOfKeys; i++) {
			cout << "Key[" << i << "]:" << generateKey(charType) << '\n';
		}
	}


	static void fillArrayWithRandomNumbers(int arr[100], int arrLegnth, int from, int to) {

		for (int i = 0; i < arrLegnth; i++) {
			arr[i] = getRandomNumber(from, to);
		}
	}

	static void fillArrayWithRandomWords(string arr[100], int arrLegnth, enCharTypes charType, int wordLegnth) {
		for (int i = 0; i < arrLegnth; i++) {
			arr[i] = generateWord(charType, wordLegnth);
		}
	}

	static void fillArrayWithRandomKeys(string arr[100], int arrLegnth, enCharTypes charType) {
		for (int i = 0; i < arrLegnth; i++) {
			arr[i] = generateKey(charType);
		}
	}


	static void Swap(int& a, int& b) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	static void Swap(double& a, double& b) {
		double temp;
		temp = a;
		b = a;
		a = temp;
	}
	static void Swap(string& a, string& b) {
		string temp;
		temp = a;
		a = b;
		b = temp;
	}
	static void Swap(clsDate& date1, clsDate& date2) {
		clsDate temp;
		temp = date1;
		date1 = date2;
		date2 = temp;
	}
	static void Swap(bool& a, bool& b) {
		bool temp;
		temp = a;
		a = b;
		b = temp;
	}
	static void Swap(char& a, char& b) {
		char temp;
		temp = a;
		a = b;
		b = temp;
	}

	static void shuffleArray(int arr[100], int arrLegnth) {
		for (int i = 0; i < arrLegnth; i++) {
			Swap(arr[i], arr[getRandomNumber(0, arrLegnth - 1)]);
		}
	}

	static void printArray(int arr[100], int arrLegnth) {
		for (int i = 0; i < arrLegnth; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	static void shuffleArray(string arr[100], int arrLegnth) {
		for (int i = 0; i < arrLegnth; i++) {
			Swap(arr[i], arr[getRandomNumber(0, arrLegnth - 1)]);
		}
	}
	static string Tabs(short numOfTabs) {
		string t = "";
		for (short i = 1; i <= numOfTabs; i++) {
			t += '\t';
		}
		return t;
	}

	static string encryptText(string text, short keyEncryption) {
		
		for (int i = 0; i < text.length(); i++) {
			text[i] = char((int)text[i] + keyEncryption);
		}
		return text;
	}
	static string decryptText(string text, short keyEncryption) {

		for (int i = 0; i < text.length(); i++) {
			text[i] = char((int)text[i] - keyEncryption);
		}
		return text;
	}

	static string numberToText(int num) {
		if (num == 0)
			return "";

		if (num >= 1 && num <= 19) {

			string arr[] = { ""," one "," two "," three "," four "," five "," six "," seven "," eight "," nine "
	," ten "," eleven "," twelve "," thirteen "," forteen "," fifteen " ," sixteen " ," seventeen "," eighteen "," nineteen " };

			return arr[num];
		}

		if (num >= 20 && num <= 99) {

			string arr[] = { "",""," twenty "," thirty "," forty "," fifty "," sixty "," seventy "," eightty "," ninty " };

			return arr[num / 10] + numberToText(num % 10);

		}

		if (num >= 100 && num <= 199) {

			return "one Hundred" + numberToText(num % 100);
		}
		if (num >= 200 && num <= 999) {
			return numberToText(num / 100) + " Hundreds " + numberToText(num % 100);
		}

		if (num >= 1000 && num <= 1999) {
			return " one Thousand " + numberToText(num % 1000);
		}
		if (num >= 2000 && num <= 999999) {

			return numberToText(num / 1000) + " Thousands " + numberToText(num % 1000);
		}

		if (num >= 1000000 && num <= 1999999) {
			return " one Million " + numberToText(num % 1000000);
		}
		if (num >= 2000000 && num <= 999999999) {

			return numberToText(num / 1000000) + " Millions " + numberToText(num % 1000000);
		}
		else {
			return "one Billion " + numberToText(num % 1000000000);
		}

	}


	};

