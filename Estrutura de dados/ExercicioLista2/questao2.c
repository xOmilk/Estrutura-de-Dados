/*
Faça um algoritmo que implemente uma função que leia uma sequência
de NOMES informados pelo usuário, salve-os numa lista simples-
mente encadeada circular, ordene-os usando um dos algoritmos de
ordenação visto em sala e mostre-os em ordem decrescente.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

typedef struct no
{
    char cont[50];
    struct no *prox;
} Lista;

void selectionSortListas(Lista *topo)
{
    if (!topo)
        return;

    Lista *i, *j, *min;
    char aux[50];

    for (i = topo; i != NULL; i = i->prox)
    {
        min = i;
        for (j = i->prox; j != NULL; j = j->prox)
        {
            if (strcmp(j->cont,min->cont)>1)//str1 é maior que str2
            {
                min = j;
            }
        }
        if (min != i)
        {

            strcpy();
            aux = i->cont;
            i->cont = min->cont;
            min->cont = aux;
        }
    }
}