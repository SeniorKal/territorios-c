# Projeto War em C

Este projeto implementa uma simulacao simples de batalha entre territorios inspirada no jogo War.

O estado atual deste repositorio corresponde ao nivel `aventureiro` da atividade. Nesta etapa, o foco foi sair de uma versao basica com vetor fixo e evoluir para uma implementacao com alocacao dinamica, funcoes separadas e logica de ataque entre territorios.

## Nivel atual: Aventureiro

Nesta versao, o programa ja atende os principais requisitos pedidos para a simulacao:

- cadastro de territorios com `nome`, `cor` e `tropas`
- uso de `struct Territorio`
- alocacao dinamica de memoria com `calloc`
- acesso aos dados por ponteiros
- menu interativo no terminal
- exibicao dos territorios cadastrados
- simulacao de ataque com dados aleatorios
- atualizacao de cor e tropas apos a batalha
- liberacao da memoria com `free`

## Objetivo de aprendizagem

Este commit foi construido para praticar conceitos importantes da linguagem C:

- `struct`
- ponteiros
- alocacao dinamica
- vetores de estruturas
- funcoes com parametros
- validacao de entrada
- `rand` e `srand`
- organizacao modular do codigo

## Como o programa funciona

Ao iniciar, o programa pede ao usuario o numero total de territorios que serao criados.

Depois disso, ele apresenta um menu com as opcoes:

1. Cadastrar territorios
2. Mostrar territorios
3. Atacar territorio
4. Sair

Na opcao de cadastro, o usuario informa:

- nome do territorio
- cor do exercito
- quantidade de tropas

Na opcao de ataque:

- o usuario escolhe um territorio atacante
- o usuario escolhe um territorio defensor
- cada lado rola um dado com valor entre `1` e `6`
- se o atacante vencer, o territorio defensor passa a ter a mesma cor do atacante
- parte das tropas do atacante e transferida para o territorio conquistado
- se o atacante perder, ele perde uma tropa

## Estrutura do codigo

O arquivo principal do projeto e [War.c](./War.c).

As funcoes principais sao:

- `exibirMenu()`: mostra as opcoes do sistema
- `limparEntrada()`: limpa o buffer do teclado
- `lerInteiro()`: le numeros com validacao
- `cadastrarTerritorios()`: registra os territorios no vetor dinamico
- `exibirTerritorios()`: mostra os dados atuais do mapa
- `rolarDado()`: gera um numero aleatorio entre 1 e 6
- `atacar()`: executa a batalha entre dois territorios
- `liberarMemoria()`: libera a memoria alocada

## Exemplo de fluxo

```text
Informe o numero total de territorios: 2

========== WAR TERRITORIOS ==========
1. Cadastrar territorios
2. Mostrar territorios
3. Atacar territorio
4. Sair
Escolha uma opcao: 1

Cadastro do territorio 1
Nome: Brasil
Cor do exercito: Verde
Quantidade de tropas: 10

Cadastro do territorio 2
Nome: Argentina
Cor do exercito: Azul
Quantidade de tropas: 8
```

## Como compilar

No Windows:

```bash
gcc War.c -o War.exe
```

No Linux ou macOS:

```bash
gcc War.c -o War
```

## Como executar

No Windows:

```bash
War.exe
```

No Linux ou macOS:

```bash
./War
```

📌 Author

Kauê de Figueiredo