/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_char_declare_11.cpp
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array.label.xml
Template File: sources-sink-11.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_char_declare_11
{

#ifndef OMITBAD

void bad()
{
    char * data;
    data = NULL; /* Initialize data */
    if(global_returns_t())
    {
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            char data_buf[100];
            memset(data_buf, 'A', 100-1); /* fill with 'A's */
            data_buf[100-1] = '\0'; /* null terminate */
            data = data_buf;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            char * data_buf = new char[100];
            memset(data_buf, 'A', 100-1); /* fill with 'A's */
            data_buf[100-1] = '\0'; /* null terminate */
            data = data_buf;
        }
    }
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the global_returns_t() to global_returns_f() */
static void goodG2B1()
{
    char * data;
    data = NULL; /* Initialize data */
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            char data_buf[100];
            memset(data_buf, 'A', 100-1); /* fill with 'A's */
            data_buf[100-1] = '\0'; /* null terminate */
            data = data_buf;
        }
    }
    else
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            char * data_buf = new char[100];
            memset(data_buf, 'A', 100-1); /* fill with 'A's */
            data_buf[100-1] = '\0'; /* null terminate */
            data = data_buf;
        }
    }
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    data = NULL; /* Initialize data */
    if(global_returns_t())
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            char * data_buf = new char[100];
            memset(data_buf, 'A', 100-1); /* fill with 'A's */
            data_buf[100-1] = '\0'; /* null terminate */
            data = data_buf;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            char data_buf[100];
            memset(data_buf, 'A', 100-1); /* fill with 'A's */
            data_buf[100-1] = '\0'; /* null terminate */
            data = data_buf;
        }
    }
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

void good()
{
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_char_declare_11; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
