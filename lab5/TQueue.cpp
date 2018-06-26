#include <iostream>
using namespace std;

template <class A>
struct tnode{
        A *data;
        tnode *next;
        tnode();
};

template <class A>
tnode<A>::tnode(){
        data = NULL;
        next = NULL;
}
/////////////////////////////////////
template <class B>
class TQueue {
protected:
        tnode<B> *front;
        tnode<B> *back;
        int count;
	int total;
	int max;
	void init();
        void clean();
	// void deepCopy(const TQueue<B>&); // TBI
public:
        TQueue();
        virtual~TQueue();
	void clear();
	int getLength(){return count;}
	void addAtFront(B*);
	void addAtBack(B*);
	B* deleteAtFront();
	B* deleteAtBack();
        void enqueue(B*);
        B* dequeue();
	void push(B*);
	B* pop();
	void insert(B*);
	void insert(B*, int(*compare)(B*,B*));
};
/////////////////////////////////////
template <class B>
TQueue<B>::TQueue(){
	init();
}

template <class B>
TQueue<B>::~TQueue(){
	clean();
}
template <class B>
void TQueue<B>::init(){
	front = NULL;
	back = NULL;
	count = 0;
	total = 0;
	max = 0;
}

template <class B>
void TQueue<B>::clean(){
        tnode<B> *tptr;
        tptr = front;
        while(tptr != NULL){
		tptr = tptr->next;
		front->next = NULL;
                delete front->data;
		delete front;
                front = tptr;
	}
}

template<class B>
void TQueue<B>::clear(){
	clean();
	init();
}
/*
template <class B>
void TQueue<B>::deepCopy(const TQueue<B> & tq){
	if(tq.front == NULL) init();
	else{
		if(front!=NULL) clear();
		tnode<B> *tptr = tq.front;
		while(tptr->next != NULL){	
			B* temp = new B;
			*temp = *tptr->data;
			addAtBack(temp);
			temp = NULL;
			tptr = tptr->next;
		}
	}
}
*/
template <class B>
void TQueue<B>::addAtFront(B* d){
	tnode<B> *n = new tnode<B>;
	n->data = d;
	n->next = NULL;
	if(front == NULL){
		front = n;
		back = n;
	} else {
		n->next = front;
		front = n;
	}
	count++;
	total++;
	if(max<count) max = count;
	n = NULL;
}

template <class B>
void TQueue<B>::addAtBack(B* d){
	tnode<B> *n = new tnode<B>;
	n->data = d;
	n->next = NULL;
	if(front == NULL){
		front = n;
		back = n;
	} else {
		back->next = n;
		back = n;
	}
	count++;
	total++;
	if(max<count) max = count;
	n = NULL;
}

template <class B>
B* TQueue<B>::deleteAtFront(){
	B *ret = NULL;
	if(front == NULL) return ret;
	else{
		tnode<B> *temp = front;
		front = front->next;
		ret = temp->data;
		temp->data = NULL;
		temp->next = NULL;
		delete temp;
		temp = NULL;
		count--;
	}
	return ret;
}

template <class B>
B* TQueue<B>::deleteAtBack(){
	B* ret = NULL;
	if(front == NULL) return ret;
	else{
		tnode<B> *tptr = front;
		ret = back->data;
		back->data = NULL;
		while(tptr->next != back){
			tptr = tptr->next;
		}
		tptr->next = NULL;
		delete back;
		back = tptr;
		tptr = NULL;
		count--;
	}
	return ret;
}				

template <class B>
void TQueue<B>::enqueue(B* d){
	addAtBack(d);
}

template <class B>
B* TQueue<B>::dequeue(){
	return deleteAtFront();
}

template<class B>
void TQueue<B>::push(B* d){
	addAtFront(d);
}

template<class B>
B* TQueue<B>::pop(){
	return deleteAtFront();
}

template<class B>
void TQueue<B>::insert(B* d){
	if(front == NULL){
		tnode<B> *n = new tnode<B>;
		n->data = d;
		n->next = NULL;
		front = n;
		back = n;
		n = NULL;
		count++;
		total++;
		if(max<count) max = count;
	} else if(d->compare(*front->data) == -1) {
		addAtFront(d);
	} else if(d->compare(*back->data) == 1) {
		addAtBack(d);
	} else {
		tnode<B> *tptr, *fptr;
		tptr = front->next;
		fptr = front;
		while(d->compare(*tptr->data) == 1){
			fptr = tptr;
			tptr = tptr->next;
		}
		tnode<B> *n = new tnode<B>;
		n->data = d;
		fptr->next = n;
                n->next = tptr;
                n = NULL;
                tptr = NULL;
                fptr = NULL;
		count++;
		total++;
		if(max<count) max = count;
	}
}

template<class B>
void TQueue<B>::insert(B* d, int(*compare)(B*, B*)){
        if(front == NULL){
                tnode<B> *n = new tnode<B>;
                n->data = d;
                n->next = NULL;
                front = n;
                back = n;
                n = NULL;
                count++;
		total++;
		if(max<count) max = count;
        } else if(compare(d,front->data) == -1) {
                addAtFront(d);
        } else if(compare(d,back->data) == 1) {
                addAtBack(d);
        } else {
                tnode<B> *tptr, *fptr;
                tptr = front->next;
                fptr = front;
                while(compare(d,tptr->data) == 1){
                        fptr = tptr;
                        tptr = tptr->next;
                }
                tnode<B> *n = new tnode<B>;
                n->data = d;
                fptr->next = n;
                n->next = tptr;
                n = NULL;
                tptr = NULL;
                fptr = NULL;
                count++;
		total++;
		if(max<count) max = count;
        }
}
