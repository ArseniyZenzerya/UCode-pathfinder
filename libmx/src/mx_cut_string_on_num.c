#include "../inc/libmx.h"

char *mx_cut_string_on_num(char *str, int num){

    char *timeStr = mx_strnew(mx_strlen(str) - num);

    for (int i = 0; i < mx_strlen(str) - num; i++)
    {
        *(timeStr + i) = str[num + i];
    }

return timeStr;

}

