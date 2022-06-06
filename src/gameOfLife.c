#include "../include/gameOfLife.h"

int main() {
    char option[64];

    printf(" 1. Random board\n");

    while (atoi(option) != 1 && atoi(option) != 2) {
        fgets(option, sizeof(option), stdin);
    }

    initializeBoard();


    while (1) {
        clrscr();

        printBoardCurrentState();

        setBoardNextState();

        usleep(sleepingTime);
    }
}


void clrscr() {
    system("clear");
}
