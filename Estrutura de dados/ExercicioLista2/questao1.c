#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int cont;
    struct no *ant;
    struct no *prox;
} Lista;

Lista *inserirNoFinal(Lista *topo, int valor) {
    Lista *aux = topo, *novo = malloc(sizeof(Lista));
    if (!novo) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novo->cont = valor;
    novo->prox = NULL;

    if (topo == NULL) {
        novo->ant = NULL;
        return novo;
    }

    while (aux->prox != NULL)
        aux = aux->prox; // percorre toda a lista

    // Chegou no final
    aux->prox = novo;
    novo->ant = aux;

    return topo;
}

void imprimirLista(Lista *topo) {
    if (topo == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Lista *aux = topo;
    printf("Lista:\n");
    while (aux != NULL) {
        printf("%d ", aux->cont);
        aux = aux->prox;
    }
    printf("\n---------------\n");
}

void selectionSortListas(Lista *topo) {
    if (!topo) return;

    Lista *i, *j, *min;
    int aux;

    for (i = topo; i != NULL; i = i->prox) {
        min = i;
        for (j = i->prox; j != NULL; j = j->prox) {
            if (j->cont < min->cont) {
                min = j;
            }
        }
        if (min != i) {
            aux = i->cont;
            i->cont = min->cont;
            min->cont = aux;
        }
    }
}

int main() {
    Lista *topo = NULL;
    int resp, valor;

    do {
        printf("Informe um valor: ");
        scanf("%d", &valor);
        topo = inserirNoFinal(topo, valor);

        printf("Deseja continuar inserindo valores? [0] - Sair | [1] - Continuar\nResposta: ");
        scanf("%d", &resp);
        printf("\n");
    } while (resp != 0);

    do {
        printf("\nMENU:\n");
        printf("[1] - Ordenar a lista\n");
        printf("[2] - Imprimir a lista\n");
        printf("[3] - Sair do programa\n");
        printf("Resposta: ");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                selectionSortListas(topo);
                printf("Lista ordenada!\n");
                imprimirLista(topo);
                break;
            case 2:
                imprimirLista(topo);
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (resp != 3);

    return 0;
}
