#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2){


    char *newStr;
   
    if (s1 != NULL && s2 == NULL) {
        newStr = mx_strdup(s1);
    }
    else if (s1 == NULL && s2 != NULL) {
        newStr = mx_strdup(s2);
    }
    else if (s1 == NULL && s2 == NULL) {
        return NULL;
    }
    else {
        newStr = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        mx_strcat(newStr, s1);
        mx_strcat(newStr, s2);
    }
    return newStr;
}


