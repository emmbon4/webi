/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_34.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING L"hello"

typedef union
{
    int a;
    int b;
} CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_34_union_type;

#ifndef OMITBAD

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_34_bad()
{
    int data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_34_union_type my_union;
    /* Initialize data */
    data = -1;
    data = RAND32();
    my_union.a = data;
    {
        int data = my_union.b;
        {
            wchar_t * wchar_t_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                wchar_t_string = (wchar_t *)malloc(data*sizeof(wchar_t));
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                free(wchar_t_string);
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_34_union_type my_union;
    /* Initialize data */
    data = -1;
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
    my_union.a = data;
    {
        int data = my_union.b;
        {
            wchar_t * wchar_t_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                wchar_t_string = (wchar_t *)malloc(data*sizeof(wchar_t));
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                free(wchar_t_string);
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_34_union_type my_union;
    /* Initialize data */
    data = -1;
    data = RAND32();
    my_union.a = data;
    {
        int data = my_union.b;
        {
            wchar_t * wchar_t_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > wcslen(HELLO_STRING) && data < 100)
            {
                wchar_t_string = (wchar_t *)malloc(data*sizeof(wchar_t));
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                free(wchar_t_string);
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
    }
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_34_good()
{
    goodG2B();
    goodB2G();
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
