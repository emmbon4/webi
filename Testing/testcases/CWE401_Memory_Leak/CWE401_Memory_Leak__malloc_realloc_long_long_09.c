/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__malloc_realloc_long_long_09.c
Label Definition File: CWE401_Memory_Leak__malloc_realloc.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Sinks:
 *    GoodSink: Ensure the memory block pointed to by data is always freed
 *    BadSink : malloc() and use then realloc() and use data before free()
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE401_Memory_Leak__malloc_realloc_long_long_09_bad()
{
    if(global_const_t)
    {
        {
            long long * data = (long long *)malloc(100*sizeof(long long));
            /* Initialize and make use of data */
            data[0] = 5L;
            printLongLongLine(data[0]);
            /* FLAW: If realloc() fails, the initial memory block will not be freed() */
            data = (long long *)realloc(data, (130000)*sizeof(long long));
            if (data != NULL)
            {
                /* Reinitialize and make use of data */
                data[0] = 10L;
                printLongLongLine(data[0]);
                free(data);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            long long * data = (long long *)malloc(100*sizeof(long long));
            long long * tmp;
            /* Initialize and make use of data */
            data[0] = 5L;
            printLongLongLine(data[0]);
            tmp = (long long *)realloc(data, (130000)*sizeof(long long));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
             * allocated with realloc() */
            if (tmp != NULL)
            {
                data = tmp;
                /* Reinitialize and make use of data */
                data[0] = 10L;
                printLongLongLine(data[0]);
            }
            free(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_const_f) instead of if(global_const_t) */
static void good1()
{
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            long long * data = (long long *)malloc(100*sizeof(long long));
            /* Initialize and make use of data */
            data[0] = 5L;
            printLongLongLine(data[0]);
            /* FLAW: If realloc() fails, the initial memory block will not be freed() */
            data = (long long *)realloc(data, (130000)*sizeof(long long));
            if (data != NULL)
            {
                /* Reinitialize and make use of data */
                data[0] = 10L;
                printLongLongLine(data[0]);
                free(data);
            }
        }
    }
    else
    {
        {
            long long * data = (long long *)malloc(100*sizeof(long long));
            long long * tmp;
            /* Initialize and make use of data */
            data[0] = 5L;
            printLongLongLine(data[0]);
            tmp = (long long *)realloc(data, (130000)*sizeof(long long));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
             * allocated with realloc() */
            if (tmp != NULL)
            {
                data = tmp;
                /* Reinitialize and make use of data */
                data[0] = 10L;
                printLongLongLine(data[0]);
            }
            free(data);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_const_t)
    {
        {
            long long * data = (long long *)malloc(100*sizeof(long long));
            long long * tmp;
            /* Initialize and make use of data */
            data[0] = 5L;
            printLongLongLine(data[0]);
            tmp = (long long *)realloc(data, (130000)*sizeof(long long));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
             * allocated with realloc() */
            if (tmp != NULL)
            {
                data = tmp;
                /* Reinitialize and make use of data */
                data[0] = 10L;
                printLongLongLine(data[0]);
            }
            free(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            long long * data = (long long *)malloc(100*sizeof(long long));
            /* Initialize and make use of data */
            data[0] = 5L;
            printLongLongLine(data[0]);
            /* FLAW: If realloc() fails, the initial memory block will not be freed() */
            data = (long long *)realloc(data, (130000)*sizeof(long long));
            if (data != NULL)
            {
                /* Reinitialize and make use of data */
                data[0] = 10L;
                printLongLongLine(data[0]);
                free(data);
            }
        }
    }
}

void CWE401_Memory_Leak__malloc_realloc_long_long_09_good()
{
    good1();
    good2();
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
    CWE401_Memory_Leak__malloc_realloc_long_long_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__malloc_realloc_long_long_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
