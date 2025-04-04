/*Escreva um algoritmo que receba uma lista de 10 inteiros, solicite um
número qualquer e informar se o número informado está na lista ou
não. Implemente duas versões, uma com vetores, e outra com listas
simplesmente encadeadas.*/

#include <stdio.h>
#include <stdbool.h>

#define TAM 10

bool busca(int vet[], int elementoBuscado){

    for(int i=0;i<TAM;i++){
        
        if(vet[i]==elementoBuscado){
            return true;
            break;
        }
    }
    return false;
}

void main(){

    int vet[TAM];

    for(int i=0;i<TAM;i++){
        printf("Informe o [%d] valor a ser armazenado no vetor: ", i+1);
        scanf("%d", &vet[i]);

    }

    printf("Informe o valor que deseja buscar dentro do vetor: ");
    int buscar;scanf("%d", &buscar);

    bool achou=busca(vet,buscar);
    if(achou==false)printf("O elemento nao está na lista");
    else printf("O elemento faz parte da lista");

}