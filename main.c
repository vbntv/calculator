#include <stdio.h>
#include <stdlib.h>
                                                                                 
int main(int argc, char *argv[])                    
{         
    if(!argv[1]) {
        printf("You did not enter anything\n");
        printf("Expected ./calc \"expression\"\n");
        exit(-1);
    }
    printf("%s\n", argv[1]);
    return 0;
}
