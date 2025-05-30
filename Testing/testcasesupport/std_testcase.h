#ifndef _STD_TESTCASE_H
#define _STD_TESTCASE_H

/* This file exists in order to:
 * 1) Include lots of standardized headers in one place
 * 2) To avoid #include-ing things in the middle of your code
 *    #include-ing in the middle of a C/C++ file is apt to cause compiler errors
 * 3) To get good #define's in place
 *
 * In reality you need a complex interaction of scripts of build processes to do
 * this correctly (i.e., autoconf)
 */

#ifdef _WIN32
/* Ensure the CRT does not disable the "insecure functions"
 * Ensure not to generate warnings about ANSI C functions.
 */
# define _CRT_SECURE_NO_DEPRECATE 1
# define _CRT_SECURE_NO_WARNING 1

#define ALLOCA _alloca

/* disable warnings about use of POSIX names for functions like execl()
 Visual Studio wants you to use the ISO C++ name, such as _execl() */
#pragma warning(disable:4996)

#else
/* Linux/GNU wants this macro, otherwise stdint.h and limits.h are mostly useless */
# define __STDC_LIMIT_MACROS 1

#define ALLOCA alloca
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#ifndef _WIN32
/* SIZE_MAX is in this file on Linux */
# include <stdint.h>
#endif
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifdef _WIN32
# include <io.h> /* for open/close etc */
#endif

#ifdef __cplusplus
#include <new> // for placement new

/* class used in some test cases as a custom type */
class twointsclass {
public: // Needed to access variables from label files
	int a;
	int b;
};

#endif

#ifndef __cplusplus
/* Define true and false, which are included in C++, but not in C */
#define true 1
#define false 0

#endif /* end ifndef __cplusplus */

/* rand only returns 15 bits, so we xor 3 calls together to get the full result (13 bits overflow, but that is okay) */
#define RAND32() ((rand()<<30) ^ (rand()<<15) ^ rand())

/* rand only returns 15 bits, so we xor 5 calls together to get the full result (11 bits overflow, but that is okay) */
#define RAND64() ((rand()<<60) ^ (rand()<<45) ^ (rand()<<30) ^ (rand()<<15) ^ rand())

/* struct used in some test cases as a custom type */
typedef struct _twoints
{
 int a;
 int b;
} twoints;

#ifdef __cplusplus
extern "C" {
#endif

/* The variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their 
   initialized values. */
extern const int global_const_t; /* true */
extern const int global_const_f; /* false */
extern const int global_const_five; /* 5 */

/* The variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
extern int global_t; /* true */
extern int global_f; /* false */
extern int global_five; /* 5 */

#ifdef __cplusplus
}
#endif

#include "std_testcase_io.h"

#endif
