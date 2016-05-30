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

void heapSort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   for (;;) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

int main(int argc, char const *argv[]) {
    int size;
    printf("Tamanho:\n");
    scanf("%d", &size);

    int numbers[size];

    fillRandom(numbers, size);

    printNumbers(numbers, size);

    heapSort(numbers, size);

    printNumbers(numbers, size);

    return 0;
}
