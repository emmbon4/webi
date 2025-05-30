/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_static_14.c
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free.label.xml
Template File: sources-sink-14.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 14 Control flow: if(global_five==5) and if(global_five!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_static_14_bad()
{
    int * data;
    data = NULL; /* Initialize data */
    if(global_five==5)
    {
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            static int data_buf[100];
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i] = 5;
                }
            }
            data = data_buf;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            int * data_buf = (int *)malloc(100*sizeof(int));
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i] = 5;
                }
            }
            data = data_buf;
        }
    }
    printIntLine(data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the global_five==5 to global_five!=5 */
static void goodG2B1()
{
    int * data;
    data = NULL; /* Initialize data */
    if(global_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            static int data_buf[100];
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i] = 5;
                }
            }
            data = data_buf;
        }
    }
    else
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            int * data_buf = (int *)malloc(100*sizeof(int));
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i] = 5;
                }
            }
            data = data_buf;
        }
    }
    printIntLine(data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    int * data;
    data = NULL; /* Initialize data */
    if(global_five==5)
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            int * data_buf = (int *)malloc(100*sizeof(int));
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i] = 5;
                }
            }
            data = data_buf;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            static int data_buf[100];
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    data_buf[i] = 5;
                }
            }
            data = data_buf;
        }
    }
    printIntLine(data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_static_14_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_static_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_static_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
