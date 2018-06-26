#include "Cashier.h"

Cashier::Cashier(){
	init();
}

Cashier::~Cashier(){

}

void Cashier::init(){
	currentCustomer.init();
	serviceTime = 0;
	shiftTime = 0;
	busy = false;
}

void Cashier::setCustomer(Customer c){
	currentCustomer = c;
	serviceTime = c.getServiceTime();
}

void Cashier::setServiceTime(int i){
	serviceTime = i;
}

void Cashier::setShiftTime(int i){
	shiftTime = i;
}

void Cashier::setBusy(bool b){
	busy = b;
}

void Cashier::print(){
	currentCustomer.print();
	cout<<"Service time:"<<serviceTime<<endl;
	cout<<"Shift time:"<<shiftTime<<endl;
	cout<<"busy:";
	if(busy) cout<<"true"<<endl;
	else cout<<"false"<<endl;
}
