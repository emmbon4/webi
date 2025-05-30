/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68b.c
Label Definition File: CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 135 Incorrect Calculation of Multi-Byte String Length
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

extern void * CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_bad_data;
extern void * CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_goodG2B_data;
extern void * CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_goodB2G_data;

#ifndef OMITBAD

void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68b_bad_sink()
{
    void * data = CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_bad_data;
    {
        /* POTENTIAL FLAW - treating pointer as a char* when it may point to a wide string */
        size_t data_len = strlen((char *)data);
        void * data_dest = (void *)calloc(data_len+1, 1);
        memcpy(data_dest, data, (data_len+1));
        printLine((char *)data_dest);
        free(data_dest);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68b_goodG2B_sink()
{
    void * data = CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_goodG2B_data;
    {
        /* POTENTIAL FLAW - treating pointer as a char* when it may point to a wide string */
        size_t data_len = strlen((char *)data);
        void * data_dest = (void *)calloc(data_len+1, 1);
        memcpy(data_dest, data, (data_len+1));
        printLine((char *)data_dest);
        free(data_dest);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68b_goodB2G_sink()
{
    void * data = CWE135_Incorrect_Calculation_Of_Multibyte_String_Length__basic_68_goodB2G_data;
    {
        /* FIX - treating pointer like a wchar_t*  */
        size_t data_len = wcslen((wchar_t *)data);
        void * data_dest = (void *)calloc(data_len+1, sizeof(wchar_t));
        memcpy(data_dest, data, (data_len+1)*sizeof(wchar_t));
        printWLine((wchar_t *)data_dest);
        free(data_dest);
    }
}

#endif /* OMITGOOD */
