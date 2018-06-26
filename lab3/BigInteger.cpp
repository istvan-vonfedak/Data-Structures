/*
 * BigInteger.h
 *
 *  Created on: Sep 21, 2016
 *      Author: Istvan
 */
//atol( string s.c_str() )
#ifndef BIGINTEGER_H_
#define BIGINTEGER_H_

#include <iostream>

using namespace std;

class BigInteger {
private:
	short *data;
	int length;
	int space;
	int expandSize;
	int multiplier;
	int timesMultiplied;
	bool compressed;
	void init(const int len = 0); // set it to default
	void clear(); //deletes data
	void clean(); // resets BigInteger to default
	int findLength(const char *str); //finds the length of an array of characters
	void deepCopy(const BigInteger&); // copies BigIntegers
	void deepCopy(const char*); // copies the data from an array of characters into a BigInteger
	void compress(); // compresses the BigInteger
	void compress(const int); // compresses the BigInteger to a given value
	void expand(); //expands the big integer to the size of (expandSize*(timesMultiplied+1)*multiplier)
	void expand(const int); //expands to a given multiplier integer
	void addToIndex(const short, const int); //
	short borrow(int index = 0); // borrows from a given index
	int compare(const BigInteger&);
	//void negativeSubtraction(const BigInteger&, const bool b=false);
	//void negate();




public:


	BigInteger();
	BigInteger(string);
	//BigInteger(const char*);
	BigInteger(const BigInteger&); // copy constructor
	virtual ~BigInteger();
	void setData(string);
	void setData(const char*,const int len=-1);
	void setData(const short);
	void setData(const short*,const int);
	void setData(const BigInteger&);
	short get(const int); //returns the integer in the given index

	void increment(const int index = 0,const bool b = false); //increments the BigInteger by 1 using recursion
	void add(string,  const bool b = false, const int index = 0);
	void add(const short*, const int, const bool b = false, const int index = 0);
	void add(const BigInteger&, const bool b = false, const int index = 0); //adds a given BigInteger using recursion
	void multiply(const BigInteger&,const bool b=false, const int index=0, short *n=NULL, int len=0, int nSpace=0); //multiplies a given BigInteger using recursion
	void multiplySimple(const short,const bool b=false, const int index=0, short *n=NULL, int len=0, int nSpace=0); //multiplies a given BigInteger using recursion
	void subtract(const BigInteger&, const bool b=false, const int index=0);
	void hardDivide(const int);
	void divide_worker(const BigInteger&, BigInteger &, BigInteger &,const int precision = 0);
	void divide(const BigInteger&, const bool b=false);


	void print(); //prints BigInteger
	void printFull(); //prints all the info stored in the BigInteger

	ostream& print(ostream&); // print to an output stream
	//istream& read(istream&); // TBI - read to an input stream

	BigInteger& operator=(const BigInteger&);
	BigInteger& operator=(const char*);

	friend ostream& operator<<(ostream&, BigInteger&);
	//friend istream& operator<<(istream&, BigInteger&); // TBI
};

#endif /* BIGINTEGER_H_ */

