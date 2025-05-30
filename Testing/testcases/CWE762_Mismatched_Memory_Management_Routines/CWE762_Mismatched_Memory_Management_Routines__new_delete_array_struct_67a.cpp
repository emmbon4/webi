/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_struct_67a.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-67a.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using delete
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_struct_67
{

typedef struct _struct_type
{
    twoints * a;
} struct_type;

#ifndef OMITBAD

/* bad function declaration */
void bad_sink(struct_type my_struct);

void bad()
{
    twoints * data;
    struct_type my_struct;
    /* Initialize data*/
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
    data = new twoints;
    my_struct.a = data;
    bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(struct_type my_struct);

static void goodG2B()
{
    twoints * data;
    struct_type my_struct;
    /* Initialize data*/
    data = NULL;
    /* FIX: Allocate memory from the heap using new [] */
    data = new twoints[100];
    my_struct.a = data;
    goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink(struct_type my_struct);

static void goodB2G()
{
    twoints * data;
    struct_type my_struct;
    /* Initialize data*/
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
    data = new twoints;
    my_struct.a = data;
    goodB2G_sink(my_struct);
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_struct_67; // so that we can use good and bad easily

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
