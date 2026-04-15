#include <stdio.h>   /* Biblioteca de entrada e saida: printf, scanf */
#include <stdlib.h>  /* Biblioteca para malloc, calloc, free e rand */
#include <string.h>  /* Biblioteca para manipulacao de strings, como strcpy */
#include <time.h>    /* Biblioteca para usar time e gerar aleatoriedade com srand */

/* Estrutura que representa um territorio do jogo. */
typedef struct
{
    char nome[30]; /* Nome do territorio */
    char cor[10];  /* Cor do exercito que domina o territorio */
    int tropas;    /* Quantidade de tropas presentes no territorio */
} Territorio;

/* Exibe o menu principal para orientar o usuario nas acoes disponiveis. */
void exibirMenu(void)
{
    /* Cada printf mostra uma opcao do sistema para o usuario. */
    printf("\n========== WAR TERRITORIOS ==========\n");
    printf("1. Cadastrar territorios\n");
    printf("2. Mostrar territorios\n");
    printf("3. Atacar territorio\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

/* Limpa o buffer de entrada quando o usuario digita algo invalido no scanf. */
void limparEntrada(void)
{
    int caractere; /* Variavel usada para ler e descartar os caracteres restantes. */

    /* Continua lendo ate encontrar quebra de linha ou fim de arquivo. */
    while ((caractere = getchar()) != '\n' && caractere != EOF)
    {
        /* Corpo vazio de proposito: o objetivo e apenas esvaziar o buffer. */
    }
}

/* Le um numero inteiro com validacao para evitar que o programa entre em erro. */
int lerInteiro(const char *mensagem)
{
    int valor; /* Guarda o numero digitado pelo usuario. */

    /* Repete ate o usuario informar um numero inteiro valido. */
    while (1)
    {
        /* Mostra a mensagem recebida por parametro. */
        printf("%s", mensagem);

        /* Se scanf retornar 1, a leitura do inteiro foi bem-sucedida. */
        if (scanf("%d", &valor) == 1)
        {
            /* Limpa o Enter deixado no teclado antes de continuar. */
            limparEntrada();
            return valor;
        }

        /* Caso a entrada nao seja um numero, avisa o usuario. */
        printf("Entrada invalida. Digite apenas numeros inteiros.\n");

        /* Remove os caracteres incorretos para permitir nova leitura. */
        limparEntrada();
    }
}

/* Recebe os dados de cada territorio e grava no vetor alocado dinamicamente. */
void cadastrarTerritorios(Territorio *mapa, int total)
{
    /* Percorre todas as posicoes do vetor dinamico de territorios. */
    for (int i = 0; i < total; i++)
    {
        printf("\nCadastro do territorio %d\n", i + 1);

        /* Le o nome do territorio, aceitando ate 29 caracteres + '\0'. */
        printf("Nome: ");
        scanf("%29s", mapa[i].nome);

        /* Le a cor do exercito do territorio. */
        printf("Cor do exercito: ");
        scanf("%9s", mapa[i].cor);

        /* Usa a funcao com validacao para ler a quantidade de tropas. */
        mapa[i].tropas = lerInteiro("Quantidade de tropas: ");
    }
}

/* Mostra todos os territorios cadastrados para que o usuario acompanhe o estado do mapa. */
void exibirTerritorios(Territorio *mapa, int total)
{
    /* Se nao houver territorios validos, informa isso ao usuario. */
    if (total <= 0)
    {
        printf("Nenhum territorio cadastrado.\n");
        return;
    }

    printf("\n========== TERRITORIOS CADASTRADOS ==========\n");

    /* Mostra os dados de cada territorio armazenado no vetor. */
    for (int i = 0; i < total; i++)
    {
        printf("%d. Nome: %s | Cor: %s | Tropas: %d\n",
               i + 1,
               mapa[i].nome,
               mapa[i].cor,
               mapa[i].tropas);
    }
}

/* Sorteia um valor de dado entre 1 e 6 para simular a batalha entre territorios. */
int rolarDado(void)
{
    /* rand() % 6 gera valores entre 0 e 5; somando 1, fica entre 1 e 6. */
    return rand() % 6 + 1;
}

/* Executa o ataque entre dois territorios e atualiza cor e tropas quando ha conquista. */
void atacar(Territorio *atacante, Territorio *defensor)
{
    int dadoAtacante;      /* Resultado do dado do territorio atacante */
    int dadoDefensor;      /* Resultado do dado do territorio defensor */
    int tropasTransferidas; /* Quantidade de tropas movidas em caso de conquista */

    /* Garante que os ponteiros recebidos apontem para territorios validos. */
    if (atacante == NULL || defensor == NULL)
    {
        printf("Ataque invalido.\n");
        return;
    }

    /* Impede que o mesmo territorio seja atacante e defensor ao mesmo tempo. */
    if (atacante == defensor)
    {
        printf("Um territorio nao pode atacar a si mesmo.\n");
        return;
    }

    /* Para atacar, o territorio precisa ter pelo menos 2 tropas. */
    if (atacante->tropas < 2)
    {
        printf("%s nao possui tropas suficientes para atacar.\n", atacante->nome);
        return;
    }

    /* Cada lado rola um dado para decidir o resultado da batalha. */
    dadoAtacante = rolarDado();
    dadoDefensor = rolarDado();

    /* Exibe os participantes e os resultados dos dados. */
    printf("\nAtaque: %s (%s) -> %s (%s)\n",
           atacante->nome, atacante->cor,
           defensor->nome, defensor->cor);
    printf("Dado do atacante: %d\n", dadoAtacante);
    printf("Dado do defensor: %d\n", dadoDefensor);

    /* Se o atacante tirar valor maior, ele conquista o territorio defensor. */
    if (dadoAtacante > dadoDefensor)
    {
        /* Metade das tropas do atacante sera enviada para o territorio conquistado. */
        tropasTransferidas = atacante->tropas / 2;

        /* Garante pelo menos 1 tropa movida, evitando territorio conquistado vazio. */
        if (tropasTransferidas < 1)
        {
            tropasTransferidas = 1;
        }

        /* A cor do defensor passa a ser a mesma do atacante, indicando conquista. */
        strcpy(defensor->cor, atacante->cor);

        /* O defensor passa a ter as tropas enviadas pelo atacante. */
        defensor->tropas = tropasTransferidas;

        /* O atacante perde as tropas que foram transferidas. */
        atacante->tropas -= tropasTransferidas;

        printf("%s venceu o ataque e conquistou %s.\n", atacante->nome, defensor->nome);
        printf("%d tropas foram movidas para o territorio conquistado.\n", tropasTransferidas);
    }
    else
    {
        /* Se o atacante nao vencer, ele perde 1 tropa na tentativa. */
        atacante->tropas--;
        printf("%s defendeu o territorio com sucesso.\n", defensor->nome);
        printf("%s perdeu 1 tropa na tentativa de ataque.\n", atacante->nome);
    }
}

/* Libera a memoria alocada para o vetor de territorios ao final do programa. */
void liberarMemoria(Territorio *mapa)
{
    /* free devolve ao sistema a memoria reservada com calloc. */
    free(mapa);
}

int main(void)
{
    Territorio *mapa = NULL; /* Ponteiro para o vetor dinamico de territorios */
    int totalTerritorios;    /* Quantidade total de territorios cadastrados */
    int opcao = 0;           /* Guarda a opcao escolhida no menu */
    int indiceAtacante;      /* Posicao do territorio atacante no vetor */
    int indiceDefensor;      /* Posicao do territorio defensor no vetor */

    /* Inicializa a semente do rand com a hora atual para evitar repeticao dos dados. */
    srand((unsigned int)time(NULL));

    /* Pede ao usuario quantos territorios serao criados. */
    totalTerritorios = lerInteiro("Informe o numero total de territorios: ");

    /* Exige pelo menos 2 territorios para que exista possibilidade de ataque. */
    while (totalTerritorios <= 1)
    {
        printf("Cadastre pelo menos 2 territorios para permitir ataques.\n");
        totalTerritorios = lerInteiro("Informe o numero total de territorios: ");
    }

    /* Aloca memoria para o vetor de territorios e inicializa tudo com zero. */
    mapa = (Territorio *)calloc((size_t)totalTerritorios, sizeof(Territorio));

    /* Verifica se a alocacao funcionou corretamente. */
    if (mapa == NULL)
    {
        printf("Erro ao alocar memoria para os territorios.\n");
        return 1;
    }

    /* Mantem o programa em execucao ate o usuario escolher sair. */
    while (opcao != 4)
    {
        exibirMenu();

        /* Le a opcao do menu e valida se foi digitado um numero. */
        if (scanf("%d", &opcao) != 1)
        {
            printf("Opcao invalida. Digite apenas numeros.\n");
            limparEntrada();
            continue;
        }

        /* Limpa o Enter deixado pelo scanf para manter a leitura organizada. */
        limparEntrada();

        /* Escolhe qual acao executar de acordo com a opcao do usuario. */
        switch (opcao)
        {
        case 1:
            /* Preenche os dados dos territorios no vetor dinamico. */
            cadastrarTerritorios(mapa, totalTerritorios);
            break;

        case 2:
            /* Mostra todos os territorios cadastrados no momento. */
            exibirTerritorios(mapa, totalTerritorios);
            break;

        case 3:
            /* Exibe os territorios para o usuario escolher quem ataca e quem defende. */
            exibirTerritorios(mapa, totalTerritorios);

            /* O usuario digita numeros iniciando em 1, por isso subtraimos 1. */
            indiceAtacante = lerInteiro("Escolha o numero do territorio atacante: ") - 1;
            indiceDefensor = lerInteiro("Escolha o numero do territorio defensor: ") - 1;

            /* Valida se os indices escolhidos estao dentro do vetor. */
            if (indiceAtacante < 0 || indiceAtacante >= totalTerritorios ||
                indiceDefensor < 0 || indiceDefensor >= totalTerritorios)
            {
                printf("Indice de territorio invalido.\n");
                break;
            }

            /* Envia os enderecos dos territorios para a funcao de ataque. */
            atacar(&mapa[indiceAtacante], &mapa[indiceDefensor]);

            /* Exibe o estado atualizado dos territorios apos a batalha. */
            exibirTerritorios(mapa, totalTerritorios);
            break;

        case 4:
            /* Finaliza o laco principal e encerra o programa. */
            printf("Encerrando o programa...\n");
            break;

        default:
            /* Trata qualquer opcao fora das alternativas do menu. */
            printf("Opcao invalida.\n");
            break;
        }
    }

    /* Libera a memoria antes de terminar o programa. */
    liberarMemoria(mapa);
    return 0;
}
