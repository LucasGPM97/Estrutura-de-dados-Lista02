/*

Escreva um programa em C que ordene uma matriz bidimensional (uma matriz de inteiros, por exemplo)
usando o algoritmo de ordenação por inserção.

*/
//  Lucas Gabriel Pereira de Menezes UC22101832

#include <stdio.h>

#define MAX_ROWS 5
#define MAX_COLS 5

void insertion_sort(int* a, int size);

int main() {
    int matriz[MAX_ROWS][MAX_COLS] = {
        {1, 3, 2, 5, 4},
        {5, 4, 3, 2, 1},
        {2, 4, 1, 3, 5},
        {4, 5, 2, 1, 3},
        {3, 1, 5, 4, 2}
    };

    for (int i = 0; i < MAX_ROWS; i++) {
        insertion_sort(matriz[i], MAX_COLS);
    }

    printf("\nMatriz Ordenada:\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void insertion_sort(int* a, int size) {
    int i, j, aux;

    for (i = 1; i < size; i++) {
        aux = a[i];
        for (j = i - 1; j >= 0 && aux < a[j]; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = aux;
    }
}
