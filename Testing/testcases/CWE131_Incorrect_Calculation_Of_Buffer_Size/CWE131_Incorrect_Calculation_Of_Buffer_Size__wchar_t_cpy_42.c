/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_cpy_42.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.off_by_one.label.xml
Template File: sources-sink-42.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: cpy
 *    BadSink : Copy string to data using wcscpy()
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

#ifndef OMITBAD

static wchar_t * bad_source(wchar_t * data)
{
    /* FLAW: Did not leave space for a null terminator */
    data = (wchar_t *)malloc(10*sizeof(wchar_t));
    return data;
}

void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_cpy_42_bad()
{
    wchar_t * data;
    data = NULL;
    data = bad_source(data);
    {
        wchar_t data_src[10+1] = SRC_STRING;
        /* POTENTIAL FLAW: data may not have enough space to hold data_src */
        wcscpy(data, data_src);
        printWLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static wchar_t * goodG2B_source(wchar_t * data)
{
    /* FIX: Allocate space for a null terminator */
    data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
    return data;
}

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    data = goodG2B_source(data);
    {
        wchar_t data_src[10+1] = SRC_STRING;
        /* POTENTIAL FLAW: data may not have enough space to hold data_src */
        wcscpy(data, data_src);
        printWLine(data);
        free(data);
    }
}

void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_cpy_42_good()
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
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_cpy_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_cpy_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
