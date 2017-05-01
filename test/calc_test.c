#include <stdio.h>
#include <math.h>
#include <stdlib.h>                                 
#include <ctype.h>
#include "calc.h"
#include <ctest.h>
#define CTEST_COLOR_OK

CTEST(plusminus, test1) 
{   
    char *str = "2+2";
    unsigned short index = 0;
    float result = plusminus(str, &index);
    ASSERT_EQUAL(4, result);
}

CTEST(plusminus, test2) 
{   
    char *str = "2,5 + 2,5";  //выдаст ошибку т.к должна быть точка а не запятая
    unsigned short index = 0;
    float result = plusminus(str, &index);
    ASSERT_EQUAL(-1, result);
}

CTEST(plusminus, test3) 
{   
    char *str = "2.5+2.5";
    unsigned short index = 0;
    float result = plusminus(str, &index);
    ASSERT_EQUAL(5, result);
}
CTEST(plusminus, test4) 
{   
    char *str = "1+1.5";
    unsigned short index = 0;
    float result = plusminus(str, &index);
    ASSERT_EQUAL(2.5, result);
}



