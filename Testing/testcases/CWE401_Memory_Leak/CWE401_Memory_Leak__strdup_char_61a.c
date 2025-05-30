/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_61a.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
char * CWE401_Memory_Leak__strdup_char_61b_bad_source(char * data);

void CWE401_Memory_Leak__strdup_char_61_bad()
{
    char * data;
    data = NULL;
    data = CWE401_Memory_Leak__strdup_char_61b_bad_source(data);
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
char * CWE401_Memory_Leak__strdup_char_61b_goodG2B_source(char * data);

static void goodG2B()
{
    char * data;
    data = NULL;
    data = CWE401_Memory_Leak__strdup_char_61b_goodG2B_source(data);
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
char * CWE401_Memory_Leak__strdup_char_61b_goodB2G_source(char * data);

static void goodB2G()
{
    char * data;
    data = NULL;
    data = CWE401_Memory_Leak__strdup_char_61b_goodB2G_source(data);
    /* FIX: Deallocate memory initialized in the source */
    free(data);
}

void CWE401_Memory_Leak__strdup_char_61_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE401_Memory_Leak__strdup_char_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__strdup_char_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
