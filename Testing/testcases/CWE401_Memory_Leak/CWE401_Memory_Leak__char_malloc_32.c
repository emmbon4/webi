/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__char_malloc_32.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: malloc Allocate data using malloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__char_malloc_32_bad()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    data = NULL;
    {
        char * data = *data_ptr1;
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (char *)malloc(100*sizeof(char));
        /* Initialize and make use of data */
        strcpy(data, "A String");
        printLine(data);
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    data = NULL;
    {
        char * data = *data_ptr1;
        {
            /* FIX: Use memory allocated on the stack */
            char data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            strcpy(data, "A String");
            printLine(data);
        }
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    data = NULL;
    {
        char * data = *data_ptr1;
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (char *)malloc(100*sizeof(char));
        /* Initialize and make use of data */
        strcpy(data, "A String");
        printLine(data);
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        /* FIX: Deallocate memory */
        free(data);
    }
}

void CWE401_Memory_Leak__char_malloc_32_good()
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
    CWE401_Memory_Leak__char_malloc_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__char_malloc_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
