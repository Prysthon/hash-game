#include <iostream>

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
  int gameLength = 3;
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
    for (int j = 0; j < gameLength - 1; j++) {
      printf("%c | ", game[i][j]);
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
  
  return 0;
}