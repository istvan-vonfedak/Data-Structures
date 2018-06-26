/*
 * Object.h
 *
 *  Created on: Nov 29, 2016
 *      Author: nigel
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <iostream>
#include <string>
using namespace std;

class Object {
private:
	string name;
public:
	Object();
	virtual ~Object();

	void setName(string n) { name = n; }
	string getName() { return name; }

	virtual void print()=0; // pure abstract
	virtual ostream& print(ostream&)=0;
	virtual void write() { cout << "Object" << endl; }
	virtual int compare(Object *)= 0;
};

#endif /* OBJECT_H_ */
