/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_char_declare_44.cpp
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array.label.xml
Template File: sources-sink-44.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_char_declare_44
{

#ifndef OMITBAD

static void bad_sink(char * data)
{
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

void bad()
{
    char * data;
    /* define a function pointer */
    void (*func_ptr) (char *) = bad_sink;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        char data_buf[100];
        memset(data_buf, 'A', 100-1); /* fill with 'A's */
        data_buf[100-1] = '\0'; /* null terminate */
        data = data_buf;
    }
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink(char * data)
{
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

static void goodG2B()
{
    char * data;
    void (*func_ptr) (char *) = goodG2B_sink;
    data = NULL; /* Initialize data */
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        char * data_buf = new char[100];
        memset(data_buf, 'A', 100-1); /* fill with 'A's */
        data_buf[100-1] = '\0'; /* null terminate */
        data = data_buf;
    }
    func_ptr(data);
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_char_declare_44; // so that we can use good and bad easily

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
