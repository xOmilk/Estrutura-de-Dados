#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Cliente {
    char nome[100];
    char rg[15];
    char cpf[15];
    char telefone[15];
    struct Cliente *prox;
} Cliente;


Cliente* criarCliente(char nome[], char rg[], char cpf[], char telefone[]) {
    Cliente *novo = (Cliente*) malloc(sizeof(Cliente));

    strcpy(novo->nome, nome);
    strcpy(novo->rg, rg);
    strcpy(novo->cpf, cpf);
    strcpy(novo->telefone, telefone);
    novo->prox = NULL;

    return novo;
}


Cliente* adicionarCliente(Cliente *topo, char nome[], char rg[], char cpf[], char telefone[]) {
    Cliente *novo = criarCliente(nome, rg, cpf, telefone);

    if (topo == NULL) {
        return novo;
    } else {
        Cliente *aux = topo;
        while (aux->prox != NULL) {
            aux = aux->prox; 
        }
        aux->prox = novo;
        return topo;
    }
}

void exibirClientes(Cliente *topo) {
    if (topo == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("\n--- Dados dos Clientes Cadastrados ---\n");
    Cliente *aux = topo;
    while (aux != NULL) {
        printf("Nome: %s\n", aux->nome);
        printf("RG: %s\n", aux->rg);
        printf("CPF: %s\n", aux->cpf);
        printf("Telefone: %s\n\n", aux->telefone);
        aux = aux->prox;
    }
}

int main() {
    Cliente *listaClientes = NULL;
    char nome[100], rg[15], cpf[15], telefone[15];
    char opcao;

    do {
        printf("Digite os dados do cliente:\n");

        printf("Nome completo: ");
        fflush(stdin); 
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        printf("RG: ");
        scanf("%s", rg);

        printf("CPF: ");
        scanf("%s", cpf);

        printf("Telefone: ");
        scanf("%s", telefone);

        listaClientes = adicionarCliente(listaClientes, nome, rg, cpf, telefone);

        printf("\nDeseja cadastrar outro cliente? (s/n): ");
        scanf(" %c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    exibirClientes(listaClientes);

    return 0;
}
