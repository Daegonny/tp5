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
    clock_t t1, t2;
    int size;
    printf("Tamanho:\n");
    scanf("%d", &size);

    int numbers[size];
    fillRandom(numbers, size);

    t1 = clock();
    heapSort(numbers, size);
    t2 = clock();

    printf("tempo = %.3e segundos\n", ((double)t2 - (double)t1) / (double)CLOCKS_PER_SEC );
    return 0;
}
