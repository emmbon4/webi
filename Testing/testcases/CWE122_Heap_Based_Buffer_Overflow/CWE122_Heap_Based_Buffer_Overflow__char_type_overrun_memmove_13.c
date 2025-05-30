/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__char_type_overrun_memmove_13.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Sinks: type_overrun_memmove
 *    GoodSink: Perform the memmove() and prevent overwriting part of the structure
 *    BadSink : Overwrite part of the structure by incorrectly using the sizeof(struct) in memmove()
 * Flow Variant: 13 Control flow: if(global_const_five==5) and if(global_const_five!=5)
 *
 * */

#include "std_testcase.h"

#define SRC_STR "0123456789abcde0123"

typedef struct _charvoid
{
    char x[16];
    void * y;
    void * z;
} charvoid;

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__char_type_overrun_memmove_13_bad()
{
    if(global_const_five==5)
    {
        {
            charvoid * cv_struct = (charvoid *)malloc(sizeof(charvoid));
            cv_struct->y = SRC_STR;
            /* Print the initial block pointed to by cv_struct->y */
            printLine((char *)cv_struct->y);
            /* FLAW: Use the sizeof(*cv_struct) which will overwrite the pointer y */
            memmove(cv_struct->x, SRC_STR, sizeof(*cv_struct));
            cv_struct->x[(sizeof(cv_struct->x)/sizeof(char))-1] = '\0'; /* null terminate the string */
            printLine((char *)cv_struct->x);
            printLine((char *)cv_struct->y);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            charvoid * cv_struct = (charvoid *)malloc(sizeof(charvoid));
            cv_struct->y = SRC_STR;
            /* Print the initial block pointed to by cv_struct->y */
            printLine((char *)cv_struct->y);
            /* FIX: Use the sizeof(cv_struct->x) to avoid overwriting the pointer y */
            memmove(cv_struct->x, SRC_STR, sizeof(cv_struct->x));
            cv_struct->x[(sizeof(cv_struct->x)/sizeof(char))-1] = '\0'; /* null terminate the string */
            printLine((char *)cv_struct->x);
            printLine((char *)cv_struct->y);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_const_five!=5) instead of if(global_const_five==5) */
static void good1()
{
    if(global_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            charvoid * cv_struct = (charvoid *)malloc(sizeof(charvoid));
            cv_struct->y = SRC_STR;
            /* Print the initial block pointed to by cv_struct->y */
            printLine((char *)cv_struct->y);
            /* FLAW: Use the sizeof(*cv_struct) which will overwrite the pointer y */
            memmove(cv_struct->x, SRC_STR, sizeof(*cv_struct));
            cv_struct->x[(sizeof(cv_struct->x)/sizeof(char))-1] = '\0'; /* null terminate the string */
            printLine((char *)cv_struct->x);
            printLine((char *)cv_struct->y);
        }
    }
    else
    {
        {
            charvoid * cv_struct = (charvoid *)malloc(sizeof(charvoid));
            cv_struct->y = SRC_STR;
            /* Print the initial block pointed to by cv_struct->y */
            printLine((char *)cv_struct->y);
            /* FIX: Use the sizeof(cv_struct->x) to avoid overwriting the pointer y */
            memmove(cv_struct->x, SRC_STR, sizeof(cv_struct->x));
            cv_struct->x[(sizeof(cv_struct->x)/sizeof(char))-1] = '\0'; /* null terminate the string */
            printLine((char *)cv_struct->x);
            printLine((char *)cv_struct->y);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_const_five==5)
    {
        {
            charvoid * cv_struct = (charvoid *)malloc(sizeof(charvoid));
            cv_struct->y = SRC_STR;
            /* Print the initial block pointed to by cv_struct->y */
            printLine((char *)cv_struct->y);
            /* FIX: Use the sizeof(cv_struct->x) to avoid overwriting the pointer y */
            memmove(cv_struct->x, SRC_STR, sizeof(cv_struct->x));
            cv_struct->x[(sizeof(cv_struct->x)/sizeof(char))-1] = '\0'; /* null terminate the string */
            printLine((char *)cv_struct->x);
            printLine((char *)cv_struct->y);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            charvoid * cv_struct = (charvoid *)malloc(sizeof(charvoid));
            cv_struct->y = SRC_STR;
            /* Print the initial block pointed to by cv_struct->y */
            printLine((char *)cv_struct->y);
            /* FLAW: Use the sizeof(*cv_struct) which will overwrite the pointer y */
            memmove(cv_struct->x, SRC_STR, sizeof(*cv_struct));
            cv_struct->x[(sizeof(cv_struct->x)/sizeof(char))-1] = '\0'; /* null terminate the string */
            printLine((char *)cv_struct->x);
            printLine((char *)cv_struct->y);
        }
    }
}

void CWE122_Heap_Based_Buffer_Overflow__char_type_overrun_memmove_13_good()
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
    CWE122_Heap_Based_Buffer_Overflow__char_type_overrun_memmove_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__char_type_overrun_memmove_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
