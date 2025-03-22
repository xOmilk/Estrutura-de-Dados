#include <stdio.h>


void trocarElementos(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}





int dividir(int vetor[], int esquerda, int direita)
{
    int pivot=vetor[direita];//ultimo elemento como pivot
    int i= esquerda-1;//menor elemento

    for(int j=esquerda;j<direita;j++){

        if(vetor[j]<=pivot){//se elemento atual for menor ou igual ao pivot

            i++;
            trocarElementos(&vetor[i],&vetor[j]);
        }
        

    }

    trocarElementos(&vetor[i + 1], &vetor[direita]);//coloca o pivot na posicao correta
    return i+1;//retorna o valor do pivot


}

void quickSort(int vetor[], int esquerda, int direita)
{

    if (esquerda < direita)
    {

        int pivot = dividir(vetor, esquerda, direita); // divide o vetor

        quickSort(vetor, esquerda, pivot - 1); // ordenando o lado esquerdo
        quickSort(vetor, pivot + 1, direita);  // ordenando o lado direito
    }
}


int main() {
    int array[] = {8, 6, 3, 1, 2, 1};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    quickSort(array, 0, n - 1);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}