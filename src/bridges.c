#include "pathfinder.h"
t_line *buildBridge(const char *s)
{
    t_line *res = malloc(sizeof *res);
    char **piece = mx_strsplit(s, ',');

    res->lenth = mx_atoi(piece[1]);
    char **name = mx_strsplit(piece[0], '-');
    res->firstIsland = mx_strdup(name[0]);

    res->secondIsland = mx_strdup(name[1]);
    mx_del_strarr(&name);
    mx_del_strarr(&piece);
    return res;
}

