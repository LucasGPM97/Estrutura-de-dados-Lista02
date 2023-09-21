/*

Implemente uma versão do algoritmo de ordenação por inserção que ordene em ordem decrescente em
vez de crescente.

*/

//  Lucas Gabriel Pereira de Menezes UC22101832


#include <stdio.h>
#define MAX 5

void insertion_sort(int* a, int size);

int main(){

    int vetor[MAX] = {1, 3, 2, 5, 4};
    int i=0;
    insertion_sort(vetor, MAX);

    for (i = 0; i < MAX; i++)
    {
        printf("%d\t", vetor[i]);
    }
    

    return 0;
}

void insertion_sort(int* a, int size){
    int i, j , aux;

    for(i=1;i<size;i++){
        aux = a[i];
        for(j=i-1; j>= 0 && aux > a[j]; j--){
            a[j+1] = a[j];
        }
        a[j+1] = aux;
    }
}
