#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int cont;
    struct no *prox;
} Lista;

Lista *inserirInicioListaCircular(Lista *topo, int valor)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->cont = valor;

    if (topo == NULL)
    { // Lista vazia
        novo->prox = novo;
        topo = novo;
    }
    else
    { // Lista nao esta vazia
        Lista *aux = topo;
        while (aux->prox != topo)
        { // Chegar ate o final
            aux = aux->prox;
        }

        aux->prox = novo;
        novo->prox = topo;
        topo = novo;
    }
}

Lista *inserirFinalListaCircular(Lista *topo, int valor)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));

    novo->cont = valor;

    if (topo == NULL)
    { // Lista vazia
        novo->prox = novo;
        topo = novo;
    }
    else
    {
        Lista *aux = topo;
        while (aux->prox != topo)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = topo;
    }
    return topo;
}

Lista *removerInicioListaCircular(Lista *topo)
{

    if (topo == NULL)
    {
        printf("Lista vazia, nao pode remover! ");
        return NULL;
    }

    if (topo->prox == topo)
    { // se so tiver um elemento
        free(topo);
        topo = NULL;
        return NULL;
    }
    Lista *aux = topo;
    while (aux->prox != topo)
    {
        aux = aux->prox;
    }

    Lista *no = topo; // aponta pra o inicio
    aux->prox = no->prox;
    topo = no->prox;
    free(no);

    return topo;
}

Lista *removerFinalListaCircular(Lista *topo)
{

    if (topo == NULL)
    {
        printf("Lista vazia, nao pode remover! ");
        return NULL;
    }

    if (topo->prox == topo)
    { // se so tiver um elemento
        free(topo);
        topo = NULL;
        return NULL;
    }
    Lista *ant, *aux = topo;

    while (aux->prox != topo)
    { // percorre ate o final marcando o anterior
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = aux->prox;
    free(aux);

    return topo;
}
