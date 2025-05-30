/* header file to define functions in io.c.  Not named io.h
   because that name is already taken by a system header on 
	 Windows */

#ifndef _STD_TESTCASE_IO_H
#define _STD_TESTCASE_IO_H

#include "std_testcase.h" /* needed for the twoint struct */

#ifdef __cplusplus
extern "C" {
#endif

void printLine(const char * line);

void printWLine(const wchar_t * line);

void printIntLine (int i);

void printLongLongLine(long long int i);

void printSizeTLine(size_t i);

void printHexCharLine(char c);

void printWcharLine(wchar_t wc);

void printUnsignedLine(unsigned u);

void printHexUnsignedCharLine(unsigned char uc);

void printDoubleLine(double d);

void printStructLine(const twoints * t);

int global_returns_t();

int global_returns_f();

int global_returns_t_or_f();

/* Define some global variables that will get argc and argv */
extern int global_argc;
extern char** global_argv;

#ifdef __cplusplus
}
#endif

#endif
