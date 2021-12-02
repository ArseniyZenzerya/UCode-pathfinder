#include "pathfinder.h"

void endFunctionForPath(int *weights, char **nodes, t_line **bridges, int count, char *from, int bridge_count) {

    int *len = malloc(count * sizeof *len);
    char **path = malloc((count + 1) * sizeof *path);
    path[count] = NULL;
    int *check = malloc(bridge_count * sizeof *check);
    int perm_blocked = 0;
    int blocked = 0;

    while (true)
    {
        int steps = get_path(nodes, bridges, count, from, path, check, &blocked, &perm_blocked, len, weights);
        if (steps < 0) {
            break;
        }

        
        mx_printstr("========================================\n");

        mx_printstr("Path: ");
        mx_printstr(path[0]);
        mx_printstr(" -> ");
        mx_printstr(path[steps - 1]);
        mx_printchar('\n');
        mx_printstr("Route: ");
        int i = 0;

        while(i < steps){
            mx_printstr(path[i]);

            if ( i != steps - 1) {
                mx_printstr(" -> ");
            }

            i++;
        }

        mx_printchar('\n');
        mx_printstr("Distance: ");
        int sum = 0;
        i = 0;
        while (i < steps - 1)
        {
            sum += len[i];
            mx_printint(len[i]);

            if (i + 1 != steps - 1){
                 mx_printstr(" + ");
            }
            i++;
        }
        if (sum != len[0])
        {
            mx_printstr(" = ");
            mx_printint(sum);
        }
            mx_printchar('\n');
         mx_printstr("========================================\n");

    }
    free(len);
    free(path);
    free(check);
}
