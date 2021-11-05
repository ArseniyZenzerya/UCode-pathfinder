#include "../inc/libmx.h"

int mx_findCount(const char *fileName){

    
    int file = open(fileName, O_RDONLY);
    char s;
    long n = read(file, &s, 1);
    int count = 0;

    while (n > 0) {
            n = read(file, &s, 1);
            count++;
    }
    close(file);
    return count;
}

