#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void deletespace(char *);                    
float value(char *);                             
float plusminus(char *, int *);                 
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
    float val = number(arr, index);
        
    while (*(arr + *index) == '+' || *(arr + *index) == '-') {                                          
        switch (*(arr + *index)) {       
            case '+':
                ++*index;          
                val += number(arr, index);
                break;
            case '-':
                ++*index;           
                val -= number(arr, index);
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
