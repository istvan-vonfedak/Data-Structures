/*
 * TStack.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: nigel
 */

#include <iostream>
using namespace std;

template<class A>
struct tnode {
	A *data;
	tnode *next;

	tnode();
};

template<class A>
tnode<A>::tnode() {
	data = NULL;
	next = NULL;
}

template<class B>
class TStack {
private:
	tnode<B> *top;
	int count;

public:
	TStack();
	virtual ~TStack();

	void push(B*);
	B *pop();
};

template<class B>
TStack<B>::TStack() {
	top = NULL;
	count = 0;
}

template<class B>
TStack<B>::~TStack() {
	tnode<B> *tp;
	tp = top;
	while(tp!=NULL) {
		top = top->next;
		tp->next = NULL;
		delete tp->data;
		delete tp;
	}
}

template<class B>
void TStack<B>::push(B *d) {
	if (d!=NULL) {
		tnode<B> *n = new tnode<B>;
		n->data = d;
		n->next = top;
		top = n;
		count++;
	}
}

template<class B>
B *TStack<B>::pop() {
	B *ret = NULL;
	if (top!=NULL) {
		ret = top->data;
		tnode<B> *tp = top;
		top = top->next;
		tp->data = NULL;
		delete tp;
	}
	return ret;
}
