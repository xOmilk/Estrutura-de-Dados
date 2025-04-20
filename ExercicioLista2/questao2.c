/*
Faça um algoritmo que implemente uma função que leia uma sequência
de NOMES informados pelo usuário, salve-os numa lista simples-
mente encadeada circular, ordene-os usando um dos algoritmos de
ordenação visto em sala e mostre-os em ordem decrescente.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char nome[50];
    struct no *prox;
} Lista;

// Insere no final da lista circular
void inserir(Lista **topo, char nome[])
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    strcpy(novo->nome, nome);

    if (*topo == NULL)
    {
        novo->prox = novo;
        *topo = novo;
    }
    else
    {
        Lista *aux = *topo;
        while (aux->prox != *topo)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = *topo;
    }
}

// Selection sort EM LISTAS CIRCULAR DECRESCENTE
void selectionSortListas(Lista *topo)
{
    if (!topo || topo->prox == topo)
        return;

    Lista *i = topo;
    do
    {
        Lista *max = i;
        Lista *j = i->prox;

        while (j != topo)
        {
            if (strcmp(j->nome, max->nome) > 0)
            {
                max = j;
            }
            j = j->prox;
        }

        if (max != i)
        {
            char aux[50];
            strcpy(aux, i->nome);
            strcpy(i->nome, max->nome);
            strcpy(max->nome, aux);
        }

        i = i->prox;
    } while (i->prox != topo); // Parar quando chegar no ultimo antes de voltar ao topo
}

void mostrarLista(Lista *topo)
{
    if (!topo)
        return;

    Lista *aux = topo;
    do
    {
        printf("%s\n", aux->nome);
        aux = aux->prox;
    } while (aux != topo);
}

int main()
{
    Lista *lista = NULL;
    char nome[50];
    int resp = 1;
    int contador = 0;
    printf("### INSERCAO DA LISTA ###\n\n");
    do
    {

        printf("Digite o nome [%d]: ", contador + 1);
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = 0; // remover \n
        inserir(&lista, nome);

        printf("Deseja continuar adicionando nomes?\t\t(1) - Sim\t(0) - Sair\nResposta: ");
        scanf("%d", &resp);
        getchar();

        contador++;
    } while (resp != 0);

    printf("\n\nNomes antes da ordenacao:\n");
    mostrarLista(lista);

    selectionSortListas(lista);

    printf("\n\nNomes em ordem decrescente:\n");
    mostrarLista(lista);

    return 0;
}
