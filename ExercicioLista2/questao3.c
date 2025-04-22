
/*

Faça um algoritmo que implemente a função
celula *buscarOuInserir(int x, celula *point),
onde x é um inteiro e *point é um ponteiro para uma lista de inteiros.
Esta função deverá buscar o inteiro x na lista de inteiros cujo topo é
apontado por *point. Se encontrar x, deverá retornar um ponteiro
para o elemento que contém x, se não encontrar x, deverá inserir x na
última posição da lista e deverá retornar um ponteiro para o elemento
inserido.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no *prox;
} celula;

void imprimir(celula *lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia\n");
        return;
    }

    for (celula *aux = lista; aux != NULL; aux = aux->prox)
    {
        printf(" %d ->", aux->conteudo);
    }

    printf("\n");
}

celula *buscarOuInserir(int inteiroX, celula *point)
{
    celula *atual = point;
    celula *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->conteudo == inteiroX)
        {
            printf("O valor '%d' foi encontrado na lista.\n", inteiroX);
            return atual;
        }
        anterior = atual;
        atual = atual->prox;
    }

    // não encontrou, inserir no final
    celula *novo = (celula *)malloc(sizeof(celula));
    novo->conteudo = inteiroX;
    novo->prox = NULL;

    if (anterior == NULL)
    {
        printf("Lista vazia. Inserindo o valor %d...\n", inteiroX);
        return novo;
    }
    else
    {
        // Inserindo no final da lista
        anterior->prox = novo;
        printf("Valor %d inserido no final da lista.\n", inteiroX);
        return novo;
    }
}

int main()
{
    celula *lista = NULL;
    int respo;
    int conteudo;

    printf("\n###\tLista\t###\n\n");
    do
    {
        printf("\nMenu:");
        printf("\n[0] - Sair");
        printf("\n[1] - Inserir/Buscar valor");
        printf("\n[2] - Imprimir lista");
        printf("\nO que deseja fazer?\nDecisao: ");
        scanf("%d", &respo);

        switch (respo)
        {
        case 1:
            printf("\nInsira um valor: ");
            scanf("%d", &conteudo);

            if (lista == NULL)
            {
                lista = buscarOuInserir(conteudo, lista);
            }
            else
            {
                buscarOuInserir(conteudo, lista);
            }
            break;
        case 2:
            imprimir(lista);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (respo != 0);

    return 0;
}