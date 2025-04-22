/*

Faça um algoritmo que leia duas listas informadas pelo usuário, depois
mostre-as na tela e deixe o usuário escolher um elemento de cada listas
e troque-os. Não pode trocar apenas o conteúdo da célula, deve-se re-
alizar a troca através da manipulação de ponteiros, trocando as células
de posição.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    int cont;
    struct no *prox;
} Lista;

void imprimirLista(Lista *topo)
{
    int contador = 0;
    printf("\n\n#### Impressao da lista ####\n\n");
    for (Lista *aux = topo; aux != NULL; aux = aux->prox)
    {
        printf("Posicao [%d], valor: %d\n", contador, aux->cont);
        contador++;
    }
    printf("\n");
}

Lista *inserirNoFinal(Lista *topo, int valor)
{
    Lista *novo = malloc(sizeof(Lista));
    novo->cont = valor;
    novo->prox = NULL;

    if (topo == NULL)
    {
        return novo;
    }

    Lista *aux = topo;
    while (aux->prox != NULL)
        aux = aux->prox;

    aux->prox = novo;
    return topo;
}

Lista *coletarDadosLista()
{
    Lista *nova = NULL;
    int posicao = 0;
    int respo = 1;

    printf("\n\n#### Coleta de dados da Lista ####\n\n");

    do
    {
        printf("Digite o valor para a posicao [%d]: ", posicao);
        int conteudo;
        scanf("%d", &conteudo);
        nova = inserirNoFinal(nova, conteudo);

        printf("Deseja continuar inserindo elementos?\t\t(0) - Sair\nResposta: ");
        scanf("%d", &respo);
        posicao++;

    } while (respo != 0);

    return nova;
}

// Função para buscar um nó e seu anterior, com base no valor
void buscarNoEAnterior(Lista *inicio, int cont, Lista **no, Lista **anterior)
{
    *no = inicio;
    *anterior = NULL;

    while (*no && (*no)->cont != cont)
    {
        *anterior = *no;
        *no = (*no)->prox;
    }
}

// Troca de nós das listas
void trocarNosSimples(Lista **topo1, Lista *n1, Lista *n1Ant, Lista **topo2, Lista *n2, Lista *n2Ant)
{
    if (!n1 || !n2 || n1 == n2)
        return;

    if (n1Ant)
        n1Ant->prox = n2;
    else
        *topo1 = n2;

    if (n2Ant)
        n2Ant->prox = n1;
    else
        *topo2 = n1;

    Lista *tmp = n1->prox;
    n1->prox = n2->prox;
    n2->prox = tmp;
}

// Realiza a troca
void trocarElementosLista(Lista **Lista1, int elmtEscolhidoPrimeira, Lista **Lista2, int elmtEscolhidoSegunda)
{
    Lista *n1 = NULL, *n1Ant = NULL;
    Lista *n2 = NULL, *n2Ant = NULL;

    buscarNoEAnterior(*Lista1, elmtEscolhidoPrimeira, &n1, &n1Ant);
    buscarNoEAnterior(*Lista2, elmtEscolhidoSegunda, &n2, &n2Ant);

    trocarNosSimples(Lista1, n1, n1Ant, Lista2, n2, n2Ant);
}

int escolherElemento(Lista *topo)
{
    int elementoArmazenado;

    imprimirLista(topo);

    printf("Informe o elemento que você deseja armazenar da lista: ");
    scanf("%d", &elementoArmazenado);

    for (Lista *aux = topo; aux != NULL; aux = aux->prox)
    {
        if (elementoArmazenado == aux->cont)
        {
            return elementoArmazenado;
        }
    }

    return -1;
}

int main()
{
    printf("Coleta de dados da primeira lista");
    Lista *l1 = coletarDadosLista();

    printf("\n\n---Coleta de dados da Segunda lista----");
    Lista *l2 = coletarDadosLista();

    int elmtEscolhidoPrimeira = escolherElemento(l1);
    int elmtEscolhidoSegunda = escolherElemento(l2);

    if ((elmtEscolhidoPrimeira != -1) && (elmtEscolhidoSegunda != -1))
    {
        printf("Listas antes da troca de elementos\n");
        imprimirLista(l1);
        imprimirLista(l2);

        printf("\n\nEfetuando troca de elementos\n");
        trocarElementosLista(&l1, elmtEscolhidoPrimeira, &l2, elmtEscolhidoSegunda);

        printf("-------------Listas apos a troca de elementos-----------------\n\n");
        printf("Lista 1");
        imprimirLista(l1);
        printf("Lista 2");
        imprimirLista(l2);
    }
    else
    {
        printf("\nErro: Algum dos elementos escolhidos nao existem\n");
    }

    return 0;
}