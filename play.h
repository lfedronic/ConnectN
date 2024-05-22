#ifndef PLAY_H
#define PLAY_H
    char*** takeTurn(bool player1_turn, char*** game_board_address, int num_rows, int num_columns, int num_in_row_to_win);
    void playGame(char*** game_board_address, int num_rows, int num_columns, int num_in_row_to_win);
#endif