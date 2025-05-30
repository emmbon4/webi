/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_68b.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with new [] and check the size of the memory to be allocated
 *    BadSink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING L"hello"

namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_68
{

extern int bad_data;
extern int goodG2B_data;
extern int goodB2G_data;

#ifndef OMITBAD

void bad_sink()
{
    int data = bad_data;
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

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink()
{
    int data = goodG2B_data;
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

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink()
{
    int data = goodB2G_data;
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

#endif /* OMITGOOD */

} // close namespace
