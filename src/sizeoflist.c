#include "pathfinder.h"

int sizeOfList(t_island *list) {
    int size = 0;

    while (list != NULL) {
        size++;
        list = list->next;
    }

    return size;
}
