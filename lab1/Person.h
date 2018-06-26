/*
 * Person.h
 *
 *  Created on: Aug 25, 2016
 *      Author: Istvan
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
using namespace std;

struct Person{
	string firstName;
	string lastName;

	Person();
	Person(string firstName, string lastName);
	Person(string fullName);

	void print();
	void setPerson(string firstName, string lastName);
	void setPerson(string s);//Gets the last word of a full name and makes it a last name
	string getPerson(); // returns last name, first name
};

#endif /* PERSON_H_ */
