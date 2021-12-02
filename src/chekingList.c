#include "pathfinder.h"

bool checkList(int c, int *check, int size) {

    for(int i = 0; i < size; i++ ) {
        if (check[i] == c) {
            return true;
        }
    }
    return false;
}


