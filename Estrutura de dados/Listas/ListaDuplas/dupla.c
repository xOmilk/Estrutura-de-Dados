#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    struct Lista *ant;
    int conteudo;
    struct Lista *prox;

} Lista;

Lista *inserirInicio(struct Lista *topo, int valor)
{
    Lista *novo = malloc(sizeof(Lista));
    novo->ant = NULL;
    novo->prox = topo;
    novo->conteudo = valor;

    if (topo == NULL)
    {
        topo = novo;
        return topo;
    }
    if (topo != NULL)
    {
        topo->ant = novo;
    }
    topo = novo;

    return topo;
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

Lista *removerInicio(struct Lista *topo)
{

    Lista *novo = malloc(sizeof(Lista));

    if (topo == NULL)
    {
        printf("Não é possivel remover um elemento de uma lista vazia");
        return topo;
    }
    novo = topo;
    topo = novo->prox; // topo recebe o proximo elemento de topo

    if (novo->prox != NULL)
    { // não possui apenas um elemento na lista

        novo->prox->ant = NULL;
    }

    free(novo);
    return topo;
}

Lista *removerNoFinal(struct Lista *topo)
{

    if (topo == NULL)
    {
        printf("Não é possivel remover um elemento de uma lista vazia");
        return topo;
    }

    Lista *novo = topo;
    while (novo->prox != NULL)
    {
        novo = novo->prox;
    }

    if (novo->ant == NULL)
    {
        topo = novo->prox;
    }
    else
    {
        novo->ant->prox = NULL; // faz com que ninguem aponte pra o ultimo
    }

    free(novo);
    return topo;
}

Lista *removerEspecifico(struct Lista *topo, int valor)
{

    if (topo == NULL)
    {
        printf("Não é possivel remover um elemento de uma lista vazia");
        return topo;
    }
    Lista *novo = topo;
    while (novo != NULL && novo->conteudo != valor)
        novo = novo->prox;

    if (novo == NULL)
    {
        printf("Não encontrado");
        return topo;
    }
    if (novo->ant == NULL) // removendo o primeiro no da lista
    { 
        topo = novo->prox;
    }
    else //removendo no meio
    {
        novo->ant->prox = novo->prox; // aponta pra NULL
    }

    if (novo->prox != NULL) //caso nao for o ultimo
    {
        novo->prox->ant = novo->ant; // corta as ligações do no
    }
    free(novo);
    return topo;
}

int consultaListaPorElemento(struct Lista *topo, int elementoProcurado)
{

    if (topo == NULL)
        return 0;

    Lista *novo = topo;


    while (novo != NULL && novo->conteudo!=elementoProcurado) //percorre toda a lista
    {
        novo = novo->prox;
    }

    if (novo == NULL)
    {
        printf("Não foi encontrado");
        return 0;
    }
    else
    {//se foi achado
        printf("O valor [%d] foi encontrado na lista", novo->conteudo);
        return 1;
    }
}

void main()
{
    Lista *l1=NULL;
    int resp;

    do
    {
        




        printf("Deseja continuar? aperte 's'\n");
        scanf("%d", &resp);

    } while (resp=='s');
    


}