/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_42.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-42.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: ncat
 *    BadSink : Copy string to data using strncat
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

static char * bad_source(char * data)
{
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    return data;
}

void CWE665_Improper_Initialization__char_ncat_42_bad()
{
    char * data;
    char data_buf[100];
    data = data_buf;
    data = bad_source(data);
    {
        size_t src_len;
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        src_len = strlen(src);
        /* POTENTIAL FLAW: If data is not initialized properly, strncat() may not function correctly */
        strncat(data, src, src_len);
        printLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static char * goodG2B_source(char * data)
{
    /* FIX: Properly initialize data */
    data[0] = '\0'; /* null terminate */
    return data;
}

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char data_buf[100];
    data = data_buf;
    data = goodG2B_source(data);
    {
        size_t src_len;
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        src_len = strlen(src);
        /* POTENTIAL FLAW: If data is not initialized properly, strncat() may not function correctly */
        strncat(data, src, src_len);
        printLine(data);
    }
}

void CWE665_Improper_Initialization__char_ncat_42_good()
{
    goodG2B();
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
    CWE665_Improper_Initialization__char_ncat_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__char_ncat_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
