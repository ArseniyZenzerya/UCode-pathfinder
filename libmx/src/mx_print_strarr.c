#include "../inc/libmx.h"


void mx_print_strarr(char **arr, const char *delim){
    
    int flag = 0;
    if (arr && delim)
    {
        for (int i = 0; arr[i] != NULL; i++)
        {
            if (flag == 1)
            {
                mx_printstr(delim);
            }
            
            mx_printstr(arr[i]);
            flag = 1;
        }
        mx_printchar('\n');
        
    }

    return;
}
