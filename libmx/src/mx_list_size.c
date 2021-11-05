#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    int count = 0;

    t_list *tmp = NULL;

    if (list) {
        tmp = list;


        while (tmp != NULL) {
            tmp = tmp -> next;
            count++;
        }
    }
    return count;
}
