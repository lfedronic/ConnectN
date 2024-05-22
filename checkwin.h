#ifndef CHECKWIN_H
#define CHECKWIN_H
    bool checkVerticalWin(char** game_board, int selected_column, int* selected_row_address, int num_rows, int num_columns, int row_of_highest_piece, int num_in_row_to_win, char char_to_check);
    bool checkHorizontalWin(char** game_board, int num_columns, int selected_column, int row_of_highest_piece, int num_in_row_to_win, char char_to_check);
    bool checkDownUpDiagonal(char** game_board, int num_columns, int num_rows, int selected_column, int row_of_highest_piece, int num_in_row_to_win, char char_to_check);
    bool checkUpDownDiagonal(char** game_board, int num_columns, int num_rows, int selected_column, int row_of_highest_piece, int num_in_row_to_win, char char_to_check);
    bool checkIfWinner(char** game_board, int num_rows, int num_columns, int num_in_row_to_win, int selected_column, int* selected_row_address, bool player1_turn);
#endif