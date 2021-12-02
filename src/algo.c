#include "pathfinder.h"

void algorythm(char **arrayNameIslands, int countOfLine, t_line **arrLine, int countUniqueValue) {

    for (int i = 0; i < countOfLine - 1; i++) {

        for (int j = i + 1; j < countOfLine - 1; j++) {

            if ((index(arrayNameIslands, arrLine[i]->firstIsland) +
                    index(arrayNameIslands, arrLine[i]->secondIsland)) >
                        (index(arrayNameIslands, arrLine[j]->firstIsland) +
                            index(arrayNameIslands, arrLine[j]->secondIsland))) {
                
                t_line *tmp;
                tmp = arrLine[i];
                arrLine[i] = arrLine[j];
                arrLine[j] = tmp;

            }

        }
        
    }
    int *distancePath = malloc((countUniqueValue + 1) * sizeof(int));
    for (int i = 0; i < countUniqueValue - 1; i++) {
        for (int j = i + 1; j < countUniqueValue; j++) {
            for (int k = 0; k < countUniqueValue; k++) distancePath[k] = -1;
            distance(&distancePath, arrayNameIslands, arrayNameIslands[j], 0);
            dictPath(distancePath, arrayNameIslands, arrLine, countUniqueValue);
            endFunctionForPath(distancePath, arrayNameIslands, arrLine, countUniqueValue, arrayNameIslands[i], countOfLine);
        }
    }
    free(distancePath);
}
