#include <stdio.h>
#define CTEST_MAIN
#define CTEST_COLOR_OK
#include <ctest.h>

CTEST (main, test1)
{
    ASSERT_EQUAL(0, 0);
}

CTEST (main, test2)
{
    ASSERT_EQUAL(2, 3);
}

CTEST (main, test3)
{
    ASSERT_STR("2+2", "2+2");
}

int main(int argc, const char *argv[])
{ 
    return ctest_main(argc, argv);
}


