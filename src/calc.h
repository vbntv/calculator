#ifndef CALC_H
#define CALC_H

void deletespace(char *);
void checkbrackets(char *);         
float value(char *);                             
float plusminus(char *, int *); 
float muldiv(char *, int *);
float power(char *, int *);
float priority(char *, int *);
float number(char *, int *);  

#endif  
