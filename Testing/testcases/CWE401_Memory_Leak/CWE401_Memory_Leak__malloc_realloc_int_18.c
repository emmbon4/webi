/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__malloc_realloc_int_18.c
Label Definition File: CWE401_Memory_Leak__malloc_realloc.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Sinks:
 *    GoodSink: Ensure the memory block pointed to by data is always freed
 *    BadSink : malloc() and use then realloc() and use data before free()
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE401_Memory_Leak__malloc_realloc_int_18_bad()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        int * data = (int *)malloc(100*sizeof(int));
        int * tmp;
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
        tmp = (int *)realloc(data, (130000)*sizeof(int));
        /* FIX: Ensure realloc() was successful before assigning data to the memory block
         * allocated with realloc() */
        if (tmp != NULL)
        {
            data = tmp;
            /* Reinitialize and make use of data */
            data[0] = 10;
            printIntLine(data[0]);
        }
        free(data);
    }
sink:
    {
        int * data = (int *)malloc(100*sizeof(int));
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
        /* FLAW: If realloc() fails, the initial memory block will not be freed() */
        data = (int *)realloc(data, (130000)*sizeof(int));
        if (data != NULL)
        {
            /* Reinitialize and make use of data */
            data[0] = 10;
            printIntLine(data[0]);
            free(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        int * data = (int *)malloc(100*sizeof(int));
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
        /* FLAW: If realloc() fails, the initial memory block will not be freed() */
        data = (int *)realloc(data, (130000)*sizeof(int));
        if (data != NULL)
        {
            /* Reinitialize and make use of data */
            data[0] = 10;
            printIntLine(data[0]);
            free(data);
        }
    }
sink:
    {
        int * data = (int *)malloc(100*sizeof(int));
        int * tmp;
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
        tmp = (int *)realloc(data, (130000)*sizeof(int));
        /* FIX: Ensure realloc() was successful before assigning data to the memory block
         * allocated with realloc() */
        if (tmp != NULL)
        {
            data = tmp;
            /* Reinitialize and make use of data */
            data[0] = 10;
            printIntLine(data[0]);
        }
        free(data);
    }
}

void CWE401_Memory_Leak__malloc_realloc_int_18_good()
{
    good1();
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
    CWE401_Memory_Leak__malloc_realloc_int_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__malloc_realloc_int_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
