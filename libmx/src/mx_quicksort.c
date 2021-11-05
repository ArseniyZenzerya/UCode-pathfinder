#include "../inc/libmx.h"



int mx_quicksort(char **arr, int left, int right){

int counter = 0;
    if (left < right)
    {
        int first = left;
        int last = right;
        int middle = mx_strlen(arr[(first + last) / 2]);
        do
        {
            while (mx_strlen(arr[first]) < middle) first++;
            while (mx_strlen(arr[last]) > middle) last--;
            if (first <= last)
            {
                char *tmp = arr[first];
                arr[first] = arr[last];
                arr[last] = tmp;
                first++;
                last--;
                counter ++;
            }
        } while (first <= last);
        mx_quicksort(arr, left, last);
        mx_quicksort(arr, first, right);
    }


    return counter;
}

