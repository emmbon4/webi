/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_wchar_t_declare_42.cpp
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array.label.xml
Template File: sources-sink-42.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_wchar_t_declare_42
{

#ifndef OMITBAD

static wchar_t * bad_source(wchar_t * data)
{
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        wchar_t data_buf[100];
        wmemset(data_buf, L'A', 100-1); /* fill with 'A's */
        data_buf[100-1] = L'\0'; /* null terminate */
        data = data_buf;
    }
    return data;
}

void bad()
{
    wchar_t * data;
    data = NULL; /* Initialize data */
    data = bad_source(data);
    printWLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static wchar_t * goodG2B_source(wchar_t * data)
{
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        wchar_t * data_buf = new wchar_t[100];
        wmemset(data_buf, L'A', 100-1); /* fill with 'A's */
        data_buf[100-1] = L'\0'; /* null terminate */
        data = data_buf;
    }
    return data;
}

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    data = NULL; /* Initialize data */
    data = goodG2B_source(data);
    printWLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
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

using namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_wchar_t_declare_42; // so that we can use good and bad easily

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
