#include <stdio.h>
#include <math.h>
#include <stdlib.h>                                 
#include <ctype.h>
#include "calc.h"
 
void deletespace(char *arr)
{
    int i = 0, j = 0;
    
    while ((*(arr+i) = *(arr + j++)) != '\0') 
        if (*(arr+i) != ' ')
            i++;                   
    return;
}

void checkbrackets(char *arr)
{
    int open = 0, close = 0;
    
    while (*arr) {
        if (*arr == '(') {
            open++;
        } else if(*arr == ')') {
            close++;
        }
        ++arr;
    }
    if (close != open) {
        printf("Brackets unbalanced!\n");
        exit(-1);
    }
        
}

float value(char *arr)
{
    int index = 0;
 
    return plusminus(arr, &index);
}
 
float plusminus(char *arr, int *index)
{                                 
    float val = muldiv(arr, index);
        
    while (*(arr + *index) == '+' || *(arr + *index) == '-') {                                          
        switch (*(arr + *index)) {       
            case '\0':                                                  //проверка на конец строки (потом можно убрать это для тестов)
                return val;
            case '+':
                ++*index;          
                val += muldiv(arr, index);
                break;
            case '-':
                ++*index;           
                val -= muldiv(arr, index);
                break;                                                    
        }
    }
    return val;
}
 
float muldiv(char *arr, int *index)                        //multiplication - '/' division - '*'
{    
    float div;      
    float val = power(arr, index);   
     
    while (*(arr + *index) == '*' || *(arr + *index) == '/') {                                  
        switch (*(arr + *index)) {      
            case '\0':                  
                return val;
            case '*':
                ++*index;
                val *= power(arr, index);
                break;
            case '/':
                ++*index;
                div = power(arr, index);
                if (div != 0) {                                     //проверка на делениние на 0
                    val /= div;
                }
                else {                                            
                    printf("Division by zero is not defined\n");          
                    exit(-1);
                }
                break;
       }
   }
    return val;
} 
                 
float power(char *arr, int *index)                
{                  
    float val = priority(arr, index);
        
    while (*(arr + *index) == '^') {   
        switch (*(arr + *index)) {
            case '\0':                  
                return val;
            case '^':
                ++*index;                  
                val = pow(val, priority(arr, index));                   //возведение в степень
                break;        
        }
    }
    return val;      
}

float priority(char *arr, int *index)        
{
    float val;    
    int flag = 1; 
   
    while (*(arr + *index) == '-') {                    //проверка на отрицательный префикс (-1)    
        flag *= -1;
        ++*index; 
    } 
    
    if (*(arr + *index) == '(') {                       //ищет открывающую скобку
        ++*index;
        val = plusminus(arr, index);
        ++*index;                 
    }
    else
        val = number(arr, index);    
        
    return val * flag;
}
 
float number(char *arr, int *index)                     //обработка строки
{     
    float val = 0; 
    float factor = 1;


    while (*(arr + *index) >= 'a' && *(arr + *index) <= 'z') {                             //проверка на буквы
       printf("Incorrect input\n");
       exit(-1);
    }                                 
    while (*(arr + *index) >= '0' && *(arr + *index) <= '9') {    //символы в число
        val = 10 * val + (*(arr + *index) - '0');
        ++*index;              
    }
    if (*(arr + *index) == ',') {                                 //проверка на запятую
        printf("Introduced \",\" but expected \".\"\n");
        exit(-1);
    }                               
    if (*(arr + *index) != '.') {                           //проверка на десятичную точку
        return val;
    }              
    while (*(arr + *index) >= '0' && *(arr + *index) <= '9') {     //десятичная часть
        factor *= 0.1;
        val = val + (*(arr + *index) - '0') * factor;
    }
    return val;
}        
