/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_char_fixed_square_67b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the squaring operation
 *    BadSink : Square data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

typedef struct _CWE190_Integer_Overflow__unsigned_char_fixed_square_67_struct_type
{
    unsigned char a;
} CWE190_Integer_Overflow__unsigned_char_fixed_square_67_struct_type;

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_char_fixed_square_67b_bad_sink(CWE190_Integer_Overflow__unsigned_char_fixed_square_67_struct_type my_struct)
{
    unsigned char data = my_struct.a;
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        unsigned char result = data * data;
        printHexUnsignedCharLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__unsigned_char_fixed_square_67b_goodG2B_sink(CWE190_Integer_Overflow__unsigned_char_fixed_square_67_struct_type my_struct)
{
    unsigned char data = my_struct.a;
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        unsigned char result = data * data;
        printHexUnsignedCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__unsigned_char_fixed_square_67b_goodB2G_sink(CWE190_Integer_Overflow__unsigned_char_fixed_square_67_struct_type my_struct)
{
    unsigned char data = my_struct.a;
    {
        unsigned char result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (unsigned char)sqrt((unsigned char)UCHAR_MAX))
        {
            result = data * data;
            printHexUnsignedCharLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
}

#endif /* OMITGOOD */
