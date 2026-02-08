#include <stdio.h>
#include <stdlib.h>
#include "board.h"

static void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = ' ';
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE], Score score) {
    clear_screen();
    printf("Score  You: %d  Computer: %d  Draws: %d\n\n",
           score.player, score.computer, score.draw);

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---+---+---\n");
    }
    printf("\n\n");
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char p) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == p && board[i][1] == p && board[i][2] == p) ||
            (board[0][i] == p && board[1][i] == p && board[2][i] == p))
            return 1;
    }

    return (board[0][0] == p && board[1][1] == p && board[2][2] == p) ||
           (board[2][0] == p && board[1][1] == p && board[0][2] == p);
}

int check_draw(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

