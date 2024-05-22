// Get valid user input during turns of Connect-n
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "board.h"
#include "inputvalidation.h"
bool clear_the_input_buffer(){
    /**
    * Clears the input buffer until a new line is encountered.
    * @return True if only whitespace was found while reading, false otherwise.
    */
    char letter;
    bool only_whitespace_after = true;
    do{
        scanf("%c", &letter);
        if(!isspace(letter)){
            only_whitespace_after = false;
        }
    }while(letter != '\n');
    return only_whitespace_after;
}

int getAnInt(int lower, int upper){
    int num, num_args_read;
    /**
    * Gets an integer from input within a specified range.
    * @param lower Lower bound of the range.
    * @param upper Upper bound of the range.
    * @return The valid integer read from the input or -2 if input constraints are violated.
    */
    bool only_whitespace_after;
    do{
        num_args_read = scanf("%d",&num);
        only_whitespace_after = clear_the_input_buffer();
        if (!only_whitespace_after) {
            return -2;
        }
    }while((num_args_read != 1) && (num < lower) && (num >= upper));

    return num;
}

int getValidTurn(char** game_board, int num_columns, int num_rows, int* selected_row_address) {
    /**
     * Gets a valid turn from the player and updates the game board.
     * @param game_board The game board array.
     * @param num_columns Number of columns in the game board.
     * @param num_rows Number of rows in the game board.
     * @param selected_row_address Address to store the selected row of the move.
     * @return The selected column for the turn.
     */
    int selected_column = -1;
    do {
        printf("Enter a column between 0 and %d to play in: ", num_columns - 1);
        selected_column = getAnInt(0, num_columns);
    } while (!(spaceInColumn(game_board, selected_column, selected_row_address, num_rows, num_columns)));
    return selected_column;
}