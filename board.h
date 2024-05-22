#ifndef BOARD_H
#define BOARD_H
    void printBoard(char** game_board, int num_rows, int num_columns);
    char*** setUpBoard(char*** game_board_address, int num_rows, int num_columns);
    char*** fillBoard(char*** game_board_address, int selected_column, int num_rows, bool player1_turn);
    bool checkIfSpaceRemains(char** game_board, int num_columns);
    bool spaceInColumn(char** game_board, int selected_column, int* selected_row_address, int num_rows, int num_columns);
#endif