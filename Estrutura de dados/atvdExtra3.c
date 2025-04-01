/*
Um vetor ARRUMADO é um vetor v[p .. r] onde existe ao menos um j
∈ [p, r] tal que v[p..j − 1] ≤ v[j] < v[j + 1..r] (ou seja, existe ao menos
um j pertencente ao vetor v, cujos elementos da esquerda são menores
que j e os elementos da direita são maiores que j). Escreva um
algoritmo, em linguagem C, que decida se v[p..r] está ARRUMADO.
Em caso afirmativo, o seu algoritmo deve devolver o valor de j. OBS.:
Os vetores arrumados NÃO se resumem aos vetores ORDENADOS,
pois eles podem não estar exatamente ordenados!!
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int valorArrumado(int vetor[], int p, int r)
{
    int index=p;

    for(int j=1;j<=r;j++){
        int isArrumado=0;
        for(int h=(j-1);h>=0;h--){//ELEMENTOS A ESQUERDA
            if(vetor[h]>vetor[j]){
                isArrumado=1;
            }
        }

        for(int l=(j+1);l<=r;l++){//ELEMENTOS A DIREITA
            if(vetor[l]<vetor[j]){
                isArrumado=1;
            }
        }

        if(!isArrumado){
            printf("O vetor é arrumado na posição [%d], que possui valor: %d", j, vetor[j]);
            return vetor[j];
        }
    }

    return -1;
}

int main(){
    int vetor[]={5,2,3,6,9,8};
    int p=1;
    int r= TAM;
    int valorVetorArrumado;

    printf("Verificação se o seu vetor é arrumado\n---------------\n");
    valorVetorArrumado=valorArrumado(vetor, p, r);


    printf("\n\nApos a chamada da funcao, valor arrumado: ");


    return 1;
}
