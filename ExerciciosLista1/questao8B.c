#include <stdio.h>


long long calcularFatorialRecursivo(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * calcularFatorialRecursivo(n - 1);
}


void exibirFatorialRecursivo(int n) {
    if (n < 0) {
        printf("Fatorial não é definido para números negativos.\n");
        return;
    }

    printf("%d! = ", n);
    for (int i = n; i > 0; i--) {
        printf("%d", i);
        if (i > 1) {
            printf("*");
        }
    }

    printf(" = %lld\n", calcularFatorialRecursivo(n));
}

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    exibirFatorialRecursivo(numero);

    return 0;
}
