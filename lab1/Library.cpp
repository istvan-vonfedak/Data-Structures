/*
 * Library.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: Istvan
 */

#include "Library.h"

Library::Library() {

	libraryName = "N/A";
	owner.firstName = "N/A";
	owner.lastName = "N/A";
	bookCount = 0;
	//Included a default constructor for bookArray
	for(int i = 0;i<100;i++){
		// strings by order Title, firstName, lastName, Language, Year, Rating.
		//How would you use a default constructor to build each bookArray? aren't they constructed when the array is created?
		bookArray[i].setBook("N/A","N/A","N/A","N/A","N/A","N/A");
	}
}
Library::Library(string name, Person p) {
	libraryName = name;
	owner = p;
	bookCount = 0;
}
Library::Library(string name, Person own, const int bookNum, Book array[]) {

	libraryName = name;
	owner = own;
	bookCount = bookNum;
	//Included a default constructor for bookArray
	for(int i = 0;i<bookNum;i++){
		// strings by order Title, firstName, lastName, Language, Year, Rating.
		//How would you use a default constructor to build each bookArray? aren't they constructed when the array is created?
		bookArray[i] = array[i];
	}
}
Library::Library(string name, string fullName, const int bookNum, Book array[]) {

	libraryName = name;
	owner.setPerson(fullName);
	bookCount = bookNum;
	//Included a default constructor for bookArray
	for(int i = 0;i<bookNum;i++){
		bookArray[i] = array[i];
	}
}

void Library::setOwner(string fn, string ln){
	owner.firstName = fn;
	owner.lastName = ln;
}
void Library::setBook(int index, string title, Person author, string language, string year, string rating){
	bookArray[index].setBook(title,author,language,year,rating);
	bookCount++;
}
void Library::setBookArray(Book b[],int bc){
	for(int i = 0; i < bc; i++)
	{
		bookArray[i]=b[i];
	}
	bookCount = bc;
}
void Library::setLibrary(string name,Person o,const int bc, Book b[]){
	libraryName = name;
	owner = o;
	for(int i = 0; i < bc; i++)
		{
			bookArray[i]=b[i];
		}
		bookCount = bc;
}

void Library::print(){
	cout<< "Library Name: " << libraryName << endl;
	cout<< "Library Owner: "; owner.print();
	cout<< "Library Book Count: " << bookCount << endl;
	cout<< endl << "Books: " << endl << endl;
	for(int i = 0; i < bookCount; i++){
		bookArray[i].print();
	}

}
void Library::printInfo(){
	cout<< "Library Name: "<<libraryName<< endl;
	cout<< "Library Owner: "; owner.print();
	cout<< endl << "Books: "<< endl << endl;
}
void Library::printBookArray(){
	//prints book object using a loop
	for(int i = 0; i < bookCount;i++){
		bookArray[i].print();
	}
}

void Library::finBookFile(string fileName){
	//This function populates a given array of books
	//with a fin file having the format: title \n author \n language \n year\n
	int bookNumber = 0;
	ifstream fin(fileName.c_str());
	if(fin.fail()) cout<<"File could not open\n";
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
			bookArray[bookNumber].setBook(title, fullName, language,year);
			bookNumber++;
		}
		fin.close();
		bookCount = bookNumber;
	}
}
void Library::foutBookFile(string fileName){
	//This function creates a file populated by the contents of a given array of Book object
		ofstream fout(fileName.c_str());
		if(fout.fail()){
			cout<<"Couldn't create the file!"<<endl;
		}
		else{
			for(int i = 0; i < bookCount; i++){
				fout<<bookArray[i].getTitle()<<endl;
				fout<<bookArray[i].getAuthor().firstName +" "+bookArray[i].getAuthor().lastName<<endl;
				fout<<bookArray[i].getLanguage()<<endl;
				fout<<bookArray[i].getYear()<<endl;
				fout<<bookArray[i].getRating()<<endl;
			}
			fout.close();
		}
}
void Library::foutLibrary(string fileName){
	//This function creates a file populated by the contents of a given Library object
		ofstream fout(fileName.c_str());
		if(fout.fail()){
			cout<<"Couldn't create the file!"<<endl;
		}
		else{
			//Fouts the basic information of the library
			fout<<libraryName<<endl;
			fout<< owner.firstName +" "+ owner.lastName<<endl;
			fout<< bookCount<<endl;
			//Fouts the book array
			for(int i = 0; i < bookCount; i++){
				fout<<bookArray[i].getTitle()<<endl;
				fout<<bookArray[i].getAuthor().firstName +" "+bookArray[i].getAuthor().lastName<<endl;
				fout<<bookArray[i].getLanguage()<<endl;
				fout<<bookArray[i].getYear()<<endl;
				fout<<bookArray[i].getRating()<<endl;
			}
			fout.close();
		}
}
void Library::reverseBookArray(){
	//This function reverses the order of an array of book objects
		int startIndex = 0;
		int endIndex = bookCount-1;
		Book temp;
		while(startIndex <= endIndex){
			temp = bookArray[startIndex];
			bookArray[startIndex] = bookArray[endIndex];
			bookArray[endIndex] = temp;
			startIndex++;
			endIndex--;
		}
}

