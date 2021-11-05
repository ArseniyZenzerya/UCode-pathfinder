#include "../inc/libmx.h"

char *mx_itoa(int number){

    int timeNum = number;
    int counter = 0;

    while(timeNum != 0){
        counter ++;
        timeNum /= 10;
    }

    char *string = mx_strnew(counter); // change on mx_newstr
    int oneOfNum;
    for (int i = counter; i > 0; i--) {
        oneOfNum =  number % 10;
        string[i - 1] = oneOfNum + 48;
        number /= 10;
    }

    return string;
}

