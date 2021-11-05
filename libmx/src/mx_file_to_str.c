#include "../inc/libmx.h"


char *mx_file_to_str(const char *file){

    int fileN = open(file, O_RDONLY);

    if (fileN == -1)
    {
        close(fileN);
        return NULL;
    }
    
    int n = 0;
    int size = mx_findCount(file);

    if (size == 0)
    {
        return NULL;
    }
    

    char *str = mx_strnew(size);


    n = read(fileN, str, size);
    close(fileN);

    return str;


}

