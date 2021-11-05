#include "../inc/libmx.h"

char *mx_strnew(const int size){


    char *p = (char *) malloc(size + 1);

    if (p == NULL)
        return NULL;

    for (int i = 0; i < size + 1; i++)
        p[i] = '\0';

    return p;
}
