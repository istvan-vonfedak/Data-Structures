/*
 * PTree.h
 *
 *  Created on: Dec 6, 2016
 *      Author: Istvan
 */

#ifndef PTREE_H_
#define PTREE_H_

#include "Object.h"
#include <iostream>
#include <string>
using namespace std;

class PTree {
protected:
	struct bnode {
		Object *data;
		bnode *left, *right;
		bnode(){
			data = NULL;
			left = NULL;
			right = NULL;
		}
		~bnode(){
			delete data;
		}		
	};

	bnode *root;
	int count;
	void init();
	void clear_r(bnode *);
	int depth_r(bnode *);
	Object* search_r(bnode*, Object*);
	bnode* addNode_r(bnode *,Object*);

	void print_ra(bnode*);
	void print_rd(bnode*);
	void print_ra(bnode *, ostream&);
	void print_rd(bnode *, ostream&);

	void print_rpo(bnode *, ostream&);
	void print_rpr(bnode *, ostream&);
public:
	PTree();
	virtual ~PTree();
	void clear();
	void addNode(Object*);
	Object* search(Object*);
	int depth() { return depth_r(root); }
	int size() { return count; }
	ostream &print(ostream&, bool ascending=true);
	void print(bool ascending=true);
};

#endif /* PTREE_H_ */
