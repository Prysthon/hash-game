#include <iostream>

void printGame(char *game, int gameLength) {
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
        printf("%c | ", *game);
      }
      else {
        printf("%c ", *game);
      }
    game++;
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

// Define o turno
void nextShift(int *shift, int playersLength) {
  if (*shift < playersLength - 1) {
    *shift = *shift + 1;
  } else {
    *shift = 0;
  };
}

bool validPosition(char *game) {
		if (*game != ' ') {
			printf("Posicao invalida, por favor, digite uma nova coordenada: \n\n");
			return false;
		};
		return true;
}

int main() {
  int playersLength;
  // Começo do cabeçalho
  printf("* * * J O G O   D A   V E L H A * * *\n");
  printf("*************************************\n");
  printf("\n");

  // Definindo número de jogadores e criando vetor de jogadores e seus simbolos
  printf("Digite o numero de jogadores: ");
  scanf("%d", &playersLength);
  char players[playersLength][50];
  char symbol[playersLength];
  printf("\n");
  
  // Colocando os nomes nos vetores
  for (int i = 0; i < playersLength; i++) {
    printf("Nome do Jogador numero %d: ", i+1);
    scanf(" %[^\n]s", players[i]);
    printf("Simbolo jogador %d: ", i+1);
    scanf(" %c", &symbol[i]);
    printf("\n");
  }
  
  // Imprimindo o boa sorte
  printf("Boa sorte ");
  for (int i = 0; i < playersLength - 2; i++) {
    printf("%s, ", players[i]);
  }
  printf("%s e %s!\n", players[playersLength-2], players[playersLength-1]);
  printf("*************************************\n");
  printf("\n\n");

  // Perguntar tamanho do tabuleiro e definindo tamanho do jogo
  int gameLength;
  printf("Tamanho do tabuleiro: ");
  scanf("%d", &gameLength);
  printf("\n");
  char game[gameLength][gameLength];
  
  // Definindo os caracteres nulos como início do jogo
  for (int i = 0; i < gameLength; i++) {
    for (int j = 0; j < gameLength; j++) {
      game[i][j] = ' ';
    }
  }

  // Definindo os turno
  int shift = 0;
  
  // INÍCIO DO JOGO
  while (true) {
    int x, y;
    // Imprime - cabeçalho e jogo
    // Pega as coordenadas
    printf("---------------  Turno de %s  ---------------\n", players[shift]);
    printGame(&game[0][0], gameLength);
    printf("\nDigite a linha: ");
    scanf("%d", &x);
    printf("Digite a coluna: ");
    scanf("%d", &y);
    printf("\n");

    // Confere se posição é válida
    if (!validPosition(&game[x][y])) continue;

    // Atribui o símbolo a coordenada
    game[x][y] = symbol[shift];

    // Próximo jogador
    nextShift(&shift, playersLength);
  }
  
  return 0;
}