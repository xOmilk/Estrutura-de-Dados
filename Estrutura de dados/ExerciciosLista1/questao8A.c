#include <stdio.h>

void calcularFatorialIterativo(int n) {
    if (n < 0) {
        printf("Fatorial não é definido para números negativos.\n");
        return;
    }

    long long fatorial = 1;
    printf("%d! = ", n);

    for (int i = n; i > 0; i--) {
        fatorial *= i;
        printf("%d", i);
        if (i > 1) {
            printf("*");
        }
    }

    printf(" = %lld\n", fatorial);
}

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    calcularFatorialIterativo(numero);

    return 0;
}
