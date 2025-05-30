/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_sscanf_12.c
Label Definition File: CWE252_Unchecked_Return_Value.string.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: sscanf
 *    GoodSink: Check if sscanf() fails
 *    BadSink : Do not check if sscanf() fails
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#define SRC "sscanf"

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__char_sscanf_12_bad()
{
    if(global_returns_t_or_f())
    {
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char data_buf[100] = "";
            char * data = data_buf;
            /* FLAW: Do not check the return value */
            sscanf(SRC, "%99s\0", data);
        }
    }
    else
    {
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char data_buf[100] = "";
            char * data = data_buf;
            /* FIX: check the return value */
            if (sscanf(SRC, "%99s\0", data) == EOF)
            {
                printLine("sscanf failed!");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(global_returns_t_or_f())
    {
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char data_buf[100] = "";
            char * data = data_buf;
            /* FIX: check the return value */
            if (sscanf(SRC, "%99s\0", data) == EOF)
            {
                printLine("sscanf failed!");
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
            /* FIX: check the return value */
            if (sscanf(SRC, "%99s\0", data) == EOF)
            {
                printLine("sscanf failed!");
            }
        }
    }
}

void CWE252_Unchecked_Return_Value__char_sscanf_12_good()
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
    CWE252_Unchecked_Return_Value__char_sscanf_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__char_sscanf_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
