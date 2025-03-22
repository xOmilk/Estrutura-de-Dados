#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Para usar a função "strcspn" para remover o '\n'

#define MAX_PACIENTES 3

typedef struct {
    char nome[100];
    int idade;
    float valorBase;
    float indenizacaoReajustada;
} Paciente;

float calcularReajuste(float valorBase, int idade) {
    if (idade <= 12) {
        return valorBase * 1.30;  // 30% de aumento
    } else if (idade >= 13 && idade <= 49) {
        return valorBase * 1.10;  // 10% de aumento
    } else if (idade >= 50 && idade <= 65) {
        return valorBase * 1.15;  // 15% de aumento
    } else {
        return valorBase * 1.35;  // 35% de aumento
    }
}

int main() {
    Paciente pacientes[MAX_PACIENTES];  
    int numPacientes = 0;  

    char continuar;
    
    do {
        printf("Digite o nome completo do paciente: ");
        fgets(pacientes[numPacientes].nome, sizeof(pacientes[numPacientes].nome), stdin);
        
        // Remover o caractere de nova linha no final do nome, caso exista
        pacientes[numPacientes].nome[strcspn(pacientes[numPacientes].nome, "\n")] = 0;

        printf("Digite a idade do paciente: ");
        scanf("%d", &pacientes[numPacientes].idade);

        printf("Digite o valor base da indenização: ");
        scanf("%f", &pacientes[numPacientes].valorBase);

        pacientes[numPacientes].indenizacaoReajustada = calcularReajuste(pacientes[numPacientes].valorBase, pacientes[numPacientes].idade);

        numPacientes++;

        printf("Deseja cadastrar outro paciente? (s/n): ");
        getchar();  // Limpar o buffer após o scanf
        scanf("%c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    // Exibindo os resultados
    printf("\nRelatório de Indenizações Reajustadas:\n");
    printf("Nome do paciente        | Idade | Indenização Reajustada\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < numPacientes; i++) {
        printf("%-23s | %-5d | %.2f\n", pacientes[i].nome, pacientes[i].idade, pacientes[i].indenizacaoReajustada);
    }

    return 0;
}
