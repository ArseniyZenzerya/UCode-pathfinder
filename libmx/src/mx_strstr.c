#include "../inc/libmx.h"

char *mx_strstr(const char *s1, const char *s2) {

   int r = 0;
    for (int i = 0; *(s1+i) !='\0'; i++)
    {
        if (s2[0] == s1[i] ) {  /// 00 skip   //01 true
         int endCheck = 0;
         r = i;
            for (int j = 0; j <=  mx_strlen(s2); j++)
            {
                if (*(s1 + r) == *(s2+j)) {
                    endCheck++;
                    r++;   
                }
                 else{
                    endCheck = 0;
                }
                if (endCheck == mx_strlen(s2))
                {
                    return (char *)&s1[r - endCheck];
                }
            } 
        }

    }
    
    
return NULL;

}
