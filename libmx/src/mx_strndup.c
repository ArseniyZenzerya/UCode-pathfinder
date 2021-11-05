#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n){


    char *newStr = mx_strnew(n);

    if (newStr == NULL || s1 == NULL) 
        return NULL; 


    for (size_t i = 0; i < n; i++)
    {
        newStr[i] = s1[i];
    }
    

    return newStr;

}





