#include <stdio.h>
#include <math.h>
#include <stdlib.h>                                 
#include "calc.h"
 
void delete_space(char *str)
{
    unsigned short i = 0, j = 0;
    
    while ((*(str+i) = *(str + j++)) != '\0') {
        if (*(str+i) != ' ') {
            i++;
        }
    }
}

void check_brackets(char *str)
{
    unsigned short open = 0, close = 0;
    
    while (*str) {
        if (*str == '(') {
            open++;
        } else if (*str == ')') {
            close++;
        }
   
        ++str;
    }
  
    if (open > close || close > open) {
        printf("Brackets unbalanced!\n");
        exit(-1);
    }
        
}

float value(char *str)
{
    unsigned short index = 0;

    return plus_minus(str, &index);
}
 
float plus_minus(char *str, unsigned short *index)
{
    float value = muldiv(str, index);

    while (*(str + *index) == '+' || *(str + *index) == '-') {                            
        switch (*(str + *index)) {
        case '+':
            ++*index;
            value += muldiv(str, index);
            break;

        case '-':
            ++*index;
            value -= muldiv(str, index);
            break;
        }
    }
    
    return value;
}
 
float muldiv(char *str, unsigned short *index)      
{
    float divider;
    float value = power(str, index);

    while (*(str + *index) == '*' || *(str + *index) == '/') {                       
        switch (*(str + *index)) {
        case '*':
            ++*index;
            value *= power(str, index);
            break;

        case '/':
            ++*index;
            divider = power(str, index);
            
            if (divider != 0) {                      
                value /= divider;
            } else {                        
                printf("Division by zero is not defined\n");         
                exit(-1);
            }
            
            break;
       }
    }
    
    return value;
}
              
float power(char *str, unsigned short *index)         
{
    float value = brackets_priority(str, index);

    while (*(str + *index) == '^') {
        switch (*(str + *index)) {
        case '^':
            ++*index;
            value = pow(value, brackets_priority(str, index));         
            break;
        }
    }
    
    return value;
}

float brackets_priority(char *str, unsigned short *index)    
{
    float value;

    if (*(str + *index) == '(') {                   
        ++*index;
        value = plus_minus(str, index);
        ++*index;
    } else {
        value = number(str, index);  
    }
    
    return value;
}
 
float number(char *str, unsigned short *index)                     
{
    float value = 0;
    float factor = 1;
    short flag = 1;

    while (*(str + *index) == '-') {                    
        flag *= -1;
        ++*index;
    }

    while (*(str + *index) >= 'a' && *(str + *index) <= 'z') {                      
       printf("Incorrect input\n");
       exit(-1);
    }
    
    while (*(str + *index) >= '0' && *(str + *index) <= '9') {
        value = 10 * value + (*(str + *index) - '0');
        ++*index;
    }
    
    if (*(str + *index) == ',') {
        printf("Introduced \",\" but expected \".\"\n");
        exit(-1);
    }
    
    if ( *(str + *index) == '.') {
        ++*index;
                         
        while (*(str + *index) >= '0' && *(str + *index) <= '9') { 
            factor *= 0.1;
            value = value + (*(str + *index) - '0') * factor;
            ++*index;
        }
    }
    
    return value * flag;
}
