/*
 * support.h
 *
 *  Created on: Sep 6, 2016
 *      Author: nigel
 */

#ifndef SUPPORT_H_
#define SUPPORT_H_

#include <stdlib.h>
#include <string>
#include <ctime>


using namespace std;

//////////////////My functions/////////////////////
int getCalendarDate(void);
int string2int(string);
int pow(int, int);
///////////////////////////////////////////////////

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
#include <sys/time.h>
#include <sys/resource.h>
#elif defined(_WIN32)
#include <time.h>
#endif

double getCPUTime(void);
int randomInRange(const int start, const int end);

#endif /* SUPPORT_H_ */

