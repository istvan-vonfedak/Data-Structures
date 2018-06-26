#include <stdlib.h>
#include <iostream>
#include "TQueue.cpp"
//#include "support.h"
#include "Customer.h"
#include "Cashier.h"

using namespace std;

int compare(int * a, int *b){
	if(*a < *b) return -1;
	else if(*a > *b) return 1;
	else return 0;
}

int Random(const int start, const int end){
	return(start + random()%(end - start + 1));
}

void printArrival(Customer *n){
	cout<<"Time:"<<time<<":Customer Arrival:";
        n->print();
	n = NULL;
}

void printDequeue(Customer *n){
	cout<<"Time:"<<time<<":Customer Dequeue:";
        n->print();
	n = NULL;
}



void main(){
	cout<<"Started\n";
	int aTR[2] = {1,4}; //arrival time range
	int sTR[2] = {1,4}; // service time range
	int id = 0; // customer ID
	int arrivalTime;
	int serviceTime;
	int time = 0;
	Cashier cashier;
	TQueue<Customer> customerQueue; // Customer queue
	TQueue<Cashier> cashierQueue; // Cashier queue
	
//first Customer arrival
	//1)
	time += Random(1,4);
	Customer *first = new Customer;
	serviceTime = Random(1,4); //2a)
	first->set(id++,time,0,serviceTime);
	//Customer arrival
	printArrival(first);
	customerQueue.enqueue(first);
	first = NULL;
	//Customer Dequeue
	first = customerQueue.dequeue();
	first->setDequeue(time);
	printDequeue(first);
	cashier.setCustomer(*first);//2b)
	cout<<"Time:"<<time<<":Service Start:"; first->print();
	delete first;
	first = NULL;

	while(time<20){
		time += Random(1,4);
		Customer *n = new Customer;
		serviceTime = Random(1,4);
		n->set(id++,time,0,serviceTime);
		printArrival(n);
		customerQueue.enqueue(n);
		n = NULL;
		if(cashier.getServiceTime() <= time){
			cout<<"Time:"<<time<<"Service End:"; cashier.printCustomer();
			n = customerQueue.dequeue();
			printDequeue(n);
			cashier.setCustomer(*n);
			cout<<"Time:"<<time<<"Service Start:"; first->print();
        		delete n;
			n = NULL;
		}
	}
		
/*

	TQueue<int> tint;
	for(int i=0;i<5;i++) {
		int *x = new int;
		*x = i*i;
		tint.insert(x, compare);
	}

	for(int j=0;j<5;j++) {
		int *x;
		x = tint.dequeue();
		cout << x << "," << *x << endl;
		delete x;
	}
*/
}
