/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_memmove_68a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.string.label.xml
Template File: sources-sink-68a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: memmove
 *    BadSink : Copy string to data using memmove
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

wchar_t * CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_memmove_68_bad_data;
wchar_t * CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_memmove_68_goodG2B_data;

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_memmove_68
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink();

void bad()
{
    wchar_t * data;
    data = NULL;
    /* FLAW: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = new wchar_t[50];
    data[0] = L'\0'; /* null terminate */
    CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_memmove_68_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    /* FIX: Allocate using new[] and point data to a large buffer that is at least as large as the large buffer used in the sink */
    data = new wchar_t[100];
    data[0] = L'\0'; /* null terminate */
    CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_memmove_68_goodG2B_data = data;
    goodG2B_sink();
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

using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_memmove_68; // so that we can use good and bad easily

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
