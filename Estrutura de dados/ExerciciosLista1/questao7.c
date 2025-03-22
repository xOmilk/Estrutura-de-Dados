#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    int num;
    char conteudo[8]; //tamanho max:carneiro
    struct nodo *prox;
} nodo;



nodo *adicionar(nodo *topo, char signo[], int num) {
    nodo *nova;
    nova = malloc(sizeof(nodo));
    strcpy(nova->conteudo, signo);
    nova->num = num;
    nova->prox = NULL;

    if (topo == NULL) {
        topo = nova;
    } else if (topo->prox == NULL) {
        topo->prox = nova;
    } else {
        nodo *aux = topo;
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = nova;
    }

    return topo;
}

char *procurar(nodo *topo, int num) {
    nodo *aux = topo;
    
    do
    {
        if (num == aux->num) {
            return aux->conteudo;
        }

        aux = aux->prox;
    } while (aux != NULL);
    
} 

void main()
{
    nodo *listaSignos = NULL;

    listaSignos = adicionar(listaSignos, "Macaco", 0);
    listaSignos = adicionar(listaSignos, "Galo", 1);
    listaSignos = adicionar(listaSignos, "Cao", 2);
    listaSignos = adicionar(listaSignos, "Porco", 3);
    listaSignos = adicionar(listaSignos, "Rato", 4);
    listaSignos = adicionar(listaSignos, "Boi", 5);
    listaSignos = adicionar(listaSignos, "Tigre", 6);
    listaSignos = adicionar(listaSignos, "Coelho", 7);
    listaSignos = adicionar(listaSignos, "Dragao", 8);
    listaSignos = adicionar(listaSignos, "Serpente", 9);
    listaSignos = adicionar(listaSignos, "Cavalo", 10);
    listaSignos = adicionar(listaSignos, "Carneiro", 11);

    int ano;
    printf("######## ZODIACO CHINES ######\n\n");
    printf("Diga o ano em que voce nasceu: ");
    scanf("%d", &ano);

    printf("De acordo com o zodiaco chines o seu signo eh: %s", procurar(listaSignos, ano % 12));
}