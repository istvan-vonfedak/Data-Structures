/*
*
* MoviePlayList.h
*
* Created: Dec 6, 2016
*	Author: istvan
*/

#ifndef MOVIEPLAYLIST_H_
#define MOVIEPLAYLIST_H_
#include "Movie.h"
#include <stdlib.h>
//#include "Object.h"

class MoviePlayList: public Object {
protected:
	LinkList pl;
	string name;
	RTime rt;
	int count;
	void init();
	void peekline(istream &, string &);
public:
	MoviePlayList();
	virtual ~MoviePlayList();
	void shallowClean(){pl.shallowClean(); init();}
	void man(); //manual for MoviePlayList
	void clear();
	void setName(const string &s){ name = s; }
	string getName(){ return name; }
	void populate(LinkList*, int);
	int getTime(){ return rt.time(); } // last two digits are minutes the rest are hours
	RTime returnRuntime(){ return rt; } 
	int length(){return count;}
	Object* search(int);
	int compare(Object*);
	void insert(Object*);
	void print();
	void printMovies();
	ostream& print(ostream&);
	void read();	
	istream& read(istream&);
};

#endif /*MOVIEPLAYLIST_H_*/
