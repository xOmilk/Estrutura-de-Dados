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
#include <stdbool.h>
typedef struct no
{
    int inteiroX;
    struct no *prox;
    struct no *ant;
} celula;

celula *buscarOuInserir(int inteiroX, celula *point)
{
    bool achou = false;
    int posicao = 0;

    if (point == NULL || (*point == NULL))
    {
        printf("O ponteiro está vazio ou possui valor vazio");
        return NULL;
    }
    // NÃO ESTA VAZIO
    else
    {
        celula *aux;
        for (aux = point; aux != NULL; aux->prox == aux)
        {
            // Buscar o valor dentro da lista
            if (inteiroX == aux->inteiroX)
            {
                printf("O valor '%d' foi encontrado dentro da lista na posição %d.", inteiroX, posicao);
                achou = true;
            }
            posicao++;
        }

        // SE NÃO ENCONTRAR X -> INSERIR NA ULTIMA POSICAO
        // AUX JA ESTÁ APONTANDO PRA NULL
        if (!achou)
        {
            celula *novo = (celula *)malloc(sizeof(celula));
            novo->inteiroX = inteiroX;

            // Atualizando os ponteiros
            novo->prox = NULL;
            novo->ant = aux;
            aux->prox = novo;
        }
    }
}

int main()
{

    celula *lista;
    int respo;
    do
    {

        
        printf("Deseja continuar inserindo valores?");
        scanf("%d", &respo);
    } while (respo != 0);
}
