/*
 * Date.cpp
 *
 *  Created on: Sep 12, 2016
 *      Author: Istvan
 */
//#include <iomanip>
#include "Date.h"

//////////Functions used for lab2//////////////////////////////////
Date::Date() {
	year = 0;
	month = 0;
	day = 0;
}
int Date::getDate(){
	return ((year *pow(10,4)) + (month *pow(10,2)) + day);
}

void Date::setDate(int d){
	year = d/10000;
	month = (d/100)%100;
	day = d%100;
}

void Date::setDate(string d){
	int temp = string2int(d);
	year = temp/10000;
	month = (temp/100)%100;
	day = temp%100;
}

int Date::age(){
	return getCalendarDate()/10000 - year;
}

void Date::print(){
        cout << setfill('0') << setw(4)<< year;
        cout << setfill('0') << setw(2) << month;
        cout << setfill('0') << setw(2) << day;
}
////////////////////////////////////////////////////////////

////////////// More functions //////////////////////////////
/*
Date::Date(int d) {
	year = d/10000;
	month = (d/100)%100;
	day = d%100;
}
Date::~Date() {

}

void Date::setDate(int d){
	year = d/10000;
	month = (d/100)%100;
	day = d%100;
}

void Date::printNice(){
	cout<<"Day: "<< setfill('0') << setw(2) << day;
	cout << ", Month: " << setfill('0') << setw(2)<< month;
	cout << ", Year: " << setfill('0') << setw(4) << year << endl;
}
//*/



