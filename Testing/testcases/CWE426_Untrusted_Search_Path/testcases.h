// NOTE - eventually this file will be automatically updated using a Perl script that understand
// the naming of test case files, functions, and namespaces.

#ifndef _TESTCASES_H
#define _TESTCASES_H

#ifdef __cplusplus
extern "C" {
#endif

// declare C good and bad functions
#ifndef OMITGOOD
	/* BEGIN-AUTOGENERATED-C-GOOD-FUNCTION-DECLARATIONS */
	void CWE426_Untrusted_Search_Path__char_popen_01_good();

	void CWE426_Untrusted_Search_Path__char_popen_02_good();

	void CWE426_Untrusted_Search_Path__char_popen_03_good();

	void CWE426_Untrusted_Search_Path__char_popen_04_good();

	void CWE426_Untrusted_Search_Path__char_popen_05_good();

	void CWE426_Untrusted_Search_Path__char_popen_06_good();

	void CWE426_Untrusted_Search_Path__char_popen_07_good();

	void CWE426_Untrusted_Search_Path__char_popen_08_good();

	void CWE426_Untrusted_Search_Path__char_popen_09_good();

	void CWE426_Untrusted_Search_Path__char_popen_10_good();

	void CWE426_Untrusted_Search_Path__char_popen_11_good();

	void CWE426_Untrusted_Search_Path__char_popen_12_good();

	void CWE426_Untrusted_Search_Path__char_popen_13_good();

	void CWE426_Untrusted_Search_Path__char_popen_14_good();

	void CWE426_Untrusted_Search_Path__char_popen_15_good();

	void CWE426_Untrusted_Search_Path__char_popen_16_good();

	void CWE426_Untrusted_Search_Path__char_popen_17_good();

	void CWE426_Untrusted_Search_Path__char_popen_18_good();

	void CWE426_Untrusted_Search_Path__char_popen_19_good();

	void CWE426_Untrusted_Search_Path__char_popen_31_good();

	void CWE426_Untrusted_Search_Path__char_popen_32_good();

	void CWE426_Untrusted_Search_Path__char_popen_34_good();

	void CWE426_Untrusted_Search_Path__char_popen_41_good();

	void CWE426_Untrusted_Search_Path__char_popen_42_good();

	void CWE426_Untrusted_Search_Path__char_popen_44_good();

	void CWE426_Untrusted_Search_Path__char_popen_45_good();

	void CWE426_Untrusted_Search_Path__char_popen_51_good();

	void CWE426_Untrusted_Search_Path__char_popen_52_good();

	void CWE426_Untrusted_Search_Path__char_popen_53_good();

	void CWE426_Untrusted_Search_Path__char_popen_54_good();

	void CWE426_Untrusted_Search_Path__char_popen_61_good();

	void CWE426_Untrusted_Search_Path__char_popen_63_good();

	void CWE426_Untrusted_Search_Path__char_popen_64_good();

	void CWE426_Untrusted_Search_Path__char_popen_65_good();

	void CWE426_Untrusted_Search_Path__char_popen_66_good();

	void CWE426_Untrusted_Search_Path__char_popen_67_good();

	void CWE426_Untrusted_Search_Path__char_popen_68_good();

	void CWE426_Untrusted_Search_Path__char_system_01_good();

	void CWE426_Untrusted_Search_Path__char_system_02_good();

	void CWE426_Untrusted_Search_Path__char_system_03_good();

	void CWE426_Untrusted_Search_Path__char_system_04_good();

	void CWE426_Untrusted_Search_Path__char_system_05_good();

	void CWE426_Untrusted_Search_Path__char_system_06_good();

	void CWE426_Untrusted_Search_Path__char_system_07_good();

	void CWE426_Untrusted_Search_Path__char_system_08_good();

	void CWE426_Untrusted_Search_Path__char_system_09_good();

	void CWE426_Untrusted_Search_Path__char_system_10_good();

	void CWE426_Untrusted_Search_Path__char_system_11_good();

	void CWE426_Untrusted_Search_Path__char_system_12_good();

	void CWE426_Untrusted_Search_Path__char_system_13_good();

	void CWE426_Untrusted_Search_Path__char_system_14_good();

	void CWE426_Untrusted_Search_Path__char_system_15_good();

	void CWE426_Untrusted_Search_Path__char_system_16_good();

	void CWE426_Untrusted_Search_Path__char_system_17_good();

	void CWE426_Untrusted_Search_Path__char_system_18_good();

	void CWE426_Untrusted_Search_Path__char_system_19_good();

	void CWE426_Untrusted_Search_Path__char_system_31_good();

	void CWE426_Untrusted_Search_Path__char_system_32_good();

	void CWE426_Untrusted_Search_Path__char_system_34_good();

	void CWE426_Untrusted_Search_Path__char_system_41_good();

	void CWE426_Untrusted_Search_Path__char_system_42_good();

	void CWE426_Untrusted_Search_Path__char_system_44_good();

	void CWE426_Untrusted_Search_Path__char_system_45_good();

	void CWE426_Untrusted_Search_Path__char_system_51_good();

	void CWE426_Untrusted_Search_Path__char_system_52_good();

	void CWE426_Untrusted_Search_Path__char_system_53_good();

	void CWE426_Untrusted_Search_Path__char_system_54_good();

	void CWE426_Untrusted_Search_Path__char_system_61_good();

	void CWE426_Untrusted_Search_Path__char_system_63_good();

	void CWE426_Untrusted_Search_Path__char_system_64_good();

	void CWE426_Untrusted_Search_Path__char_system_65_good();

	void CWE426_Untrusted_Search_Path__char_system_66_good();

	void CWE426_Untrusted_Search_Path__char_system_67_good();

	void CWE426_Untrusted_Search_Path__char_system_68_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_01_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_02_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_03_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_04_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_05_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_06_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_07_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_08_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_09_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_10_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_11_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_12_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_13_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_14_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_15_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_16_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_17_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_18_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_19_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_31_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_32_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_34_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_41_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_42_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_44_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_45_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_51_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_52_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_53_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_54_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_61_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_63_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_64_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_65_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_66_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_67_good();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_68_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_01_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_02_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_03_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_04_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_05_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_06_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_07_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_08_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_09_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_10_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_11_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_12_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_13_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_14_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_15_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_16_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_17_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_18_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_19_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_31_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_32_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_34_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_41_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_42_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_44_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_45_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_51_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_52_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_53_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_54_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_61_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_63_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_64_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_65_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_66_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_67_good();

	void CWE426_Untrusted_Search_Path__wchar_t_system_68_good();

	/* END-AUTOGENERATED-C-GOOD-FUNCTION-DECLARATIONS */
#endif // OMITGOOD


#ifndef OMITBAD
	/* BEGIN-AUTOGENERATED-C-BAD-FUNCTION-DECLARATIONS */
	void CWE426_Untrusted_Search_Path__char_popen_01_bad();

	void CWE426_Untrusted_Search_Path__char_popen_02_bad();

	void CWE426_Untrusted_Search_Path__char_popen_03_bad();

	void CWE426_Untrusted_Search_Path__char_popen_04_bad();

	void CWE426_Untrusted_Search_Path__char_popen_05_bad();

	void CWE426_Untrusted_Search_Path__char_popen_06_bad();

	void CWE426_Untrusted_Search_Path__char_popen_07_bad();

	void CWE426_Untrusted_Search_Path__char_popen_08_bad();

	void CWE426_Untrusted_Search_Path__char_popen_09_bad();

	void CWE426_Untrusted_Search_Path__char_popen_10_bad();

	void CWE426_Untrusted_Search_Path__char_popen_11_bad();

	void CWE426_Untrusted_Search_Path__char_popen_12_bad();

	void CWE426_Untrusted_Search_Path__char_popen_13_bad();

	void CWE426_Untrusted_Search_Path__char_popen_14_bad();

	void CWE426_Untrusted_Search_Path__char_popen_15_bad();

	void CWE426_Untrusted_Search_Path__char_popen_16_bad();

	void CWE426_Untrusted_Search_Path__char_popen_17_bad();

	void CWE426_Untrusted_Search_Path__char_popen_18_bad();

	void CWE426_Untrusted_Search_Path__char_popen_19_bad();

	void CWE426_Untrusted_Search_Path__char_popen_31_bad();

	void CWE426_Untrusted_Search_Path__char_popen_32_bad();

	void CWE426_Untrusted_Search_Path__char_popen_34_bad();

	void CWE426_Untrusted_Search_Path__char_popen_41_bad();

	void CWE426_Untrusted_Search_Path__char_popen_42_bad();

	void CWE426_Untrusted_Search_Path__char_popen_44_bad();

	void CWE426_Untrusted_Search_Path__char_popen_45_bad();

	void CWE426_Untrusted_Search_Path__char_popen_51_bad();

	void CWE426_Untrusted_Search_Path__char_popen_52_bad();

	void CWE426_Untrusted_Search_Path__char_popen_53_bad();

	void CWE426_Untrusted_Search_Path__char_popen_54_bad();

	void CWE426_Untrusted_Search_Path__char_popen_61_bad();

	void CWE426_Untrusted_Search_Path__char_popen_63_bad();

	void CWE426_Untrusted_Search_Path__char_popen_64_bad();

	void CWE426_Untrusted_Search_Path__char_popen_65_bad();

	void CWE426_Untrusted_Search_Path__char_popen_66_bad();

	void CWE426_Untrusted_Search_Path__char_popen_67_bad();

	void CWE426_Untrusted_Search_Path__char_popen_68_bad();

	void CWE426_Untrusted_Search_Path__char_system_01_bad();

	void CWE426_Untrusted_Search_Path__char_system_02_bad();

	void CWE426_Untrusted_Search_Path__char_system_03_bad();

	void CWE426_Untrusted_Search_Path__char_system_04_bad();

	void CWE426_Untrusted_Search_Path__char_system_05_bad();

	void CWE426_Untrusted_Search_Path__char_system_06_bad();

	void CWE426_Untrusted_Search_Path__char_system_07_bad();

	void CWE426_Untrusted_Search_Path__char_system_08_bad();

	void CWE426_Untrusted_Search_Path__char_system_09_bad();

	void CWE426_Untrusted_Search_Path__char_system_10_bad();

	void CWE426_Untrusted_Search_Path__char_system_11_bad();

	void CWE426_Untrusted_Search_Path__char_system_12_bad();

	void CWE426_Untrusted_Search_Path__char_system_13_bad();

	void CWE426_Untrusted_Search_Path__char_system_14_bad();

	void CWE426_Untrusted_Search_Path__char_system_15_bad();

	void CWE426_Untrusted_Search_Path__char_system_16_bad();

	void CWE426_Untrusted_Search_Path__char_system_17_bad();

	void CWE426_Untrusted_Search_Path__char_system_18_bad();

	void CWE426_Untrusted_Search_Path__char_system_19_bad();

	void CWE426_Untrusted_Search_Path__char_system_31_bad();

	void CWE426_Untrusted_Search_Path__char_system_32_bad();

	void CWE426_Untrusted_Search_Path__char_system_34_bad();

	void CWE426_Untrusted_Search_Path__char_system_41_bad();

	void CWE426_Untrusted_Search_Path__char_system_42_bad();

	void CWE426_Untrusted_Search_Path__char_system_44_bad();

	void CWE426_Untrusted_Search_Path__char_system_45_bad();

	void CWE426_Untrusted_Search_Path__char_system_51_bad();

	void CWE426_Untrusted_Search_Path__char_system_52_bad();

	void CWE426_Untrusted_Search_Path__char_system_53_bad();

	void CWE426_Untrusted_Search_Path__char_system_54_bad();

	void CWE426_Untrusted_Search_Path__char_system_61_bad();

	void CWE426_Untrusted_Search_Path__char_system_63_bad();

	void CWE426_Untrusted_Search_Path__char_system_64_bad();

	void CWE426_Untrusted_Search_Path__char_system_65_bad();

	void CWE426_Untrusted_Search_Path__char_system_66_bad();

	void CWE426_Untrusted_Search_Path__char_system_67_bad();

	void CWE426_Untrusted_Search_Path__char_system_68_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_01_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_02_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_03_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_04_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_05_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_06_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_07_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_08_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_09_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_10_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_11_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_12_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_13_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_14_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_15_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_16_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_17_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_18_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_19_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_31_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_32_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_34_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_41_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_42_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_44_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_45_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_51_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_52_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_53_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_54_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_61_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_63_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_64_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_65_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_66_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_67_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_popen_68_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_01_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_02_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_03_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_04_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_05_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_06_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_07_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_08_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_09_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_10_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_11_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_12_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_13_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_14_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_15_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_16_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_17_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_18_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_19_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_31_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_32_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_34_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_41_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_42_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_44_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_45_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_51_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_52_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_53_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_54_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_61_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_63_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_64_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_65_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_66_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_67_bad();

	void CWE426_Untrusted_Search_Path__wchar_t_system_68_bad();

	/* END-AUTOGENERATED-C-BAD-FUNCTION-DECLARATIONS */
#endif // OMITBAD

#ifdef __cplusplus
} // end extern "C"
#endif

#ifdef __cplusplus
// declare C++ namespaces and good and bad functions

#ifndef OMITGOOD
	/* BEGIN-AUTOGENERATED-CPP-GOOD-FUNCTION-DECLARATIONS */

	/* END-AUTOGENERATED-CPP-GOOD-FUNCTION-DECLARATIONS */
#endif // OMITGOOD


#ifndef OMITBAD
	/* BEGIN-AUTOGENERATED-CPP-BAD-FUNCTION-DECLARATIONS */

	/* END-AUTOGENERATED-CPP-BAD-FUNCTION-DECLARATIONS */
#endif // OMITBAD


#endif // __cplusplus


#endif //  _TESTCASES_H
