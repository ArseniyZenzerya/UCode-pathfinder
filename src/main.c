#include "pathfinder.h"



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
    char **arrLine = mx_strsplit(str, '\n');

    for (int j = 0; arrLine[0][j] != '\0'; j++)
    {
        if (mx_isdigit(arrLine[0][j]) != 1 )
        {
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
    }

    
     for (int i = 1; i < countLine; i++)     //воззможно переделать ибо сработает на ,, без - 
    {
        int check = 0;
        for (int j = 0; arrLine[i][j] != '\0'; j++)
        {
            if (arrLine[i][j] == '-' || arrLine[i][j] == ',')
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

    t_line **arrLinetr = malloc((countLine + 1) * sizeof *arrLinetr);
    arrLinetr[countLine] = NULL;


  
    long long summOfLenth = 0;
    int j = 0;
    for (int i = 1; arrLine[i] != NULL; i++)
    {
        arrLinetr[j] = NULL;
        arrLinetr[j] = buildBridge(arrLine[i]);
        summOfLenth += arrLinetr[j]->lenth;
         j++;
    }


    for (int i = 0; i < countLine - 1; i++)
    {
            if (mx_strcmp(arrLinetr[i]->firstIsland, arrLinetr[i]->secondIsland) == 0)
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
            if ((mx_strcmp(arrLinetr[i]->firstIsland, arrLinetr[j]->firstIsland) == 0)
                    && (mx_strcmp(arrLinetr[i]->secondIsland, arrLinetr[j]->secondIsland) == 0))
                {
                    mx_printerr("error: duplicate bridges\n");
                    exit(0);
                }
            
        }
        
    }

     for (int i = 0; i < countLine - 1; i++)
    {
        if (arrLinetr[i]->lenth >= 2147483647)
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
    
    countLetter += mx_strlen(arrLinetr[i]->firstIsland);
    countLetter ++;
    countLetter +=  mx_strlen(arrLinetr[i]->secondIsland);
    countLetter ++;
}

   char *stringForCheckNext = mx_strnew(countLetter);

for (int i = 0; i < countLine - 1; i++)
{
    stringForCheckNext = mx_strcat(stringForCheckNext, arrLinetr[i]->firstIsland);
    stringForCheckNext = mx_strcat(stringForCheckNext, " ");
    stringForCheckNext = mx_strcat(stringForCheckNext, arrLinetr[i]->secondIsland);
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

   if (mx_atoi(arrLine[0]) != countUniqueValue)
    {
        mx_printerr("error: invalid number of islands\n");
        exit(0);
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
                if (mx_strcmp(arrLinetr[i]->firstIsland, arrayForUniqueValue[k]) == 0 
                &&  mx_strcmp(arrLinetr[i]->secondIsland, arrayForUniqueValue[l]) == 0)
                    {
                        matrix[k][l] = arrLinetr[i]->lenth;
                        matrix[l][k] = arrLinetr[i]->lenth;
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
	


algorythm(arrayForUniqueValue, countLine, arrLinetr, countUniqueValue);



    for(int i = 0; i < countLine - 1; i++) {
        free(arrLinetr[i]->firstIsland);
        free(arrLinetr[i]->secondIsland);
        free(arrLinetr[i]);
    }
    free(arrLine);

    return 0;
}






int index(char **islands, char *island) {
    int i = 0;
    while (islands[i] != NULL) {
        if (mx_strcmp(islands[i], island) == 0) 
            return -1;
        i++;
    }
    return i;
}



void popBack(t_island **head) {

    if (!head){
        return;
    }

    t_island *tmp = *head;

    while (tmp) {
        if (tmp->next->next != NULL && tmp->next != NULL){
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
void pushBack(t_island **head, char *island) {

    if (!*head) {
        *head = createNodes(island);
        return;
    }

    t_island *tmp = *head;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    t_island *back = createNodes(island);
 
    tmp->next = back;
}




















