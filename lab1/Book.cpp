/*
 * Book.cpp
 *
 *  Created on: Aug 25, 2016
 *      Author: Istvan
 */

#include "Book.h"

Book::Book() {
	title = "N/A";
	author.firstName = "N/A";
	author.lastName = "N/A";
	language = "N/A";
	year = "N/A";
	rating = "N/A";
}
Book::Book(string t, Person a, string l, string y, string r){
	title = t;
	author = a;
	language = l;
	year = y;
	rating = r;
}
Book::Book(string t, string fn, string ln, string l, string y, string r){
	title = t;
	author.firstName = fn;
	author.lastName = ln;
	language = l;
	year = y;
	rating = r;
}
Book::Book(string t, string fulln, string l, string y, string r){
	title = t;
	author.setPerson(fulln);
	language = l;
	year = y;
	rating = r;
}

void Book::setAuthor(string fn, string ln){
	author.setPerson(fn,ln);
}
void Book::setBook(string t, Person a, string l, string y){
	title = t;
	author = a;
	language = l;
	year = y;
	rating = "N/A";
}
void Book::setBook(string t, Person a, string l, string y, string r){
	title = t;
	author = a;
	language = l;
	year = y;
	rating = r;
}
void Book::setBook(string t, string fn, string ln, string l, string y, string r){
	title = t;
	author.firstName = fn;
	author.lastName = ln;
	language = l;
	year = y;
	rating = r;
}
void Book::setBook(string t, string fulln, string l, string y){
	title = t;
	author.setPerson(fulln);
	language = l;
	year = y;
	rating = "N/A";
}
void Book::setBook(string t, string fulln, string l, string y, string r){
	title = t;
	author.setPerson(fulln);
	language = l;
	year = y;
	rating = r;
}
void Book::print(){
	cout<< "Title: " << title << endl;
	cout<< "Author: " << author.lastName << ", " << author.firstName<< endl;
	cout << "Language: " << language << endl;
	cout << "Year: " << year << endl;
	cout << "Rating: " << rating << endl<<endl;
}



