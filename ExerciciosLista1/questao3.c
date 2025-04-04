#include <stdio.h>


float calcularMedia(float numeros[], int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += numeros[i];
    }
    return soma / tamanho;
}


void encontrarMaiorMenor(float numeros[], int tamanho, float *maior, float *menor) {
    *maior = numeros[0];
    *menor = numeros[0];

    for (int i = 1; i < tamanho; i++) {
        if (numeros[i] > *maior) {
            *maior = numeros[i];
        }
        if (numeros[i] < *menor) {
            *menor = numeros[i];
        }
    }
}


void contarPositivosNegativos(float numeros[], int tamanho, int *positivos, int *negativos) {
    *positivos = 0;
    *negativos = 0;

    for (int i = 0; i < tamanho; i++) {
        if (numeros[i] > 0) {
            (*positivos)++;
        } else if (numeros[i] < 0) {
            (*negativos)++;
        }
    }
}

int main() {
    float numeros[10];
    int tamanho = 10;


    printf("Digite 10 números reais:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Número %d: ", i + 1);
        scanf("%f", &numeros[i]);
    }


    float media = calcularMedia(numeros, tamanho);

    float maior, menor;
    encontrarMaiorMenor(numeros, tamanho, &maior, &menor);

    int positivos, negativos;
    contarPositivosNegativos(numeros, tamanho, &positivos, &negativos);

    // Exibindo os resultados
    printf("\nResultados:\n");
    printf("a) Média dos elementos: %.2f\n", media);
    printf("b) Maior elemento: %.2f, Menor elemento: %.2f\n", maior, menor);
    printf("c) Quantidade de positivos: %d, Quantidade de negativos: %d\n", positivos, negativos);

    return 0;
}
