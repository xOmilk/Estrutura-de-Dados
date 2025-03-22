/*Escreva um algoritmo que receba uma lista de 10 inteiros, salve
em um vetor e mostre toda a lista em na mesma linha.*/
#include <stdio.h>

#define TAM 10

int main(){

    int vet[TAM];

    for(int i=0;i<TAM;i++){
        printf("Informe o [%d] valor a ser armazenado no vetor\n", i+1);
        scanf("%d", &vet[i]);

    }

    for(int i=0;i<TAM;i++){
        if(i==0){
            printf("Impressão dos valores do vetor\n");
        }
        printf("[%d] ", vet[i]);
        

    }
    return 0;
}

