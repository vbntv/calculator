#include <stdio.h>
#include <stdlib.h>

void deletespace(char *arr);
                                                                                 
int main(int argc, char *argv[])                    
{         
    if(!argv[1]) {
        printf("You did not enter anything\n");
        printf("Expected ./calc \"expression\"\n");
        exit(-1);
    }
    //deletespace(argv[1]);
    printf("%s\n", argv[1]);
    return 0;
}

/*void deletespace(char *arr)
{
    unsigned short i = 0, j = 0;
    
    while ((*(arr+i) = *(arr + j++)) != '\0') 
        if (*(arr+i) != ' ')
            i++;                   
    return;
}*/
