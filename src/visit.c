#include "pathfinder.h"


bool visited(char **visited, char *s, int numberVisit) {

    for(int i = 0; i < numberVisit; i++) {
        if (!mx_strcmp(visited[i], s)) return true;
    }
    return false;
}
