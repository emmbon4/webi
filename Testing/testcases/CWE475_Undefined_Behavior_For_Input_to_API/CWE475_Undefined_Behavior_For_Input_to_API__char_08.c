/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE475_Undefined_Behavior_For_Input_to_API__char_08.c
Label Definition File: CWE475_Undefined_Behavior_For_Input_to_API.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 475 Undefined Behavior For Input to API
 * Sinks:
 *    GoodSink: Copy overlapping memory regions using memmove()
 *    BadSink : Copy overlapping memory regions using memcpy()
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

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

void CWE475_Undefined_Behavior_For_Input_to_API__char_08_bad()
{
    if(static_returns_t())
    {
        {
            char data_buf[100] = "";
            char * data = data_buf;
            strcpy(data, "abcdefghijklmnopqrstuvwxyz");
            /* FLAW: Copy overlapping memory regions using memcpy() for which the result is undefined */
            memcpy(data + 6, data + 4, 10*sizeof(char));
            printLine(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char data_buf[100] = "";
            char * data = data_buf;
            strcpy(data, "abcdefghijklmnopqrstuvwxyz");
            /* FIX: Copy overlapping memory regions using memmove() */
            memmove(data + 6, data + 4, 10*sizeof(char));
            printLine(data);
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
            char data_buf[100] = "";
            char * data = data_buf;
            strcpy(data, "abcdefghijklmnopqrstuvwxyz");
            /* FLAW: Copy overlapping memory regions using memcpy() for which the result is undefined */
            memcpy(data + 6, data + 4, 10*sizeof(char));
            printLine(data);
        }
    }
    else
    {
        {
            char data_buf[100] = "";
            char * data = data_buf;
            strcpy(data, "abcdefghijklmnopqrstuvwxyz");
            /* FIX: Copy overlapping memory regions using memmove() */
            memmove(data + 6, data + 4, 10*sizeof(char));
            printLine(data);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_returns_t())
    {
        {
            char data_buf[100] = "";
            char * data = data_buf;
            strcpy(data, "abcdefghijklmnopqrstuvwxyz");
            /* FIX: Copy overlapping memory regions using memmove() */
            memmove(data + 6, data + 4, 10*sizeof(char));
            printLine(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char data_buf[100] = "";
            char * data = data_buf;
            strcpy(data, "abcdefghijklmnopqrstuvwxyz");
            /* FLAW: Copy overlapping memory regions using memcpy() for which the result is undefined */
            memcpy(data + 6, data + 4, 10*sizeof(char));
            printLine(data);
        }
    }
}

void CWE475_Undefined_Behavior_For_Input_to_API__char_08_good()
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
    CWE475_Undefined_Behavior_For_Input_to_API__char_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE475_Undefined_Behavior_For_Input_to_API__char_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
