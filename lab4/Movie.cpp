/*
 * Movie.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: Istvan
 */

#include "Movie.h"

Movie::Movie() {
	init();
}
Movie::Movie(const Movie &m) {
	deepCopy(m);
}

Movie::~Movie() {
	clear();
}

void Movie::init(){
	title = "N/A";
	runtime.set(-1,-1);
	ratings = NULL;
}

void Movie::clear(){
	deleteAllRatings();
	init();
}

void Movie::deepCopy(const Movie &m){
	clear();
	title = m.title;
	runtime = m.runtime;

	if(ratings !=NULL) deleteAllRatings();
	if(m.ratings != NULL){
		ratings = new RatingList;
		*ratings = *m.ratings;
	}
}

void Movie::man(){
	cout<<"Welcome to the Movie manual\n";
	cout<<"ifstream\n\n";
	cout<<"Manual input(cin):\n";
	cout<<"	-when using cin to manually input a file.\n";
	cout<<"Title: type the title, hit enter.\n";
	cout<<"Runtime: type the runtime, hit enter.\n";
	cout<<"	- The hours and minutes should be together.\n";
	cout<<"	- Any integer less than 60 is considered minutes.\n";
	cout<<"	- Ex: 140 is 1 hour 40 minutes.\n";
	cout<<"RatingList:\n";
	cout<<"	- 1) Type the rating, hit enter.\n";
	cout<<"	- 2) Type the comment for that rating, hit enter.\n";
	cout<<"		- Repeat step 2 and 3 to add more ratings.\n";
	cout<<"	- 3)Type REND to stop reading ratings, hit enter.\n";
}

void Movie::setTitle(string s){
	title = s;
}

void Movie::setRuntime(const RTime rt){
	runtime = rt;
}
void Movie::setRuntime(const string rt){
	runtime.set(rt);
}

void Movie::setRuntime(const int h, const int m){
	runtime.set(h,m);
}

void Movie::set(const Movie &m){
	deepCopy(m);
}

void Movie::addRating(const Rating &r){
		if(ratings == NULL){
			ratings = new RatingList;
			ratings->addRating(r);
		} else {
			ratings->addRating(r);
		}
}

void Movie::addRating(const string &r, const string &c){
	if(ratings == NULL){
		ratings = new RatingList;
		ratings->addRating(r,c);
	} else {
		ratings->addRating(r,c);
	}
}

void Movie::addRatingList(const RatingList &rl){
	ratings->set(rl);
}

void Movie::deleteRating(const Rating &r){
	if(ratings == NULL) cerr<<"Error:Movie: Cannot deleteRating if RatingList in Movie is uninitialized\n";
	else ratings->deleteRating(r);
	/*
	if(ratings->getLength() == 0){
		delete ratings;
		ratings = NULL;
	}
	*/
}

void Movie::deleteAllRatings(){
	if(ratings != NULL){
		delete ratings;
		ratings = NULL;
	}
}

int Movie::compare(Movie *m){//1 means internal title is larger than m's title
	if(m == NULL){
		cerr<<"Error:Movie: Cannot compare an uninitialized movie parameter\n";
		return -2;
	}
	else{
		if(m->title > title) return -1;
		else if(m->title < title) return 1;
		else return 0;
	}
}

void Movie::print(){
	cout<<"Title: "<<title<<endl;
	cout<<"Runtime: "; runtime.print();
	if(ratings!=NULL) ratings->print();
	else cout<<"No ratings.\n";
}

Movie& Movie::operator=(const Movie &m){
	deepCopy(m);
	return *this;
}

ostream& Movie::print(ostream &out){
	out<<title<<endl;
	out<<runtime<<endl;
	out<<"RSTART\n";
	if(ratings!=NULL) out<<*ratings;
	out<<"REND\n";
	return out;
}

ifstream& Movie::readFile(ifstream& in){
	clear();
	string t,run;
	ratings = new RatingList;
	getline(in,t);
	getline(in, run);
	if(!in.fail()){
		title = t;
		runtime.set(run);
	}
	ratings->readFile(in);
	if(ratings->getLength()==0) deleteAllRatings();
	return in;
}

istream& Movie::read(istream &in){
	clear();
	string t,run;
	ratings = new RatingList;
	cout<<"Movie's Title             ~>";
	getline(in,t);
	cout<<"Movie's Runtime           ~>";
	getline(in,run);
	if(!in.fail()){
		title = t;
		runtime.set(run);
	}
	ratings->read(in);
	if(ratings->getLength()==0) deleteAllRatings();
	return in;
}

ostream& operator<<(ostream &out, Movie &m){
	m.print(out);
	return out;
}

istream& operator>>(istream &in, Movie &m){
	m.read(in);
	return in;
}

ifstream& operator>>(ifstream &in, Movie &m){
	m.readFile(in);
	return in;
}


