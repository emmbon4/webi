/*
 * @description Improper Resource Shutdown or Release
 * 
 * */

#include "std_testcase.h"

namespace CWE404_Improper_Resource_Shutdown__new_array_free_01
{

#ifndef OMITBAD

	class BadClass {

	public:
	
		BadClass(char * name){
			
			badname = new char[strlen(name) + 1];
			strcpy(badname, name);
		}

		~BadClass(){
			/* FLAW: Using free() to deallocate memory allocated with new [] */
			free(badname);
		}

		void printName(){
			printLine(badname);
		}

	private:

		char * badname;
	};

void bad()
{
    BadClass a = BadClass("BadClass");

	a.printName();
}

#endif /* OMITBAD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on 
   its own for testing or for building a binary to use in testing binary 
   analysis tools. It is not used when compiling all the testcases as one 
   application, which is how source code analysis tools are tested. */ 

#ifdef INCLUDEMAIN

using namespace CWE404_Improper_Resource_Shutdown__new_array_free_01; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
