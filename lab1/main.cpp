/*
 * main.cpp
 *
 *  Created on: Aug 25, 2016
 *      Author: Istvan
 */
#include "Library.h"
#include <fstream>

int finBookArray(Book book[], string fileName){
	//This function populates a given array of books
	//with a fin file having the format: title \n author \n language \n year\n
	int bookCount = 0;
	ifstream fin(fileName.c_str());
	if(fin.fail()){
		cout<<"File could not open\n";
		return -1;
	}
	else{
		string title, fullName, language, year;
		Person author;

		while(true){
			//Input section//
			getline(fin,title);
			if(fin.fail()) break;
			getline(fin,fullName);
			if(fin.fail()) break;
			getline(fin,language);
			if(fin.fail()) break;
			getline(fin, year);
			if(fin.fail()) break;
			book[bookCount].setBook(title, fullName, language,year);
			bookCount++;
		}
		fin.close();
		return bookCount;
	}
}

void printBookArray(Book b[], const int bookCount){
	//prints book object using a loop
	for(int i = 0; i < bookCount;i++){
		b[i].print();
	}
}

void reverseBookArray(Book b[], const int bookCount){
	//This function reverses the order of an array of book objects
	int startIndex = 0;
	int endIndex = bookCount-1;
	Book temp;
	while(startIndex <= endIndex){
		temp = b[startIndex];
		b[startIndex] = b[endIndex];
		b[endIndex] = temp;
		startIndex++;
		endIndex--;
	}
}

int foutBookArray(Book b[], const int bookCount, string fileName){
	//This function creates a file populated by the contents of a given array of Book object
	ofstream fout(fileName.c_str());
	if(fout.fail()){
		cout<<"Couldn't create the file!"<<endl;
		return -1;
	}
	else{
		for(int i = 0; i < bookCount; i++){
			fout<<b[i].getTitle()<<endl;
			fout<<b[i].getAuthor().firstName +" "+b[i].getAuthor().lastName<<endl;
			fout<<b[i].getLanguage()<<endl;
			fout<<b[i].getYear()<<endl;
			fout<<b[i].getRating()<<endl;
		}
		fout.close();
		return 0;
	}
}

int main(){

	//Populate given array of Book objects
	Book book[100];
	const int bookCount = finBookArray(book, "Book2.txt");

	//Reverses and prints the book array
	reverseBookArray(book,bookCount);
//	printBookArray(book,bookCount);

	//Outputs the reversed array of Book objects
	foutBookArray(book,bookCount,"Book2Reversed.txt");

	//Creates a library, populates it with books from book and prints the library
	Library a;
	a.finBookFile("Book2.txt");
	a.reverseBookArray();
//	a.print();

	//Creates a library and constructs it using an already propagated book array
	Library l("ECE218","Ubuntu Unix", bookCount, book);
	l.setBookArray(book,bookCount);
	l.foutLibrary("l_test.txt");
	l.foutBookFile("LibraryArray_test.txt");

	return 0;
}

