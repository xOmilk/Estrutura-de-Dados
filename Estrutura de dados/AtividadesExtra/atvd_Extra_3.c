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

int valorArrumado(int vetor[], int r)
{
    // int index = p;

    for (int j = 1; j < r; j++)
    {
        int isArrumado = 1;
        for (int h = (j - 1); h >= 0; h--)
        {                             // ELEMENTOS A ESQUERDA
            if (vetor[h] >= vetor[j]) // se for maior ou igual
            {
                isArrumado = 0;
            }
        }

        for (int l = (j + 1); l <= r; l++)
        {                             // ELEMENTOS A DIREITA
            if (vetor[l] <= vetor[j]) // se for menor ou igual
            {
                isArrumado = 0;
            }
        }

        if (isArrumado)
        {
            printf("\nO VETOR EH ARRUMADO na posicao [%d], que possui valor: %d", j, vetor[j]);
            return vetor[j];
        }
    }

    return -1;
}

void imprimirVetor(int vetor[], int r)
{
    for (int i = 0; i < r; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main()
{
    // int vetor[] = {5, 2, 3, 6, 9, 8};
    int tamanhoVetor;

    printf("Defina o tamanho do vetor que voce deseja\nTamanho escolhido: ");
    scanf("%d", &tamanhoVetor);

    int vet[tamanhoVetor];
    printf("Informe os valores para preencher o vetor\n------------\n");
    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("vetor [%d]: ", i);
        scanf("%d", &vet[i]);
    }
    printf("------------");

    printf("\nVerificacao se o seu vetor eh arrumado...\n\nVetor: ");
    imprimirVetor(vet, tamanhoVetor);
    int valorVetorArrumado = valorArrumado(vet, tamanhoVetor - 1);
    if (valorVetorArrumado == -1)
    {
        printf("O vetor informado\nNAO EH UM VETOR ARRUMADO");
        if (tamanhoVetor <= 2)
        {
            printf("\nNao pode ser considerado um vetor arrumado pois viola a condicao de:\n\n\t\tTer ao menos um elemento menor a esquerda de J e um elemento maior a direita de J\n");
        }
    }

    return 1;
}