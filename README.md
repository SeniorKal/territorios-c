# Cadastro de Territórios em C

Este projeto é um programa simples em linguagem C inspirado no jogo War. Ele permite cadastrar territórios com nome, cor e quantidade de tropas, além de listar os territórios já registrados.

O objetivo do código é praticar conceitos básicos de programação em C, como:

- `struct`
- vetores
- `while`
- `if` e `else`
- entrada de dados com `scanf`
- laços de repetição com `for`

## Como o programa funciona

O programa mostra um menu com 3 opções:

1. Adicionar território
2. Mostrar territórios
3. Sair

Quando o usuário escolhe adicionar um território, o programa pede:

- nome do território
- cor do território
- quantidade de tropas

Essas informações são armazenadas em um vetor com espaço para até 5 territórios.

Se o usuário escolher mostrar territórios, o programa percorre o vetor e exibe apenas os territórios que já foram cadastrados.

## Estrutura do código

### `struct Territorio`

Essa estrutura agrupa os dados de cada território:

```c
typedef struct
{
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;
```

Cada território possui:

- `nome`: nome do território
- `cor`: cor associada ao território
- `tropas`: quantidade de tropas no território

## Lógica principal

No `main()`, o programa usa:

- `escolha` para guardar a opção digitada no menu
- `total` para controlar quantos territórios já foram cadastrados
- `territorios[5]` para armazenar até 5 registros

O menu roda dentro de um `while`, repetindo até o usuário escolher a opção `3`.

## Cuidados implementados no código

O programa também possui algumas proteções importantes:

- impede cadastrar mais de 5 territórios
- trata entrada inválida no menu
- limita o tamanho das strings lidas com `scanf`

Esses limites evitam problemas como travamento do programa e estouro de memória.

## Exemplo de uso

```text
==========/WAR TERRITORIOS/=========
1. Adicionar territorio
2. Mostrar territorios
3. Sair
Escolha uma opcao: 1
Nome: Brasil
Cor: Verde
Tropas: 10

==========/WAR TERRITORIOS/=========
1. Adicionar territorio
2. Mostrar territorios
3. Sair
Escolha uma opcao: 2
Territorios cadastrados:
Nome: Brasil, Cor: Verde, Tropas: 10
```

## Como compilar

Se você estiver usando `gcc`, compile com:

```bash
gcc War.c -o War
```

No Windows, também pode gerar um executável com:

```bash
gcc War.c -o War.exe
```

## Como executar

No Linux ou macOS:

```bash
./War
```

No Windows:

```bash
War.exe
```

## Arquivo principal

O código-fonte principal está em [War.c](./War.c).
