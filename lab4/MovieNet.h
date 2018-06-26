/*
 * MovieNet.h
 *
 *  Created on: Oct 28, 2016
 *      Author: Istvan
 */

#ifndef MOVIENET_H_
#define MOVIENET_H_
#include "MovieList.h"

class MovieNet {
private:
	string name;
	MovieList *movies;
	void init();
	void clear();
public:
	MovieNet();
	virtual ~MovieNet();
	void loadData(string);
	void storeData(string);
	void print();
	ostream& print(ostream&);
	istream& read(istream&);
	ifstream& readFile(ifstream&);
	friend ostream& operator<<(ostream&, MovieNet&);
	friend istream& operator>>(istream&, MovieNet&);
	friend ifstream& operator>>(ifstream&, MovieNet&);
};

#endif /* MOVIENET_H_ */

