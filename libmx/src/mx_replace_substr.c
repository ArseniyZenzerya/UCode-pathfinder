#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace){

    int countSub = mx_count_substr(str, sub);

    int sizeOfStr = mx_strlen(str);
    int sizeSub = mx_strlen(sub);
    int sizeReplace = mx_strlen(replace);

    char *arr = mx_strnew(mx_strlen(str));

    mx_strcpy(arr, str);

    char *newArr = mx_strnew(sizeOfStr - sizeSub  * countSub + sizeReplace * countSub);


    int n = 0;


for (int j = 0; j < countSub; j++)
{


    for (int i = 0; i < mx_get_substr_index(arr, sub); i++)
    {
        newArr[n] = arr[i];
        n++;
    }
    
    for (int l = 0; l < sizeSub; l++)
    {
        newArr[n] = replace[l];
        n++;
    }
    arr = mx_cut_string_on_num(arr, mx_get_substr_index(arr, sub) + sizeSub);
}
    

return newArr;

}


