#include "../inc/libmx.h"

void mx_swap_char(char *s1, char *s2) {


    char timeChar1;
    char timeChar2;
    
    timeChar1 = *s1;
    timeChar2 = *s2;
    *s1 = timeChar2;
    *s2 = timeChar1;

}

