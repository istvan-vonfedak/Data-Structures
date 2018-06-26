/*
 * LinkList.h
 *
 *  Created on: Dec 6, 2016
 *      Author: Istvan
 */
/*
int(*compare)(B*,B*)

*/
#ifndef LINKLIST_H_
#define LINKLIST_H_

#include <iostream>
#include "Object.h"

using namespace std;

class LinkList {
protected:
        struct tnode{
                Object *data;
                tnode *next;
                tnode(){
                        data = NULL;
                        next = NULL;
                }
        };
        tnode *front;
        tnode *back;
        int count;
        int total;
        int max;
        void init();
        void clean();
        // void deepCopy(const TQueue<B>&); // TBI
public:
        LinkList();
        virtual~LinkList();
        void clear();
	void shallowClean();
        int length(){return count;}
        void addAtFront(Object*);
        void addAtBack(Object*);
        Object* deleteAtFront();
        Object* deleteAtBack();
        void enqueue(Object*);
        Object* dequeue();
        void push(Object*);
        Object* pop();
        void insert(Object*, bool duplicates = false);
        void insert(Object*, int(*compare)(Object*,Object*));
	Object* remove(Object*);
	Object* search(int i);	
//	Object* search(int i, int(*compare)(Object*, Object*)); // TBI
	void print();
	ostream& print(ostream&);
	
};

#endif /* LINKLIST_H_ */
