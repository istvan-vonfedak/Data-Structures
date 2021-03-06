/*
 * RatingList.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: Istvan
 */

#include "RatingList.h"

RatingList::RatingList() {
	init();
}
RatingList::RatingList(const RatingList &rl) {
	deepCopy(rl);
}

RatingList::~RatingList() {
	clear();
}

void RatingList::init(){
	front = NULL;
	back = NULL;
	length = 0;
}

void RatingList::clear(){
	node *tptr;
	tptr = front;
	while(tptr != NULL){
		front = front->next;
		delete tptr;
		tptr = front;
	}
	init();
}

void RatingList::deepCopy(const RatingList &rl){
	clear();
	if(rl.front==NULL){
		front = NULL;
	} 
	else if(front != NULL) clear();
	else {
		front = new node;
		node *n;
		node *tptr;
		n = front;
		tptr = rl.front;
		while(tptr->next != NULL){
			n->rating = tptr->rating;
			n->next = new node;
			n = n->next;
			tptr= tptr->next;
			length++;
		}
		//adding back node
		n->rating = tptr->rating;
		n->next = NULL;
		back = n;
		length++;
		//making sure pointers are not deleted
		n = NULL;
		tptr = NULL;
	}
}

Rating RatingList::getRating(const int l){
	if(l>length) {
		cerr<<"Error:RatingList: getRating index greater than length of RatingList.\n";
		Rating err;
		return err;
	} else if(front==NULL) {
		cerr<<"Error:RatingList: Cannot getRating if RatingList is uninitialized.\n";
		Rating err;
		return err;
	} else {
		node *tptr;
		tptr = front;

		for(int i = 0; i<l;i++){
			tptr= tptr->next;
		}
		Rating copy;
		copy = tptr->rating;
		return copy;
	}
}

void RatingList::removeAllRatings(){
	clear();
}

void RatingList::addRating(const Rating &r){
	node *n = new node; // creates node to store temp info
	n->rating = r; // makes the temporaries pointer rating equal to r
	n->next = NULL; // since n is the last node the next pointer should be NULL

	if(front==NULL){ // if empty
		front = n; //since front is NULL the last item on list is also first
		back = n; // makes back node pointer to point to the back
		length++;
	} else {
		back->next = n; // makes the last node point to the temporary node pointer n
		back = n; // makes the last node pointer n because n is the last node;
		length++;
	}
}

void RatingList::addRating(const string i, const string s){
	Rating temp;
	temp.set(i,s);
	addRating(temp);
}

void RatingList::set(const RatingList &rl){
	deepCopy(rl);
}

void RatingList::addRatingList(const RatingList &rl){
	if(rl.front!=NULL){
		node *n = back;
		node *tptr = rl.front;
		n->next = new node;
		n = n->next;
		while(tptr->next != NULL){
			n->rating = tptr->rating;
			n->next = new node;
			n = n->next;
			tptr= tptr->next;
			length++;
		}
		// adding back pointer
		n->rating = tptr->rating;
		n->next = NULL;
		back = n;
		length++;
		// making sure not deleted
		n = NULL;
		tptr =NULL;
	}
}

void RatingList::removeAtStart(){
	if(front==NULL) cerr<<"Error:RatingList: Cannot removeAtStart in an uninitialized RatingList.\n";
	else{
		node *tptr;
		tptr = front->next;
		delete front;
		front = tptr;
		length--;
	}
}

void RatingList::removeAtEnd(){
	if(front == NULL) cerr<<"Error:RatingList: Cannot removeAtEnd in an uninitialized RatingList.\n";
	else{
		node *tptr,*fptr;
		tptr = front;
		fptr = NULL;
		while(tptr->next != NULL){
			fptr = tptr;
			tptr = tptr->next;
		}
		delete tptr;
		fptr->next = NULL;
		back = fptr;
		length--;
	}
}

void RatingList::deleteRating(const Rating &r){
	if(front == NULL){
		cerr<<"Error:RatingList: Cannot deleteRating in an uninitialized RatingList.\n";
	} else if(front->rating == r){
		removeAtStart();
	} else if (back->rating == r){
		removeAtEnd();
	} else{
		node *tptr, *fptr;
		tptr = front;
		fptr = NULL;
		while(tptr->rating != r){
			fptr = tptr;
			tptr=tptr->next;
		}
		fptr->next = tptr->next;
		delete tptr;
		length--;
	}
}

void RatingList::print(){
	if(front==NULL){
		cerr<<"Error:RatingList: Cannot print uninitialized RatingList.\n";
	} else {
		node *tptr;
		tptr = front;
		for(int i = 0; i<length;i++){
			tptr->rating.print();
			tptr = tptr->next;
		}
	}
}

ostream& RatingList::print(ostream &out){
	if(front==NULL){
		cerr<<"Error:RatingList: Cannot print(ostream&) uninitialized RatingList.\n";
	} else {
		node *tptr;
		tptr = front;

		for(int i = 0; i<length;i++){
			out << tptr->rating<<endl;
			tptr = tptr->next;
		}
	}
	return out;
}
istream& RatingList::read(istream& in){
	clear();
	string search, r,c;
	cout<<"Input RatingList.\n";
	cout<<"	- Type REND to end RatingList.\n";
	while(!in.fail()){
		cout<<"Rating                    ~>";
		getline(in,r);
		if(r =="REND"||r =="STOP"||r =="stop") return in;
		cout<<"Comment                   ~>";
		getline(in,c);
		if(r =="REND"||r =="STOP"||r =="stop") return in;
		if(!in.fail()) addRating(r,c);
	}
	return in;
}

void RatingList::peekline(istream &in, string &s){
	streampos sp = in.tellg();
	getline(in, s);
	in.seekg(sp);
}

ifstream& RatingList::readFile(ifstream& in){
	clear();
	string search, r,c;
	while(!in.fail()){
		peekline(in,search);
		if(search == "RSTART"){
			getline(in,search);
			peekline(in,search);//checks if there are no reviews
		}
		if(search == "REND") {
			getline(in, search);
			return in;
		}
		getline(in,r);
		getline(in,c);
		if(!in.fail()) addRating(r,c);
	}
	return in;
}

RatingList& RatingList::operator=(const RatingList &rl){
	deepCopy(rl);
	return *this;
}

ostream& operator <<(ostream &out, RatingList &rl){
	rl.print(out);
	return out;
}

istream& operator >>(istream &in, RatingList &rl){
	rl.read(in);
	return in;
}
ifstream& operator >>(ifstream &in, RatingList &rl){
	rl.readFile(in);
	return in;
}
