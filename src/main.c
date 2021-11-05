#include "../inc/pathfinder.h"


char *mx_all_before_del(char *str, char delimeter);

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
  

    int fileN = open(argv[1], O_RDONLY);

    if (fileN == -1)
    {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        close(fileN);
        exit(0);
    }
    
    int n = 0;
    int size = mx_findCount(argv[1]);

    if (size == 0)
    {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(0);
    }
    

    char *str = mx_strnew(size);


    n = read(fileN, str, size);
    close(fileN);


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
        
    } //////////


    struct oneLine {
    
        char *firstIsland;
        char *seconndIsland;
        int lenth;

    };


    struct oneLine lineStruct[countLine];



    for (int i = 1; i < countLine; i++) //1 cause    in first line we have just number 
    {

        lineStruct[i].firstIsland = mx_all_before_del(lines[i], '-');
        lines[i] = mx_cut_string_on_num(lines[i], mx_get_substr_index(lines[i],"-") + 1);

        lineStruct[i].seconndIsland = mx_all_before_del(lines[i], ',');
        lines[i] = mx_cut_string_on_num(lines[i], mx_get_substr_index(lines[i],",") + 1);

        lineStruct[i].lenth = atoi(mx_all_before_del(lines[i], '\0'));
        mx_cut_string_on_num(lines[i], mx_get_substr_index(lines[i],"\0"));

    }
    

    for (int i = 1; i < countLine; i++)
    {
            if (mx_strcmp(lineStruct[i].firstIsland, lineStruct[i].seconndIsland) == 0)
            {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                exit(0);
            }
        
    }
    

    for (int i = 1; i < countLine; i++)
    {
        for (int j = i + 1; j < countLine; j++)
        {
            if ((mx_strcmp(lineStruct[i].firstIsland, lineStruct[j].firstIsland) == 0)
                    && (mx_strcmp(lineStruct[i].seconndIsland, lineStruct[j].seconndIsland) == 0))
                {
                    mx_printerr("error: duplicate bridges\n");
                    exit(0);
                }
            
        }
        
    }

    for (int i = 1; i < countLine; i++)
    {
        if (lineStruct[i].lenth >= 2147483647)
        {
            mx_printerr("error: sum of bridges lengths is too big");
        }
        
    }
    


// for (int i = 1; i < countLine; i++)
// {
//     printf("%s ", lineStruct[i].firstIsland);
//       printf("%s ", lineStruct[i].seconndIsland);
//         printf("%d\n", lineStruct[i].lenth);
// }


int countLetter = 0;

for (int i = 1; i < countLine; i++)
{
    
    countLetter += mx_strlen(lineStruct[i].firstIsland);
    countLetter ++;
    countLetter +=  mx_strlen(lineStruct[i].seconndIsland);
    countLetter ++;
}

   char *stringForCheckNext = mx_strnew(countLetter);

for (int i = 1; i < countLine; i++)
{
    stringForCheckNext = mx_strcat(stringForCheckNext, lineStruct[i].firstIsland);
    stringForCheckNext = mx_strcat(stringForCheckNext, " ");
    stringForCheckNext = mx_strcat(stringForCheckNext, lineStruct[i].seconndIsland);
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


int matrix[countUniqueValue][countUniqueValue];


for (int i = 0; i < countUniqueValue; i++)
{
    for (int j = 0; j < countUniqueValue; j++)
    {
        matrix[i][j] = 0;
    }
    
}




for (int i = 1; i < countLine; i++)
{
    for (int k = 0; k < countUniqueValue; k++)
        {
            for (int l = 0; l < countUniqueValue; l++)
            { 
                if (mx_strcmp(lineStruct[i].firstIsland, arrayForUniqueValue[k]) == 0 
                &&  mx_strcmp(lineStruct[i].seconndIsland, arrayForUniqueValue[l]) == 0)
                    {
                        matrix[k][l] = lineStruct[i].lenth;
                        matrix[l][k] = lineStruct[i].lenth;
                }
            }
        }
}









for (int forDefinitions = 0; forDefinitions < countUniqueValue; forDefinitions++)
{


    int d[countUniqueValue]; // минимальное расстояние
    int v[countUniqueValue]; // посещенные вершины
    int temp, minindex, min;
    int begin_index = forDefinitions;

    for (int i = 0; i<countUniqueValue; i++)
    {
        d[i] = 2147483647;
        v[i] = 1;
    }
    d[begin_index] = 0;



    // Шаг алгоритма
    do {
        minindex = 2147483647;
        min = 2147483647;
        for (int i = 0; i<countUniqueValue; i++)
        { // Если вершину ещё не обошли и вес меньше min
            if ((v[i] == 1) && (d[i]<min))
            { // Переприсваиваем значения
                min = d[i];
                minindex = i;
            }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != 2147483647)
        {
            for (int i = forDefinitions + 1; i < countUniqueValue; i++)
            {
                if (matrix[minindex][i] > 0)
                {
                temp = min + matrix[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
        v[minindex] = 0;
        }
    } while (minindex < 2147483647);


  // Восстановление пути
  int ver[countUniqueValue]; // массив посещенных вершин

   int end = 4 ; // индекс конечной вершины = 5 - 1 //4

  ver[0] = end + 1; // начальный элемент - конечная вершина //5    /// конечная буква    D
  int k = 1; // индекс предыдущей вершины
  int weight = d[end]; // вес конечной вершины   //10   // 3 - d

  while (end != begin_index) // пока не дошли до начальной вершины   
  {
     
    for (int i = 0; i<countUniqueValue; i++) // просматриваем все вершины
      if (matrix[i][end] != 0)   // если связь есть
      {
        int temp = weight - matrix[i][end]; // определяем вес пути из предыдущей вершины
        if (temp == d[i]) // если вес совпал с рассчитанным
        {                 // значит из этой вершины и был переход
          weight = temp; // сохраняем новый вес
          end = i;       // сохраняем предыдущую вершину
          ver[k] = i + 1; // и записываем ее в массив
          k++;
           printf("%d ", weight);
        }
      }
  }




    // Вывод кратчайших расстояний до вершин
    for (int i = 0; i<countUniqueValue; i++){
        if (d[i] != 2147483647 && d[i] != 0)
        {
            mx_printstr("========================================\n");
            mx_printstr("Path: ");
            mx_printstr(arrayForUniqueValue[forDefinitions]);
            mx_printstr(" -> ");
            mx_printstr(arrayForUniqueValue[i]);
            mx_printstr("\n");
            mx_printstr("Distance: ");
            mx_printint(d[i]);
            mx_printstr("\n");
            printf("\nВывод кратчайшего пути\n");
            for (int i = k - 1; i >= 0; i--)
                printf("%d ", ver[i]);

            
            mx_printstr("========================================\n");
  
 






        }
    }



}







printf("\n    ");



for (int i = 0; i < countUniqueValue; i++)
{
     printf("%5s", arrayForUniqueValue[i]);
}

 printf("\n");

for (int i = 0; i < countUniqueValue; i++)
    {
        printf("%4s ", arrayForUniqueValue[i]);
        for (int j = 0; j < countUniqueValue; j++)
        {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
printf("------------------------\n");



//     A   b   c   d   E
// A       11  10
// B               5
// C               6   15
// D                   4
// E








    return 0;
}



char *mx_all_before_del(char *str, char delimeter){

int count = 0;

    for (int i = 0; str[i] != delimeter; i++)
    {
        count ++;
    }

char *generalStr = mx_strnew(count);
    mx_strncpy(generalStr, str, count - 1);


    return generalStr;

}


