/*
 * main.cpp
 *
 *  Created on: Sep 12, 2016
 *      Author: Daghamos
 */
#include "Person.h"
#include <iostream>
#include <fstream>

int determineSize(string s){
	/*
	 * Determins the size of the array based on the imput file.
	 */
	ifstream fin(s.c_str());
	if(!fin){
		cout<< "couldn't open the file \n";
		return 0;
	}
	else{
		int lineCount=0;
		string line;
		//counting lines
		while(getline(fin,line) && !fin.fail()){
			lineCount++;
		}
		return lineCount;
	}
}
void print(Person p[], const int n){
	for(int i = 0; i < n;i++){
		cout<<i<<" ";
		p[i].print();
	}
}
void finData(string s, Person p[]){
	/*
	 * It populates the array of books.
	 */
	ifstream fin(s.c_str());
	if(!fin){
		cout<< "couldn't open the file \n";
	}
	else{
		//Populating the array with information.
		string ssn,fn,ln,dob;
		for(int i = 0; !fin.fail(); i++){
			fin>>ssn;
			if(fin.fail()) break;
			fin>> fn;
			if(fin.fail()) break;
			fin>>ln;
			if(fin.fail()) break;
			fin>>dob;
			if(fin.fail()) break;
			p[i].setPerson(ssn,fn,ln,dob);
		}
	}
}

void bubbleSort(Person a[], const int n){
	Person temp;
	for(int i = 0; i< n; i++){
		for(int j = 0; j<(n-1)-i; j++){
			if(a[j].age()>a[j+1].age()){
				temp = a[j+1];
				a[j+1]= a[j];
				a[j]=temp;
			}
		}
	}
}
void shakerSort(Person a[], const int n){
	Person temp;
	for(int i = 0; i< n; i++){
		//left -> right
		for(int j = i; j<(n-1)-i; j++){
			if(a[j].age()>a[j+1].age()){
				temp = a[j+1];
				a[j+1]= a[j];
				a[j]=temp;
			}
		}
		//right -> left
		for(int j = (n-1)-i; j>i; j--){
			if(a[j].age()<a[j-1].age()){
				temp = a[j-1];
				a[j-1]= a[j];
				a[j]=temp;
			}
		}
	}
}
void selectionSort(Person a[], const int n){
	int maxIndex;
	Person temp;
	for(int i = n-1; i>0; i--){
		//find max index
		maxIndex =i;
		for(int j = 0; j <i;j++){
			if(a[maxIndex].age()<a[j].age()) maxIndex = j;
		}
		//swap
		if(a[maxIndex].age()!=a[i].age()){
			temp = a[maxIndex];
			a[maxIndex] = a[i];
			a[i]=temp;
		}
	}
}
void insertionSort(Person a[], const int n){
	Person tmp;
	for (int i = 1; i < n; i++) {
		for (int j  = i;a[j - 1].age() > a[j].age() && j > 0; j--) {
			tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;
		}
	}

 }

