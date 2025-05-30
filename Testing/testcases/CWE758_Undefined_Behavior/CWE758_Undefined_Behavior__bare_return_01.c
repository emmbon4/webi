/*
 * @description Undefined Behavior
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static int helper_bad(void){
	
	/* FLAW: bare return in a function with an explicit return type of int */
	return;
}

void CWE758_Undefined_Behavior__bare_return_01_bad() {
	int data = helper_bad();
	printIntLine(data);
}

#endif /* OMITBAD */


#ifndef OMITGOOD

static int helper_good1(void){
	
	/* FIX: return a value */
	return 5;
}

static void good1() {
	int data = helper_good1();
	printIntLine(data);
}

void CWE758_Undefined_Behavior__bare_return_01_good() 
{
    good1();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on 
   its own for testing or for building a binary to use in testing binary 
   analysis tools. It is not used when compiling all the testcases as one 
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[]) {

    /* seed randomness */
    srand( (unsigned)time(NULL) );

#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE758_Undefined_Behavior__bare_return_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */

#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE758_Undefined_Behavior__bare_return_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;

} 

#endif