/*

Escreva um programa em C que ordene uma matriz bidimensional (uma matriz de inteiros, por exemplo)
usando o algoritmo de quicksort

*/

//  Lucas Gabriel Pereira de Menezes UC22101832

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void quick_sort(int* a, int left, int right);

int main(){

    int i, j;
    int matriz[MAX][MAX] = {{1, 3, 2, 5, 4},
                            {5, 4, 3, 2, 1},
                            {2, 4, 1, 3, 5},
                            {4, 5, 2, 1, 3},
                            {3, 1, 5, 4, 2}};


    for (i = 0; i < MAX; i++) {
        quick_sort(matriz[i], 0, MAX - 1);
    }

    printf("\nMatriz Ordenada:\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }


    return 0;
}

void quick_sort(int* a, int left, int right){
    
    int i, j, x ,y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j){
        while(a[i] < x && i < right){
            i++;
        }
        while(a[j] > x && j > left){
            j--;
        }
        if(i <= j){
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left){
        quick_sort(a, left, j);
    }

    if(i < right) {
        quick_sort(a, i, right);
    }

}
