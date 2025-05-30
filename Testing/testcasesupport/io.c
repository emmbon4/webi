#include <stdio.h>
#include <stdlib.h>
#include "std_testcase.h"

void printLine (const char * line){
	if(line != NULL) {
		printf("%s\n", line);
	}
}

void printWLine (const wchar_t * line){
	if(line != NULL) {
		wprintf(L"%s\n", line);
	}
}

void printIntLine (int i){
	printf("%d\n", i);

}

void printLongLongLine (long long int i){
	printf("%lld\n", i);

}

void printSizeTLine (size_t i){
	printf("%ud\n", i);
}

void printHexCharLine (char c){
	printf("%02x\n", c);
}

void printWcharLine(wchar_t wc) {
	/* ISO standard dictates wchar_t can be ref'd only with %ls, so we must make a
	 * string to print a wchar */
	wchar_t s[2];
        s[0] = wc;
        s[1] = L'\0';
	printf("%ls\n", s);
}

void printUnsignedLine(unsigned u) {
	printf("%u\n", u);
}

void printHexUnsignedCharLine(unsigned char uc) {
	printf("%02x\n", uc);
}

void printDoubleLine(double d) {
	printf("%g\n", d);
}

void printStructLine (const twoints * t){
	printf("%d -- %d\n", t->a, t->b);

}

/* The two functions always return 1 or 0, so a tool should be able to 
   identify that uses of these functions will always return these values */
int global_returns_t() {
	return 1;
}

int global_returns_f() {
	return 0;
}

int global_returns_t_or_f() {
	return (rand() % 2);
}

/* The variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their 
   initialized values. */
const int global_const_t = 1; /* true */
const int global_const_f = 0; /* false */
const int global_const_five = 5; 

/* The variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
int global_t = 1; /* true */
int global_f = 0; /* false */
int global_five = 5; 

/* define a bunch of these as empty functions so that if a test case forgets
 to make their's statically scoped, we'll get a linker error */
void good1() { }
void good2() { }
void good3() { }
void good4() { }
void good5() { }
void good6() { }
void good7() { }
void good8() { }
void good9() { }

/* shouldn't be used, but just in case */
void bad1() { }
void bad2() { }
void bad3() { }
void bad4() { }
void bad5() { }
void bad6() { }
void bad7() { }
void bad8() { }
void bad9() { }

/* define global argc and argv */

#ifdef __cplusplus
extern "C" {
#endif

int global_argc = 0;
char** global_argv = NULL;

#ifdef __cplusplus
}
#endif