void reverse(Person p[], const int n){
	/*
	 * I could pass a boolean function into the sorting functions,
	 * but I found this easier to debug and doesn't take a long time.
	 * I would have to change the comparisons on the sorting functions
	 * to change the conditions for the sorting algorithms. Or I can
	 * pass a boolean parameter that tells the function if it's
	 * ascending(true) or decending(false) with and if(ascending)
	 * sort assending, else sort decending, but personally I din't
	 * like the way the long functions looked.
	 */
	Person temp;
	for(int i = 0; i < n/2; i++){
		temp = p[i];
		p[i] = p[(n-i)-1];
		p[(n-i)-1] = temp;
	}
}
int main(){

	cout<<"Running...\n\n";
	/*
	 * Change the imput file here to whatever file you want to read into the person array
	 * as long as it's in the format ssn fn ln YYYYMMDD\n.
	 */
	string s = "database1.txt";

	//This function finds the number of lines the fin has.
	int n = determineSize(s);
	
	// After determining the size, the array of books is created.

	Person *p = new Person[1000];
	finData(s, p);
	/*
	//I commented out this section because of automation, if you want to check my
	//sorting algorithms just uncomment this section.
	cout<<"Populated the array with the file \n";
	finData(s, p);

	bubbleSort(p,n);
	shakerSort(p,n);
	selectionSort(p,n);
	insertionSort(p,n);

	print(p,n);
	//*/

	/*AUTOMATION SECTION
	 * This section is to measure the time it takes to sort an array.
	 * It starts by defining the fin file name ex: s = "database20.txt";
	 * It then deletes the array stored in the heap and creats one according
	 * to the size of the new file
	 * There are 4 sections, one for each sorting algorithms, that each have a
	 * for loop. Each time the for loop restarts it fins the file to
	 * hace a clean array that repeat each sorting algorithm 3 times to obtain an
	 * average. Each time it goes through the loop it prints out the three
	 * different times it took to sort, sort the sorted array, and sort
	 * the reversed array.
	 *
	 * You can change the database by modifying the string s
	 */

	// <- delete one "/" to comment this whole section out

	//initialize doubles to measure time and index.
	double beforeUnsorted, afterUnsorted,beforeSorted, afterSorted, beforeReversed, afterReversed,i;

	//////////////////////////////////////////////////////////////////////
	s = "database1.txt";
	delete[] p; //prevents leaks
	n = determineSize(s);
	p = new Person[n];
	cout<<" Using bubble sort for "<<s<<endl;
	for(i =1; i<=3;i++){
		finData(s, p);

		beforeUnsorted = getCPUTime();
		bubbleSort(p,n);
		afterUnsorted = getCPUTime();

		beforeSorted = getCPUTime();
		bubbleSort(p,n);
		afterSorted = getCPUTime();

		reverse(p,n);

		beforeReversed = getCPUTime();
		bubbleSort(p,n);
		afterReversed = getCPUTime();
		cout<<"\n ===================================== \n";
		cout<<" Trial number: "<< i<<endl;
		cout<< "Unsorted time = "<<afterUnsorted-beforeUnsorted<<endl;
		cout<< "Sorted time = "<<afterSorted-beforeSorted<<endl;
		cout<< "Reversed time = "<< afterReversed - beforeReversed<<endl;
	}

	cout<<"\n //////////////////////////////////////////////";
	cout<<"\n //////////////////////////////////////////////\n";

	cout<<" Using Shaker sort for:"<<s<<endl;
	for(i =1; i<=3;i++){
		finData(s, p);

		beforeUnsorted = getCPUTime();
		shakerSort(p,n);
		afterUnsorted = getCPUTime();

		beforeSorted = getCPUTime();
		shakerSort(p,n);
		afterSorted = getCPUTime();

		reverse(p,n);

		beforeReversed = getCPUTime();
		shakerSort(p,n);
		afterReversed = getCPUTime();
		cout<<"\n ===================================== \n";
		cout<<" Trial number: "<< i<<endl;
		cout<< "Unsorted time = "<<afterUnsorted-beforeUnsorted<<endl;
		cout<< "Sorted time = "<<afterSorted-beforeSorted<<endl;
		cout<< "Reversed time = "<< afterReversed - beforeReversed<<endl;
	}
	cout<<"\n //////////////////////////////////////////////";
	cout<<"\n //////////////////////////////////////////////\n";
	cout<<" Using selection sort for:"<<s<<endl;
	for(i =1; i<=3;i++){
		finData(s, p);

		beforeUnsorted = getCPUTime();
		selectionSort(p,n);
		afterUnsorted = getCPUTime();

		beforeSorted = getCPUTime();
		selectionSort(p,n);
		afterSorted = getCPUTime();

		reverse(p,n);

		beforeReversed = getCPUTime();
		selectionSort(p,n);
		afterReversed = getCPUTime();
		cout<<"\n ===================================== \n";
		cout<<" Trial number: "<< i<<endl;
		cout<< "Unsorted time = "<<afterUnsorted-beforeUnsorted<<endl;
		cout<< "Sorted time = "<<afterSorted-beforeSorted<<endl;
		cout<< "Reversed time = "<< afterReversed - beforeReversed<<endl;
	}

	cout<<"\n //////////////////////////////////////////////";
	cout<<"\n //////////////////////////////////////////////\n";

	cout<<" Using insertion sort for:"<<s<<endl;
	for(i =1; i<=3;i++){
		finData(s, p);

		beforeUnsorted = getCPUTime();
		insertionSort(p,n);
		afterUnsorted = getCPUTime();

		beforeSorted = getCPUTime();
		insertionSort(p,n);
		afterSorted = getCPUTime();

		reverse(p,n);

		beforeReversed = getCPUTime();
		insertionSort(p,n);
		afterReversed = getCPUTime();
		cout<<"\n ===================================== \n";
		cout<<" Trial number: "<< i<<endl;
		cout<< "Unsorted time = "<<afterUnsorted-beforeUnsorted<<endl;
		cout<< "Sorted time = "<<afterSorted-beforeSorted<<endl;
		cout<< "Reversed time = "<< afterReversed - beforeReversed<<endl;
	}
	cout<<"\n#############################################################\n";
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//*/
	
	return 0;
}



