/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67a.c
Label Definition File: CWE195_Signed_To_Unsigned_Conversion.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Positive integer
 * Sinks: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67_struct_type
{
    int a;
} CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67b_bad_sink(CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67_struct_type my_struct);

void CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67_bad()
{
    int data;
    CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    data = RAND32();
    my_struct.a = data;
    CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67b_goodG2B_sink(CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67_struct_type my_struct);

static void goodG2B()
{
    int data;
    CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    my_struct.a = data;
    CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67b_goodG2B_sink(my_struct);
}

void CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67_good()
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
    CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE195_Signed_To_Unsigned_Conversion__rand_memcpy_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
