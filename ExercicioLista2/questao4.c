/*

Faça um algoritmo que leia duas listas informadas pelo usuário, depois
mostre-as na tela e deixe o usuário escolher um elemento de cada listas
e troque-os. Não pode trocar apenas o conteúdo da célula, deve-se re-
alizar a troca através da manipulação de ponteiros, trocando as células
de posição.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no *prox;
    struct no *ant;
} Lista;

void trocarElementosLista(struct Lista **Lista1, struct Lista **Lista2)
{
}

Lista *inserirNoFinal(struct lista *topo, int valor)
{

    Lista *aux = topo, *novo = malloc(sizeof(Lista));
    novo->conteudo = valor;
    novo->prox = NULL;
    if (topo == NULL)
    {
        topo = novo;
        novo->ant = NULL;
    }
    else
    {
        while (aux->prox != NULL)
            aux = aux->prox; // percorre toda a lista

        // cheguei no final
        aux->prox = novo;
        novo->ant = aux;
    }

    return topo;
}

Lista *coletarDadosLista()
{
    Lista *l1;



    return;
}

void main()
{
    Lista *l1;
    Lista *l2;
}
