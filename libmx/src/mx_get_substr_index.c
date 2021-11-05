#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub){


if (!str || !sub)
{
    return -2;
}


    int r = 0;
    for (int i = 0; *(str+i) !='\0'; i++)
    {
        r++;
        if (sub[0] == str[i]) {
            int endCheck = 0;
            for (int j = 0; j <  mx_strlen(sub); j++)
            {
                if (*(str + r - 1) == *(sub+j)) {
                    endCheck++;
                    r++;   
                }
                 if (endCheck == mx_strlen(sub))
                {
                    return (r - endCheck - 1);
                }
            } 
            
        }
    }
    
    
return -1;

}



