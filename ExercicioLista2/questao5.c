/*
Faça um algoritmo que inverta uma fila F1, criando uma nova fila F2.
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int cont;
    struct no *prox;
} Fila;

Fila *inserirFila(Fila *topo, int elemento)
{
    Fila *novo, *aux;
    novo = (Fila *)malloc(sizeof(Fila));
    novo->cont = elemento;
    novo->prox = NULL;

    if (topo == NULL)
    {
        topo = novo;
    }
    else
    {
        for (aux = topo; aux->prox != NULL; aux = aux->prox)
            ;
        aux->prox = novo;
    }
    return topo;
}

Fila *inverterFila(Fila *topo)
{
    Fila *f2 = NULL;
    Fila *atual = topo;
    Fila *novo;

    while (atual != NULL)
    {
        novo = (Fila *)malloc(sizeof(Fila));
        novo->cont = atual->cont;
        novo->prox = f2;
        f2 = novo;

        atual = atual->prox;
    }

    return f2;
}

void imprimirFila(Fila *topo)
{
    Fila *aux;
    int cont;

    for (cont = 1, aux = topo; aux != NULL; aux = aux->prox, cont++)
        printf("%do elemento da fila: %d\n", cont, aux->cont);
}

int main()
{
    Fila *topo = NULL;
    int respo = 1, contador = 0;
    printf("Insercao de valores da Fila original");
    do
    {
        printf("\nDigite o valor a ser inserido na posicao [%d]: ", contador);
        int valor;
        scanf("%d", &valor);
        topo = inserirFila(topo, valor);

        printf("\nDeseja continuar o processo?\t\t(0) - Sair\nResposta: ");
        scanf("%d", &respo);
        contador++;

    } while (respo != 0);

    printf("\n\nImpressao da fila original:\n");
    imprimirFila(topo);

    printf("\n\nInversao da fila original:\n");
    Fila *f2 = NULL;
    f2 = inverterFila(topo);

    printf("\n\nImpressao da fila EM SUA FORMA INVERTIDA:\n");
    imprimirFila(f2);
    return 1;
}
