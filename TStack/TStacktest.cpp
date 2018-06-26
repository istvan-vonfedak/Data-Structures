//============================================================================
// Name        : TStacktest.cpp
// Author      : NMJ
// Version     :
// Copyright   : © Nigel John
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "TStack.cpp"

int main() {
	cout << "Started" << endl; // prints Started

	TStack<int> tint;

	for(int i=0;i<5;i++) {
		int *x = new int;
		*x = i*i;
		tint.push(x);
	}

	for(int j=0;j<5;j++) {
		int *x;
		x = tint.pop();
		cout << x << "," << *x << endl;
		delete x;
	}

	TStack<double> tdoub;

	for(int i=0;i<5;i++) {
		double *x = new double;
		*x = i*i+0.5;
		tdoub.push(x);
	}

	for(int j=0;j<5;j++) {
		double *x;
		x = tdoub.pop();
		cout << x << "," << *x << endl;
		delete x;
	}


	return 0;
}
