/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_char_declare_ncpy_34.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.string.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: ncpy
 *    BadSink : Copy data to string using strncpy
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    char * a;
    char * b;
} CWE121_Stack_Based_Buffer_Overflow__src_char_declare_ncpy_34_union_type;

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__src_char_declare_ncpy_34_bad()
{
    char * data;
    CWE121_Stack_Based_Buffer_Overflow__src_char_declare_ncpy_34_union_type my_union;
    char data_buf[100];
    data = data_buf;
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    memset(data, 'A', 100-1); /* fill with 'A's */
    data[100-1] = '\0'; /* null terminate */
    my_union.a = data;
    {
        char * data = my_union.b;
        {
            char dest[50] = "";
            /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
            strncpy(dest, data, strlen(data));
            dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
            printLine(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    CWE121_Stack_Based_Buffer_Overflow__src_char_declare_ncpy_34_union_type my_union;
    char data_buf[100];
    data = data_buf;
    /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
    memset(data, 'A', 50-1); /* fill with 'A's */
    data[50-1] = '\0'; /* null terminate */
    my_union.a = data;
    {
        char * data = my_union.b;
        {
            char dest[50] = "";
            /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
            strncpy(dest, data, strlen(data));
            dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
            printLine(data);
        }
    }
}

void CWE121_Stack_Based_Buffer_Overflow__src_char_declare_ncpy_34_good()
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
    CWE121_Stack_Based_Buffer_Overflow__src_char_declare_ncpy_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__src_char_declare_ncpy_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
