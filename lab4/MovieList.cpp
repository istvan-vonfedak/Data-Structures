/*
 * MovieList.cpp
 *
 *  Created on: Oct 25, 2016
 *      Author: Istvan
 */

#include "MovieList.h"

MovieList::MovieList() {
	init();
}

MovieList::~MovieList() {
	clear();
}

void MovieList::init(){
	front = NULL;
	back = NULL;
	length = -1;
}

void MovieList::clear(){
	if(front != NULL){
		node *tptr;
		tptr = front;
		while(tptr != NULL){ //tptr->next
			front = front->next;
			tptr->movie->clear();
			delete tptr->movie;
			delete tptr;
			tptr = front;
		}
	}
	init();
}

void MovieList::addAtFront(Movie *m){
	if(m == NULL) cerr<< "Error:MovieList: Cannot addAtFront an uninitialized movie pointer.\n";
	else {
		node *n = new node;
		n->movie = new Movie;
		n->movie->set(*m);
		n->next = NULL;
		//if empty
		if(front==NULL){
			front = n;
			back = n;
			length++;
		} else{
			n->next = front;
			front = n;
			length++;
		}
	}
}

void MovieList::addAtBack(Movie*m){
	if(m == NULL) cerr<< "Error:MovieList: Cannot addAtBack an uninitialized movie pointer.\n";
	else{
		node *n = new node;
		n->movie = new Movie;
		n->movie->set(*m);
		n->next = NULL;
		//if empty
		if(front == NULL){
			front = n;
			back = n;
			length++;
		} else {
			back->next = n;
			back = n;
			length++;
		}
	}
}

void MovieList::addMovie(Movie *m){
	if(m == NULL) cerr<< "Error:MovieList: Cannot addMovie an uninitialized movie pointer.\n";
	else{	
		//if empty
		if(front == NULL){
			node *n = new node;
			n->movie = new Movie;
			n->movie->set(*m);
			n->next = NULL;
	
			front = n;
			back = n;
			length++;
		//1 means internal title is larger than m's title
		} else if (front->movie->compare(m)==1) {
			addAtFront(m);
		} else if (back->movie->compare(m)==-1) {
			addAtBack(m);
		} else {
			node *n = new node;
			n->movie = new Movie;
			n->movie->set(*m);
			n->next = NULL;
	
			node *tptr, *fptr;
			tptr = front;
			fptr = NULL;
			while(tptr->movie->compare(m)==-1){
				fptr = tptr;
				tptr=tptr->next;
			}
			n->next = fptr->next;
			fptr->next = n;
			length++;
		}
	}
}
void MovieList::removeAtFront(){
	if(front == NULL) cerr<<"Error:MovieList: Cannot removeAtFront if MovieList is uninitialized\n";
	else{
		node *tptr;
		tptr = front->next;
		delete front;
		front = tptr;
		tptr = NULL;
		length --;
	}
}

void MovieList::removeAtBack(){
	if(front == NULL) cerr<<"Error:MovieList: Cannot removeAtBack if MovieList is uninitialized\n";
	else{
		node *tptr, *fptr;
		tptr = front;
		fptr = NULL;
		while(tptr->next != NULL){
			fptr = tptr;
			tptr = tptr->next;
		}
		delete tptr;
		fptr->next = NULL;
		back = fptr;
		tptr = NULL;
		fptr = NULL;
		length--;
	}

}
void MovieList::removeMovie(const string t){
	if(front==NULL) cerr<<"Error:MovieList: Cannot removeMovie if MovieList is uninitialized\n";
	else {
		if(front->movie->getTitle() == t) {
			 removeAtFront();
		} else if(back->movie->getTitle() == t) {
			removeAtBack();
		} else { 
			node *tptr, *fptr;
			tptr = front;
			fptr = NULL;
			while(tptr->movie->getTitle() != t){
				fptr = tptr;
				tptr = tptr->next;
			}
			fptr->next = tptr->next;
			delete tptr;
			tptr=NULL;
			fptr=NULL;
		}
	}
}

void MovieList::removeAllMovies(){
	clear();
}

void MovieList::addRating(const string t, const Rating &r){
	node *tptr;
	tptr = front;
	while(tptr->movie->getTitle() != t){
		tptr= tptr->next;
	}
	tptr->movie->addRating(r);
}

void MovieList::deleteRating(const string t, const Rating &r){
	node *tptr;
	tptr = front;
	while(tptr->movie->getTitle() != t){
		tptr = tptr->next;
	}
	tptr->movie->deleteRating(r);
}

void MovieList::printMovie(const string t){
	if(front==NULL){
		cerr<<"Error:MovieList: Cannot print an uninitialized MovieList\n";
	} else {
		node *tptr;
		tptr = front;
		while(tptr->movie->getTitle() != t){
			tptr = tptr->next;
		}
		tptr->movie->print();
	}
}

ostream& MovieList::printMovie(ostream& out, const string t){
	if(front==NULL){
		cerr<<"Error:MovieList: Cannot print an uninitialized MovieList\n";
	} else {
		node *tptr;
		tptr = front;
		while(tptr->movie->getTitle() != t){
			tptr = tptr->next;
		}
		tptr->movie->print(out);
	}
	return out;
}

void MovieList::print(){
	if(front==NULL){
		cerr<<"Error:MovieList: Cannot print an uninitialized MovieList\n";
	} else {
		node *tptr;
		tptr = front;
		while(tptr != NULL){
			tptr->movie->print();
			tptr = tptr->next;
		}
	}
}

ostream& MovieList::print(ostream &out){
	if(front==NULL){
		cerr<<"Error:MovieList: Cannot print an uninitialized MovieList\n";
	} else {
		node *tptr;
		tptr = front;
		out<<"START\n";
		while(tptr != NULL){
			tptr->movie->print(out);
			tptr = tptr->next;
		}
		out<<"END";
	}
	return out;
}

void MovieList::peekline(ifstream &in, string &s){
	streampos sp = in.tellg();
	getline(in, s);
	in.seekg(sp);
}

istream& MovieList::read(istream &in){
	clear();
	Movie *m = new Movie;
	string search;
	while(!in.fail()){
		if(!in.fail()){
			m->read(in);
			addMovie(m);
		}
		cout<<"Type END to end MovieList ~>";
		getline(in,search);
		if(search == "END") break;
	}
	delete m;
	return in;
}

ifstream& MovieList::readFile(ifstream &in){
	clear();
	Movie *m = new Movie;
	string search;
	while(!in.fail()){
		peekline(in,search);
		if(search=="START"){
			getline(in,search);
			peekline(in,search); //checks if MovieList is empty
		}
		if(search=="END") break;
		if(!in.fail()){
			m->readFile(in);
			addMovie(m);
		}
	}
	delete m;
	return in;
}

ostream& operator<<(ostream& out, MovieList& ml){
	ml.print(out);
	return out;
}

ifstream& operator>>(ifstream& in, MovieList& ml){
	ml.readFile(in);
	return in;
}

istream& operator>>(istream& in, MovieList& ml){
	ml.read(in);
	return in;
}

