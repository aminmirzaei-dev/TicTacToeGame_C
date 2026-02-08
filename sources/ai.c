#include <stdio.h>
#include "ai.h"

void player_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    do {
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        row--; col--;
    } while (!is_valid_move(board, row, col));

    board[row][col] = PLAYER_X;
}

void computer_move(char board[BOARD_SIZE][BOARD_SIZE], int difficulty) {

    // Win move
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') {
                board[i][j] = PLAYER_O;
                if (check_win(board, PLAYER_O)) return;
                board[i][j] = ' ';
            }

    // Block move
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') {
                board[i][j] = PLAYER_X;
                if (check_win(board, PLAYER_X)) {
                    board[i][j] = PLAYER_O;
                    return;
                }
                board[i][j] = ' ';
            }

    if (difficulty == 2 && board[1][1] == ' ') {
        board[1][1] = PLAYER_O;
        return;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') {
                board[i][j] = PLAYER_O;
                return;
            }
}

