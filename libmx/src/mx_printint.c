#include "../inc/libmx.h"

void mx_printint(int n){
    int save[10];
    int length = 0;

    if(n < 0){
        mx_printchar('-');
        n *= -1;
    }

    do{
        save[length] = n % 10;
        n = n / 10;
        length++;
    }while(n);

    length--;

    while (length != -1){
        mx_printchar(save[length] + 48);
        length--;
    }

    return;
}

