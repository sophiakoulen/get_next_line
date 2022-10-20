#include "tests.h"

int main()
{
	printf("get_next_line unit tests\n\n");

	CU_ErrorCode err = CU_initialize_registry();
	if (err == CUE_NOMEMORY)
	{
		printf("malloc error\n");
		return (0);
	}


	CU_pSuite suite_firstline = CU_add_suite("reading the first line", 0, 0);

	CU_pTest firstline5 = CU_add_test(suite_firstline, "firstline one-newline", test_firstline_onenewline);

	CU_pTest firstline2 = CU_add_test(suite_firstline, "firstline multi-line-1", test_firstline_multiline1);

	CU_pTest firstline1 = CU_add_test(suite_firstline, "firstline helloworld", test_firstline_helloworld);

	CU_pTest firstline0 = CU_add_test(suite_firstline, "firstline emptyfile", test_firstline_emptyfile);
	
	
	CU_pTest firstline3 = CU_add_test(suite_firstline, "firstline multi-line-2", test_firstline_multiline2);

	CU_pTest firstline4 = CU_add_test(suite_firstline, "firstline multi-newline", test_firstline_multinewline);


	//CU_console_run_tests();
	//CU_automated_run_tests();
	CU_basic_run_tests();
	CU_cleanup_registry();
	return (0);
}