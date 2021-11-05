#include "../inc/libmx.h"

int mx_atoi(const char *str){
    int out = 0;
    int i = 0;
    bool minus = false;
    if(str[0] == '-'){
        i++;
        minus = true;
    }

    for (; str[i] != '\0'; i++) {
        if(mx_isspace(str[i]) || !mx_isdigit(str[i])){
            break;
        }
        out = out * 10 + str[i] - 48;
    }

    if(minus){
        out *= -1;
    }

    return out;
}
