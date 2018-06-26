/*
 * Person.cpp
 *
 *  Created on: Aug 25, 2016
 *      Author: Istvan
 */

#include "Person.h"
//////////Functions used in lab2////////
Person::Person(){
	ssn = 0;
	firstName =  "N/A";
	lastName = "N/A";
	birthDate.setDate(0);
	howOld = 0;
}
void Person::print(){
	cout<< ssn <<" "<< firstName << " " << lastName << " " << birthDate.getDate() << endl;
}
void Person::setPerson(string soNum, string fn, string ln, string bDay){
	ssn = string2int(soNum);
	firstName =  fn;
	lastName = ln;
	birthDate.setDate(bDay);
	howOld = (getCalendarDate()/10000) - (string2int(bDay)/10000);
}
////////////////////////////////////////
////////////// More functions //////////
// one thats pretty cool is setPerson(string s)
/*

Person::Person(int soNum, string fn, string ln, int bDay){

	ssn = soNum;
	firstName =  fn;
	lastName = ln;
	birthDate.setDate(bDay);
	howOld = 0;
}
Person::Person(int soNum, string fn, string ln, Date bDay){

	ssn = soNum;
	firstName =  fn;
	lastName = ln;
	birthDate = bDay;
	howOld = 0;
}
Person::Person(string soNum, string fn, string ln, string bDay){
	ssn = string2int(soNum);
	firstName =  fn;
	lastName = ln;
	birthDate.setDate(bDay);
	howOld = 0;
}
Person::Person(string soNum, string fn, string ln, Date bDay){
	ssn = string2int(soNum);
	firstName =  fn;
	lastName = ln;
	birthDate = bDay;
	howOld = 0;
}
Person::Person(int soNum,string s, int bDay){
	ssn = soNum;
	birthDate.setDate(bDay);
	howOld = 0;
	//splitting the name;
	int lastSpaceIndex; // this int defines the index of the " " that separates the last name from the first name.
	for(int i = s.length(); 0<=i;i--){
		if(s[i] == ' '){//starts at the last index of the full name string and stops when it find the last " "
			lastSpaceIndex = i;//redefines the index of where the " " is.
			while(i < s.length()){//records the last name
				lastName += s[i+1];
				i++;
			}
			for(int j = 0; j < lastSpaceIndex; j++){//records the first name
				firstName += s[j];
			}
			break;
		}
	}
}
Person::Person(int soNum,string s, Date bDay){
	ssn = soNum;
	birthDate = bDay;
	howOld = 0;
	//splitting the name;
	int lastSpaceIndex; // this int defines the index of the " " that separates the last name from the first name.
	for(int i = s.length(); 0<=i;i--){
		if(s[i] == ' '){//starts at the last index of the full name string and stops when it find the last " "
			lastSpaceIndex = i;//redefines the index of where the " " is.
			while(i < s.length()){//records the last name
				lastName += s[i+1];
				i++;
			}
			for(int j = 0; j < lastSpaceIndex; j++){//records the first name
				firstName += s[j];
			}
			break;
		}
	}
}
Person::Person(string soNum,string s, string bDay){
	ssn = string2int(soNum);
	birthDate.setDate(bDay);
	howOld = 0;
	//splitting the name
	int lastSpaceIndex; // this int defines the index of the " " that separates the last name from the first name.
	for(int i = s.length(); 0<=i;i--){
		if(s[i] == ' '){//starts at the last index of the full name string and stops when it find the last " "
			lastSpaceIndex = i;//redefines the index of where the " " is.
			while(i < s.length()){//records the last name
				lastName += s[i+1];
				i++;
			}
			for(int j = 0; j < lastSpaceIndex; j++){//records the first name
				firstName += s[j];
			}
			break;
		}
	}
}
Person::Person(string soNum,string s, Date bDay){
	ssn = string2int(soNum);
	birthDate = bDay;
	howOld = 0;
	//splitting the name
	int lastSpaceIndex; // this int defines the index of the " " that separates the last name from the first name.
	for(int i = s.length(); 0<=i;i--){
		if(s[i] == ' '){//starts at the last index of the full name string and stops when it find the last " "
			lastSpaceIndex = i;//redefines the index of where the " " is.
			while(i < s.length()){//records the last name
				lastName += s[i+1];
				i++;
			}
			for(int j = 0; j < lastSpaceIndex; j++){//records the first name
				firstName += s[j];
			}
			break;
		}
	}
}
Person::Person(string s){
	//This function splits a string in the format ssn firstName lastName YYYYMMDD
	//and stores it into the class Person.

	//local temporary variables
	howOld = 0;
	string ssNum,lName, fName, dob;

	bool sNum = true, fn = true, ln = true;
	for(int i = 0; i < s.length(); i++){
		if(sNum){
			if(s[i] == ' ') sNum = false;
			else ssNum += s[i];
		}
		else if(fn){
			if(s[i] == ' ') fn = false;
			else fName += s[i];
		}
		else if(ln){
			if(s[i] == ' ') ln = false;
			else lName += s[i];
		}
		else{
			dob += s[i];
		}
	}
	ssn = string2int(ssNum), firstName = fName, lastName = lName, birthDate.setDate(dob);
}


void Person::printNice(){
	cout<< ssn <<" "<< lastName << ", " << firstName << " " << birthDate.getDate() << endl;
}

void Person::setPerson(int soNum, string fn, string ln, int bDay){

	ssn = soNum;
	firstName =  fn;
	lastName = ln;
	birthDate.setDate(bDay);
}
void Person::setPerson(int soNum, string fn, string ln, Date bDay){

	ssn = soNum;
	firstName =  fn;
	lastName = ln;
	birthDate = bDay;
}

void Person::setPerson(string soNum, string fn, string ln, Date bDay){
	ssn = string2int(soNum);
	firstName =  fn;
	lastName = ln;
	birthDate = bDay;
}
void Person::setPerson(int soNum,string s, int bDay){
	ssn = soNum;
	birthDate.setDate(bDay);
	//splitting the name;
	int lastSpaceIndex; // this int defines the index of the " " that separates the last name from the first name.
	for(int i = s.length(); 0<=i;i--){
		if(s[i] == ' '){//starts at the last index of the full name string and stops when it find the last " "
			lastSpaceIndex = i;//redefines the index of where the " " is.
			while(i < s.length()){//records the last name
				lastName += s[i+1];
				i++;
			}
			for(int j = 0; j < lastSpaceIndex; j++){//records the first name
				firstName += s[j];
			}
			break;
		}
	}
}
void Person::setPerson(int soNum,string s, Date bDay){
	ssn = soNum;
	birthDate = bDay;
	//splitting the name;
	int lastSpaceIndex; // this int defines the index of the " " that separates the last name from the first name.
	for(int i = s.length(); 0<=i;i--){
		if(s[i] == ' '){//starts at the last index of the full name string and stops when it find the last " "
			lastSpaceIndex = i;//redefines the index of where the " " is.
			while(i < s.length()){//records the last name
				lastName += s[i+1];
				i++;
			}
			for(int j = 0; j < lastSpaceIndex; j++){//records the first name
				firstName += s[j];
			}
			break;
		}
	}
}
void Person::setPerson(string soNum,string s, string bDay){
	ssn = string2int(soNum);
	birthDate.setDate(bDay);
	//splitting the name
	int lastSpaceIndex; // this int defines the index of the " " that separates the last name from the first name.
	for(int i = s.length(); 0<=i;i--){
		if(s[i] == ' '){//starts at the last index of the full name string and stops when it find the last " "
			lastSpaceIndex = i;//redefines the index of where the " " is.
			while(i < s.length()){//records the last name
				lastName += s[i+1];
				i++;
			}
			for(int j = 0; j < lastSpaceIndex; j++){//records the first name
				firstName += s[j];
			}
			break;
		}
	}
}
void Person::setPerson(string soNum,string s, Date bDay){
	ssn = string2int(soNum);
	birthDate = bDay;
	//splitting the name
	int lastSpaceIndex; // this int defines the index of the " " that separates the last name from the first name.
	for(int i = s.length(); 0<=i;i--){
		if(s[i] == ' '){//starts at the last index of the full name string and stops when it find the last " "
			lastSpaceIndex = i;//redefines the index of where the " " is.
			while(i < s.length()){//records the last name
				lastName += s[i+1];
				i++;
			}
			for(int j = 0; j < lastSpaceIndex; j++){//records the first name
				firstName += s[j];
			}
			break;
		}
	}
}
void Person::setPerson(string s){
	//This function splits a string in the format ssn firstName lastName YYYYMMDD
	//and stores it into the class Person.

	//local temporary variables
	string ssNum,lName, fName, dob;

	bool sNum = true, fn = true, ln = true;
	for(int i = 0; i < s.length(); i++){
		if(sNum){
			if(s[i] == ' ') sNum = false;
			else ssNum += s[i];
		}
		else if(fn){
			if(s[i] == ' ') fn = false;
			else fName += s[i];
		}
		else if(ln){
			if(s[i] == ' ') ln = false;
			else lName += s[i];
		}
		else{
			dob += s[i];
		}
	}
	ssn = string2int(ssNum), firstName = fName, lastName = lName, birthDate.setDate(dob);
}

string Person::getHuman(){
	return firstName +" "+ lastName;
}
//*/

