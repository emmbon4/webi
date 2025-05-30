/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__char_declare_memcpy_67a.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sinks: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE126_Buffer_Overread__char_declare_memcpy_67_struct_type
{
    char * a;
} CWE126_Buffer_Overread__char_declare_memcpy_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE126_Buffer_Overread__char_declare_memcpy_67b_bad_sink(CWE126_Buffer_Overread__char_declare_memcpy_67_struct_type my_struct);

void CWE126_Buffer_Overread__char_declare_memcpy_67_bad()
{
    char * data;
    CWE126_Buffer_Overread__char_declare_memcpy_67_struct_type my_struct;
    char data_badbuf[50];
    char data_goodbuf[100];
    memset(data_badbuf, 'A', 50-1); /* fill with 'A's */
    data_badbuf[50-1] = '\0'; /* null terminate */
    memset(data_goodbuf, 'A', 100-1); /* fill with 'A's */
    data_goodbuf[100-1] = '\0'; /* null terminate */
    /* FLAW: Set data pointer to a small buffer */
    data = data_badbuf;
    my_struct.a = data;
    CWE126_Buffer_Overread__char_declare_memcpy_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE126_Buffer_Overread__char_declare_memcpy_67b_goodG2B_sink(CWE126_Buffer_Overread__char_declare_memcpy_67_struct_type my_struct);

static void goodG2B()
{
    char * data;
    CWE126_Buffer_Overread__char_declare_memcpy_67_struct_type my_struct;
    char data_badbuf[50];
    char data_goodbuf[100];
    memset(data_badbuf, 'A', 50-1); /* fill with 'A's */
    data_badbuf[50-1] = '\0'; /* null terminate */
    memset(data_goodbuf, 'A', 100-1); /* fill with 'A's */
    data_goodbuf[100-1] = '\0'; /* null terminate */
    /* FIX: Set data pointer to a large buffer */
    data = data_goodbuf;
    my_struct.a = data;
    CWE126_Buffer_Overread__char_declare_memcpy_67b_goodG2B_sink(my_struct);
}

void CWE126_Buffer_Overread__char_declare_memcpy_67_good()
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
    CWE126_Buffer_Overread__char_declare_memcpy_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE126_Buffer_Overread__char_declare_memcpy_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
