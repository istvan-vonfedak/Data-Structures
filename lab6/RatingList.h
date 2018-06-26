/*
 * RatingList.h
 *
 *  Created on: Oct 24, 2016
 *      Author: Istvan
 */

#ifndef RATINGLIST_H_
#define RATINGLIST_H_

#include "LinkList.h"
#include "Rating.h"

class RatingList {
private:
	LinkList list;
	void init();
	void peekline(istream &in, string &s);

public:

	RatingList();
	virtual ~RatingList();
	int length(){return list.length();}
	Rating getRating(const int);
	void clear();
	void addRating(const Rating&);
	void addRating(const string, const string);
	void addRating(const int, const string);
	void deleteRating(const Rating&);
	void print();
	RatingList& operator=(const RatingList&);
	ostream& print(ostream&);
	istream& read(istream&);
	ifstream& readFile(ifstream&);
	friend ostream& operator<<(ostream&, RatingList &);
	friend istream& operator>>(istream&, RatingList&);
	friend ifstream& operator>>(ifstream&, RatingList &);
};

#endif /* RATINGLIST_H_ */

