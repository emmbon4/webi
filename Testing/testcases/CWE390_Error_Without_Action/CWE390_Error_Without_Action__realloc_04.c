/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__realloc_04.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: realloc
 *    GoodSink: Check to see if realloc() failed, and handle errors properly
 *    BadSink : Check to see if realloc() failed, but fail to handle errors
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE390_Error_Without_Action__realloc_04_bad()
{
    if(static_const_t)
    {
        {
            char * data = NULL;
            data = (char *)realloc(data, 100);
            /* FLAW: Check to see if realloc() failed, but do nothing about it */
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data = NULL;
            data = (char *)realloc(data, 100);
            /* FIX: Check to see if realloc() failed and handle errors properly */
            if (data == NULL)
            {
                printLine("realloc() failed");
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
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_const_f) instead of if(static_const_t) */
static void good1()
{
    if(static_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data = NULL;
            data = (char *)realloc(data, 100);
            /* FLAW: Check to see if realloc() failed, but do nothing about it */
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
    else
    {
        {
            char * data = NULL;
            data = (char *)realloc(data, 100);
            /* FIX: Check to see if realloc() failed and handle errors properly */
            if (data == NULL)
            {
                printLine("realloc() failed");
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
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_t)
    {
        {
            char * data = NULL;
            data = (char *)realloc(data, 100);
            /* FIX: Check to see if realloc() failed and handle errors properly */
            if (data == NULL)
            {
                printLine("realloc() failed");
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data = NULL;
            data = (char *)realloc(data, 100);
            /* FLAW: Check to see if realloc() failed, but do nothing about it */
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
}

void CWE390_Error_Without_Action__realloc_04_good()
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
    CWE390_Error_Without_Action__realloc_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__realloc_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
