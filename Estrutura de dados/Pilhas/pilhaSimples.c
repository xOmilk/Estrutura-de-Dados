#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int cont;
    struct no *prox;
} Pilha;

Pilha *empilhar(Pilha *topo, int valor)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));

    novo->cont = valor;
    novo->prox = NULL;

    if (novo)
    {

        if (topo == NULL)
        {
            topo = novo;
        }
        else
        {
            novo->prox = topo;
            topo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria");

    return topo;
}

Pilha *desempilhar(Pilha *topo)
{
    Pilha *aux = topo;
    if (aux == NULL)
    {
        printf("A pilha ja esta vazia");
        return NULL;
    }

    if (aux->prox == NULL)
    { // removendo um único elemento existente
        aux = aux->prox;
        topo = aux;
    }
    else
    { // caso nao seja o unico elemento existente
        topo = aux->prox;
        printf("Removendo o conteudo :%d", aux->cont);
        free(aux);
    }
    return topo;
}

void imprimirPilha(Pilha *topo)
{
    Pilha *aux;
    int cont;

    for (cont = 1, aux = topo; aux != NULL; aux = aux->prox, cont++)
        printf("%do Elemento da pilha: %d", cont, aux->cont);
}

