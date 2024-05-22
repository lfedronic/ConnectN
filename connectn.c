// Set up and Play Connect-N
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "inputvalidation.h"
#include "checkwin.h"
#include "play.h"

int main(int argc, char* argv[]) {
    if (argc > 4){
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }
    else if (argc < 4){
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }
    int num_rows = atoi(argv[1]); int num_columns = atoi(argv[2]); int num_in_row_to_win = atoi(argv[3]); 
    if ((num_rows < 0) || (num_columns < 0) || (num_in_row_to_win < 0)) {
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }
    char** game_board;
    char*** game_board_address = &game_board;
    game_board_address = setUpBoard(game_board_address, num_rows, num_columns);
    playGame(game_board_address, num_rows, num_columns, num_in_row_to_win);
    return 0;
}