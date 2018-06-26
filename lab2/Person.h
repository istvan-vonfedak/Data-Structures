/*
 * Person.h
 *
 *  Created on: Aug 25, 2016
 *      Author: Istvan
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "Date.h"
using namespace std;

class Person{
private:
	int ssn;
	string firstName;
	string lastName;
	Date birthDate;
	int howOld;

public:
	//////////Functions used in lab2////////
	Person();
	void print();
	void setPerson(string ssn, string firstName, string lastName, string birthDate);
	int age(){return howOld;}

	//If you want to do the comparisons without using howOld (the long way)
	//comment out the age function above and uncomment the one below
	//int age(){return birthDate.age();}
	/////////////////////////////////////////

	////////////// More functions //////////
	// one thats pretty cool is setPerson(string s)
	/*


	Person(int ssn, string firstName, string lastName, int birthDate);
	Person(int ssn, string firstName, string lastName, Date birthDate);
	Person(string ssn, string firstName, string lastName, string birthDate);
	Person(string ssn, string firstName, string lastName, Date birthDate);
	Person(int ssn, string fullName, int birthDate);
	Person(int ssn, string fullName, Date birthDate);
	Person(string ssn, string fullName, string birthDate);
	Person(string ssn, string fullName, Date birthDate);
	Person(string s);//sets the person from one string structured in ssn firstName lastName birthDay


	void printNice();

	void setPerson(int ssn, string firstName, string lastName, int birthDate);
	void setPerson(int ssn, string firstName, string lastName, Date birthDate);

	void setPerson(string ssn, string firstName, string lastName, Date birthDate);
	void setPerson(int ssn, string fullName, int birthDate);
	void setPerson(int ssn, string fullName, Date birthDate);
	void setPerson(string ssn, string fullName, string birthDate);
	void setPerson(string ssn, string fullName, Date birthDate);
	void setPerson(string s);//sets the person from one string structured in ssn firstName lastName birthDay

	int getSnn(){return ssn;}
	string getHuman();
	string getFirstName(){return firstName;}
	string getLastName(){return lastName;}
	Date getBirthDate(){ return birthDate;}
	//*/


};

#endif /* PERSON_H_ */

