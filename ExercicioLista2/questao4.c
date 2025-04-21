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
    int conteudo;
    struct no *prox;
    struct no *ant;
} Lista;

void trocarElementosLista(struct Lista **Lista1, int elmtEscolhidoPrimeira, struct Lista **Lista2, int elmtEscolhidoSegunda)
{
    // Codigo para a troca:

    



    // Listas apos a troca
    imprimirLista(Lista1);
    imprimirLista(Lista2);
}

void imprimirLista(struct Lista *topo)
{
    printf("\n\n#### Impressao da lista ####\n\n");
    for (Lista *aux = topo; aux != NULL; aux->prox = aux)
    {
        printf("Posicao [%d], valor: %d\n", contador, aux->conteudo);
    }
    printf("#### Lista finalizada ####\n");
}

int escolherElemento(struct Lista *topo)
{
    int elementoArmazenado;
    int contador = 0;
    bool achou = false;

    imprimirLista(topo);

    printf("Informe o elemento que você deseja armazenar da lista: ");
    scanf("%d", &elementoArmazenado);

    // VERIFICAR SE O ELEMENTO EXISTE DENTRO DA LISTA
    for (Lista *aux = topo; aux != NULL; aux->prox = aux)
    {
        if (elementoArmazenado == aux->conteudo)
        {
            // achou elemento
            achou = true;
            return elementoArmazenado;
        }
    }

    if (!achou)
        return -1;
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
    Lista *nova;
    int posicao = 0;
    int respo = 1;
    printf("\n\n#### Coleta de dados de Lista ####\n\n");

    do
    {
        printf("Digite o valor para a posicao [%d]: ", posicao);
        int conteudo;
        scanf("%d", &conteudo);
        inserirNoFinal(nova, conteudo);

        printf("Deseja continuar inserindo elementos");
        scanf("%d", &respo);

    } while (respo != 0);

    return nova;
}

void main()
{
    printf("Coleta de dados da primeira lista");
    Lista *l1;
    l1 = coletarDadosLista();

    printf("Coleta de dados da primeira lista");
    Lista *l2;
    l2 = coletarDadosLista();

    //Fazer a escolha dos elementos
    int elmtEscolhidoPrimeira = escolherElemento(l1);
    int elmtEscolhidoSegunda = escolherElemento(l2);

    // Verificar se os elementos existem (elmt!= -1)
    if ((elmtEscolhidoPrimeira != -1) && (elmtEscolhidoSegunda != -1))
    {
        printf("Listas antes da troca de elementos\n");
        imprimirLista(l1);
        imprimirLista(l2);

        printf("Efetuando troca de elementos");
        trocarElementosLista(l1, elmtEscolhidoPrimeira, l2, elmtEscolhidoSegunda);
    }
    else
    {
        printf("\nErro: Algum dos elementos escolhidos nao existem\n");
    }
}
