/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_61b.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: fromConsole Read input from the console
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

#ifndef OMITBAD

wchar_t * CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_61b_bad_source(wchar_t * data)
{
    {
        /* Read input from the console */
        size_t data_len = wcslen(data);
        /* if there is room in data, read into it from the console */
        if(100-data_len > 1)
        {
            fgetws(data+data_len, (int)(100-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgetws() */
            data_len = wcslen(data);
            if (data_len > 0)
            {
                data[data_len-1] = L'\0';
            }
        }
    }
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
wchar_t * CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_61b_goodG2B_source(wchar_t * data)
{
    /* FIX: Set data to a number less than MAX_LOOP */
    wcscpy(data, L"15");
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
wchar_t * CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_61b_goodB2G_source(wchar_t * data)
{
    {
        /* Read input from the console */
        size_t data_len = wcslen(data);
        /* if there is room in data, read into it from the console */
        if(100-data_len > 1)
        {
            fgetws(data+data_len, (int)(100-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgetws() */
            data_len = wcslen(data);
            if (data_len > 0)
            {
                data[data_len-1] = L'\0';
            }
        }
    }
    return data;
}

#endif /* OMITGOOD */
