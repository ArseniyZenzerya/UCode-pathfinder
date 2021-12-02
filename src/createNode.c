#include "pathfinder.h"

t_island *createNodes(char *island) {
    t_island *new = (t_island *) malloc(sizeof (t_island));
    new->island = island;
    new->next = NULL;
    return new;
}
