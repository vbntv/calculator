#ifndef CALC_H
#define CALC_H

void deletespace(char *);                           //удаление пробелов из строки
void checkbrackets(char *);                         //определяет правильность введённой скобочной структуры
float value(char *);                                //получение результата
float plusminus(char *, unsigned short *);          //сложение "+" вычитание "-"            
float muldiv(char *, unsigned short *);             //умножение "*" деление "/"
float power(char *, unsigned short *);              //возведение в степень  "^"
float priority(char *, unsigned short *);           //приоритет для скобок и проверка на отрицательный префикс
float number(char *, unsigned short *);             //получение числа 

#endif  
