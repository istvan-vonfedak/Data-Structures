/*
 * RatingList.h
 *
 *  Created on: Oct 24, 2016
 *      Author: Istvan
 */

#ifndef RATINGLIST_H_
#define RATINGLIST_H_

#include "Rating.h"

class RatingList {
private:
	struct node {
		Rating rating;
		node *next;
	};
	node *front, *back;
	int length;
	void init();
	void clear();
	void copy();
	void deepCopy(const RatingList&);
	void peekline(istream &in, string &s);

public:

	RatingList();
	RatingList(const RatingList&);
	virtual ~RatingList();
	int getLength(){return length;}
	Rating getRating(const int);
	void removeAllRatings();
	void removeAtStart();
	void removeAtEnd();
	void addRating(const Rating&);
	void addRating(const string, const string);
	void addRatingList(const RatingList&);
	void set(const RatingList&);
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

