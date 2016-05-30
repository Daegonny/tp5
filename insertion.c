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

void insertionSort(int original[], int length)
{
	int i, j, atual;

	for (i = 1; i < length; i++)
	{
		atual = original[i];
		j = i - 1;

		while ((j >= 0) && (atual < original[j]))
		{
			original[j + 1] = original[j];
            j = j - 1;
		}

		original[j + 1] = atual;
	}
}

int main(int argc, char const *argv[]) {

    int size;
    printf("Tamanho:\n");
    scanf("%d", &size);

    int numbers[size];

    fillRandom(numbers, size);

    printNumbers(numbers, size);

    insertionSort(numbers, size);

    printNumbers(numbers, size);

    return 0;
}
