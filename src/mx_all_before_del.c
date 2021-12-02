#include "../inc/pathfinder.h"

char *mx_all_before_del(char *str, char delimeter){

int count = 0;

    for (int i = 0; str[i] != delimeter; i++)
    {
        count ++;
    }

char *generalStr = mx_strnew(count);
    mx_strncpy(generalStr, str, count - 1);


    return generalStr;

}


