/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__char_fwrite_11.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-11.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fwrite
 *    GoodSink: Correctly check if fwrite() failed
 *    BadSink : Incorrectly check if fwrite() failed
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__char_fwrite_11_bad()
{
    if(global_returns_t())
    {
        {
            /* FLAW: fwrite() might fail, in which case the return value will not be equal to strlen(data),
             * but we are checking to see if the return value is less than 0 */
            if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0)
            {
                printLine("fwrite failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check for the correct return value */
            if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) != strlen("string"))
            {
                printLine("fwrite failed!");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_returns_f()) instead of if(global_returns_t()) */
static void good1()
{
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: fwrite() might fail, in which case the return value will not be equal to strlen(data),
             * but we are checking to see if the return value is less than 0 */
            if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0)
            {
                printLine("fwrite failed!");
            }
        }
    }
    else
    {
        {
            /* FIX: check for the correct return value */
            if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) != strlen("string"))
            {
                printLine("fwrite failed!");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_returns_t())
    {
        {
            /* FIX: check for the correct return value */
            if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) != strlen("string"))
            {
                printLine("fwrite failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: fwrite() might fail, in which case the return value will not be equal to strlen(data),
             * but we are checking to see if the return value is less than 0 */
            if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0)
            {
                printLine("fwrite failed!");
            }
        }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__char_fwrite_11_good()
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
    CWE253_Incorrect_Check_of_Return_Value__char_fwrite_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__char_fwrite_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
