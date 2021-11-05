#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {


if (!str)
{
    return -1;
}

int count = 1;
int size = 0;

    for (int i = 0; *(str + i) != '\0'; i++)
    {    
        if (*(str + i) == delimiter && *(str + i + 1) != delimiter) {
            count ++;
        }
        size ++;

    }
    if (str[0] == delimiter) {
        count --;
    }
    if (str[size - 1] == delimiter) {
        count --;
    }
    return count;
}

