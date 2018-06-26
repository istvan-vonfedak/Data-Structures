/*
 * RTime.h
 *
 *  Created on: Oct 24, 2016
 *      Author: Istvan
 */

#ifndef RTIME_H_
#define RTIME_H_

#include <iostream>
#include <fstream>
#include "Object.h"
using namespace std;

class RTime: public Object {
private:
	int hours;
	int minutes;
public:
	RTime();
	virtual ~RTime();
	void init();
	int time(){ return hours*100+minutes; } 
	void setHours(const int);
	void setMinutes(const int);
	void set(const int, const int);
	void set(const int);
	void set(const string);
	void set(const RTime&);
	void addRuntime(const RTime&);
	void addRuntime(const int);
	void print();
	void read();
	int compare(Object*);
	int compare(const RTime&);
	ostream& print(ostream&);
	istream& read(istream&);
	void operator=(const RTime&);
	friend ostream& operator <<(ostream&, RTime&);
	friend istream& operator >>(istream &in, RTime &t);
};

#endif /* RTIME_H_ */

