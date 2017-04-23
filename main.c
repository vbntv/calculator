#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void deletespace(char *);                    
float value(char *);                             
float plusminus(char *, int *); 
float muldiv(char *, int *);
float power(char *, int *);                 
float number(char *, int *);               
                                                                                 
int main(int argc, char *argv[])                    
{         
    if(!argv[1]) {
        printf("You did not enter anything\n");
        printf("Expected ./calc \"expression\"\n");
        exit(-1);
    }
    deletespace(argv[1]);
    printf("%g\n", value(argv[1]));
    return 0;
}

void deletespace(char *arr)
{
    int i = 0, j = 0;
    
    while ((*(arr+i) = *(arr + j++)) != '\0') 
        if (*(arr+i) != ' ')
            i++;                   
    return;
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
    float val = number(arr, index);
        
    while (*(arr + *index) == '^') {   
        switch (*(arr + *index)) {
            case '\0':                  
                return val;
            case '^':
                ++*index;                  
                val = pow(val, number(arr, index));                   //возведение в степень
                break;        
        }
    }
    return val;      
}

float number(char *arr, int *index)               //обработка строки
{     
    float val = 0;  
                                
    while (isdigit(*(arr + *index))) {                      //символы в число
        val = 10 * val + (*(arr + *index) - '0');
        ++*index;              
    }
    return val;
}    
