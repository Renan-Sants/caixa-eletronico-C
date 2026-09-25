#include <stdio.h>
#include <stdlib.h>

#define MAX_OPERACOES 100

void pausar(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

void realizarSaque(float *saldo, char extrato[][100], int *quantidadeOperacoes) {
    int valorSaque, valorRestante;
    int notas100, notas50, notas20, notas10, notas5;

    printf("\n========== SAQUE ==========\n");
    printf("Saldo disponivel: R$ %.2f\n", *saldo);
    printf("Digite o valor do saque: R$ ");
    scanf("%d", &valorSaque);

    if (valorSaque <= 0) {
        printf("\n[ERRO] O valor do saque deve ser maior que zero.\n");
        return;
    }

    if (valorSaque % 5 != 0) {
        printf("\n[ERRO] O valor deve ser multiplo de R$ 5.\n");
        return;
    }

    if (valorSaque > *saldo) {
        printf("\n[ERRO] Saldo insuficiente.\n");
        return;
    }

    valorRestante = valorSaque;

    notas100 = valorRestante / 100;
    valorRestante %= 100;

    notas50 = valorRestante / 50;
    valorRestante %= 50;

    notas20 = valorRestante / 20;
    valorRestante %= 20;

    notas10 = valorRestante / 10;
    valorRestante %= 10;

    notas5 = valorRestante / 5;

    *saldo -= valorSaque;

    printf("\n========== SAQUE REALIZADO ==========\n");

    if (notas100 > 0)
        printf("%d nota(s) de R$ 100\n", notas100);
    if (notas50 > 0)
        printf("%d nota(s) de R$ 50\n", notas50);
    if (notas20 > 0)
        printf("%d nota(s) de R$ 20\n", notas20);
    if (notas10 > 0)
        printf("%d nota(s) de R$ 10\n", notas10);
    if (notas5 > 0)
        printf("%d nota(s) de R$ 5\n", notas5);

    printf("-------------------------------------\n");
    printf("Valor retirado: R$ %.2f\n", (float)valorSaque);
    printf("Novo saldo: R$ %.2f\n", *saldo);

    if (*quantidadeOperacoes < MAX_OPERACOES) {
        snprintf(extrato[*quantidadeOperacoes], 100,
                 "SAQUE - R$ %.2f", (float)valorSaque);
        (*quantidadeOperacoes)++;
    }
}

void realizarDeposito(float *saldo, char extrato[][100], int *quantidadeOperacoes) {
    float valorDeposito;

    printf("\n========= DEPOSITO =========\n");
    printf("Digite o valor do deposito: R$ ");
    scanf("%f", &valorDeposito);

    if (valorDeposito <= 0) {
        printf("\n[ERRO] O valor do deposito deve ser maior que zero.\n");
        return;
    }

    *saldo += valorDeposito;

    printf("\n========== DEPOSITO REALIZADO ==========\n");
    printf("Valor depositado: R$ %.2f\n", valorDeposito);
    printf("Novo saldo: R$ %.2f\n", *saldo);

    if (*quantidadeOperacoes < MAX_OPERACOES) {
        snprintf(extrato[*quantidadeOperacoes], 100,
                 "DEPOSITO - R$ %.2f", valorDeposito);
        (*quantidadeOperacoes)++;
    }
}

void mostrarExtrato(char extrato[][100], int quantidadeOperacoes) {
    int i;

    printf("\n============= EXTRATO =============\n");

    if (quantidadeOperacoes == 0) {
        printf("Nenhuma operacao realizada.\n");
    } else {
        for (i = 0; i < quantidadeOperacoes; i++) {
            printf("%d. %s\n", i + 1, extrato[i]);
        }
    }

    printf("====================================\n");
}

int main(void) {
    float saldo = 1500.00;
    char extrato[MAX_OPERACOES][100];
    int quantidadeOperacoes = 0;
    int opcao;

    do {
        system("cls");

        printf("====================================\n");
        printf("          CAIXA ELETRONICO - V2.0\n");
        printf("====================================\n");
        printf("\n");
        printf("1 - Consultar saldo\n");
        printf("2 - Realizar saque\n");
        printf("3 - Realizar deposito\n");
        printf("4 - Ver extrato\n");
        printf("0 - Sair\n");
        printf("\n====================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n========== SALDO ==========\n");
                printf("Saldo disponivel: R$ %.2f\n", saldo);
                printf("============================\n");
                break;

            case 2:
                realizarSaque(&saldo, extrato, &quantidadeOperacoes);
                break;

            case 3:
                realizarDeposito(&saldo, extrato, &quantidadeOperacoes);
                break;

            case 4:
                mostrarExtrato(extrato, quantidadeOperacoes);
                break;

            case 0:
                printf("\n====================================\n");
                printf("Obrigado por utilizar o sistema!\n");
                printf("Sistema encerrado.\n");
                printf("====================================\n");
                break;

            default:
                printf("\n[ERRO] Opcao invalida!\n");
        }

        if (opcao != 0) {
            pausar();
        }

    } while (opcao != 0);

    return 0;
}
