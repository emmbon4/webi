/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__char_sscanf_03.c
Label Definition File: CWE390_Error_Without_Action.string.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: sscanf
 *    GoodSink: Check if sscanf() failed and handle errors properly
 *    BadSink : Check to see if sscanf() failed, but do nothing about it
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#define SRC "sscanf"

#ifndef OMITBAD

void CWE390_Error_Without_Action__char_sscanf_03_bad()
{
    if(5==5)
    {
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char data_buf[100] = "";
            char * data = data_buf;
            /* FLAW: check the return value, but do nothing if there is an error */
            if (sscanf(SRC, "%99s\0", data) == EOF)
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
            if (sscanf(SRC, "%99s\0", data) == EOF)
            {
                printLine("sscanf failed!");
                exit(1);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(5!=5) instead of if(5==5) */
static void good1()
{
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char data_buf[100] = "";
            char * data = data_buf;
            /* FLAW: check the return value, but do nothing if there is an error */
            if (sscanf(SRC, "%99s\0", data) == EOF)
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
            if (sscanf(SRC, "%99s\0", data) == EOF)
            {
                printLine("sscanf failed!");
                exit(1);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(5==5)
    {
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char data_buf[100] = "";
            char * data = data_buf;
            /* FIX: check the return value and handle errors properly */
            if (sscanf(SRC, "%99s\0", data) == EOF)
            {
                printLine("sscanf failed!");
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
            if (sscanf(SRC, "%99s\0", data) == EOF)
            {
                /* do nothing */
            }
        }
    }
}

void CWE390_Error_Without_Action__char_sscanf_03_good()
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
    CWE390_Error_Without_Action__char_sscanf_03_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__char_sscanf_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
