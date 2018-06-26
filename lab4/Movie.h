/*
 * Movie.h
 *
 *  Created on: Oct 24, 2016
 *      Author: Istvan
 */

#ifndef MOVIE_H_
#define MOVIE_H_
#include "RatingList.h"
#include "RTime.h"

class Movie {
private:
	string title;
	RTime runtime;
	RatingList *ratings;
	void init();
	void deepCopy(const Movie&);

public:
	Movie();
	Movie(const Movie&);
	virtual ~Movie();
	void clear();
	void man();
	string getTitle(){return title;}
	void setTitle(const string);
	void setRuntime(const RTime);
	void setRuntime(const string);
	void setRuntime(const int, const int);
	void set(const Movie&);
	void addRating(const Rating&);
	void addRating(const string&, const string&);
	void addRatingList(const RatingList&);
	void deleteRating(const Rating&);
	void deleteAllRatings();
	int compare(Movie*);
	void print();
	Movie& operator=(const Movie&);
	ostream& print(ostream&);
	istream& read(istream&);
	ifstream& readFile(ifstream&);
	friend ostream& operator<<(ostream&, Movie&);
	friend istream& operator>>(istream&, Movie&);
	friend ifstream& operator>>(ifstream&, Movie&);
};

#endif /* MOVIE_H_ */

