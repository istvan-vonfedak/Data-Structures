/*
 * MovieList.h
 *
 *  Created on: Oct 25, 2016
 *      Author: Istvan
 */

#ifndef MOVIELIST_H_
#define MOVIELIST_H_
#include "Movie.h"

class MovieList {
private:
	struct node{
		Movie *movie;
		node *next;
	};
	node *front, *back;
	int length;
	void init();
	void clear();
	// void deepCopy(const MovieList&); - TBI
	void addAtFront(Movie *m);
	void addAtBack(Movie *m);
	void removeAtFront();
	void removeAtBack();
	void peekline(ifstream &, string &);
public:
	MovieList();
	virtual ~MovieList();
	int getLength(){return length;}
	void addMovie(Movie *m); //adds a movie to the list sorted by title
	void removeMovie(const string t); //removes movie with title t
	void removeAllMovies(); // removes all movies
	void addRating(const string t, const Rating &r); // adds the Rating r to the movie of title t
	void deleteRating(const string t, const Rating &r); // finds and deletes the rating r from the movie title t
	void printMovie(const string t); // printMovie(string t) print movie and ratings with title t
	void print(); // Method to print the entire list of movies
	ostream& printMovie(ostream&, const string t);
	ostream& print(ostream&);
	ifstream& readFile(ifstream&);
	istream& read(istream&);
	friend ostream& operator<<(ostream&, MovieList&);
	friend ifstream& operator>>(ifstream&, MovieList&);
	friend istream& operator>>(istream&, MovieList&);
};

#endif /* MOVIELIST_H_ */

