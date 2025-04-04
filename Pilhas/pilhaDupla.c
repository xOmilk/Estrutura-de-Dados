/*
Em pilhas o segue o padrao LIFO, que significa que o primeiro elemento a entrar vai ser o ultimo a sair
E o utlimo elemento a entrar vai ser o primeiro a sair

O novo elemento a ser colocado deve sempre ser atualizado pra ser o topo da pilha

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int cont;
    struct no *prox;
    struct no *ant;
} Pilha;

Pilha *empilhar(Pilha *topo, int valor)
{

    Pilha *novo = malloc(sizeof(Pilha));
    novo->cont = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    if (topo == NULL)
        topo = novo;

    else
    {
        novo->prox = topo;
        topo->ant = novo;
        topo = novo;
    }
    return topo;
}

Pilha *desempilhar(Pilha *topo)
{
    if (topo == NULL)
    {
        printf("A pilha já está vazia\n");
        return NULL;
    }

    Pilha *temp = topo;

    if (topo->prox == NULL)
    { // só um elemento
        topo = NULL;
    }
    else
    {
        topo = topo->prox;
        topo->ant = NULL;
    }

    free(temp);
    return topo;
}

