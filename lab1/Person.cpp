/*
 * Person.cpp
 *
 *  Created on: Aug 25, 2016
 *      Author: Istvan
 */

#include "Person.h"

Person::Person(){
	firstName =  "N/A";
	lastName = "N/A";
}

Person::Person(string fn, string ln){
	firstName =  fn;
	lastName = ln;
}

Person::Person(string s){
	/*Last name converter
		 * Finds the last word of a full name and makes it the last name
		 * Ex: full name: Istvan von Fedak --> first name: Istvan von ; last name: Fedak
		 * Future updates: make it identify composite last names
		 */

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

void Person::print(){
	cout<< lastName << ", " << firstName<<endl;
}

void Person::setPerson(string fn, string ln){
	firstName =  fn;
	lastName = ln;
}

void Person::setPerson(string s){
	/*Last name converter
	 * Finds the last word of a full name and makes it the last name
	 * Ex: full name: Istvan von Fedak --> first name: Istvan von ; last name: Fedak
	 * Future updates: make it identify composite last names
	 */
	firstName = "", lastName = ""; // resets the name from the default constructor

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

string Person::getPerson(){
	return firstName +" "+ lastName;
}

