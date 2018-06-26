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

RatingList::~RatingList() {
	clear();
}

void RatingList::init(){

}

void RatingList::clear(){
	list.clear();
}

Rating RatingList::getRating(const int i){
	Rating ret;
	Rating *rat = dynamic_cast<Rating *>(list.search(i));
	if(rat == NULL){//Will return NULL if rating not found or if original type is not Rating
		return ret;
	}
	else {
		Rating ret;
		ret.set(*rat);
		rat = NULL;
		return ret;
	}
}

void RatingList::addRating(const Rating &r){
	Rating *rat = new Rating;
	*rat = r;
	list.insert(rat);
	rat = NULL;
}

void RatingList::addRating(const int i, const string s){
        Rating *rat = new Rating;
        rat->set(i,s);
        list.insert(rat);
        rat = NULL;
}

void RatingList::addRating(const string i, const string s){
	Rating *rat = new Rating;
	rat->set(i,s);
	list.insert(rat);
	rat = NULL;
}

void RatingList::deleteRating(const Rating &r){
	Rating temp;
	temp = r;
	Rating *rat = dynamic_cast<Rating *>(list.remove(&temp));
	delete rat;
}

void RatingList::print(){
	if(list.length() != 0){
		int s = list.length();
        	Rating *r;
        	for(int i=0;i<s;i++){
        	        r = dynamic_cast<Rating *>(list.search(i));
        	        r->print();
        	}
		r = NULL;
	}
	else cerr<<"RatingList:Error: printing uninitialized RatingList\n";
}

ostream& RatingList::print(ostream &out){
	if(list.length() != 0){
                int s = list.length();
                Rating *r;
                for(int i=0;i<s;i++){
                        r = dynamic_cast<Rating *>(list.search(i));
                        r->print(out);out<<endl;
                }
		r = NULL;
        }
        else cerr<<"RatingList:Error: printing uninitialized RatingList\n";
	return out;
}

istream& RatingList::read(istream& in){
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
	//clear();
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
