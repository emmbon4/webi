/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_char_static_15.c
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free.label.xml
Template File: sources-sink-15.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_char_static_15_bad()
{
    char * data;
    data = NULL; /* Initialize data */
    switch(6)
    {
    case 6:
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        static char data_buf[100];
        memset(data_buf, 'A', 100-1); /* fill with 'A's */
        data_buf[100-1] = '\0'; /* null terminate */
        data = data_buf;
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        char * data_buf = (char *)malloc(100*sizeof(char));
        memset(data_buf, 'A', 100-1); /* fill with 'A's */
        data_buf[100-1] = '\0'; /* null terminate */
        data = data_buf;
    }
    break;
    }
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the switch to switch(5) */
static void goodG2B1()
{
    char * data;
    data = NULL; /* Initialize data */
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        static char data_buf[100];
        memset(data_buf, 'A', 100-1); /* fill with 'A's */
        data_buf[100-1] = '\0'; /* null terminate */
        data = data_buf;
    }
    break;
    default:
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        char * data_buf = (char *)malloc(100*sizeof(char));
        memset(data_buf, 'A', 100-1); /* fill with 'A's */
        data_buf[100-1] = '\0'; /* null terminate */
        data = data_buf;
    }
    break;
    }
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the switch */
static void goodG2B2()
{
    char * data;
    data = NULL; /* Initialize data */
    switch(6)
    {
    case 6:
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        char * data_buf = (char *)malloc(100*sizeof(char));
        memset(data_buf, 'A', 100-1); /* fill with 'A's */
        data_buf[100-1] = '\0'; /* null terminate */
        data = data_buf;
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        static char data_buf[100];
        memset(data_buf, 'A', 100-1); /* fill with 'A's */
        data_buf[100-1] = '\0'; /* null terminate */
        data = data_buf;
    }
    break;
    }
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_char_static_15_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_char_static_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_char_static_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
