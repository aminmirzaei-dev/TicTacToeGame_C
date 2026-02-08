#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "board.h"
#include "ai.h"

static int difficulty;
static Score score = {0, 0, 0};

static void input_difficulty(void);

void start_game(void) {
    srand(time(NULL));
    int choice;

    input_difficulty();

    do {
        char board[BOARD_SIZE][BOARD_SIZE];
        init_board(board);

        char current = rand() % 2 ? PLAYER_X : PLAYER_O;

        while (1) {
            print_board(board, score);

            if (current == PLAYER_X) {
                player_move(board);
                if (check_win(board, PLAYER_X)) {
                    score.player++;
                    print_board(board, score);
                    printf("You win!\n");
                    break;
                }
                current = PLAYER_O;
            } else {
                computer_move(board, difficulty);
                if (check_win(board, PLAYER_O)) {
                    score.computer++;
                    print_board(board, score);
                    printf("Computer wins!\n");
                    break;
                }
                current = PLAYER_X;
            }

            if (check_draw(board)) {
                score.draw++;
                print_board(board, score);
                printf("It's a draw!\n");
                break;
            }
        }

        printf("Play again? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    printf("Thanks for playing!\n");
}

static void input_difficulty(void) {
    do {
        printf("Select difficulty:\n");
        printf("1. Normal\n");
        printf("2. God Mode\n");
        printf("Choice: ");
        scanf("%d", &difficulty);
    } while (difficulty != 1 && difficulty != 2);
}

