// Handle setting up and updating the game board, as well as checking its state
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printBoard(char** game_board, int num_rows, int num_columns) {
    /**
    * Display the game board.
    * @param game_board The game board array.
    * @param num_rows Number of rows in the game board.
    * @param num_columns Number of columns in the game board.
    */
    for (int i = 0; i < num_rows; ++i) {
        printf("%d ", num_rows - i - 1);
        for (int j = 0; j < num_columns; ++j) {
            printf("%c ", game_board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (int i = 0; i < num_columns; ++i) {
        printf("%d ", i);
    }
    printf("\n");
}

char*** setUpBoard(char*** game_board_address, int num_rows, int num_columns) {
    /**
    * Sets up the game board with initial empty values.
    * @param game_board_address Address of the game board array.
    * @param num_rows Number of rows in the game board.
    * @param num_columns Number of columns in the game board.
    * @return The address of the game board array.
    */
    *game_board_address = (char**)calloc(num_rows, sizeof(char*));
    for (int i = 0; i < num_rows; ++i) {
        (*game_board_address)[i] = (char *)calloc(num_columns, sizeof(char));
    }
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_columns; ++j) {
            (*game_board_address)[i][j] = '*';
        }
    }
    return game_board_address;
}

char*** fillBoard(char*** game_board_address, int selected_column, int num_rows, bool player1_turn) {
    /**
    * Updates the game board with a player's move.
    * @param game_board_address Address of the game board array.
    * @param selected_column Column selected by player to put gamepiece in.
    * @param num_rows Number of rows in the game board.
    * @param player1_turn Boolean indicating player's turn (True if player 1's turn, False otherwise)
    * @return The address of the updated game board array.
    */
    char fill_char = player1_turn ? 'X' : 'O';
    for (int i = num_rows - 1; i >= 0; --i) {
        if ((*game_board_address)[i][selected_column] == '*') {
            (*game_board_address)[i][selected_column] = fill_char;
            return game_board_address;
        }
    }
    return game_board_address;
}

bool checkIfSpaceRemains(char** game_board, int num_columns) {
    /**
    * Checks if there are empty spaces remaining on the game board.
    * @param game_board The game board array.
    * @param num_columns Number of columns in the game board.
    * @return Boolean indicating if there are empty spaces left.
    */
    for (int i = 0; i < num_columns; ++i) {
        if (game_board[0][i] == '*') {
            return true;
        }
    }
    return false;
}

bool spaceInColumn(char** game_board, int selected_column, int* selected_row_address, int num_rows, int num_columns) {
    /**
    * Checks if there's an available space in a given column.
    * @param game_board The game board array.
    * @param selected_column Column selected by player to put gamepiece in.
    * @param selected_row_address Address to store the selected row.
    * @param num_rows Number of rows in the game board.
    * @param num_columns Number of columns in the game board.
    * @return Boolean indicating if space is available in the column.
    */
    for (int i = num_rows - 1; i >= 0; i--) {
        if (game_board[i][selected_column] == '*') {
            *selected_row_address = i;
            return true;
        }
    }
    return false;
}
