#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

//GLOBALS
char pivots[SIZE], lefts[SIZE], rights[SIZE];

int isInArray(char x, char array[], int from, int size)
{
    int i = from;
    int flag = 0;

    while( i < size && !flag)
    {
        if(array[i] == x) flag = 1;
        i++;
    }

    return flag;
}

void printLetters(char *c, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", c[i]);
    }
    printf("\n\n");
}

void printQuickSort(char letters[], int index, int size)
{
    int i;
    for( i = 0; i < size; i++)
    {
        if(isInArray(letters[i], lefts, 0, size)) printf("[ ");
        // if(isInArray(letters[i], pivots,  size)) printf("(");
        printf("%c ", letters[i]);
        // if(isInArray(letters[i], pivots,  size)) printf(") ");
        // if(isInArray(letters[i], rights, 0, size)) printf("] ");
    }
    printf("]\n\n");
}

void quickSort(char v[], int left, int right, int *index)
{

    int pivot, w;
    int i = left, j = right;
    pivot = v[(i+j)/2]; //pivot

    pivots[*index] = pivot;
    lefts[*index] = v[left];
    rights[*index] = v[right];

    *index = *index + 1;

    printLetters(v, SIZE);

    // printQuickSort(v, *index, SIZE);

    do {
        while(pivot > v[i]) i++;
        while(pivot < v[j]) j--;
        if (i <= j)
        {
            w = v[i]; v[i] = v[j]; v[j] = w;
            i++; j--;
        }
    } while(i <= j);

    if(left < j) quickSort(v, left, j, index);

    if (i < right) quickSort(v, i, right, index);
}

int main(int argc, char const *argv[]) {

    int index = 0;

    char letters[SIZE] = {
        'a', 'i', 'v', 'e', 'g', 'm', 'n', 'y', 'u', 'q',
        'o', 'z', 'p', 'l', 'j', 'k', 'f', 'c', 'x', 'r'
    };

    quickSort(letters, 0, SIZE-1, &index);

    int k;
    for(k = 0; k < index; k++){
        printf("%2d => , ", k);
        printf("%c, ", pivots[k]);
        printf("%c, ", lefts[k]);
        printf("%c\n", rights[k]);
    }
    return 0;
}
