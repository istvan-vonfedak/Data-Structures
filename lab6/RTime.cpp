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
	hours = 0;
	minutes = 0;
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

void RTime::addRuntime(const RTime& rt){
	if(minutes + rt.minutes > 59){
		int temp = minutes;
		minutes = (temp +rt.minutes)%60;
		hours +=(temp +rt.minutes)/60;
	} else { 
		minutes += rt.minutes;
	}
	hours += rt.hours;
}

void RTime::addRuntime(const int i){
	RTime temp;
	temp.set(i);
	addRuntime(temp);
}

int RTime::compare(Object* obj){
	RTime* rt = dynamic_cast< RTime* >(obj);
	if(rt == NULL){
		cerr<<"RTime:: Error comparing NULL pointer\n"; 
		return 1;
	}
	if(hours == rt->hours && minutes == rt->minutes) return 0;
	else if(hours < rt->hours) return -1;
	else if(minutes < rt->minutes)return -1;
	else return 1;
}

int RTime::compare(const RTime& rt){
        if(hours == rt.hours && minutes == rt.minutes) return 0;
        else if(hours < rt.hours) return -1;
        else if(minutes < rt.minutes)return -1;
        else return 1;
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

void RTime::read(){
	int t;
	cout<<"Runtime                   ~>";
        cin>>t;
        set(t);
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

