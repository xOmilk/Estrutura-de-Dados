#include <stdio.h>

typedef struct node
{

    int conteudo;
    struct node *prox;
} node;

node *adicionar(node *topo, int valor)
{
    node *nova;
    nova = malloc(sizeof(node));
    nova->conteudo = valor;
    nova->prox = NULL;

    if (topo == NULL)//se estiver vazia
    {
        topo = nova;
    }
    else
    {
        node *aux = topo;

        while (aux->prox != NULL)
            aux = aux->prox;

        aux->prox = nova;
    }

    return topo;
}

node *procurar(node *topo, int valor)
{
    node *aux = topo;

    do
    {
        if (aux->conteudo == valor)
        {
            return aux;
        }

        aux = aux->prox;
    } while (aux != NULL);

    return NULL;
}

void main(){
    node *lista = NULL;

    int numBusca,numeroAdicionar;

    for(int i=0;i<10;i++){
        printf("Digite o [%d] numero a ser adicionado na sua lista: ", i+1);
        scanf("%d", &numeroAdicionar);

        lista = adicionar(lista, numeroAdicionar);


    }

    printf("Digite o numero que deseja buscar na lista: ");
    scanf("%d", &numBusca);

    node *achou = procurar(lista, numBusca);



    if(achou!=NULL) printf("Elemento encontrado, o numero que voce decidiu buscar eh: %d", achou->conteudo);
    else printf("O elemento nao faz parte da lista");

}
