#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n){

    char *p_s = (char *)s;

    for (size_t i = 0; *p_s != 0 && i < n; i++)
    {
        if (*p_s == c)
        {
            return p_s;
        }
        p_s++;
        
    }



return NULL;

}


