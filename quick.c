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
    clock_t t1, t2;
    int size;
    printf("Tamanho:\n");
    scanf("%d", &size);

    int numbers[size];
    fillRandom(numbers, size);

    t1 = clock();
    quickSort(numbers, 0, size-1);
    t2 = clock();

    printf("tempo = %.3e segundos\n", ((double)t2 - (double)t1) / (double)CLOCKS_PER_SEC );
    return 0;
}
