#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct {
    int player;
    int computer;
    int draw;
} Score;

void init_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE], Score score);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);

#endif

