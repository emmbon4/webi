#! /usr/bin/env/python 3.0
#
# Running this script will update the batch files that compile the test cases
# for each CWE into a separate .exe file.  This script also edits source code
# and header files needed for a successful compilation with these batch files.
#
#
import os, glob, shutil, time, sys

# add parent directory to search path so we can use py_common
sys.path.append("..")

import py_common

import update_main_cpp_and_testcases_h

def create_batch_file(cwe, cflags, lflags, c_files_exist):
	contents = ""
	contents += "\nrem NOTE: this batch file is to be run in a Visual Studio command prompt\n"

	contents += "\nrem Delete old files\n"
	contents += "del *.obj\n"
	contents += "del *.ilk\n"
	contents += "del *.exe\n"
	contents += "del *.pdb\n"

	contents += "\nrem Compile files into .obj files in current directory\n"

	files_to_compile = ' *.cpp'
	if c_files_exist:
		files_to_compile += ' *.c'

	contents += 'cl ' + cflags + files_to_compile + \
			' ..\\..\\testcasesupport\io.c' + \
			' ..\\..\\testcasesupport\std_thread.c'

	contents += "\nrem Link all .obj file into a exe\n"
	contents += 'cl ' + "/Fe" + cwe + " *.obj " + lflags + "\n"

	return contents

def check_if_c_files_exist(directory):

	files = py_common.find_files_in_dir(directory, ".*\.c$")
	if len(files) > 1:
		return True

	return False

def help():
	sys.stderr.write('Usage: \n')
	sys.stderr.write('   create_per_cwe_files.py (builds per CWE files for all testcases without debug flags)\n')
	sys.stderr.write('   create_per_cwe_files.py CWE False (builds per CWE files for all testcases without debug flags)\n')
	sys.stderr.write('   create_per_cwe_files.py CWE(78|15) (builds per CWE files for test cases for CWE 78 and CWE 15 without debug flags)\n')
	sys.stderr.write('   create_per_cwe_files.py CWE(78|15) True (builds per CWE files for test cases for CWE 78 and CWE 15 with debug flags)')

# may need /bigobj flag: http://msdn.microsoft.com/en-us/library/ms173499%28VS.90%29.aspx
debug_flags = '/I"..\\..\\testcasesupport" /W3 /MTd /GS- /RTC1 /bigobj /EHsc /nologo /Zi /Od /INCREMENTAL:NO /DEBUG'
linker_flags = '/I"..\\..\\testcasesupport" /W3 /MT /GS /RTC1 /bigobj /EHsc /nologo'
compile_flags = linker_flags + " /c"
debug_compile_flags = debug_flags + " /c"
if __name__ == "__main__":

	# check if ./testcases directory exists, if not, we are running
	# from wrong working directory
	if not os.path.exists("testcases"):
		print("Wrong working directory; could not find testcases directory")
		exit()
	
	# default values which are used if no arguments are passed on command line
	cwe_regex = "CWE"
	use_debug = False

	if len(sys.argv) > 1:
	
		if ((sys.argv[1] == '-h') or (len(sys.argv) > 3)):
			help()
			exit()

		if len(sys.argv) == 2:		
			cwe_regex = sys.argv[1]
			
		if len(sys.argv) == 3:
			cwe_regex = sys.argv[1]
			use_debug = (sys.argv[2] == "True")

	# get the CWE directories in testcases folder
	cwe_dirs = py_common.find_directories_in_dir("testcases", cwe_regex)

	# only allow directories
	cwe_dirs = filter(lambda x: os.path.isdir(x), cwe_dirs)

	for dir in cwe_dirs:

		# copy main.cpp and testcases.h into this testcase dir
		shutil.copy("testcasesupport\\main.cpp", dir)
		shutil.copy("testcasesupport\\testcases.h", dir)

		# update main.cpp/testcases.h to call only this cwe's testcases
		testcase_files = update_main_cpp_and_testcases_h.build_list_of_primary_c_cpp_testcase_files(dir, None)
		fcl = update_main_cpp_and_testcases_h.generate_calls_to_fxs(testcase_files)
		update_main_cpp_and_testcases_h.update_main_cpp(dir, "main.cpp", fcl)
		update_main_cpp_and_testcases_h.update_testcases_h(dir, "testcases.h", fcl)

		# get the CWE number from directory name
		cwe_index = dir.index("CWE")
		unders_index = dir.index("_", cwe_index)
		cwe = dir[cwe_index:unders_index]

		# check if any .c files exist to compile
		c_files_exist = check_if_c_files_exist(dir)

		if use_debug:
			bat_contents = create_batch_file(cwe, debug_compile_flags, debug_flags, c_files_exist)
		else:
			bat_contents = create_batch_file(cwe, compile_flags, linker_flags, c_files_exist)

		bat_filename = cwe + ".bat"
		bat_fullpath = os.path.join(dir, bat_filename)
		py_common.write_file(bat_fullpath, bat_contents)
