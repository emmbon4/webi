/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_fscanf_51a.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-51a.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with new [] and check the size of the memory to be allocated
 *    BadSink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING L"hello"

namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_fscanf_51
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink(int data);

void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    fscanf (stdin, "%d", &data);
    bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void goodG2B_sink(int data);
void goodB2G_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
    goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    fscanf (stdin, "%d", &data);
    goodB2G_sink(data);
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

using namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_fscanf_51; // so that we can use good and bad easily

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
