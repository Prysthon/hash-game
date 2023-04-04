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

void gravity(char *game, int *x, int gameLength) {
	for (int line = gameLength - 1 ;line > *x ;line--) {
		if (*game == ' ') {
			*x = line;
			break;
		}
		game -= gameLength;
	}
} 

bool lineVictory(char *game, int gameLength) {
  int points = 0;
  char symbol;
  
  // primeiro for para as linhas
  for (int y = 0; y < gameLength; y++) {
    // Resetando informações a cada linha
    symbol = '\0';
    points = 0;
    // segundo for para as colunas
    for (int x = 0; x < gameLength; x++) {
      // Verifica se existe algo
      if (*game != ' ') {
        // Caso seja primeira aparição
        if (!symbol) {
          symbol = *game;
          points += 1;
        // Caso seja igual
        } else if (symbol == *game) {
          points += 1;
          // Verificando se houve vitória
          if (points >= 3) return true;
        // Caso seja diferente
        } else {
          points = 0;
          char symbol = *game;
        }
      } else {
          points = 0;
          symbol = '\0';
        }
      // Mudando de posição no vetor
      game++;
    }
  }
  
  return false;
}

bool columnVictory(char *game, int gameLength) {
   int points = 0;
  char symbol;

  // primeiro for para as colunas
  for (int x = 0; x < gameLength; x++) {
    // Resetando informações a cada coluna
    symbol = '\0';
    points = 0;
    // segundo for para as linhas
    for (int y = 0; y < gameLength; y++) {
      // Verifica se existe algo
      if (*(game + y * gameLength + x) != ' ') {
        // Caso seja primeira aparição
        if (!symbol) {
          symbol = *(game + y * gameLength + x);
          points += 1;
        // Caso seja igual
        } else if (symbol == *(game + y * gameLength + x)) {
          points += 1;
          // Verificando se houve vitória
          if (points >= 3) return true;
        // Caso seja diferente
        } else {
          points = 0;
          char symbol = *(game + y * gameLength + x);
        }
      } else {
          points = 0;
          symbol = '\0';
        }
    }
  }

  return false;
}

bool principalDiagonalVictory(char *game, int gameLength) {
  // primeiro for para as linhas
  for (int y = 0; y < gameLength - (gameLength - 3); y++) {
    // segundo for para as colunas
    for (int x = 0; x < gameLength; x++) {
      // Verifica se existe algo
      if (*game != ' ') {
        if (*game == *(game + gameLength + 1)) {
          if (*game == *((game + gameLength*2) + 2)) {
            return true;
          }
        }
      }
      game++;
    }
  }
  
  return false;
}

bool secundaryDiagonalVictory(char *game, int gameLength) {
  // primeiro for para as linhas
  for (int y = 0; y < gameLength - (gameLength - 3); y++) {
    // segundo for para as colunas
    for (int x = 0; x < gameLength; x++) {
      // Verifica se existe algo
      if (*game != ' ') {
        if (*game == *(game + gameLength -1)) {
          if (*game == *((game + gameLength*2) - 2)) {
            return true;
          }
        }
      }
      game++;
    }
  }
  
  return false;
}

bool victory(char *game, int gameLength) {
	if (lineVictory(game, gameLength) || columnVictory(game, gameLength) || principalDiagonalVictory(game, gameLength) || secundaryDiagonalVictory(game, gameLength)) return true;
	return false;
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

  // Definindo os turnos
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
    
    // Coloca efeito gravidade
    gravity(&game[gameLength - 1][y], &x, gameLength);

    // Atribui o símbolo a coordenada
    game[x][y] = symbol[shift];

    // Verifica vitória
    if(victory(&game[0][0], gameLength)) break;
    
    // Próximo jogador
    nextShift(&shift, playersLength);
  }

  // Finalizando
  printf("\n\n\n* * *  F I M   D O   J O G O  * * *\n\n");
  printGame(&game[0][0], gameLength);
  printf("*******************************************\n");
  printf("voce nao merece palmas,  %s, merece tocantins inteiro!!!\n", players[shift]);
  printf("*******************************************\n");
  return 0;
}