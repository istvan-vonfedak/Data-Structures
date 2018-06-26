/*
* Name: MovieTree.h 
*
* Date Created: Dec 6, 2016
* 
* Author: Istvan
*
*/

#ifndef MOVIETREE_H_
#define MOVIETREE_H_

#include "PTree.h"
#include "Movie.h"

class MovieTree {
	PTree mt;	
	void peekline(istream &, string &);
public:
	MovieTree();
	virtual ~ MovieTree();
	void clear();
	void addMovie(Movie*);
	Movie* findMovie(const string);
	int getDepth(){ return mt.depth(); }
	int getNumMovies(){ return mt.size(); }
	void printTree(bool ascending = true);
	void print(bool ascending = true);
	void read();
	ostream& print(ostream&, bool ascending = true);
	istream& read(istream&);

};

#endif /* MOVIETREE_H_ */
