/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_char_fscanf_42.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-42.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with new [] and check the size of the memory to be allocated
 *    BadSink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING "hello"

namespace CWE789_Uncontrolled_Mem_Alloc__new_char_fscanf_42
{

#ifndef OMITBAD

static int bad_source(int data)
{
    fscanf (stdin, "%d", &data);
    return data;
}

void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = bad_source(data);
    {
        char * char_string;
        /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > 0)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than 0");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static int goodG2B_source(int data)
{
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
    return data;
}

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    data = goodG2B_source(data);
    {
        char * char_string;
        /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > 0)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than 0");
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static int goodB2G_source(int data)
{
    fscanf (stdin, "%d", &data);
    return data;
}

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    data = goodB2G_source(data);
    {
        char * char_string;
        /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if ((size_t)data > strlen(HELLO_STRING) && data < 100)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than the length of the source string or too large");
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

using namespace CWE789_Uncontrolled_Mem_Alloc__new_char_fscanf_42; // so that we can use good and bad easily

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
