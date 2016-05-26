#include <stdio.h>
#include <stdlib.h>

void quickSort(char v[], int left, int right)
{
    int pivot, w;
    int i = left, j = right;
    pivot = v[(i+j)/2]; //pivot

    do {
        while(pivot > v[i]) i++;
        while(pivot < v[j]) j--;
        if (i <= j)
        {
            w = v[i]; v[i] = v[j]; v[j] = w;
            i++; j--;
        }
    } while(i <= j);

    if(left < j) quickSort(v, left, j);

    if (i < right) quickSort(v, i, right);
}

void printLetters(char *c, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", c[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    char letters[20] = {
        'a', 'i', 'v', 'e', 'g', 'm', 'n', 'y', 'u', 'q',
        'o', 'z', 'p', 'l', 'p', 'k', 'f', 'c', 'x', 'r'
    };

    printLetters(letters, 20);

    quickSort(letters, 0, 19);

    printLetters(letters, 20);

    return 0;
}
