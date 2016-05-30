#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandom (int *numbers, int n){
    srand(time(0));
    int i;
    for (i = 0; i < n; i++) {
        numbers[i] = rand()%1001;
    }
}

void printNumbers(int *numbers, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");
}

void quickSort(int vet[], int esq, int dir){
    int pivo = esq,i,ch,j;
    for(i=esq+1;i<=dir;i++){
        j = i;
        if(vet[j] < vet[pivo]){
         ch = vet[j];
         while(j > pivo){
            vet[j] = vet[j-1];
            j--;
         }
         vet[j] = ch;
         pivo++;
        }
    }
    if(pivo-1 >= esq){
        quickSort(vet,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        quickSort(vet,pivo+1,dir);
    }
 }

int main(int argc, char const *argv[]) {

    int size;
    printf("Tamanho:\n");
    scanf("%d", &size);

    int numbers[size];

    fillRandom(numbers, size);

    printNumbers(numbers, size);

    quickSort(numbers, 0, size-1);

    printNumbers(numbers, size);

    return 0;
}
