/*
 * Rating.h
 *
 *  Created on: Oct 24, 2016
 *      Author: Istvan
 */

#ifndef RATING_H_
#define RATING_H_

#include <iostream>
#include <fstream>
using namespace std;

class Rating {
private:
	int score;
	string comment;

public:
	Rating();
	Rating(const string);
	Rating(const string, const string);
	Rating(const Rating&);
	virtual ~Rating();
	void init();
	void set(const string);
	void set(const Rating&);
	void setRating(const int);
	void setRating(const string);
	void setComment(const string);
	void set(const int, const string);
	void set(const string, const string);
	void print();
	ostream& print(ostream&);
	istream& read(istream&);
	Rating& operator=(const Rating&);
	friend ostream& operator<<(ostream&, Rating&);
	friend istream& operator>>( istream&, Rating&);
	friend bool operator == (const Rating &s1, const Rating &s2); // TBI
	friend bool operator != (const Rating &s1, const Rating &s2); // TBI
};

#endif /* RATING_H_ */

