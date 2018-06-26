#ifndef CASHIER_H_
#define CASHIER_H_
#include "Customer.h"

class Cashier {
protected:
	Customer currentCustomer;
	int serviceTime;
	int shiftTime;
	bool busy;
public:
	Cashier();
	virtual ~Cashier();
	void init();
	int getServiceTime(){return serviceTime;}
	int getCustomerTime(){return (currentCustomer.getDequeueTime() );}
	void setCustomer(Customer);
	void setServiceTime(int);
	void setShiftTime(int);
	void setBusy(bool);
	void print();
	void printCustomer(){currentCustomer.print();}
};


#endif /* CASHIER_H_ */
