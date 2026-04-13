#include <stdio.h>

typedef struct
{
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    int escolha = 0;
    int total = 0;
    Territorio territorios[5];

    while (escolha != 3) {
        printf("==========/WAR TERRITORIOS/=========\n");
        printf("1. Adicionar territorio\n");
        printf("2. Mostrar territorios\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");

        // Verifica se o usuario digitou um numero valido para o menu.
        if (scanf("%d", &escolha) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");

            // Limpa o restante da entrada para evitar loop infinito no scanf.
            while (getchar() != '\n');
            continue;
        }

        if (escolha == 1) {
            if (total < 5) {
                printf("Nome: ");
                scanf("%29s", territorios[total].nome);

                printf("Cor: ");
                scanf("%9s", territorios[total].cor);

                printf("Tropas: ");
                scanf("%d", &territorios[total].tropas);

                // Avanca para a proxima posicao livre do vetor.
                total++;
            } else {
                printf("Limite de territorios atingido!\n");
            }
        }
        else if (escolha == 2) {
            printf("Territorios cadastrados:\n");

            // Percorre somente os territorios que ja foram cadastrados.
            for (int i = 0; i < total; i++) {
                printf("Nome: %s, Cor: %s, Tropas: %d\n", territorios[i].nome, territorios[i].cor, territorios[i].tropas);
            }
        }
        else if (escolha == 3) {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
