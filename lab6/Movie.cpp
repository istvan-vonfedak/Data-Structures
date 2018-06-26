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
/* TBI 
Movie::Movie(const Movie &m) {
	deepCopy(m);
}
*/

Movie::~Movie() {
	clear();
}

void Movie::init(){
	title = "N/A";
	runtime.set(-1,-1);
	ratings = NULL;
}

void Movie::clear(){
	clearRatings();
	init();
}
/* TBI
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
*/
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
/* TBI
void Movie::set(const Movie &m){
	deepCopy(m);
}
*/

void Movie::addRating(const Rating &r){
	if(ratings == NULL) ratings = new LinkList;
	Rating *rt = new Rating;
	rt->set(r);
	
	ratings->insert(rt);
	rt = NULL;
}

void Movie::addRating(const string &r, const string &c){
	if(ratings == NULL) ratings = new LinkList;
	Rating *rt = new Rating;
        rt->set(r,c);	
	ratings->insert(rt);
	rt = NULL;
}

/* TBI
void Movie::addRatingList(const RatingList &rl){
	ratings->set(rl);
}
*/


void Movie::deleteRating(const Rating &r){
	if(ratings == NULL) cerr<<"Error:Movie: Cannot deleteRating if RatingList in Movie is uninitialized\n";
	else{
		Rating temp;
		temp = r;
		Rating *rat = dynamic_cast<Rating *>(ratings->remove(&temp));
		delete rat;
		rat = NULL;
	}
	if(ratings->length() == 0) clearRatings();
}

void Movie::clearRatings(){
	delete ratings;
	ratings =  NULL;
}

int Movie::compare(Object *obj){//1 means internal title is larger than m's title
	Movie *m = dynamic_cast<Movie *>(obj);
	if(m == NULL){
		cerr<<"Error:Movie: Cannot compare an uninitialized movie parameter\n";
		return -2;
	}
	else{
		if(this->title < m->title) return -1;
		else if(this->title > m->title) return 1;
		else return 0;
	}
}

void Movie::print(){
	cout<<"Title: "<<title<<endl;	
	cout<<"Runtime: "; runtime.print();
	if(ratings!=NULL) ratings->print();
	else cout<<"RSTART\nREND\n";
}
/*
Movie& Movie::operator=(const Movie &m){
	deepCopy(m);
	return *this;
}
*/
ostream& Movie::print(ostream &out){
	out<<title<<endl;
	out<<runtime<<endl;
	out<<"RSTART\n";
	if(ratings!=NULL) ratings->print(out);
	out<<"REND\n";
	return out;
}

void Movie::peekline(istream &in, string &s){
        streampos sp = in.tellg();
        getline(in, s);
        in.seekg(sp);
}

istream& Movie::read(istream& in){
	clear();
	string t,run, search, r, c;;
	ratings = new LinkList;
	getline(in,t);
	getline(in, run);
	if(!in.fail()){
		title = t;
		runtime.set(run);
	}
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
                if(!in.fail()){
			Rating *temp = new Rating;
                        temp->set(r,c);
                        ratings->insert(temp);
                        temp = NULL;
		}
        }
	if(ratings->length() == 0) delete ratings;
	return in;
}

void Movie::read(){
	clear();
	string t,run, r, c;
	ratings = new LinkList;
	cout<<"Movie's Title             ~>";
	getline(cin,t);
	cout<<"Movie's Runtime           ~>";
	getline(cin,run);
	if(!cin.fail()){	
		title = t;
		runtime.set(run);
	}
	cout<<"Input RatingList.\n";
        cout<<" - Type REND to end RatingList.\n";
        while(true){
                cout<<"Rating                    ~>";
                getline(cin,r);
                if(r =="REND") return;
                cout<<"Comment                   ~>";
                getline(cin,c);
                if(r =="REND") return;
                if(!cin.fail()){
			Rating *temp = new Rating;
			temp->set(r,c);
			ratings->insert(temp);
			temp = NULL;	
		}
        }
	if(ratings->length() == 0) delete ratings;
}

ostream& operator<<(ostream &out, Movie &m){
	m.print(out);
	return out;
}

istream& operator>>(istream &in, Movie &m){
	m.read(in);
	return in;
}



