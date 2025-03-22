#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int conteudo;
    struct Lista* proximo;
} Lista;


void removerDuplicatas(Lista* topo) {
    Lista* atual = topo;

    while (atual != NULL) {
        Lista* referencia = atual;
        Lista* temp = atual->proximo;

        while (temp != NULL) {
            if (temp->conteudo == atual->conteudo) { // encontrou valor duplicado

                referencia->proximo = temp->proximo; // pula o duplicado
                free(temp);
                temp = referencia->proximo;

            } else { // segue normal
                referencia = temp;
                temp = temp->proximo;
            }
        }

        atual = atual->proximo;
    }
}


void inserirNoFinal(Lista** topo, int valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->conteudo = valor;
    novo->proximo = NULL;

    if (*topo == NULL) {
        *topo = novo;
        return;
    }

    Lista* temp = *topo;
    while (temp->proximo != NULL) {
        temp = temp->proximo;
    }
    temp->proximo = novo;
}


void imprimirLista(Lista* topo) {
    while (topo != NULL) {
        printf("%d -> ", topo->conteudo);
        topo = topo->proximo;
    }
    printf("NULL\n");
}


int main() {
    Lista* topo = NULL;
    
    //  1 → 3 → 2 → 3 → 4 → 2 → 5
    inserirNoFinal(&topo, 1);
    inserirNoFinal(&topo, 3);
    inserirNoFinal(&topo, 2);
    inserirNoFinal(&topo, 3);
    inserirNoFinal(&topo, 4);
    inserirNoFinal(&topo, 2);
    inserirNoFinal(&topo, 5);

    printf("Lista antes de remover duplicatas:\n");
    imprimirLista(topo);

    removerDuplicatas(topo);

    printf("Lista após remover duplicatas:\n");
    imprimirLista(topo);

    return 0;
}
