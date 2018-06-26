/*
 * MovieNet.cpp
 *
 *  Created on: Oct 28, 2016
 *      Author: Istvan
 */

#include "MovieNet.h"

MovieNet::MovieNet() {
	init();
}

MovieNet::~MovieNet() {
	clear();
}

void MovieNet::init(){
	name = "N/A";
	movies = NULL;
}

void MovieNet::clear(){
	delete movies;
	init();
}

void MovieNet::loadData(string s){
	string temp;
	if(movies != NULL) clear();
	ifstream fin(s.c_str());
	if(fin.fail()) cerr<<"Error:MovieNet: LoadData file could not be opened.\n";
	else{
		clear();
		movies = new MovieList;
		getline(fin,temp);
		if(!fin.fail()) name=temp;
		movies->readFile(fin);
	}
	fin.close();
}

void MovieNet::storeData(string s){
	if(movies == NULL) cerr<<"Error:MovieNet: Cannot storeData of an uninitialized MovieNet.\n";
	else{
		ofstream fout(s.c_str());
		if(fout.fail()) cerr<<"Error:MovieNet: storeData file could not be created.\n";
		else{
			fout<<name<<endl;
			fout<<*movies;
		}
		fout.close();
	}
}

void MovieNet::print(){
	if(movies == NULL) cerr<<"Error:MovieNet: Cannot print an uninitialized MovieNet.\n";
	else{
		cout<<"Name: "<<name<<endl;
		if(movies != NULL) movies->print();
		else cout<<"No movies.\n";
	}
}

ostream& MovieNet::print(ostream& out){
	if(movies == NULL) cerr<<"Error:MovieNet: Cannot print an uninitialized MovieNet.\n";
	else{
		cout<<name<<endl;
		if(movies != NULL) cout<<*movies;
	}
	return out;
}

istream& MovieNet::read(istream &in){
	string n;
	if(movies != NULL) clear();
	movies = new MovieList;
	cout<<"MovieNet's name           ~>";
	getline(in,n);
	if(!in.fail()) name = n;
	movies->read(in);
	return in;
}

ifstream& MovieNet::readFile(ifstream &in){
	if(movies != NULL) clear();
	movies = new MovieList;
	in>>name;
	movies->readFile(in);
	return in;
}

ostream& operator<<(ostream &out, MovieNet&mn){
	mn.print(out);
	return out;
}

istream& operator>>(istream &in, MovieNet &mn){
	mn.read(in);
	return in;
}
ifstream& operator>>(ifstream &in, MovieNet &mn){
	mn.readFile(in);
	return in;
}
