// Establish the game loop and take turns until the game ends 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "inputvalidation.h"
#include "checkwin.h"


char*** takeTurn(bool player1_turn, char*** game_board_address, int num_rows, int num_columns, int num_in_row_to_win) {
    /**
    * Takes a turn for a player.
    * @param player1_turn Boolean indicating player's turn (True for player 1, False for player 2)
    * @param game_board_address Address of the game board array.
    * @param num_rows Number of rows in the game board.
    * @param num_columns Number of columns in the game board.
    * @param num_in_row_to_win Number of pieces required in a row to win.
    * @return The address of the updated game board array.
    */
    int selected_row;
    int* selected_row_address = &selected_row;
    int selected_column = getValidTurn(*game_board_address, num_columns, num_rows, selected_row_address);
    if (selected_column == -1) {
        printBoard(*game_board_address, num_rows, num_columns);
        printf("Tie game!\n");
        exit(0);
    }
    game_board_address = fillBoard(game_board_address, selected_column, num_rows, player1_turn);
    if (checkIfWinner(*game_board_address, num_rows, num_columns, num_in_row_to_win, selected_column, selected_row_address, player1_turn)) {
        printBoard(*game_board_address, num_rows, num_columns);
        printf("Player %d Won!\n", (int)!(player1_turn) + 1);
        exit(0);
    }
    if (!checkIfSpaceRemains(*game_board_address, num_columns)) {
        printBoard(*game_board_address, num_rows, num_columns);
        printf("Tie game!\n");
        exit(0);
    }
    return game_board_address;
}

void playGame(char*** game_board_address, int num_rows, int num_columns, int num_in_row_to_win) {
    /**
     * Plays the game, alternating turns between two players until there's a winner or a tie.
     * @param game_board_address Address of the game board array.
     * @param num_rows Number of rows in the game board.
     * @param num_columns Number of columns in the game board.
     * @param num_in_row_to_win Number of pieces required in a row to win.
     */
    bool player1_turn = true;
    while (true) {
        printBoard(*game_board_address, num_rows, num_columns);
        game_board_address = takeTurn(player1_turn, game_board_address, num_rows, num_columns, num_in_row_to_win);
        player1_turn = !player1_turn;
        
    } 
}