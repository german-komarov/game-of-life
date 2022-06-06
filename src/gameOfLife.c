#include "../include/gameOfLife.h"

int main() {
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
