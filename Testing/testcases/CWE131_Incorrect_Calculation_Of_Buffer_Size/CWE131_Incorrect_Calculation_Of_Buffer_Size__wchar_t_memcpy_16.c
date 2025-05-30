/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_16.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.off_by_one.label.xml
Template File: sources-sink-16.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: memcpy
 *    BadSink : Copy string to data using memcpy()
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

#ifndef OMITBAD

void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_16_bad()
{
    wchar_t * data;
    data = NULL;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Allocate space for a null terminator */
        data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
        break;
    }
    while(1)
    {
        /* FLAW: Did not leave space for a null terminator */
        data = (wchar_t *)malloc(10*sizeof(wchar_t));
        break;
    }
    {
        wchar_t data_src[10+1] = SRC_STRING;
        /* POTENTIAL FLAW: data may not have enough space to hold data_src */
        memcpy(data, data_src, wcslen(data_src)*sizeof(wchar_t));
        data[wcslen(data_src)] = L'\0'; /* NULL terminate */
        printWLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the while statements */
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    while(1)
    {
        /* FIX: Allocate space for a null terminator */
        data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Did not leave space for a null terminator */
        data = (wchar_t *)malloc(10*sizeof(wchar_t));
        break;
    }
    {
        wchar_t data_src[10+1] = SRC_STRING;
        /* POTENTIAL FLAW: data may not have enough space to hold data_src */
        memcpy(data, data_src, wcslen(data_src)*sizeof(wchar_t));
        data[wcslen(data_src)] = L'\0'; /* NULL terminate */
        printWLine(data);
        free(data);
    }
}

void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_16_good()
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
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_memcpy_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
