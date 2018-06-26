/*
 * Library.h
 *
 *  Created on: Sep 1, 2016
 *      Author: Istvan
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_
#include "Book.h"
#include <fstream>

class Library {
private:
	string libraryName;
	Person owner;
	int bookCount;
	Book bookArray[100];

public:
	Library();
	Library(string libraryName, Person owner);
	Library(string libraryName, Person owner, const int bookNum, Book array[]);
	Library(string libraryName, string owner, const int bookNum, Book array[]);

	void setName(string name){libraryName = name;}
	void setOwner(Person p){owner = p;}
	void setOwner(string firstName,string lastName);
	void setOwner(string fullName){owner.setPerson(fullName);};
	void setBookCount(int bc){bookCount = bc;}
	void setBook(int index, string title, Person author, string language, string year, string rating);
	void setBookArray(Book array[], int bookCount);
	void setLibrary(string libraryName,Person owner,const int bookCount, Book bookArray[]);

	string getName(){return libraryName;}
	Person getOwner(){return owner;}
	int getBookCout(){return bookCount;}
	Book getBook(int index){return bookArray[index];}
	void print();
	void printInfo();
	void printBookArray();

	void finBookFile(string fileName);
	void foutBookFile(string fileName);
	void foutLibrary(string fileName);
	void reverseBookArray();
};
#endif /* LIBRARY_H_ */

