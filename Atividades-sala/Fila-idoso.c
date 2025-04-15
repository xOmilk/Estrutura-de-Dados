/*
Em um banco, há apenas um caixa e todos devem ser atendidos por
ordem de chegada. No entanto, pessoas idosas têm prioridade e passam para
o início da fila. Considerando que, em vários dias, o número de idosos é muito
grande, foram estipuladas as seguintes regras:
1. uma pessoa é atendida na ordem de chegada.
2. no máximo 2 idosos podem passar na frente de uma pessoa que não é
idosa.
Escreva um programa que leia uma sequência de informação da ordem de
chegada e categoria do cliente e imprima a ordem de atendimento (considere
que todos chegaram antes de começar o atendimento, na ordem em que são
apresentados).
Ex. de entrada:
geral, geral, idoso, idoso, idoso, geral, idoso
ou pode ser lido tb: 1,1,2,2,2,1,2 (considerando que 1 é geral e 2 é idoso) Ex.
saída: 3 4 1 2 5 7 6
OBS.: Crie e use as funções enfileirar, desenfileirar, imprimir fila, etc, faça o
algoritmo para funcionar com qualquer entrada fornecida. Pode usar números
no lugar das palavras geral e idoso.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int categoria;
  int ordemChegada;
  int qntdPassou;
  struct no *prox;
}Fila;

Fila *enfileirar (struct no *topo, int categoria, int ordemChegada){
    Fila *novo = (Fila*)malloc(sizeof(Fila));
    novo->categoria = categoria;
    novo->ordemChegada = ordemChegada;
    novo->prox=NULL;

    if(topo==NULL){
        topo=novo;
        return;
    }


}
Fila *desenfileirar(struct no *topo){

}

void imprimir(Fila *topo){
    Fila *aux=NULL;
    for(aux=topo; aux->prox==NULL;aux=aux->prox){
        printf("Categoria: %d\nOrdem de chegada: %d\nOrdem de atendimeno: %d");
    }

}




int main (){
  

}


