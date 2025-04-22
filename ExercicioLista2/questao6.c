/*

Implemente um sistema de biblioteca usando fila
Cada livro deve ser representado por um Struct com (Nome do
livro, disponibilidade, fila de espera)
Ao requisitar um livro, a pessoa entra na fila de espera se o livro
não estiver disponível
Quando um livro fica disponível, o primeiro da fila de espera do
livro deve receber o livro
Implemente as demais funcionalidades (cadastra livro, solicita livro,
etc ) que julgar necessárias

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100

typedef struct Pessoa
{
    char nome[MAX_NOME];
    struct Pessoa *prox;
} Pessoa;

typedef struct Livro
{
    char nome[MAX_NOME];
    int disponivel; // 1 = disponivel, 0 = emprestado
    Pessoa *filaEspera;
    struct Livro *prox;
} Livro;

Livro *criarLivro(const char *nome)
{
    Livro *novo = (Livro *)malloc(sizeof(Livro));
    strcpy(novo->nome, nome);
    novo->disponivel = 1;
    novo->filaEspera = NULL;
    novo->prox = NULL;
    return novo;
}

void cadastrarLivro(Livro **lista, const char *nome)
{
    Livro *novo = criarLivro(nome);
    novo->prox = *lista;
    *lista = novo;
    printf("Livro '%s' cadastrado com sucesso!\n", nome);
}

Livro *buscarLivro(Livro *lista, const char *nome)
{
    while (lista != NULL)
    {
        if (strcmp(lista->nome, nome) == 0)
            return lista;
        lista = lista->prox;
    }
    return NULL;
}

void entrarFila(Pessoa **fila, const char *nome)
{
    Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (*fila == NULL)
    {
        *fila = novo;
    }
    else
    {
        Pessoa *atual = *fila;
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = novo;
    }
}

Pessoa *sairFila(Pessoa **fila)
{
    if (*fila == NULL)
        return NULL;
    Pessoa *primeira = *fila;
    *fila = primeira->prox;
    return primeira;
}

void solicitarLivro(Livro *lista, const char *nomeLivro, const char *nomePessoa)
{
    Livro *livro = buscarLivro(lista, nomeLivro);
    if (!livro)
    {
        printf("Livro nao encontrado.\n");
        return;
    }

    if (livro->disponivel)
    {
        livro->disponivel = 0;
        printf("%s pegou o livro '%s'.\n", nomePessoa, nomeLivro);
    }
    else
    {
        entrarFila(&(livro->filaEspera), nomePessoa);
        printf("Livro indisponivel. %s entrou na fila de espera.\n", nomePessoa);
    }
}

void devolverLivro(Livro *lista, const char *nomeLivro)
{
    Livro *livro = buscarLivro(lista, nomeLivro);
    if (!livro)
    {
        printf("Livro nao encontrado.\n");
        return;
    }

    if (livro->filaEspera != NULL)
    {
        Pessoa *proximo = sairFila(&(livro->filaEspera));
        printf("Livro '%s' entregue para %s (proximo da fila).\n", nomeLivro, proximo->nome);
        free(proximo);
    }
    else
    {
        livro->disponivel = 1;
        printf("Livro '%s' devolvido e agora esta disponivel.\n", nomeLivro);
    }
}

void listarLivros(Livro *lista)
{
    if (!lista)
    {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    while (lista != NULL)
    {
        printf("Livro: %s | Disponivel: %s\n", lista->nome, lista->disponivel ? "Sim" : "Nao");
        printf("Fila de espera: ");
        if (lista->filaEspera == NULL)
        {
            printf("Nenhuma\n");
        }
        else
        {
            Pessoa *p = lista->filaEspera;
            while (p != NULL)
            {
                printf("%s ", p->nome);
                p = p->prox;
            }
            printf("\n");
        }
        printf("-----------------------------\n");
        lista = lista->prox;
    }
}

void liberarMemoria(Livro *lista)
{
    while (lista)
    {
        Livro *tempLivro = lista;
        lista = lista->prox;

        Pessoa *fila = tempLivro->filaEspera;
        while (fila)
        {
            Pessoa *tempPessoa = fila;
            fila = fila->prox;
            free(tempPessoa);
        }

        free(tempLivro);
    }
}

int main()
{
    Livro *biblioteca = NULL;
    int opcao;
    char nomeLivro[MAX_NOME];
    char nomePessoa[MAX_NOME];

    do
    {
        printf("\n=== MENU ===\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Solicitar Livro\n");
        printf("3. Devolver Livro\n");
        printf("4. Listar Livros\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Nome do livro: ");
            fgets(nomeLivro, MAX_NOME, stdin);
            nomeLivro[strcspn(nomeLivro, "\n")] = 0;
            cadastrarLivro(&biblioteca, nomeLivro);
            break;

        case 2:
            printf("Nome do livro: ");
            fgets(nomeLivro, MAX_NOME, stdin);
            nomeLivro[strcspn(nomeLivro, "\n")] = 0;
            printf("Nome da pessoa: ");
            fgets(nomePessoa, MAX_NOME, stdin);
            nomePessoa[strcspn(nomePessoa, "\n")] = 0;
            solicitarLivro(biblioteca, nomeLivro, nomePessoa);
            break;

        case 3:
            printf("Nome do livro a devolver: ");
            fgets(nomeLivro, MAX_NOME, stdin);
            nomeLivro[strcspn(nomeLivro, "\n")] = 0;
            devolverLivro(biblioteca, nomeLivro);
            break;

        case 4:
            listarLivros(biblioteca);
            break;

        case 5:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida.\n");
        }

    } while (opcao != 5);

    liberarMemoria(biblioteca);
    return 0;
}
