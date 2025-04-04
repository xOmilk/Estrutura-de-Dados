#include <stdio.h>

typedef struct lista
{
    int conteudo;
    struct lista *prox;
}lista;

struct lista *procurarValor(struct lista *pLista, int valor)
{
    while(pLista!=NULL){
        if(pLista->conteudo==valor){
            return pLista;
        }
        else{
            pLista=pLista->prox;
        }

    }

    return NULL;

}

void main(){

    struct lista m1,m2,m3;

    struct lista *gancho=&m1, *resultado;


    m1.conteudo=5;
    m2.conteudo=10;
    m3.conteudo=15;

    m1.prox=&m2;
    m2.prox=&m3;
    m3.prox=NULL;

    int valor;
    printf("Digite o valor da pesquisa");
    scanf("%d", &valor);

    resultado= procurarValor(gancho, valor);

    if(resultado==NULL){
        printf("Valor não encontrado");
    }else{
        printf("Valor %d encontrado", resultado->conteudo);
    }





}
