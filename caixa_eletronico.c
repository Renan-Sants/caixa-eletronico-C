#include <stdio.h>

int main() {
    float saldoDisponivel = 1000.00;
    int valorSaque, valorRestante;
    int notas100, notas50, notas20, notas10, notas5;

    printf("Digite o valor do saque: ");
    scanf("%d", &valorSaque);

    if (valorSaque % 5 != 0 || valorSaque > saldoDisponivel || valorSaque <= 0) {
        printf("Erro: Valor invalido ou saldo insuficiente.\n");
    }
    else {
        valorRestante = valorSaque;

        notas100 = valorRestante / 100;
        valorRestante = valorRestante % 100;

        notas50 = valorRestante / 50;
        valorRestante = valorRestante % 50;

        notas20 = valorRestante / 20;
        valorRestante = valorRestante % 20;

        notas10 = valorRestante / 10;
        valorRestante = valorRestante % 10;

        notas5 = valorRestante / 5;

        printf("\nNotas entregues:\n");

        if (notas100 > 0)
            printf("%d nota(s) de 100\n", notas100);

        if (notas50 > 0)
            printf("%d nota(s) de 50\n", notas50);

        if (notas20 > 0)
            printf("%d nota(s) de 20\n", notas20);

        if (notas10 > 0)
            printf("%d nota(s) de 10\n", notas10);

        if (notas5 > 0)
            printf("%d nota(s) de 5\n", notas5);
    }

    return 0;
}