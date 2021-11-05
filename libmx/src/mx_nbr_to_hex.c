#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr){

long buf = nbr;


int n = 0;

    while (buf != 0)
    {
        n++;
        buf /= 16;
    }

    if (n <= 0)
    {
        return 0;
    }

    char *str = mx_strnew(n);
    
    for (int i = n - 1; i >= 0; i--)
    {
        int ost = nbr % 16;

        if (ost < 10)
        {
            *(str + i) = ost + 48;
        }
        else{
            *(str + i) = ost + 87;
        }
       
        nbr /= 16;
    }

    return str;
}

