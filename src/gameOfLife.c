#include "../include/gameOfLife.h"

int main() {
  char option[64];

  printf("Starting Game!\n");
  printf("Choose a board:\n");
  printf(" 1. Random board\n");
  printf(" 2. Glider board\n");

  while(atoi(option) != 1 && atoi(option) != 2) {
    fgets(option, sizeof(option), stdin);
  }


  if (atoi(option) == 1) {
    initializeBoard();
  } else {
    setUpGlider();
  }

  while(1) {
    clrscr();

    printBoardCurrentState();

    setBoardNextState();

    usleep(sleepingTime);
  }

  return 0;
}


void clrscr() {
  system("clear");
}
