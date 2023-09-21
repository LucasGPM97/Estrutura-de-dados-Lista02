/*

Escreva uma função em C que realize uma busca sequencial em uma matriz bidimensional de inteiros para
encontrar um valor específico fornecido pelo usuário. A função deve retornar a posição da primeira ocorrência do valor
ou informar que o valor não foi encontrado.

*/


//  Lucas Gabriel Pereira de Menezes UC22101832

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 5

int main(){
    int matriz[ROWS][COLS];
    int i, j, n;
    
    srand(time(NULL));
    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matriz[i][j] = rand() % 1001;
        }
    }
    
    printf("Matriz gerada:\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\nQual valor deseja procurar? ");
    scanf("%d", &n);

    int encontrado = 0;

     for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (matriz[i][j] == n) {
                printf("%d ocorre na posicao (%d, %d) da matriz.\n", n, i, j);
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("%d Nao foi encontrado na matriz.\n", n);
    }

    return 0;
}