#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int sizeStr = mx_strlen(s);

    for (int i = 0; i < sizeStr/2 + 1; i++)
    {
        mx_swap_char(&s[sizeStr - i], &s[i]);
    }
    
}
 
