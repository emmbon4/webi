/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__new_char_loop_34.cpp
Label Definition File: CWE126_Buffer_Overread__new.label.xml
Template File: sources-sink-34.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sinks: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE126_Buffer_Overread__new_char_loop_34
{

typedef union
{
    char * a;
    char * b;
} union_type;

#ifndef OMITBAD

void bad()
{
    char * data;
    union_type my_union;
    data = NULL;
    /* FLAW: Use a small buffer */
    data = new char[50];
    memset(data, 'A', 50-1); /* fill with 'A's */
    data[50-1] = '\0'; /* null terminate */
    my_union.a = data;
    {
        char * data = my_union.b;
        {
            size_t i, dest_sz;
            char dest[100];
            memset(dest, 'C', 100-1);
            dest[100-1] = '\0'; /* null terminate */
            dest_sz = strlen(dest);
            /* POTENTIAL FLAW: using length of the dest where data
             * could be smaller than dest causing buffer overread */
            for (i = 0; i < dest_sz; i++)
            {
                dest[i] = data[i];
            }
            dest[100-1] = '\0';
            printLine(dest);
            delete [] data;
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    union_type my_union;
    data = NULL;
    /* FIX: Use a large buffer */
    data = new char[100];
    memset(data, 'A', 100-1); /* fill with 'A's */
    data[100-1] = '\0'; /* null terminate */
    my_union.a = data;
    {
        char * data = my_union.b;
        {
            size_t i, dest_sz;
            char dest[100];
            memset(dest, 'C', 100-1);
            dest[100-1] = '\0'; /* null terminate */
            dest_sz = strlen(dest);
            /* POTENTIAL FLAW: using length of the dest where data
             * could be smaller than dest causing buffer overread */
            for (i = 0; i < dest_sz; i++)
            {
                dest[i] = data[i];
            }
            dest[100-1] = '\0';
            printLine(dest);
            delete [] data;
        }
    }
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

using namespace CWE126_Buffer_Overread__new_char_loop_34; // so that we can use good and bad easily

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
