#include <stdio.h>
#include <math.h>


float calcularNorma(int vetor[], int tamanho) {
    float soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i] * vetor[i]; // soma dos quadrados dos elementos
    }

    return sqrt(soma); 
}


void calcularVetorSoma(int vetor1[], int vetor2[], int vetor3[], int vetorSoma[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetorSoma[i] = vetor1[i] + vetor2[i] + vetor3[i];
    }
}

int main() {
    int N;


    printf("Digite o tamanho dos vetores (N): ");
    scanf("%d", &N);

    int vetor1[N], vetor2[N], vetor3[N], vetorSoma[N];


    printf("\nDigite os elementos do vetor 1:\n");
    for (int i = 0; i < N; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor1[i]);
    }

    printf("\nDigite os elementos do vetor 2:\n");
    for (int i = 0; i < N; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor2[i]);
    }

    printf("\nDigite os elementos do vetor 3:\n");
    for (int i = 0; i < N; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor3[i]);
    }


    float norma1 = calcularNorma(vetor1, N);
    float norma2 = calcularNorma(vetor2, N);
    float norma3 = calcularNorma(vetor3, N);


    float maiorNorma = norma1;
    int maiorVetor = 1;

    if (norma2 > maiorNorma) {
        maiorNorma = norma2;
        maiorVetor = 2;
    }

    if (norma3 > maiorNorma) {
        maiorNorma = norma3;
        maiorVetor = 3;
    }


    calcularVetorSoma(vetor1, vetor2, vetor3, vetorSoma, N);


    printf("\nResultados:\n");
    printf("Norma do vetor 1: %.2f\n", norma1);
    printf("Norma do vetor 2: %.2f\n", norma2);
    printf("Norma do vetor 3: %.2f\n", norma3);
    printf("O vetor com a maior norma é o vetor %d (Norma = %.2f)\n", maiorVetor, maiorNorma);

    printf("\nVetor soma:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetorSoma[i]);
    }
    printf("\n");

    return 0;
}
