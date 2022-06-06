#include "../include/board.h"

void initializeBoard() {
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLUMNS; j++) {
      currentBoard[i][j] = rand() & 1;
    }
  }
}

void printBoardCurrentState() {
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLUMNS; j++) {
      if(currentBoard[i][j]) {
        printf("█");
      } else {
        printf(" ");
      }
    }

    printf("\n");
  }
}

void setBoardNextState() {
  int nextBoard[MAXROWS][MAXCOLUMNS];

  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLUMNS; j++) {
      int neighbors = 0;

      neighbors = aliveNeighbors(currentBoard, i,j);

      if ((currentBoard[i][j] && neighbors == 2) || neighbors == 3) {
        nextBoard[i][j] = 1;
      } else {
        nextBoard[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLUMNS; j++) {
      currentBoard[i][j] = nextBoard[i][j];
    }
  }
}

void setUpGlider() {
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLUMNS; j++) {
      currentBoard[i][j] = 0;
    }
  }

  currentBoard[0][1] = 1;
  currentBoard[1][2] = 1;
  currentBoard[2][0] = 1;
  currentBoard[2][1] = 1;
  currentBoard[2][2] = 1;
}
