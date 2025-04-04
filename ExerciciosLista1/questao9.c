#include <stdio.h>

int fibonacci(int num);


int main() {
    int num;

    printf("Digite um numero para calcular a sequencia de fibonnaci: ");
    scanf("%d", &num);

    printf("O fibonacci de %d eh %d\n", num, fibonacci(num));

    return 0;
}

int fibonacci(int num) {
    if (num == 1 || num == 2) return num;

    return fibonacci(num - 1) + fibonacci(num - 2);
}