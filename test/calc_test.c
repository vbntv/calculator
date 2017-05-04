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
    char *str = "2,5 + 2,5";
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
    ASSERT_EQUAL(32, result);
}

CTEST(precedence rule, test16)  
{   
    char *str = "2+2*2";
    double result = value(str);
    ASSERT_EQUAL(6, result);
}

CTEST(precedence rule, test17)
{   
    char *str = "1+2*3";
    double result = value(str);
    ASSERT_EQUAL(7, result);
}

CTEST(precedence rule, test18)
{   
    char *str = "1+2^3";
    double result = value(str);
    ASSERT_EQUAL(9, result);
}

CTEST(precedence rule, test19)
{   
    char *str = "10*2^3+5";
    double result = value(str);
    ASSERT_EQUAL(85, result);
}

CTEST(precedence rule, test20)
{   
    char *str = "10*2^3*5";
    double result = value(str);
    ASSERT_EQUAL(400, result);
}

CTEST(precedence rule, test21)
{   
    char *str = "8^4/2";
    double result = value(str);
    ASSERT_EQUAL(2048, result);
}

CTEST(precedence rule, test22)
{   
    char *str = "8^4/2/0";
    double result = value(str);
    ASSERT_EQUAL(-1, result);
}

CTEST(priority, test23)
{   
    char *str = "(2+2)*2";
    double result = value(str);
    ASSERT_EQUAL(8, result);
}

CTEST(priority, test24)
{   
    char *str = "(2+2+3*6-8*9)*(5-5)";
    double result = value(str);
    ASSERT_EQUAL(0, result);
}

CTEST(number, test25) 
{   
    char *str = "abc";
    unsigned short index = 0;
    float result = number(str, &index);
    ASSERT_EQUAL(-1, result);
}

CTEST(number, test26) 
{   
    char *str = "2,5+0";
    unsigned short index = 0;
    float result = number(str, &index);
    ASSERT_EQUAL(-1, result);
}



