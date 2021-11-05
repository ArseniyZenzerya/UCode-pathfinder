#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) {

    int count = 0;
    for (int i = 0; *(src + i) != '\0'; i++)
    {
        *(dst + i) = *(src + i);
        count++;
    }

    *(dst + count) = '\0';

        return dst;
}

