/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__char_snprintf_08.c
Label Definition File: CWE390_Error_Without_Action.string.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: snprintf
 *    GoodSink: Check if snprintf() failed and handle errors properly
 *    BadSink : Check to see if snprintf() failed, but do nothing about it
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#define SRC "string"

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

#ifndef OMITBAD

void CWE390_Error_Without_Action__char_snprintf_08_bad()
{
    if(static_returns_t())
    {
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char data_buf[100] = "";
            char * data = data_buf;
            /* FLAW: check the return value, but do nothing if there is an error */
            if (_snprintf(data,100-strlen(SRC)-1, "%s\n", SRC) < 0)
            {
                /* do nothing */
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char data_buf[100] = "";
            char * data = data_buf;
            /* FIX: check the return value and handle errors properly */
            if (_snprintf(data,100-strlen(SRC)-1, "%s\n", SRC) < 0)
            {
                printLine("snprintf failed!");
                exit(1);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_returns_f()) instead of if(static_returns_t()) */
static void good1()
{
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char data_buf[100] = "";
            char * data = data_buf;
            /* FLAW: check the return value, but do nothing if there is an error */
            if (_snprintf(data,100-strlen(SRC)-1, "%s\n", SRC) < 0)
            {
                /* do nothing */
            }
        }
    }
    else
    {
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char data_buf[100] = "";
            char * data = data_buf;
            /* FIX: check the return value and handle errors properly */
            if (_snprintf(data,100-strlen(SRC)-1, "%s\n", SRC) < 0)
            {
                printLine("snprintf failed!");
                exit(1);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_returns_t())
    {
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char data_buf[100] = "";
            char * data = data_buf;
            /* FIX: check the return value and handle errors properly */
            if (_snprintf(data,100-strlen(SRC)-1, "%s\n", SRC) < 0)
            {
                printLine("snprintf failed!");
                exit(1);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char data_buf[100] = "";
            char * data = data_buf;
            /* FLAW: check the return value, but do nothing if there is an error */
            if (_snprintf(data,100-strlen(SRC)-1, "%s\n", SRC) < 0)
            {
                /* do nothing */
            }
        }
    }
}

void CWE390_Error_Without_Action__char_snprintf_08_good()
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
    CWE390_Error_Without_Action__char_snprintf_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__char_snprintf_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
