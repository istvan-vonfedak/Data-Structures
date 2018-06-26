/*
 * Date.h
 *
 *  Created on: Sep 12, 2016
 *      Author: Istvan
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
//#include <iomanip>
#include <string>
#include "support.h"

using namespace std;

class Date {
private:
	int year, month, day;

public:
	//////////code used for lab2////////////
	Date();
	int getDate();
	void setDate(int);
	void setDate(string YYYYMMDD);
	int age();
	void print():
	////////////////////////////////////////

	////////////// More functions //////////
	/*
	Date(int YYYYMMDD);
	virtual ~Date();
	void setDate(int YYYYMMDD);

	int getYear(){return year;}
	int getMonth(){return month;};
	int getDay(){return day;}

	void printNice();
	//*/
};


#endif /* DATE_H_ */

