#include <stdlib.h>
#include <stdio.h>
#include "cell.h"
#include "boardSize.h"

void initializeBoard();
void printBoardCurrentState();
void setBoardNextState();

void setUpGlider();

int currentBoard[MAXROWS][MAXCOLUMNS];
