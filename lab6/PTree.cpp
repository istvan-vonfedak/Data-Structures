/*
 * PTree.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: istvan
 */

#include "PTree.h"

PTree::PTree() {
	init();
}

PTree::~PTree() {
	clear();
}

void PTree::init(){
	root = NULL;
	count = 0;
}

void PTree::clear_r(bnode *r){
	if(r!=NULL){
		clear_r(r->right);
		clear_r(r->left);
		delete r;
	}
}

void PTree::clear(){
	clear_r(root);
	init();
}		

PTree::bnode* PTree::addNode_r(bnode *r,Object* d) {

	if (r==NULL) {
		bnode *n = new bnode;
		n->data = d;
		n->left = NULL;
		n->right = NULL;
		return n;
	} else {
		if (r->data->compare(d) == -1) r->right = addNode_r(r->right,d);
		else if (r->data->compare(d) == 1) r->left = addNode_r(r->left,d);
		return r;
	}

}
void PTree::print_ra(bnode *r){
        if (r!=NULL) {
                print_ra(r->left);
                r->data->print(); //out<<endl;
                print_ra(r->right);
        }
}
void PTree::print_rd(bnode *r){
        if (r!=NULL) {
                print_rd(r->right);
                r->data->print(); //out << endl;
                print_rd(r->left);
        }
}

void PTree::print_ra(bnode *r, ostream &out){
	if (r!=NULL) {
		print_ra(r->left, out);
		r->data->print(out); //out<<endl;
		print_ra(r->right,out);
	}
}
void PTree::print_rd(bnode *r, ostream &out){
	if (r!=NULL) {
		print_rd(r->right, out);
		r->data->print(out); //out << endl;
		print_rd(r->left,out);
	}
}

void PTree::print_rpr(bnode *r, ostream &out){
	if (r!=NULL) {
		r->data->print(out); //out << endl;
		print_rpr(r->left, out);
		print_rpr(r->right,out);
	}
}

void PTree::print_rpo(bnode *r, ostream &out){
	if (r!=NULL) {
		print_rpo(r->left, out);
		print_rpo(r->right,out);
		r->data->print(out); //out << endl;
	}
}

int PTree::depth_r(bnode *r) {
	if (r==NULL) {
		return 0;
	} else {
		int dleft = depth_r(r->left);
		int dright = depth_r(r->right);
		if (dleft<dright) return dright+1;
		else return dleft+1;
	}
}

void PTree::addNode(Object* d) {
	root = addNode_r(root,d);
	count++;
}

Object* PTree::search_r(bnode* r, Object* d){
        if(r!=NULL){
                if(r->data->compare(d) == 0) return r->data;
                else if (r->data->compare(d) == -1) return search_r(r->right,d);
                else return search_r(r->left,d);
        }
        else return NULL;
}

Object* PTree::search(Object *d){
	return search_r(root,d);
}
ostream &PTree::print(ostream &out, bool ascending) {
	if(root == NULL)cerr<<"PTree:Error: Cannot print uninitialized PTree\n";
	else{
		if(ascending) print_ra(root,out);
		else print_rd(root,out);
		return out;
	}
}

void PTree::print(bool ascending) {
	if(root == NULL)cerr<<"PTree:Error: Cannot print uninitialized PTree\n";
        else{
                if(ascending) print_ra(root);
                else print_rd(root);
	}
}
