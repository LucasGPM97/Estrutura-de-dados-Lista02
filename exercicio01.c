/*
- Escreva um programa em C que ordena um array de inteiros usando o algoritmo de ordenação por bolha.

*/

//  Lucas Gabriel Pereira de Menezes UC22101832


#include <stdio.h>




int main(){

    int num[]={1,4,2,3,5};
    int i=0,j=0, aux=0;

    for(i=0;i<5;i++){
        for(j=0;j<5-i-1;j++){
            if(num[j]>num[j+1]){
                aux = num[j];
                num[j] = num[j+1];
                num[j+1] = aux;
            }
        }
    }

    for(i=0;i<5;i++){
        printf("%d\t", num[i]);
    }


    return 0;
}