/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_src_char_snprintf_04.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_src.label.xml
Template File: sources-sink-04.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: snprintf
 *    BadSink : Copy data to string using snprintf
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_src_char_snprintf_04_bad()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if(static_const_t)
    {
        /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
        memset(data, 'A', 100-1); /* fill with 'A's */
        data[100-1] = '\0'; /* null terminate */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
        memset(data, 'A', 50-1); /* fill with 'A's */
        data[50-1] = '\0'; /* null terminate */
    }
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        _snprintf(dest, strlen(data), "%s", data);
        printLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_const_t to static_const_f */
static void goodG2B1()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if(static_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
        memset(data, 'A', 100-1); /* fill with 'A's */
        data[100-1] = '\0'; /* null terminate */
    }
    else
    {
        /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
        memset(data, 'A', 50-1); /* fill with 'A's */
        data[50-1] = '\0'; /* null terminate */
    }
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        _snprintf(dest, strlen(data), "%s", data);
        printLine(data);
        free(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if(static_const_t)
    {
        /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
        memset(data, 'A', 50-1); /* fill with 'A's */
        data[50-1] = '\0'; /* null terminate */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
        memset(data, 'A', 100-1); /* fill with 'A's */
        data[100-1] = '\0'; /* null terminate */
    }
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        _snprintf(dest, strlen(data), "%s", data);
        printLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_src_char_snprintf_04_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE122_Heap_Based_Buffer_Overflow__c_src_char_snprintf_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_src_char_snprintf_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
