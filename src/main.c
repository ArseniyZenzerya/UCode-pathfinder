
#include "pathfinder.h"

t_line *mx_get_bridge(const char *s);
int mx_min(int a, int b);

void dijkstra(int *dstns, char **islands, t_line **lines, int count_islands);
int island_index(char **islands, char *island);
int mx_min(int a, int b);
 void algorythmForSearchWay(int **matrix, int countUniqueValue, char **arrayForUniqueValue);
void algorythm(int count_lines, char **arr_islands, t_line **lines, int real_count_of_islands);

int main(int argc, char **argv)
{
  
    if (argc != 2)
    {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
    char *str = mx_file_to_str(argv[1]);
    if (str == NULL)
    {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(0);
    }
    
    if (mx_strlen(str) == 0)
    {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(0);
    }

    int countLine = mx_count_words(str, '\n');
    char **lines = mx_strsplit(str, '\n');

    for (int j = 0; lines[0][j] != '\0'; j++)
    {
        if (mx_isdigit(lines[0][j]) != 1 )
        {
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
    }

    if (mx_atoi(lines[0]) != (countLine - 1))
    {
        mx_printerr("error: invalid number of islands\n");
    }
    
     for (int i = 1; i < countLine; i++)     //воззможно переделать ибо сработает на ,, без - 
    {
        int check = 0;
        for (int j = 0; lines[i][j] != '\0'; j++)
        {
            if (lines[i][j] == '-' || lines[i][j] == ',')
            {
            check++;
            }
        }

        if (check != 2)
        {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            exit(0);
        }
        
    } 

    t_line **lineStr = malloc((countLine + 1) * sizeof *lineStr);
    lineStr[countLine] = NULL;


  
    long long summOfLenth = 0;
    int j = 0;
    for (int i = 1; lines[i] != NULL; i++)
    {
        lineStr[j] = NULL;
        lineStr[j] = mx_get_bridge(lines[i]);
        summOfLenth += lineStr[j]->lenth;
         j++;
    }


    for (int i = 0; i < countLine - 1; i++)
    {
            if (mx_strcmp(lineStr[i]->firstIsland, lineStr[i]->secondIsland) == 0)
            {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                exit(0);
            }
        
    }
    

    for (int i = 0; i < countLine -1; i++)
    {
        for (int j = i + 1; j < countLine -1; j++)
        {
            if ((mx_strcmp(lineStr[i]->firstIsland, lineStr[j]->firstIsland) == 0)
                    && (mx_strcmp(lineStr[i]->secondIsland, lineStr[j]->secondIsland) == 0))
                {
                    mx_printerr("error: duplicate bridges\n");
                    exit(0);
                }
            
        }
        
    }

     for (int i = 0; i < countLine - 1; i++)
    {
        if (lineStr[i]->lenth >= 2147483647)
        {
            mx_printerr("error: sum of bridges lengths is too big");
             exit(0);
        }
        
    }

    if (summOfLenth >= 2147483647)
    {
      mx_printerr("error: sum of bridges lengths is too big");
       exit(0);
    }



int countLetter = 0;

for (int i = 0; i < countLine -1 ; i++)
{
    
    countLetter += mx_strlen(lineStr[i]->firstIsland);
    countLetter ++;
    countLetter +=  mx_strlen(lineStr[i]->secondIsland);
    countLetter ++;
}

   char *stringForCheckNext = mx_strnew(countLetter);

for (int i = 0; i < countLine - 1; i++)
{
    stringForCheckNext = mx_strcat(stringForCheckNext, lineStr[i]->firstIsland);
    stringForCheckNext = mx_strcat(stringForCheckNext, " ");
    stringForCheckNext = mx_strcat(stringForCheckNext, lineStr[i]->secondIsland);
    stringForCheckNext = mx_strcat(stringForCheckNext, " ");

}


char **arrayForWork = mx_strsplit(stringForCheckNext, ' ');

for (int i = 0; arrayForWork[i] != NULL; i++)
{
    for (int j = i + 1; arrayForWork[j] != NULL; j++)
    {
        if (mx_strcmp(arrayForWork[i],arrayForWork[j]) == 0)
        {
            arrayForWork[j] = "-0";
        }
     
    }
}

int countUniqueValue = 0;
for (int i = 0; arrayForWork[i] != NULL; i++)
{
    if (mx_strcmp(arrayForWork[i], "-0") != 0)
    {
       countUniqueValue++;
    }

}

char *arrayForUniqueValue[countUniqueValue];
int k =0;

for (int i = 0; arrayForWork[i] != NULL; i++)
{
    if (mx_strcmp(arrayForWork[i], "-0") != 0)
    {
        arrayForUniqueValue[k] = mx_strnew(mx_strlen(arrayForWork[i]));
        arrayForUniqueValue[k] = mx_strcpy(arrayForUniqueValue[k], arrayForWork[i]);
        k++;
    }

}




int **matrix = (int**)malloc(countUniqueValue * sizeof(int*));
 for ( int i = 0; i < countUniqueValue; i++){  

    matrix[i] = (int*)malloc(countUniqueValue * sizeof(int));
  }

for (int i = 0; i < countUniqueValue; i++)
{
    for (int j = 0; j < countUniqueValue; j++)
    {
        matrix[i][j] = 2147483647;
         matrix[i][i] = 0;
    }
    
}




for (int i = 0; i < countLine - 1; i++)
{
    for (int k = 0; k < countUniqueValue; k++)
        {
            for (int l = 0; l < countUniqueValue; l++)
            { 
                if (mx_strcmp(lineStr[i]->firstIsland, arrayForUniqueValue[k]) == 0 
                &&  mx_strcmp(lineStr[i]->secondIsland, arrayForUniqueValue[l]) == 0)
                    {
                        matrix[k][l] = lineStr[i]->lenth;
                        matrix[l][k] = lineStr[i]->lenth;
                }
            }
        }
}






for (int k = 0; k < countUniqueValue; ++k){
    for (int i = 0; i < countUniqueValue; ++i){
        for (int j = 0; j < countUniqueValue; ++j){
            if (matrix[i][k] < 2147483647 && matrix[k][j] < 2147483647){
                    matrix[i][j] = mx_min (matrix[i][j], matrix[i][k] + matrix[k][j]);

            }
        }
    }
}
	


algorythm(countLine, arrayForUniqueValue ,lineStr, countUniqueValue);



    for(int i = 0; i < countLine - 1; i++) {
        free(lineStr[i]->firstIsland);
        free(lineStr[i]->secondIsland);
        free(lineStr[i]);
    }
    free(lines);

    return 0;
}








t_line *mx_get_bridge(const char *s)
{
    t_line *res = malloc(sizeof *res);
    char **parts = mx_strsplit(s, ',');
    res->lenth = mx_atoi(parts[1]);
    char **names = mx_strsplit(parts[0], '-');
    res->firstIsland = mx_strdup(names[0]);
    res->secondIsland = mx_strdup(names[1]);
    mx_del_strarr(&names);
    mx_del_strarr(&parts);
    return res;
}


int mx_min(int a, int b){

    if (a <= b)
        return a;
    else
        return b;
    
    

}







void algorythm(int count_lines, char **arr_islands, t_line **lines, int real_count_of_islands) {
    t_line *tmp;
    for (int i = 0; i < count_lines -1; i++) {
        for (int j = i + 1; j < count_lines - 1; j++) {
            if ((island_index(arr_islands, lines[i]->firstIsland) +
                    island_index(arr_islands, lines[i]->secondIsland)) >
                        (island_index(arr_islands, lines[j]->firstIsland) +
                            island_index(arr_islands, lines[j]->secondIsland))) {
                tmp = lines[i];
                lines[i] = lines[j];
                lines[j] = tmp;
            }
        }
    }
    int *dstns = malloc((real_count_of_islands + 1) * sizeof(int));
    for (int i = 0; i < real_count_of_islands - 1; i++) {
        for (int j = i + 1; j < real_count_of_islands; j++) {
            for (int k = 0; k < real_count_of_islands; k++) dstns[k] = -1;
            distance(&dstns, arr_islands, arr_islands[j], 0);
            dijkstra(dstns, arr_islands, lines, real_count_of_islands);
            mx_print_path(dstns, arr_islands, lines, real_count_of_islands, arr_islands[i], count_lines);
        }
    }
    free(dstns);
}


int island_index(char **islands, char *island) {
    int i = 0;
    while(islands[i]) {
        if (mx_strcmp(islands[i], island) == 0) return -1;
        i++;
    }
    return i;
}

void dijkstra(int *dstns, char **islands, t_line **lines, int count_islands)
{
    char **v = malloc(count_islands * sizeof *v);
    char *curr;
    int visits = 0;
    int i = 0;
    while ( i < count_islands ) {
        int dst = 0;
        int min = 0;
        while (is_visited(v, islands[min], visits)) min++;
        if (visits == count_islands) break;
        int j = 0;
        while ( j < count_islands){
            if (is_visited(v, islands[j], visits)) {
                j++;
                continue;
            }
            if (dstns[j] >= 0 && (dstns[min] < 0 || dstns[min] > dstns[j]))
            {
                min = j;
            }
            j++;
        }
        curr = islands[min];
        j = 0;
        while (lines[j] != NULL){
            if (!mx_strcmp(lines[j]->firstIsland, curr)) {
                if (is_visited(v, lines[j]->secondIsland, visits)) {
                    j++;
                    continue;
                }
                dst = get_dist(islands, dstns, curr);
                distance(&dstns, islands, lines[j]->secondIsland, dst + lines[j]->lenth);
            } else if (!mx_strcmp(lines[j]->secondIsland, curr)) {
                if (is_visited(v, lines[j]->firstIsland, visits)) {
                    j++;
                    continue;
                }
                dst = get_dist(islands, dstns, curr);
                distance(&dstns, islands, lines[j]->firstIsland, dst + lines[j]->lenth);
            }
            j++;
        }
        v[visits] = curr;
        visits++;
        i++;
    }
    free(v);
}

t_island *mx_create_node_island(char *island) {
    t_island *new_node = (t_island *) malloc(sizeof (t_island));
    new_node->next = NULL;
    new_node->island = island;
    return new_node;
}

int mx_list_size_islands(t_island *list) {
    int size = 0;
    while (list) {
        list = list->next;
        size++;
    }
    return size;
}
void mx_pop_back_island(t_island **head) {
    if (!head){
        return;
    }
    t_island *tmp = *head;
    while (tmp) {
        if (tmp->next != NULL && tmp->next->next != NULL){
            tmp = tmp->next;
        }
        else if (tmp->next != NULL) {
            free(tmp->next);
            tmp->next = NULL;
            break;
        } else {
            free(*head);
            *head = NULL;
            break;
        }
    }
}
void mx_push_back_island(t_island **head, char *island) {
    if (!*head) {
        *head = mx_create_node_island(island);
        return;
    }
    t_island *tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    t_island *back = mx_create_node_island(island);
 
    tmp->next = back;
}
void mx_print_path(int *weights, char **nodes, t_line **bridges, int count, char *from, int bridge_count) {
    int *len = malloc(count * sizeof *len);
    char **path = malloc((count + 1) * sizeof *path);
    path[count] = NULL;
    int *blacklist = malloc(bridge_count * sizeof *blacklist);
    int perm_blocked = 0;
    int blocked = 0;
    while (true)
    {
        int steps = get_path(len, weights, nodes, bridges, count, from, path, blacklist, &blocked, &perm_blocked);
        if (steps == -1) {
            break;
        }

        for (int i = 0; i < 40; i++) {
            mx_printchar('=');
        }
        mx_printchar('\n');

        mx_printstr("Path: ");
        mx_printstr(path[0]);
        mx_printstr(" -> ");
        mx_printstr(path[steps - 1]);
        mx_printchar('\n');
        mx_printstr("Route: ");
        for(int i = 0; i < steps; i++){
            mx_printstr(path[i]);
            if ( i != steps - 1) {
                mx_printstr(" -> ");
            }
        }
        mx_printchar('\n');
        mx_printstr("Distance: ");
        int sum = 0;
        for (int i = 0; i < steps - 1; i++)
        {
            sum += len[i];
            mx_printint(len[i]);
            if (i + 1 != steps - 1) mx_printstr(" + ");
        }
        if (sum != len[0])
        {
            mx_printstr(" = ");
            mx_printint(sum);
        }
        mx_printchar('\n');
        for (int i = 0; i < 40; i++) mx_printchar('=');
        mx_printchar('\n');
    }
    free(len);
    free(path);
    free(blacklist);
}


int get_path(int *len, int *dstns, char **islands, t_line **lines, int count_islands, char *from, char **path, int *blacklist, int *blked, int *permblkd)
{
    int cur_len = 0;
    int cur_weight = -1;
    int from_weight = 0;
    int steps = 1;
    char *cur_node = from;
    int prev_bridge_i = -1;
    path[0] = from;
    int needed_bridge = -1;
    bool break_flag = true;
    bool fell = true;
    int j = 0;
    while((j < count_islands + 1) && break_flag) {
        fell = true;
        from_weight = get_dist(islands, dstns, from);
        int i = 0;
        while(lines[i] != NULL) {
            if (is_blacklisted(i, blacklist, *blked)) {
                i++;
                continue;
            }
            if (!mx_strcmp(lines[i]->firstIsland, from)) {
                cur_node = lines[i]->secondIsland;
                cur_weight = get_dist(islands, dstns, lines[i]->secondIsland);
                cur_len = lines[i]->lenth;
            } else if (!mx_strcmp(lines[i]->secondIsland, from)) {
                cur_node = lines[i]->firstIsland;
                cur_weight = get_dist(islands, dstns, lines[i]->firstIsland);
                cur_len = lines[i]->lenth;
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
                blacklist[*blked] = i;
                *blked += 1;
                path[steps] = cur_node;
                len[steps - 1] = cur_len;
                steps++;
                break_flag = false;
                fell = false;
                needed_bridge = i;
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
            from = path[0];
            steps = 1;
            blacklist[*blked] = prev_bridge_i;
            *blked += 1;
            if (!mx_strcmp(lines[prev_bridge_i]->firstIsland, path[0])
                || !mx_strcmp(lines[prev_bridge_i]->secondIsland, path[0])) {
                blacklist[*permblkd] = prev_bridge_i;
                *permblkd += 1;
                *blked = *permblkd;
            }
        }
        if (!break_flag && (!mx_strcmp(lines[needed_bridge]->firstIsland, path[0])
                            || !mx_strcmp(lines[needed_bridge]->secondIsland, path[0]))) {
            blacklist[*permblkd] = needed_bridge;
            *permblkd += 1;
            *blked = *permblkd;
        }
        j++;
    }
    path[steps] = NULL;
    return steps;
}

void distance(int **dstns, char **islands, char *s, int dst) {
    int i = 0;
    while(islands[i]){
        if (!mx_strcmp(islands[i], s)) {
            if ((*dstns)[i] < dst && (*dstns)[i] > 0) return;
            (*dstns)[i] = dst;
            return;
        }
        i++;
    }
}

bool is_visited(char **visited, char *s, int visits) {
    int i = 0;
    while(i < visits) {
        if (!mx_strcmp(visited[i], s)) return true;
        i++;
    }
    return false;
}
bool is_blacklisted(int c, int *blacklist, int size) {
    int i = 0;
    while( i < size ) {
        if (blacklist[i] == c) {
            return true;
        }
        i++;
    }
    return false;
}
int get_dist(char **islands, int *weights, char *island) {
    int i = 0;
    while (islands[i]){
        if (!mx_strcmp(islands[i], island)) return weights[i];
        i++;
    }
    return 0;
}


















