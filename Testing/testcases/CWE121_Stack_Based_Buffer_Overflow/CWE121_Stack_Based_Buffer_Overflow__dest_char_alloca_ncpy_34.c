/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__dest_char_alloca_ncpy_34.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__dest.string.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: ncpy
 *    BadSink : Copy string to data using strncpy
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    char * a;
    char * b;
} CWE121_Stack_Based_Buffer_Overflow__dest_char_alloca_ncpy_34_union_type;

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__dest_char_alloca_ncpy_34_bad()
{
    char * data;
    CWE121_Stack_Based_Buffer_Overflow__dest_char_alloca_ncpy_34_union_type my_union;
    char * data_badbuf = (char *)ALLOCA(50*sizeof(char));
    char * data_goodbuf = (char *)ALLOCA(100*sizeof(char));
    /* FLAW: Set a pointer to a "small" buffer. This buffer will be used in the sinks as a destination
     * buffer in various memory copying functions using a "large" source buffer. */
    data = data_badbuf;
    data[0] = '\0'; /* null terminate */
    my_union.a = data;
    {
        char * data = my_union.b;
        {
            char src[100];
            memset(src, 'C', 100-1); /* fill with 'C's */
            src[100-1] = '\0'; /* null terminate */
            /* POTENTIAL FLAW: Possible buffer overflow if the size of data is less than the length of src */
            strncpy(data, src, 100);
            data[100-1] = '\0'; /* Ensure the destination buffer is null terminated */
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
    CWE121_Stack_Based_Buffer_Overflow__dest_char_alloca_ncpy_34_union_type my_union;
    char * data_badbuf = (char *)ALLOCA(50*sizeof(char));
    char * data_goodbuf = (char *)ALLOCA(100*sizeof(char));
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = data_goodbuf;
    data[0] = '\0'; /* null terminate */
    my_union.a = data;
    {
        char * data = my_union.b;
        {
            char src[100];
            memset(src, 'C', 100-1); /* fill with 'C's */
            src[100-1] = '\0'; /* null terminate */
            /* POTENTIAL FLAW: Possible buffer overflow if the size of data is less than the length of src */
            strncpy(data, src, 100);
            data[100-1] = '\0'; /* Ensure the destination buffer is null terminated */
            printLine(data);
        }
    }
}

void CWE121_Stack_Based_Buffer_Overflow__dest_char_alloca_ncpy_34_good()
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
    CWE121_Stack_Based_Buffer_Overflow__dest_char_alloca_ncpy_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__dest_char_alloca_ncpy_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
