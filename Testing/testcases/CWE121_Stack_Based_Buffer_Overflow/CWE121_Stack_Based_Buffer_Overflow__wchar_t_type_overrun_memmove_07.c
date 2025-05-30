/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_07.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * Sinks: type_overrun_memmove
 *    GoodSink: Perform the memmove() and prevent overwriting part of the structure
 *    BadSink : Overwrite part of the structure by incorrectly using the sizeof(struct) in memmove()
 * Flow Variant: 07 Control flow: if(static_five==5) and if(static_five!=5)
 *
 * */

#include "std_testcase.h"

/* SRC_STR is 20 wchar_t long, including the null terminator */
#define SRC_STR L"0123456789abcde0123"

typedef struct _charvoid
{
    wchar_t x[16];
    void * y;
    void * z;
} charvoid;

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int static_five = 5;

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_07_bad()
{
    if(static_five==5)
    {
        {
            charvoid cv_struct;
            cv_struct.y = SRC_STR;
            /* Print the initial block pointed to by cv_struct.y */
            printWLine((wchar_t *)cv_struct.y);
            /* FLAW: Use the sizeof(cv_struct) which will overwrite the pointer y */
            memmove(cv_struct.x, SRC_STR, sizeof(cv_struct));
            cv_struct.x[(sizeof(cv_struct.x)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)cv_struct.x);
            printWLine((wchar_t *)cv_struct.y);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            charvoid cv_struct;
            cv_struct.y = SRC_STR;
            /* Print the initial block pointed to by cv_struct.y */
            printWLine((wchar_t *)cv_struct.y);
            /* FIX: Use sizeof(cv_struct.x) to avoid overwriting the pointer y */
            memmove(cv_struct.x, SRC_STR, sizeof(cv_struct.x));
            cv_struct.x[(sizeof(cv_struct.x)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)cv_struct.x);
            printWLine((wchar_t *)cv_struct.y);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_five!=5) instead of if(static_five==5) */
static void good1()
{
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            charvoid cv_struct;
            cv_struct.y = SRC_STR;
            /* Print the initial block pointed to by cv_struct.y */
            printWLine((wchar_t *)cv_struct.y);
            /* FLAW: Use the sizeof(cv_struct) which will overwrite the pointer y */
            memmove(cv_struct.x, SRC_STR, sizeof(cv_struct));
            cv_struct.x[(sizeof(cv_struct.x)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)cv_struct.x);
            printWLine((wchar_t *)cv_struct.y);
        }
    }
    else
    {
        {
            charvoid cv_struct;
            cv_struct.y = SRC_STR;
            /* Print the initial block pointed to by cv_struct.y */
            printWLine((wchar_t *)cv_struct.y);
            /* FIX: Use sizeof(cv_struct.x) to avoid overwriting the pointer y */
            memmove(cv_struct.x, SRC_STR, sizeof(cv_struct.x));
            cv_struct.x[(sizeof(cv_struct.x)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)cv_struct.x);
            printWLine((wchar_t *)cv_struct.y);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_five==5)
    {
        {
            charvoid cv_struct;
            cv_struct.y = SRC_STR;
            /* Print the initial block pointed to by cv_struct.y */
            printWLine((wchar_t *)cv_struct.y);
            /* FIX: Use sizeof(cv_struct.x) to avoid overwriting the pointer y */
            memmove(cv_struct.x, SRC_STR, sizeof(cv_struct.x));
            cv_struct.x[(sizeof(cv_struct.x)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)cv_struct.x);
            printWLine((wchar_t *)cv_struct.y);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            charvoid cv_struct;
            cv_struct.y = SRC_STR;
            /* Print the initial block pointed to by cv_struct.y */
            printWLine((wchar_t *)cv_struct.y);
            /* FLAW: Use the sizeof(cv_struct) which will overwrite the pointer y */
            memmove(cv_struct.x, SRC_STR, sizeof(cv_struct));
            cv_struct.x[(sizeof(cv_struct.x)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)cv_struct.x);
            printWLine((wchar_t *)cv_struct.y);
        }
    }
}

void CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_07_good()
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
    CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
