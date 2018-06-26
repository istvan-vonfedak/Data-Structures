/*
 * Rating.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: Istvan
 */

#include "Rating.h"

Rating::Rating() {
	init();
}
Rating::Rating(const string s){
	set(s);
}

Rating::Rating(const string r, const string c){
	setRating(r);
	setComment(c);
}

Rating::Rating(const Rating &r) {
	set(r);
}

Rating::~Rating() {

}

void Rating::init(){
	score = -1;
	comment = "N/A";
}

void Rating::setRating(const int r){
	score = r;
}

void Rating::setRating(const string s){
	score = atol(s.c_str());
}

void Rating::setComment(const string c){
	comment = c;
}

void Rating::set(const int r, const string c){
	setRating(r);
	setComment(c);
}

void Rating::set(const string r, const string c){
	setRating(r);
	setComment(c);
}

void Rating::set(string s){
	string r = "", c = "";
	int lastSpaceIndex; // this int defines the index of the " " that separates the last name from the first name.
	for(int i = s.length(); 0<=i;i--){
		if(s[i] == ' '){//starts at the last index of the comment string and stops when it find the last " "
			lastSpaceIndex = i;//redefines the index of where the " " is.
			while(i < s.length()){//records the comment
				c += s[i+1];
				i++;
			}
			for(int j = 0; j < lastSpaceIndex; j++){//records the rating
				r += s[j];
			}
			break;
		}
	}
	setRating(r);
	setComment(c);
}

void Rating::set(const Rating &r){
	set(r.score,r.comment);
}

void Rating::print(){
	cout<<"rating: "<<score<<", comment: "<<comment<<endl;
}

ostream& Rating::print(ostream &out){
	out<<score<<endl;
	out<<comment;
	return out;
}

istream& Rating::read(istream &in){
	string s,c;
	getline(in,s);
	getline(in,c);
	if(!in.fail()){
		score = atol(s.c_str());
		comment = c;
	}
	return in;
}

Rating& Rating::operator=(const Rating &r){
	set(r);
	return *this;
}

ostream& operator<<(ostream &out, Rating &r){
	r.print(out);
	return out;
}

istream& operator>>(istream &in, Rating &r){
	r.read(in);
	return in;
}

bool operator == (const Rating &s1, const Rating &s2){
	bool a, b;
	if(s1.score == s2.score){
		a = true;
	}
	else a = false;
	if(s1.comment == s2.comment){
		b = true;
	}
	else b = false;
	if(a&&b) return true;
	else return false;
}

bool operator != (const Rating &s1, const Rating &s2){
	if(s1==s2) return false;
	else return true;
}
