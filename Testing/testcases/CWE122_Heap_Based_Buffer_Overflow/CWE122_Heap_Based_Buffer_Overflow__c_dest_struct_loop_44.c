/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_loop_44.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.label.xml
Template File: sources-sink-44.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: loop
 *    BadSink : Copy twoints array to data using a loop
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static void bad_sink(twoints * data)
{
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
        {
            size_t i;
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            for (i = 0; i < 100; i++)
            {
                data[i] = src[i];
            }
            printStructLine(&data[0]);
            free(data);
        }
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_loop_44_bad()
{
    twoints * data;
    /* define a function pointer */
    void (*func_ptr) (twoints *) = bad_sink;
    data = NULL;
    /* FLAW: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = (twoints *)malloc(50*sizeof(twoints));
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink(twoints * data)
{
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
        {
            size_t i;
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            for (i = 0; i < 100; i++)
            {
                data[i] = src[i];
            }
            printStructLine(&data[0]);
            free(data);
        }
    }
}

static void goodG2B()
{
    twoints * data;
    void (*func_ptr) (twoints *) = goodG2B_sink;
    data = NULL;
    /* FIX: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
    data = (twoints *)malloc(100*sizeof(twoints));
    func_ptr(data);
}

void CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_loop_44_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_loop_44_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_dest_struct_loop_44_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
