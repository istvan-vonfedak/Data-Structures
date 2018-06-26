/*
* Author: Istvan
* Date Created: 11/6/2016
* Name: Customer.h
*/

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <iostream>
#include "support.h"
using namespace std;

class Customer{
protected:
	int customerID;
	int enqueueTime;
	int dequeueTime;
	int serviceTime;
public:
	Customer();
	virtual ~Customer();
	void init();
	int getServiceTime(){return serviceTime;}
	int getDequeueTime(){return dequeueTime;}
	void setID(const int i){customerID = i;}
	void setEnqueue(const int e){enqueueTime = e;}
	void setDequeue(const int d){dequeueTime = d;}
	void setService(const int s){serviceTime = s;}
	void set(const int i,const int e,const int d,const int s);
	void print();
//	void start();//gets the cpu time when arriving 
//	int end();// returns ((end cpu time)-(start cpu time)) when its dequeued
};


#endif /* CUSTOMER_H_ */
