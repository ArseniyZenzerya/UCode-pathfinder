#include "../inc/libmx.h"

void mx_printerr(const char *error){

    write(2, error, mx_strlen(error));

}

