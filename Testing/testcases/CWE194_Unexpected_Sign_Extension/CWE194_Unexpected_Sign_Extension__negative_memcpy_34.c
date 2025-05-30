/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__negative_memcpy_34.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sinks: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    short a;
    short b;
} CWE194_Unexpected_Sign_Extension__negative_memcpy_34_union_type;

#ifndef OMITBAD

void CWE194_Unexpected_Sign_Extension__negative_memcpy_34_bad()
{
    short data;
    CWE194_Unexpected_Sign_Extension__negative_memcpy_34_union_type my_union;
    /* Initialize data */
    data = 0;
    /* FLAW: Use a negative number */
    data = -1;
    my_union.a = data;
    {
        short data = my_union.b;
        {
            char src[100];
            char dest[100] = "";
            memset(src, 'A', 100-1);
            src[100-1] = '\0';
            if (data < 100)
            {
                /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
                 * the sign extension could result in a very large number */
                memcpy(dest, src, data);
                dest[data] = '\0'; /* NULL terminate */
            }
            printLine(dest);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    short data;
    CWE194_Unexpected_Sign_Extension__negative_memcpy_34_union_type my_union;
    /* Initialize data */
    data = 0;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    my_union.a = data;
    {
        short data = my_union.b;
        {
            char src[100];
            char dest[100] = "";
            memset(src, 'A', 100-1);
            src[100-1] = '\0';
            if (data < 100)
            {
                /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
                 * the sign extension could result in a very large number */
                memcpy(dest, src, data);
                dest[data] = '\0'; /* NULL terminate */
            }
            printLine(dest);
        }
    }
}

void CWE194_Unexpected_Sign_Extension__negative_memcpy_34_good()
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
    CWE194_Unexpected_Sign_Extension__negative_memcpy_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE194_Unexpected_Sign_Extension__negative_memcpy_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
