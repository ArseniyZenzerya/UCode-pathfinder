#ifndef PATHFINDER
#define PATHFINDER

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <malloc/malloc.h>


 typedef struct oneLine {
    
        char *firstIsland;
        char *secondIsland;
        int lenth;

    }t_line;


typedef struct s_island {
    char *island;
    struct s_island *next;
}t_island;

bool checkList(int c, int *check, int size);
void endFunctionForPath(int *weights, char **nodes, t_line **bridges, int count, char *from, int bridge_count);
int sizeOfList(t_island *list);
t_island *createNodes(char *island);
t_line *buildBridge(const char *s);
void algorythmForSearchWay(int **matrix, int countUniqueValue, char **arrayForUniqueValue);
char *mx_all_before_del(char *str, char delimeter);
bool checkList(int c, int *blacklist, int size);
bool visited(char **visited, char *s, int visits);
void distance(int **dstns, char **islands, char *s, int dst);
int get_path(char **islands, t_line **arrLine, int count_islands, char *from, char **path, int *check, int *blked, int *permblkd, int *len, int *distancePath);
void endFunctionForPath(int *weights, char **nodes, t_line **bridges, int count, char *from, int bridge_count);
void mx_push_back_island(t_island **head, char *island);
void mx_pop_back_island(t_island **head);
int mx_list_size_islands(t_island *list);
void dictPath(int *dstns, char **islands, t_line **lines, int count_islands);
t_island *mx_create_node_island(char *island);
int getDist(char **islands, int *weights, char *island);
int island_index(char **islands, char *island);
int mx_min(int a, int b);
void dictPath(int *distancePath, char **islands, t_line **arrLine, int count_islands);
void algorythm(char **arrayNameIslands, int countOfLine, t_line **arrLine, int countUniqueValue);
int index(char **islands, char *island);
#include "../libmx/inc/libmx.h"



#endif
