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
using namespace std;

class RTime {
private:
	int hours;
	int minutes;
public:
	RTime();
	virtual ~RTime();
	void init();
	void setHours(const int);
	void setMinutes(const int);
	void set(const int, const int);
	void set(const int);
	void set(const string);
	void set(const RTime&);
	void print();
	ostream& print(ostream&);
	istream& read(istream&);
	void operator=(const RTime&);
	friend ostream& operator <<(ostream&, RTime&);
	friend istream& operator >>(istream &in, RTime &t);
};

#endif /* RTIME_H_ */

