/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__new_wchar_t_cpy_68a.cpp
Label Definition File: CWE127_Buffer_Underread__new.label.xml
Template File: sources-sink-68a.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: cpy
 *    BadSink : Copy data to string using wcscpy
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

wchar_t * CWE127_Buffer_Underread__new_wchar_t_cpy_68_bad_data;
wchar_t * CWE127_Buffer_Underread__new_wchar_t_cpy_68_goodG2B_data;

namespace CWE127_Buffer_Underread__new_wchar_t_cpy_68
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink();

void bad()
{
    wchar_t * data;
    data = NULL;
    {
        wchar_t * data_buf = new wchar_t[100];
        wmemset(data_buf, L'A', 100-1);
        data_buf[100-1] = L'\0';
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = data_buf - 8;
    }
    CWE127_Buffer_Underread__new_wchar_t_cpy_68_bad_data = data;
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
    {
        wchar_t * data_buf = new wchar_t[100];
        wmemset(data_buf, L'A', 100-1);
        data_buf[100-1] = L'\0';
        /* FIX: Set data pointer to the allocated memory buffer */
        data = data_buf;
    }
    CWE127_Buffer_Underread__new_wchar_t_cpy_68_goodG2B_data = data;
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

using namespace CWE127_Buffer_Underread__new_wchar_t_cpy_68; // so that we can use good and bad easily

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
