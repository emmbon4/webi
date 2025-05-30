/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_To_Unsigned_Conversion__negative_memmove_34.c
Label Definition File: CWE195_Signed_To_Unsigned_Conversion.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sinks: memmove
 *    BadSink : Copy strings using memmove() with the length of data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    int a;
    int b;
} CWE195_Signed_To_Unsigned_Conversion__negative_memmove_34_union_type;

#ifndef OMITBAD

void CWE195_Signed_To_Unsigned_Conversion__negative_memmove_34_bad()
{
    int data;
    CWE195_Signed_To_Unsigned_Conversion__negative_memmove_34_union_type my_union;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a negative number */
    data = -1;
    my_union.a = data;
    {
        int data = my_union.b;
        {
            char src[100];
            char dest[100] = "";
            memset(src, 'A', 100-1);
            src[100-1] = '\0';
            if (data < 100)
            {
                /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
                 * the sign conversion could result in a very large number */
                memmove(dest, src, data);
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
    int data;
    CWE195_Signed_To_Unsigned_Conversion__negative_memmove_34_union_type my_union;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    my_union.a = data;
    {
        int data = my_union.b;
        {
            char src[100];
            char dest[100] = "";
            memset(src, 'A', 100-1);
            src[100-1] = '\0';
            if (data < 100)
            {
                /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
                 * the sign conversion could result in a very large number */
                memmove(dest, src, data);
                dest[data] = '\0'; /* NULL terminate */
            }
            printLine(dest);
        }
    }
}

void CWE195_Signed_To_Unsigned_Conversion__negative_memmove_34_good()
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
    CWE195_Signed_To_Unsigned_Conversion__negative_memmove_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE195_Signed_To_Unsigned_Conversion__negative_memmove_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
