/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_struct_declare_41.cpp
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array.label.xml
Template File: sources-sink-41.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_struct_declare_41
{

#ifndef OMITBAD

void bad_sink(twoints * data)
{
    printStructLine(&data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

void bad()
{
    twoints * data;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        twoints data_buf[100];
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data_buf[i].a = 1;
                data_buf[i].b = 1;
            }
        }
        data = data_buf;
    }
    bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void goodG2B_sink(twoints * data)
{
    printStructLine(&data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    twoints * data;
    data = NULL; /* Initialize data */
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        twoints * data_buf = new twoints[100];
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data_buf[i].a = 1;
                data_buf[i].b = 1;
            }
        }
        data = data_buf;
    }
    goodG2B_sink(data);
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

using namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_struct_declare_41; // so that we can use good and bad easily

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
