/*
 * Movie.h
 *
 *  Created on: Oct 24, 2016
 *      Author: Istvan
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include "LinkList.h"
#include "Rating.h"
#include "RTime.h"
//#include "Object.h"
class Movie: public Object{
private:
	string title;
	RTime runtime;
	LinkList *ratings;
	void init();
	void peekline(istream &in, string &s);
//	void deepCopy(const Movie&); // TBI

public:
	Movie();
//	Movie(const Movie&);
	virtual ~Movie();
	void clear();
	void man();
	string getTitle(){return title;}
	int getRuntime(){return runtime.time();}
	RTime returnRuntime(){return runtime;}
	void setTitle(const string);
	void setRuntime(const RTime);
	void setRuntime(const string);
	void setRuntime(const int, const int);
//	void set(const Movie&);
	void addRating(const Rating&);
	void addRating(const string&, const string&);
//	void addRatingList(const RatingList&); // TBI
	void deleteRating(const Rating&);
	void clearRatings();
	int compare(Object*);
	void print();
	void read();
//	Movie& operator=(const Movie&); // TBI
	ostream& print(ostream&);
	istream& read(istream&);
	friend ostream& operator<<(ostream&, Movie&);
	friend istream& operator>>(istream&, Movie&);
};

#endif /* MOVIE_H_ */

