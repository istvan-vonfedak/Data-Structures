/*
 * RTime.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: Istvan
 */

#include "RTime.h"

RTime::RTime(){
	init();
}
RTime::~RTime(){

}

void RTime::init(){
	hours = -1;
	minutes = -1;
}

void RTime::setHours(const int h){
	hours = h;
}
void RTime::setMinutes(const int m){
	minutes = m;
}

void RTime::set(const int h, const int m){
	setHours(h);
	setMinutes(m);
}

void RTime::set(const int hm){
	if(hm>60){
		setHours(hm/100);
		setMinutes(hm%100);
	} else {
		setHours(0);
		setMinutes(hm);
	}
}
void RTime::set(const string s){
	const int hm = atol(s.c_str());
	if(hm>60){
		setHours(hm/100);
		setMinutes(hm%100);
	} else {
		setHours(0);
		setMinutes(hm);
	}
}

void RTime::set(const RTime& rt){
	set(rt.hours, rt.minutes);
}

void RTime::print(){
	if(hours>1){

		if(minutes > 1 || minutes==0) cout<<hours<<" hours, "<<minutes<<" minutes"<<endl;
		else cout<<hours<<" hours, "<<minutes<<" minute"<<endl;
	} else{
		if(minutes > 1 || minutes==0) cout<<hours<<" hour, "<<minutes<<" minutes"<<endl;
		else cout<<hours<<" hours, "<<minutes<<" minute"<<endl;
	}
}

ostream& RTime::print(ostream &out){
	if(hours<=0) {
		out<<minutes;
	} else if (minutes<10) {
		out<<hours<<"0"<<minutes;
	}
	else out<<hours<<minutes;
	return out;
}

istream& RTime::read(istream &in){
	int temp;
	in>>temp;
	set(temp);
	return in;
}

void RTime::operator=(const RTime &rt){
	set(rt);
}

ostream& operator <<(ostream &out, RTime &t){
	t.print(out);
	return out;
}

istream& operator >>(istream &in, RTime &t){
	t.read(in);
	return in;
}

