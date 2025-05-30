Test Cases
December 2010 Release for C/C++

This archive contains test cases intended for use by organizations and 
individuals that wish to study software assurance tools, such as static 
source code and binary analysis tools.

--------------------
What are test cases?
--------------------
Test cases are pieces of buildable code that can be used to study software 
assurance tools.  A test case targets exactly one type of flaw, but other, 
unrelated flaws may be incidentally present.  For example, the test case 
"CWE476_NULL_Pointer_Dereference__char_01" targets only a NULL Pointer 
Dereference flaw.  In addition to the construct containing the target flaw, 
each test case contains one or more non-flawed constructs that perform a 
function similar to the flawed construct.  

A test case may be contained entirely in one source code file or may be split 
between multiple files.  Below are some examples of test cases and the files 
associated with them.

Test case CWE476_NULL_Pointer_Dereference__char_01 consists of one file: 
CWE476_NULL_Pointer_Dereference__char_01.c

Test case CWE476_NULL_Pointer_Dereference__char_51 consists of two files: 
CWE476_NULL_Pointer_Dereference__char_51a.c and 
CWE476_NULL_Pointer_Dereference__char_51b.c

Test case CWE476_NULL_Pointer_Dereference__char_54 consists of five files: 
CWE476_NULL_Pointer_Dereference__char_54a.c, 
CWE476_NULL_Pointer_Dereference__char_54b.c, 
CWE476_NULL_Pointer_Dereference__char_54c.c, 
CWE476_NULL_Pointer_Dereference__char_54d.c, and 
CWE476_NULL_Pointer_Dereference__char_54e.c

Test case CWE563_Unused_Variable__unused_class_member_value_01 consists of two 
files: 
CWE563_Unused_Variable__unused_class_member_value_01_bad.cpp and 
CWE563_Unused_Variable__unused_class_member_value_01_good1.cpp

----------------------
Test case organization
----------------------
The test cases use the Common Weakness Enumeration (CWE) as a basis for the
test case names and organization.  The test cases strive to use the most 
specific CWE entry for the target flaw.  

A test case is identified by three components in its name: 

 - The number and a possibly shortened CWE name of the target flaw.  This 
section of the test case name is ended with a double underscore ("__").
 - The functional variant name: A word or phrase that differentiates this test 
case from other test cases for this CWE.  This provides a way of separating a 
single CWE into multiple, more specific flaw types.
 - The flow variant number: A two digit number that indicates the type of data 
or control flow in which the target flaw is placed.  Test cases with the same 
flow variant number have the same type of data or control flow.  Flow variant 
"01" indicates the simplest form of the flaw with no data or control flow 
logic.

Most of the test cases in this set were generated using source files and tools 
created by the team.  All of the test cases with a flow variant other than "01" 
and most of the "01" test cases were generated.  Generated test cases contain 
a comment in the first line which indicates that they were generated.

-------------
Prerequisites
-------------
This release of the test cases targets the Microsoft Windows platform.  Many 
test cases will work on Windows and non-Windows platforms, but some are 
Windows specific.  Windows specific test cases should contain the string "w32" 
in their name.  

The build files contained in this release target the Microsoft Visual Studio 
compiler.  Development and testing was done with Visual Studio 2008 
Professional, but other versions of Visual Studio may work.

The test case distribution also contains Python scripts.  Development and 
testing of those scripts was done using Python 3.1.2 for Windows, but other 
versions of Python 3 may work.

----------------------------------------
How to compile or analyze the test cases
----------------------------------------
There are two ways to compile or analyze these test cases: as a whole or as a 
separate .exe for each Common Weakness Enumeration (CWE) entry.  Due to the 
number of files and the number of lines of code contained in these test cases, 
some software analysis tools may not be able to analyze the entirety of these 
test cases as a single unit.

To compile or analyze the test cases as a whole:

The test cases can be compiled into a single (large) .exe file named 
"testcases.exe" by running the file "compile_all.bat".  This batch file must 
be run in a "Visual Studio Command Prompt".  This batch file can be used as a 
basis for analyzing the test cases as a whole by following instructions in the 
documentation for the tool being used.

To compile or analyze the test cases per CWE:

The test cases can also be compiled so that a separate .exe file is generated 
for each CWE.  For an individual CWE, this is accomplished by running the 
batch file in the directory for that CWE (such as by running "CWE476.bat" in 
the directory "testcases\CWE476_NULL_Pointer_Dereference\" to create the file 
"CWE476.exe").  This batch file must be run in a "Visual Studio Command 
Prompt".

In order to automate the process of compiling the test cases in each CWE 
directory, the script "run_analysis_example_tool.py" can be used (also in a 
"Visual Studio Command Prompt").  This script will go to each CWE directory 
and run the batch file to compile those test cases.  This script can also be 
used as the basis for a script to automate performing analysis on the test 
cases in each directory.  The comments in the script provide an example of how 
this can be accomplished.

---------------
Desired results
---------------
When a software analysis tool is run on a test case, the desired result is for 
the tool to report one flaw of the target type.  That reported flaw should be 
in a function with the word "bad" in its name (such as bad(), bad_sink(), or 
CWE476_NULL_Pointer_Dereference__char_41_bad_sink()).  A correct report of 
this type is considered a "True Positive".  If the tool does not report a flaw 
of the target type in a "bad" function in a test case, it is considered a 
"False Negative".

It is also desired that the tool NOT report any flaws of the target type in a 
function with the word "good" in its name.  An incorrect report of this type 
is considered a "False Positive".

Because test cases may or may not contain flaws of non-target types, reports 
of flaws other than the target type are typically ignored when studying a 
tool.

-----------------------------------------------------------
How to update build files if changes are made to test cases
-----------------------------------------------------------
This archive contains two scripts that can be used to update the build files 
if changes are made to the set of test cases to be analyzed.  Using the test 
cases as distributed or after edits are made to existing test case files do 
NOT require the use of these scripts.  These scripts are only needed if test 
case files are deleted from the set or new test cases are added.  If new test 
cases are added to the test case set, care should be taken to follow the 
conventions and structure of existing test cases in order to prevent errors in 
these scripts or in compilation. 

create_single_batch_file.py – Running this script will update the file 
"compile_all.bat", which can be run to compile all the test cases into a 
single .exe file.  This script also edits source code and header files needed 
for a successful compilation with this batch file.

create_per_cwe_files.py – Running this script will update the batch files that 
compile the test cases for each CWE into a separate .exe file.  This script 
also edits source code and header files needed for a successful compilation 
with these batch files.

