/*
 * Book.h
 *
 *  Created on: Aug 25, 2016
 *      Author: Istvan
 */
#ifndef BOOK_H_
#define BOOK_H_

#include "Person.h"

using namespace std;

class Book {
private:
	string title;
	Person author;
	string language;
	string year;
	string rating;

public:
	Book();
	Book(string title, Person author, string language, string year, string rating);
	Book(string title, string firstName, string lastName, string language, string year, string rating);
	Book(string title, string fullName, string language, string year, string rating);

	//get section
	string getTitle() {return title;}
	Person getAuthor(){return author;}
	string getAuthorString(){return author.getPerson();}
	string getLanguage() {return language;}
	string getYear() {return year;}
	string getRating() {return rating;}

	//set section
	void setTitle(string t) {title = t;}
	void setAuthor(string firstName, string lastName);
	void setAuthor(string fullName){author.setPerson(fullName);}
	void setAuthor(Person p){author = p;};
	void setLanguage(string l) {language = l;}
	void setYear(string y) {year = y;}
	void setRating(string r) {rating = r;}
	void setBook(string title, Person author, string language, string year);
	void setBook(string title, Person author, string language, string year, string rating);
	void setBook(string title, string firstName, string lastName, string language, string year, string rating);
	void setBook(string title, string fullName, string language, string year);
	void setBook(string title, string fullName, string language, string year, string rating);
	void print();
};

#endif /* BOOK_H_ */

