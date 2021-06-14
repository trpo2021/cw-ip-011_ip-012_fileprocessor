#include "fileRename.h"

#include <ctest.h>
#include <string.h>

CTEST(filerename_suite, rename_success)
{
	char key[100], dir[100], lay;
	
	strcpy(dir, "test/testdir/");
	lay = 3;
	strcpy(key, "renamed");
	
	int testExp = RENAMESUCCESS;
	int testResult = fileRename(key, dir, lay);
	
	ASSERT_EQUAL(testExp, testResult);
}

CTEST(filerename_suite, rename_success)
{
	char key[100], dir[100], lay;
	
	strcpy(dir, "test/testdir/");
	lay = 4;
	strcpy(key, "renamed");
	
	int testExp = WRONGLAYOUT;
	int testResult = fileRename(key, dir, lay);
	
	ASSERT_EQUAL(testExp, testResult);
}
