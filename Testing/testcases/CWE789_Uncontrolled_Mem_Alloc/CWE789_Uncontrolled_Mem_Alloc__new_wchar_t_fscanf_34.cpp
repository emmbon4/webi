/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_fscanf_34.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-34.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with new [] and check the size of the memory to be allocated
 *    BadSink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING L"hello"

namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_fscanf_34
{

typedef union
{
    int a;
    int b;
} union_type;

#ifndef OMITBAD

void bad()
{
    int data;
    union_type my_union;
    /* Initialize data */
    data = -1;
    fscanf (stdin, "%d", &data);
    my_union.a = data;
    {
        int data = my_union.b;
        {
            wchar_t * wchar_t_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                wchar_t_string = new wchar_t[data];
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                delete [] wchar_t_string;
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    union_type my_union;
    /* Initialize data */
    data = -1;
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
    my_union.a = data;
    {
        int data = my_union.b;
        {
            wchar_t * wchar_t_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                wchar_t_string = new wchar_t[data];
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                delete [] wchar_t_string;
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    union_type my_union;
    /* Initialize data */
    data = -1;
    fscanf (stdin, "%d", &data);
    my_union.a = data;
    {
        int data = my_union.b;
        {
            wchar_t * wchar_t_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > wcslen(HELLO_STRING) && data < 100)
            {
                wchar_t_string = new wchar_t[data];
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                delete [] wchar_t_string;
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
    }
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_fscanf_34; // so that we can use good and bad easily

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
