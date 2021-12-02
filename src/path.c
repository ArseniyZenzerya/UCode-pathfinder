#include "pathfinder.h"



void distance(int **distancePath, char **islands, char *s, int dst) {
    int i = 0;
    while(islands[i]){
        if (!mx_strcmp(islands[i], s)) {
            if ((*distancePath)[i] < dst && (*distancePath)[i] > 0) return;
            (*distancePath)[i] = dst;
            return;
        }
        i++;
    }
}



int get_path(char **islands, t_line **arrLine, int count_islands, char *from, char **path, int *check, int *blked, int *permblkd, int *len, int *distancePath)
{
    int cur_len = 0;
    path[0] = from;
    int bridgeNeedest = -1;
    bool break_flag = true;
    bool fell = true;
    int from_weight = 0;
    int cur_weight = -1;
    int steps = 1;
    char *cur_node = from;
    int prev_bridge_i = -1;
    int j = 0;



    while(true && break_flag && (j < count_islands + 1)) {
        fell = true;
        from_weight = getDist(islands, distancePath, from);
        int i = 0;
        while(arrLine[i]) {
            if (checkList(i, check, *blked)) {
                i++;
                continue;
            }
            if (!mx_strcmp(arrLine[i]->firstIsland, from)) {
                cur_weight = getDist(islands, distancePath, arrLine[i]->secondIsland);
                cur_len = arrLine[i]->lenth;
                cur_node = arrLine[i]->secondIsland;
               
            } else if (!mx_strcmp(arrLine[i]->secondIsland, from)) {
                cur_node = arrLine[i]->firstIsland;
                cur_len = arrLine[i]->lenth;
                cur_weight = getDist(islands, distancePath, arrLine[i]->firstIsland);
            }
            else {
                i++;
                continue;
            }

            if (from_weight < cur_len) {
                i++;
                continue;
            }

            if (cur_weight == 0) {
                check[*blked] = i;
                *blked += 1;
                fell = false;
                bridgeNeedest = i;
                path[steps] = cur_node;
                len[steps - 1] = cur_len;
                steps++;
                break_flag = false;
                break;
            }

            if (from_weight - cur_len == cur_weight) {
                prev_bridge_i = i;
                len[steps - 1] = cur_len;
                from = cur_node;
                path[steps] = from;
                steps++;
                fell = false;
                break;
            }

            i++;
        }
        if (fell == true) {

            if (!mx_strcmp(from, path[0])) {
                return -1;
            }

            j = 0;
            check[*blked] = prev_bridge_i;
            *blked += 1;
            from = path[0];
            steps = 1;
            

            if (!mx_strcmp(arrLine[prev_bridge_i]->firstIsland, path[0])
                || !mx_strcmp(arrLine[prev_bridge_i]->secondIsland, path[0])) {
                check[*permblkd] = prev_bridge_i;
                *permblkd += 1;
                *blked = *permblkd;
            }

        }

        if (!break_flag && (!mx_strcmp(arrLine[bridgeNeedest]->firstIsland, path[0])
                            || !mx_strcmp(arrLine[bridgeNeedest]->secondIsland, path[0]))) {
            check[*permblkd] = bridgeNeedest;
            *permblkd += 1;
            *blked = *permblkd;
        }
        j++;
    }
    path[steps] = NULL;
    return steps;
}

int getDist(char **islands, int *weights, char *island) {

    int i = 0;
    while (islands[i]){

        if (!mx_strcmp(islands[i], island)) return weights[i];
        i++;
    }

    return 0;
}

