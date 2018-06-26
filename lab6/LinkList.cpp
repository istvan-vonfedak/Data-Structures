/*
 * LinkList.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: Istvan
 */

#include "LinkList.h"

LinkList::LinkList(){
	init();
}


LinkList::~LinkList(){
	clear();
}


void LinkList::init(){
	front = NULL;
	back = NULL;
	count = 0;
	total = 0;
	max = 0;
}


void LinkList::clean(){
        tnode *tptr;
        tptr = front;
        while(tptr != NULL){
		tptr = tptr->next;
		front->next = NULL;
                delete front->data;
		delete front;
                front = tptr;
	}
}
void LinkList::shallowClean(){
        tnode *tptr;
	tptr = front;
        while(tptr != NULL){
                tptr = tptr->next;
                front->next = NULL;
                front= NULL;
                front = tptr;
        }
}

void LinkList::clear(){
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

void LinkList::addAtFront(Object* d){
	tnode *n = new tnode;
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


void LinkList::addAtBack(Object* d){
	tnode *n = new tnode;
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


Object* LinkList::deleteAtFront(){
	Object *ret = NULL;
	if(front == NULL) return ret;
	else{
		tnode *temp = front;
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


Object* LinkList::deleteAtBack(){
	Object* ret = NULL;
	if(front == NULL) return ret;
	else{
		tnode *tptr = front;
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


void LinkList::enqueue(Object* d){
	addAtBack(d);
}


Object* LinkList::dequeue(){
	return deleteAtFront();
}


void LinkList::push(Object* d){
	addAtFront(d);
}


Object* LinkList::pop(){
	return deleteAtFront();
}


void LinkList::insert(Object* d, bool duplicates){

	if(!duplicates&&front!=NULL){ //prevents duplicates
		if(d->compare(front->data) == 0) return;
        	else if(d->compare(back->data) == 0) return;
	}
	if(front == NULL){
		tnode *n = new tnode;
		n->data = d;
		n->next = NULL;
		front = n;
		back = n;
		n = NULL;
		count++;
		total++;
		if(max<count) max = count;
	} else if(d->compare(front->data) == -1) {
		addAtFront(d);
	} else if(d->compare(back->data) == 1) {
		addAtBack(d);
	} else {
		if(d->compare(front->data) == 0) return;
		else if(d->compare(back->data) == 0) return;
		tnode *tptr, *fptr;
		tptr = front;
		fptr = NULL;
		do{
			fptr = tptr;
                        tptr = tptr->next;
			if(!duplicates && d->compare(tptr->data) == 0) return; //prevents duplicates		
		}while(d->compare(tptr->data) == 1);
		tnode *n = new tnode;
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


void LinkList::insert(Object* d, int(*compare)(Object*, Object*)){
        if(front == NULL){
                tnode *n = new tnode;
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
                tnode *tptr, *fptr;
                tptr = front->next;
                fptr = front;
                while(compare(d,tptr->data) == 1){
                        fptr = tptr;
                        tptr = tptr->next;
                }
                tnode *n = new tnode;
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

Object* LinkList::remove(Object* d){
	Object * ret = NULL;
        if(front == NULL){
                cerr<<"LinkList:Error: Cannot delete an uninitialized LinkList\n";
        	return ret;
	} else if(d->compare(front->data) == 0) {
                return deleteAtFront();
        } else if(d->compare(back->data) == 0) {
                return deleteAtBack();
        } else {
                tnode *tptr, *fptr;
                tptr = front->next;
		fptr = front;
                while(d->compare(tptr->data) != 0){
                        if(tptr == NULL) return ret;
			fptr = tptr;
                        tptr = tptr->next;
                }
                ret = tptr->data;
                fptr->next = tptr->next;
                tptr->data = NULL;
		tptr->next = NULL;
                tptr = NULL;
                fptr = NULL;
                count--;
		return ret;
        }
}

Object* LinkList::search(int i){
	Object *ret = NULL;
	if(front == NULL){
		cerr<<"LinkList:Error: Cannot return an uninitialized LinkList\n";
		return ret;
	}
	else if(i>=count){
		cerr<<"LinkList:Error: Malloc, Index size is larger than LinkList count\n";	
		return ret;
	}
	else{
		tnode *tptr;
		tptr = front;
		for(int j = 0; j < i; j++){
			tptr = tptr->next;
		}
		ret = tptr->data;
		tptr = NULL;
		return ret;
	}
		
}
 void LinkList::print(){
	if(front!= NULL){
		tnode *tptr = front;
		while(tptr!= NULL){
			tptr->data->print();
			tptr = tptr->next;
		}
		tptr = NULL;
		
	}
	//else cerr<<"LinkList:Error: Cannot print uninitialized list\n";
}


ostream& LinkList::print(ostream &out){
        if(front!= NULL){
                tnode *tptr = front;
                while(tptr!= NULL){
                        tptr->data->print(out);
//			cout<<endl;
                        tptr = tptr->next;
                }
                tptr = NULL;

        }
        //else cerr<<"LinkList:Error: Cannot print uninitialized list\n";
	return out;
}

