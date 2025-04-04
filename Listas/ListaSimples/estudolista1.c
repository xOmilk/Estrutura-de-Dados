#include <stdio.h>

typedef struct reg
{
    int conteudo;
    struct lista *prox;
} celula;

int main()
{

    celula m1, m2, m3;
    celula *gancho = &m1;

    m1.conteudo = 10;
    m2.conteudo = 20;
    m3.conteudo = 30;

    m1.prox = &m2;
    m2.prox = &m3;
    m3.prox = NULL;

    while (gancho != NULL)
    {
        printf("%d\n", gancho->conteudo);
        gancho = gancho->prox;
    }

    return 0;
}