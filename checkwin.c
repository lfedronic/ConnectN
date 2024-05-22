// Check all win-conditions 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkVerticalWin(char** game_board, int selected_column, int* selected_row_address, int num_rows, int num_columns, int row_of_highest_piece, int num_in_row_to_win, char char_to_check) {
    /**
    * Checks if player has won vertically.
    * @param game_board The game board array.
    * @param selected_column Column selected by player to put gamepiece in.
    * @param selected_row_address Address of the selected row for the last move.
    * @param num_rows Number of rows in the game board.
    * @param num_columns Number of columns in the game board.
    * @param row_of_highest_piece Row of the highest piece in the selected column.
    * @param num_in_row_to_win Number of pieces required in a row to win.
    * @param char_to_check Character representing the player's piece.
    * @return Boolean indicating if there's a vertical win.
    */
    int counter = 0;
    int row = row_of_highest_piece;
    while (true) {
        if (counter == num_in_row_to_win) {
            return true;
        }
        if (game_board[row][selected_column] != char_to_check) {
            return false;
        }
        ++row;
        ++counter;
    }
}

bool checkHorizontalWin(char** game_board, int num_columns, int selected_column, int row_of_highest_piece, int num_in_row_to_win, char char_to_check) {
    /**
    * Checks if a player has won horiztonally. 
    * @param game_board The game board array.
    * @param num_columns Number of columns in the game board.
    * @param selected_column Column selected by player to put gamepiece in.
    * @param row_of_highest_piece Row of the highest piece in the selected column.
    * @param num_in_row_to_win Number of pieces required in a row to win.
    * @param char_to_check Character representing the player's piece.
    * @return Boolean indicating if there's a horizontal win.
    */
    int adjacent_column = selected_column - 1;
    int adjacents = 0;
    while (adjacent_column >= 0) {
        if (game_board[row_of_highest_piece][adjacent_column] != char_to_check) {
            break;
        }
        ++adjacents;
        --adjacent_column;
    }
    adjacent_column = selected_column + 1;
    while (adjacent_column < num_columns) {
        if (game_board[row_of_highest_piece][adjacent_column] != char_to_check) {
            break;
        }
        ++adjacents;
        ++adjacent_column;
    }
    if (adjacents + 1 >= num_in_row_to_win) {
        return true;
    }
    return false;
}

bool checkDownUpDiagonal(char** game_board, int num_columns, int num_rows, int selected_column, int row_of_highest_piece, int num_in_row_to_win, char char_to_check){
    /**
     * Checks if a player has won with a downward-upward diagonal.
     * @param game_board The game board array.
     * @param num_columns Number of columns in the game board.
     * @param num_rows Number of rows in the game board.
     * @param selected_column Column selected by player to put gamepiece in.
     * @param row_of_highest_piece Row of the highest piece in the selected column.
     * @param num_in_row_to_win Number of pieces required in a row to win.
     * @param char_to_check Character representing the player's piece.
     * @return Boolean indicating if there's a diagonal win.
     */
    int diagonals = 0;
    int adjacent_column = selected_column - 1;
    int adjacent_row = row_of_highest_piece + 1;
    while ((adjacent_column >= 0) && (adjacent_row < num_rows)) {
        if (game_board[adjacent_row][adjacent_column] != char_to_check) {
            break;
        }
        ++diagonals;
        --adjacent_column;
        ++adjacent_row;
    }
    adjacent_column = selected_column + 1;
    adjacent_row = row_of_highest_piece - 1;
    while ((adjacent_column < num_columns) && (adjacent_row >= 0)) {
        if (game_board[adjacent_row][adjacent_column] != char_to_check) {
            break;
        }
        ++diagonals;
        ++adjacent_column;
        --adjacent_row;
    }
    if (diagonals + 1 >= num_in_row_to_win) {
        return true;
    }
    return false;
}

bool checkUpDownDiagonal(char** game_board, int num_columns, int num_rows, int selected_column, int row_of_highest_piece, int num_in_row_to_win, char char_to_check){
    /**
     * Checks if a player has won with a upward-downward diagonal.
     * @param game_board The game board array.
     * @param num_columns Number of columns in the game board.
     * @param num_rows Number of rows in the game board.
     * @param selected_column Column selected by player to put gamepiece in.
     * @param row_of_highest_piece Row of the highest piece in the selected column.
     * @param num_in_row_to_win Number of pieces required in a row to win.
     * @param char_to_check Character representing the player's piece.
     * @return Boolean indicating if there's a diagonal win.
     */
    int diagonals = 0;
    int adjacent_column = selected_column + 1;
    int adjacent_row = row_of_highest_piece + 1;
    while ((adjacent_column < num_columns) && (adjacent_row < num_rows)) {
        if (game_board[adjacent_row][adjacent_column] != char_to_check) {
            break;
        }
        ++diagonals;
        ++adjacent_column;
        ++adjacent_row;
    }
    adjacent_column = selected_column - 1;
    adjacent_row = row_of_highest_piece - 1;
    while ((adjacent_column >= 0) && (adjacent_row >= 0)) {
        if (game_board[adjacent_row][adjacent_column] != char_to_check) {
            break;
        }
        ++diagonals;
        --adjacent_column;
        --adjacent_row;
    }
    if (diagonals + 1 >= num_in_row_to_win) {
        return true;
    }
    return false;
}

bool checkIfWinner(char** game_board, int num_rows, int num_columns, int num_in_row_to_win, int selected_column, int* selected_row_address, bool player1_turn) {
    /**
    * Checks if a player has won the game.
    * @param game_board The game board array.
    * @param num_rows Number of rows in the game board.
    * @param num_columns Number of columns in the game board.
    * @param num_in_row_to_win Number of pieces required in a row to win.
    * @param selected_column Column selected by player to put gamepiece in.
    * @param selected_row_address Address of the selected row for the last move.
    * @param player1_turn Boolean indicating player's turn.
    * @return Boolean indicating if there's a winner.
    */
    char char_to_check = player1_turn ? 'X' : 'O';
    int row_of_highest_piece = *selected_row_address;

    if ((num_rows - *selected_row_address) >= num_in_row_to_win) {
        if (checkVerticalWin(game_board, selected_column, selected_row_address, num_rows, num_columns, row_of_highest_piece, num_in_row_to_win, char_to_check)) {
            return true;
        }
    }
    if (checkHorizontalWin(game_board, num_columns, selected_column, row_of_highest_piece, num_in_row_to_win, char_to_check)) {
        return true; 
    }
    if (checkDownUpDiagonal(game_board, num_columns, num_rows, selected_column, row_of_highest_piece, num_in_row_to_win, char_to_check)) {
        return true;
        
    }

    if (checkUpDownDiagonal(game_board, num_columns, num_rows, selected_column, row_of_highest_piece, num_in_row_to_win, char_to_check)) {
        return true;
    }

   return false;
}