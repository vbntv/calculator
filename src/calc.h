#ifndef CALC_H
#define CALC_H

void delete_space(char *);                           //удаление пробелов из строки
void check_brackets(char *);                         //определяет правильность введённой скобочной структуры
float value(char *);                                //получение результата
float plus_minus(char *, unsigned short *);          //сложение "+" вычитание "-"            
float muldiv(char *, unsigned short *);             //умножение "*" деление "/"
float power(char *, unsigned short *);              //возведение в степень  "^"
float brackets_priority(char *, unsigned short *);   //приоритет для скобок
float number(char *, unsigned short *);             //получение числа из строки

#endif  
