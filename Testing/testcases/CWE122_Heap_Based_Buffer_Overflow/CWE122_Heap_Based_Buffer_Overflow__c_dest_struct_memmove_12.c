/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memmove_12.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.label.xml
Template File: sources-sink-12.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: memmove
 *    BadSink : Copy twoints array to data using memmove
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memmove_12_bad()
{
    twoints * data;
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* FLAW: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
        data = (twoints *)malloc(50*sizeof(twoints));
    }
    else
    {
        /* FIX: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = (twoints *)malloc(100*sizeof(twoints));
    }
    {
        twoints src[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                src[i].a = 0;
                src[i].b = 0;
            }
        }
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, src, 100*sizeof(twoints));
        printStructLine(&data[0]);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the "if" so that
   both branches use the GoodSource */
static void goodG2B()
{
    twoints * data;
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* FIX: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = (twoints *)malloc(100*sizeof(twoints));
    }
    else
    {
        /* FIX: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = (twoints *)malloc(100*sizeof(twoints));
    }
    {
        twoints src[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                src[i].a = 0;
                src[i].b = 0;
            }
        }
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, src, 100*sizeof(twoints));
        printStructLine(&data[0]);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memmove_12_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memmove_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_memmove_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
