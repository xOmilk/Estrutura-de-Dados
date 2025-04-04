#include <stdio.h>
#define TAM 5

void selectionSort(int v[], int tam){
    int menor, indice, aux;
   
   
    for(int i=0; i<tam;i++){
        menor = v[i];
        indice = i;
       
        for(int j=i;j<tam;j++){
            if(menor>v[j]){
               menor = v[j];
               indice = j;
            }
        }
        aux = v[i];
        v[i] = v[indice];
        v[indice] = aux;
    }
}

void print(int v[], int tam){
    for(int i=0; i<tam; i++)
        printf("%d, ",v[i]);
    printf("\n");    
}


void main(){
    int v[TAM];
    char resp;
   
    do{
        printf("Informe os valores inteiros do vetor: ");
        for(int i=0; i<TAM; i++){
            printf("%dº valor do vetor: ",i);
            scanf("%d%*c",&v[i]);
        }    
       
       
        printf("Vetor Desordenado: \n");
        print(v,TAM);
        selectionSort(v,TAM);
        printf("Vetor Ordenado: \n");
        print(v,TAM);
       
       
        printf("Deseja repetir operação? S-Sim e N-Não\n ");
        scanf("%c",&resp);
    }while((resp=='S')||(resp=='s'));    


}