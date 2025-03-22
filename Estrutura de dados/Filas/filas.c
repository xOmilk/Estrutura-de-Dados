#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int cont;
    struct no *prox;
} Fila;

Fila *inserirFila(Fila *topo, int valor)
{ // Inserção da fila é sempre no final

    Fila *novo = (Fila *)malloc(sizeof(Fila));
    novo->cont = valor;
    novo->prox = NULL;

    if (topo == NULL)
    {
        topo = novo;
    }
    else
    {
        Fila *aux = topo;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    return topo;
}

Fila *removerFila(Fila *topo)
{ // Remove sempre o inicio
    Fila *aux = topo;
    if (topo == NULL)
    {
        printf("Erro, nao pode remover lista vazia");
        return NULL;
    }
    else
    { // Se a pilha nao estiver vazia

        if (topo->prox == NULL)
        { // Só possui um elemento
            topo = topo->prox;
        }
        else
        { // Possui mais de um elemento
            topo = topo->prox;
            printf("Removendo o elemento %d\n", aux->cont);
            aux->prox = NULL;
            free(aux);
        }
    }

    return topo;
}
