/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__char_declare_ncpy_64a.c
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-64a.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: ncpy
 *    BadSink : Copy string to data using strncpy
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE124_Buffer_Underwrite__char_declare_ncpy_64b_bad_sink(void * void_data_ptr);

void CWE124_Buffer_Underwrite__char_declare_ncpy_64_bad()
{
    char * data;
    char data_buf[100];
    memset(data_buf, 'A', 100-1);
    data_buf[100-1] = '\0';
    /* FLAW: Set data pointer to before the allocated memory buffer */
    data = data_buf - 8;
    CWE124_Buffer_Underwrite__char_declare_ncpy_64b_bad_sink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE124_Buffer_Underwrite__char_declare_ncpy_64b_goodG2B_sink(void * void_data_ptr);

static void goodG2B()
{
    char * data;
    char data_buf[100];
    memset(data_buf, 'A', 100-1);
    data_buf[100-1] = '\0';
    /* FIX: Set data pointer to the allocated memory buffer */
    data = data_buf;
    CWE124_Buffer_Underwrite__char_declare_ncpy_64b_goodG2B_sink(&data);
}

void CWE124_Buffer_Underwrite__char_declare_ncpy_64_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE124_Buffer_Underwrite__char_declare_ncpy_64_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE124_Buffer_Underwrite__char_declare_ncpy_64_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
