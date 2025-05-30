/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_twoints_67a.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-67a.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_twoints_67
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
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twoints;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printStructLine(data);
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
    data = NULL;
    /* FIX: Use memory allocated on the stack */
    twoints data_good;
    data = &data_good;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printStructLine(data);
    my_struct.a = data;
    goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink(struct_type my_struct);

static void goodB2G()
{
    twoints * data;
    struct_type my_struct;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twoints;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printStructLine(data);
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

using namespace CWE401_Memory_Leak__new_twoints_67; // so that we can use good and bad easily

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
