/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__malloc_18.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: malloc
 *    GoodSink: Check to see if malloc() failed, and handle errors properly
 *    BadSink : Check to see if malloc() failed, but fail to handle errors
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE390_Error_Without_Action__malloc_18_bad()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * data = (char *)malloc(100);
        /* FIX: Check to see if malloc() failed and handle errors properly */
        if (data == NULL)
        {
            printLine("malloc() failed");
            exit(1);
        }
        strcpy(data, "BadSinkBody");
        printLine(data);
        if (data != NULL)
        {
            free(data);
        }
    }
sink:
    {
        char * data = (char *)malloc(100);
        /* FLAW: Check to see if malloc() failed, but do nothing about it */
        if (data == NULL)
        {
            /* do nothing */
        }
        strcpy(data, "BadSinkBody");
        printLine(data);
        if (data != NULL)
        {
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
        char * data = (char *)malloc(100);
        /* FLAW: Check to see if malloc() failed, but do nothing about it */
        if (data == NULL)
        {
            /* do nothing */
        }
        strcpy(data, "BadSinkBody");
        printLine(data);
        if (data != NULL)
        {
            free(data);
        }
    }
sink:
    {
        char * data = (char *)malloc(100);
        /* FIX: Check to see if malloc() failed and handle errors properly */
        if (data == NULL)
        {
            printLine("malloc() failed");
            exit(1);
        }
        strcpy(data, "BadSinkBody");
        printLine(data);
        if (data != NULL)
        {
            free(data);
        }
    }
}

void CWE390_Error_Without_Action__malloc_18_good()
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
    CWE390_Error_Without_Action__malloc_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__malloc_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
