#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int value;
    struct node *next;

}Node;

Node *adicionarNoFinal(Node *topo, int valor);

void main(){
    
}









void inserirInicio (Node **lista, int value){
Node *novo=malloc(sizeof(Node));

    if(novo){
        novo->value= value;
        novo->next= *lista;
        *lista=novo;

    }else printf("Não foi possivel alocar memoria");

}

Node *adicionarNoFinal(Node *topo, int valor)
{
    Node *nova;
    nova = malloc(sizeof(Node));
    nova->value = valor;
    nova->next = NULL;

    if (topo == NULL)//se estiver vazia
    {
        topo = nova;
    }
    else
    {
        Node *aux = topo;

        while (aux->next != NULL)
            aux = aux->next;

        aux->next = nova;
    }

    return topo;
}


Node adicionarNoMeio(){
    
}

