/*
 * support.cpp
 *
 *  Created on: Sep 6, 2016
 *      Author: nigel
 */

#include "support.h"

//////////////////My functions/////////////////////
int pow(const int m,const int n){
	if(n>0){
		int temp = m;
		for(int i = 1; i < n; i++){
			temp *= m;
		}
		return temp;
	}
	else return 1;	
}
int getCalendarDate(void){
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	return ((now->tm_year + 1900)*10000 + (now->tm_mon + 1)*100 + (now->tm_mday));
	delete now;
}
int string2int(string s){
	int i = 0, j = s.length() -1, temp,result = 0;
		char c;
		while(i < s.length()){
			c = s[i];
			temp = (int)c -48;
			result += temp*pow(10,j);
			i++;
			j--;
		}
	return result;
}
///////////////////////////////////////////////////

double getCPUTime(void) {
#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
	struct timeval tv;
	struct rusage ru;
	getrusage(RUSAGE_SELF, &ru);
	tv = ru.ru_utime;
	double t = (double)tv.tv_sec + (double)tv.tv_usec/1000000.0;
	tv = ru.ru_stime;
	t += (double)tv.tv_sec + (double)tv.tv_usec/1000000.0;
	return t;
#elif defined(_WIN32)
	return clock()/(double)CLOCKS_PER_SEC;
#endif
}


int randomInRange(const int start, const int end) {
#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
	return (start + random()%(end-start+1));
#elif defined(_WIN32)
	return (start + rand()%(end-start+1));
#endif
}


