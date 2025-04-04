/*Implemente uma função que elimine os elementos menores ou igual a
zero de vetores lidos. Essa função deve apagar todos os elementos
menores ou iguais a zero de um vetor passado como parâmetro da
função.*/

#include <stdio.h>

#define TAM 10


int eliminarElementosNegativosOuZero(int vetor[], int tamanho) {
    int j = 0; 
    
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] > 0) {
            vetor[j] = vetor[i]; 
            j++;
        }
    }
    
    return j; 
}

int main() {

    int vet[TAM];

    for (int i = 0; i < TAM; i++) {
        printf("Insira o [%d] numero: ", i + 1);
        scanf("%d", &vet[i]);
    }

    int tamanhoFinal= eliminarElementosNegativosOuZero(vet, TAM);

    for(int i=0;i<tamanhoFinal;i++) printf("%d ", vet[i]);
}
