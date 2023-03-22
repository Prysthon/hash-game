#include <iostream>

int gameLength = 3;

// PERGUNTAR!!!!!!!!!!!
void printGame(char game[gameLength][gameLength]) {
  // COMEÇO DA IMPRESSÃO DO JOGO
  // Imprime cabeçalho
  printf("            ");
  for (int i = 0; i < gameLength; i++) {
    printf("%d   ", i);
  }
  printf("\n");
  // Imprimindo a linha
  for (int i = 0; i < gameLength; i++) {
    printf("          %d ", i);
    for (int j = 0; j < gameLength; j++) {
      if (j < gameLength - 1) {
        printf("%c | ", game[i][j]);
      }
      else {
        printf("%c ", game[i][j]);
      }
    }
    printf("\n           ");
    // Imprimindo as linhas horizontais
    if (i < gameLength - 1) {
      for (int k = 0; k < gameLength - 1; k++) {
        printf("----");
      }
      printf("---\n");
    }
  }
  printf("\n");
}

int main() {
// 1a Etapa - Obter e imprimir nome dos jogadores
  char playerOne[30], playerTwo[30];
  printf("* * * J O G O   D A   V E L H A * * *\n");
  printf("*************************************\n");
  printf("\n");
  printf("Nome do jogador 1: ");
  scanf("%[^\n]s", playerOne);
  printf("Nome do jogador 2: ");
  scanf(" %[^\n]s", playerTwo);
  printf("\n");
  printf("Boa sorte jogadores %s e %s!\n", playerOne, playerTwo);
  printf("\n");
  printf("*************************************\n");
  printf("\n");

// 2a Etapa - Criar um vetor com espaço vazio e imprimir jogo da velha vazio
  char game[gameLength][gameLength];
  // Definindo os caracteres nulos como início do jogo
  for (int i = 0; i < gameLength; i++) {
    for (int j = 0; j < gameLength; j++) {
      game[i][j] = ' ';
    }
  }
  // COMEÇO DA IMPRESSÃO DO JOGO
  // Imprime cabeçalho
  printf("            ");
  for (int i = 0; i < gameLength; i++) {
    printf("%d   ", i);
  }
  printf("\n");
  // Imprimindo a linha
  for (int i = 0; i < gameLength; i++) {
    printf("          %d ", i);
    for (int j = 0; j < gameLength; j++) {
      if (j < gameLength - 1) {
        printf("%c | ", game[i][j]);
      }
      else {
        printf("%c ", game[i][j]);
      }
    }
    printf("\n           ");
    // Imprimindo as linhas horizontais
    if (i < gameLength - 1) {
      for (int k = 0; k < gameLength - 1; k++) {
        printf("----");
      }
      printf("---\n");
    }
  }
  printf("\n");

  // 3o Etapa - criar loop e começo do jogo
  while (true) {
    int x, y;
    char symbol;
    printf("\nDigite a linha: ");
    scanf("%d", &x);
    printf("Digite a coluna: ");
    scanf("%d", &y);
    printf("Digite seu símbolo: ");
    scanf("%s", &symbol);
    
    game[x][y] = symbol;

  // COMEÇO DA IMPRESSÃO DO JOGO
  // Imprime cabeçalho
  printf("            ");
  for (int i = 0; i < gameLength; i++) {
    printf("%d   ", i);
  }
  printf("\n");
  // Imprimindo a linha
  for (int i = 0; i < gameLength; i++) {
    printf("          %d ", i);
    for (int j = 0; j < gameLength; j++) {
      if (j < gameLength - 1) {
        printf("%c | ", game[i][j]);
      }
      else {
        printf("%c ", game[i][j]);
      }
    }
    printf("\n           ");
    // Imprimindo as linhas horizontais
    if (i < gameLength - 1) {
      for (int k = 0; k < gameLength - 1; k++) {
        printf("----");
      }
      printf("---\n");
    }
  }
  printf("\n");
  // FIM
  }
  return 0;
}