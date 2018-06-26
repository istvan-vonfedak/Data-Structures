#include "Customer.h"

Customer::Customer(){
	init();
}

Customer::~Customer(){

}

void Customer::init(){
	customerID = 0;
	enqueueTime = 0;
	dequeueTime = 0;
	serviceTime = 0;
}

void Customer::set(int i, int e, int d, int s){
	setID(i);
	setEnqueue(e);
	setDequeue(d);
	setService(s);
}

void Customer::print(){
	cout<<"Customer[id:"<<customerID<<", equeue:"<<enqueueTime;
	cout<<", dequeue:"<<dequeueTime<<", service:"<<serviceTime<<"]\n";
}
/*
void Customer::start(){
	equeueTime = getCPUTime();
}

int Customer::end(){
	dequeueTime = getCPUTime
	return dequeue-enqueueTime;
}
*/
