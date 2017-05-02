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

CTEST(plusminus, test5) 
{   
    char *str = "-5+10";
    unsigned short index = 0;
    float result = plusminus(str, &index);
    ASSERT_EQUAL(5, result);
}

CTEST(plusminus, test6) 
{   
    char *str = "-5-5";
    unsigned short index = 0;
    float result = plusminus(str, &index);
    ASSERT_EQUAL(-10, result);
}

CTEST(muldiv, test7) 
{   
    char *str = "2*2";
    unsigned short index = 0;
    float result = muldiv(str, &index);
    ASSERT_EQUAL(4, result);
}

CTEST(muldiv, test8) 
{   
    char *str = "-2*2";
    unsigned short index = 0;
    float result = muldiv(str, &index);
    ASSERT_EQUAL(-4, result);
}

CTEST(muldiv, test9) 
{   
    char *str = "0.5*0.5";
    unsigned short index = 0;
    float result = muldiv(str, &index);
    ASSERT_EQUAL(0.25, result);
}

CTEST(muldiv, test10) 
{   
    char *str = "1/0";
    unsigned short index = 0;
    float result = muldiv(str, &index);
    ASSERT_EQUAL(-1, result);
}

CTEST(muldiv, test11) 
{   
    char *str = "0.5*0";
    unsigned short index = 0;
    float result = muldiv(str, &index);
    ASSERT_EQUAL(0, result);
}

CTEST(power, test12) 
{   
    char *str = "2^3";
    unsigned short index = 0;
    float result = power(str, &index);
    ASSERT_EQUAL(8, result);
}
 
CTEST(power, test13) 
{   
    char *str = "2^-1/2";
    unsigned short index = 0;
    float result = power(str, &index);
    ASSERT_EQUAL(0.25, result);
}

CTEST(power, test14) 
{   
    char *str = "10^-5";
    unsigned short index = 0;
    float result = power(str, &index);
    ASSERT_EQUAL(0.00001, result);
}

CTEST(power, test15) 
{   
    char *str = "0.5^-5";
    unsigned short index = 0;
    double result = power(str, &index);
    ASSERT_DBL_NEAR(32, result);
}



