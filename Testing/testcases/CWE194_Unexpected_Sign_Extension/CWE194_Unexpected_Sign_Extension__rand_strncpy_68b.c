/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__rand_strncpy_68b.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: rand Set data to result of rand(), which could be negative
 * GoodSource: Positive integer
 * Sink: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern short CWE194_Unexpected_Sign_Extension__rand_strncpy_68_bad_data;
extern short CWE194_Unexpected_Sign_Extension__rand_strncpy_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE194_Unexpected_Sign_Extension__rand_strncpy_68b_bad_sink()
{
    short data = CWE194_Unexpected_Sign_Extension__rand_strncpy_68_bad_data;
    {
        char src[100];
        char dest[100] = "";
        memset(src, 'A', 100-1);
        src[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign extension could result in a very large number */
            strncpy(dest, src, data);
            dest[data] = '\0'; /* strncpy() does not always NULL terminate */
        }
        printLine(dest);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE194_Unexpected_Sign_Extension__rand_strncpy_68b_goodG2B_sink()
{
    short data = CWE194_Unexpected_Sign_Extension__rand_strncpy_68_goodG2B_data;
    {
        char src[100];
        char dest[100] = "";
        memset(src, 'A', 100-1);
        src[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign extension could result in a very large number */
            strncpy(dest, src, data);
            dest[data] = '\0'; /* strncpy() does not always NULL terminate */
        }
        printLine(dest);
    }
}

#endif /* OMITGOOD */
