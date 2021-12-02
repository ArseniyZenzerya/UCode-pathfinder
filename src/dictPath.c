
#include "pathfinder.h"

void dictPath(int *distancePath, char **islands, t_line **arrLine, int count_islands)
{
    char **v = malloc(count_islands * sizeof *v);
    char *curr;
    int numberVisit = 0;
    int i = 0;
    while ( i < count_islands ) {
        int dst = 0;
        int min = 0;

        while (visited(v, islands[min], numberVisit)) min++;

        if (numberVisit == count_islands) break;
        int j = 0;
        
        while ( j < count_islands){
            if (visited(v, islands[j], numberVisit)) {
                j++;
                continue;
            }
            if ((distancePath[min] < 0 || distancePath[min] > distancePath[j]) && distancePath[j] >= 0)
            {
                min = j;
            }
            j++;
        }

        curr = islands[min];
        j = 0;

        while (arrLine[j] != NULL){
            if (!mx_strcmp(arrLine[j]->secondIsland, curr)) {
                if (visited(v, arrLine[j]->firstIsland, numberVisit)) {
                    j++;
                    continue;
                }
                dst = getDist(islands, distancePath, curr);
                distance(&distancePath, islands, arrLine[j]->firstIsland, dst + arrLine[j]->lenth);
            } else if (!mx_strcmp(arrLine[j]->firstIsland, curr)) {
                if (visited(v, arrLine[j]->secondIsland, numberVisit)) {
                    j++;
                    continue;
                }
                dst = getDist(islands, distancePath, curr);
                distance(&distancePath, islands, arrLine[j]->secondIsland, dst + arrLine[j]->lenth);
            }
            j++;
        }

        v[numberVisit] = curr;
        numberVisit++;
        i++;
    }
    free(v);
}
