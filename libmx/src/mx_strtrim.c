#include "../inc/libmx.h"

char *mx_strtrim(const char *str){
int countBefore = 0;
int countAfter = 0;

    if (str == NULL)
        return NULL;

    for (int i = 0; mx_isspace(*(str + i)) == 1; i++)
    {
        countBefore ++;
    }
    for (int i = mx_strlen(str); mx_isspace(*(str + i - 1)) == 1; i--)
    {
        countAfter ++;
    }
    
    int newsize = mx_strlen(str) - countBefore - countAfter;

    char *newString = mx_strnew(newsize);

    char Str[newsize];

    for (int i = 0; i < newsize; i++)
    {
        *(Str + i) = *(str + countBefore + i);
    }


mx_strncpy(newString, Str, newsize - 1);


return newString;
}
