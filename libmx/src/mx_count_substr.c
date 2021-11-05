#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub){


if (!str || !sub)
{
    return -1;
}



char *newStr = mx_strstr(str, sub);


if (newStr){
    int count = 0;

    while(newStr){
        count ++;
        newStr = mx_cut_string_on_num(newStr, mx_strlen(sub));
        newStr = mx_strstr(newStr, sub);
    
    }

    return count;

}
else
    return 0;


 }
