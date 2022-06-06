#include "../include/cell.h"

int aliveNeighbors(int board[MAXROWS][MAXCOLUMNS], int row, int column) {
    int aliveNeighbors = 0;
    int testRow = 0;

    if (row == 0) {
        testRow = MAXROWS - 1;
    } else {
        testRow = row - 1;
    }

    aliveNeighbors += aliveNeighborsInRow(board, testRow, row, column);

    testRow = row;

    aliveNeighbors += aliveNeighborsInRow(board, testRow, row, column);

    if (row == MAXROWS - 1) {
        testRow = 0;
    } else {
        testRow = row + 1;
    }

    aliveNeighbors += aliveNeighborsInRow(board, testRow, row, column);

    return aliveNeighbors;
}

int aliveNeighborsInRow(int board[MAXROWS][MAXCOLUMNS], int testRow, int row, int column) {
    int aliveNeighbors = 0;
    int testColumn = 0;

    if (column == 0) {
        testColumn = MAXCOLUMNS - 1;
    } else {
        testColumn = column - 1;
    }

    aliveNeighbors += board[testRow][testColumn];

    testColumn = column;

    if (testRow != row) {
        aliveNeighbors += board[testRow][testColumn];
    }

    if (column == MAXCOLUMNS - 1) {
        testColumn = 0;
    } else {
        testColumn = column + 1;
    }

    aliveNeighbors += board[testRow][testColumn];

    return aliveNeighbors;
}
