/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_class_alloca_08.cpp
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array.label.xml
Template File: sources-sink-08.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
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

namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_class_alloca_08
{

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    data = NULL; /* Initialize data */
    if(static_returns_t())
    {
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            twointsclass * data_buf = (twointsclass *)ALLOCA(100*sizeof(twointsclass));
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
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            twointsclass * data_buf = new twointsclass[100];
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
    }
    printIntLine(data[0].a);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_returns_t() to static_returns_f() */
static void goodG2B1()
{
    twointsclass * data;
    data = NULL; /* Initialize data */
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            twointsclass * data_buf = (twointsclass *)ALLOCA(100*sizeof(twointsclass));
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
    }
    else
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            twointsclass * data_buf = new twointsclass[100];
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
    }
    printIntLine(data[0].a);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    twointsclass * data;
    data = NULL; /* Initialize data */
    if(static_returns_t())
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            twointsclass * data_buf = new twointsclass[100];
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
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            twointsclass * data_buf = (twointsclass *)ALLOCA(100*sizeof(twointsclass));
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
    }
    printIntLine(data[0].a);
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

using namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_class_alloca_08; // so that we can use good and bad easily

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
