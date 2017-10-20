/**
 * ohhi.cpp
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2017
 *
 * Grace Xu, Noah Weingarden
 * xugrace, nwein
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

///////////////////////////////////////
// UTILITY FUNCTIONS //////////////////
///////////////////////////////////////

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // your code here
    int counter = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(board[i][j] == UNKNOWN){
                counter++;
            }
        }
    }
    return counter;
}


///////////////////////////////////////
// VALIDITY CHECKS ////////////////////
///////////////////////////////////////

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (board[row][i] == color) {
            counter++;
        } else {
            counter = 0;
        }
        if (counter >= 3) {
            return false;
        }
    }
    
    return true;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    // your code here
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (board[i][col] == color) {
            counter++;
        } else {
            counter = 0;
        }
        if (counter >= 3) {
            return false;
        }
    }
    
    return true;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        if (!(row_has_no_threes_of_color(board, size, i, RED)) ||
            !(row_has_no_threes_of_color(board, size, i, BLUE)) ||
            !(col_has_no_threes_of_color(board, size, i, RED)) ||
            !(col_has_no_threes_of_color(board, size, i, BLUE))) {
            return false;
        }
    }
    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (board[row1][i] == UNKNOWN || board[row2][i] == UNKNOWN) {
            return true;
        }
        if (board[row1][i] == board[row2][i]) {
            counter++;
        }
    }
    if (counter == size) {
        return false;
    } else {
        return true;
    }
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (board[i][col1] == UNKNOWN || board[i][col2] == UNKNOWN) {
            return true;
        }
        if (board[i][col1] == board[i][col2]) {
            counter++;
        }
    }
    if (counter == size) {
        return false;
    } else {
        return true;
    }
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; i < size; i++) {
            if (i != j) {
                if (!rows_are_different(board, size, i, j) || !cols_are_different(board, size, i, j)) {
                    return false;
                }
            }
        }
    }
    return true;
}


///////////////////////////////////////
// SOLVING FUNCTIONS //////////////////
///////////////////////////////////////

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    for (int i = 0; i < size; i++) {
        if (board[row][i] == UNKNOWN) {
            if (i + 3 < size) {
                if (board[row][i+1] == RED) {
                    if (board[row][i+2] == RED) {
                        if (board[row][i+3] == UNKNOWN) {
                            mark_square_as(board, size, row, i, BLUE, announce);
                            mark_square_as(board, size, row, i+3, BLUE, announce);
                        }
                    }
                } else if (board[row][i+1] == BLUE) {
                    if (board[row][i+2] == BLUE) {
                        if (board[row][i+3] == UNKNOWN) {
                            mark_square_as(board, size, row, i, RED, announce);
                            mark_square_as(board, size, row, i+3, RED, announce);
                        }
                    }
                }
            }
            if ((i - 1 >= 0) && (i + 1 < size)) {
                if (board[row][i-1] == RED) {
                    if (board[row][i+1] == RED) {
                        mark_square_as(board, size, row, i, BLUE, announce);
                    }
                } else if (board[row][i-1] == BLUE) {
                    if (board[row][i+1] == BLUE) {
                        mark_square_as(board, size, row, i, RED, announce);
                    }
                }
            }
            
        }
    }
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    // your code here
    for (int i = 0; i < size; i++) {
        if (board[i][col] == UNKNOWN) {
            if (i + 3 < size) {
                if (board[i+1][col] == RED) {
                    if (board[i+2][col] == RED) {
                        if (board[i+3][col] == UNKNOWN) {
                            mark_square_as(board, size, i, col, BLUE, announce);
                            mark_square_as(board, size, i+3, col, BLUE, announce);
                        }
                    }
                } else if (board[i+1][col] == BLUE) {
                    if (board[i+2][col] == BLUE) {
                        if (board[i+3][col] == UNKNOWN) {
                            mark_square_as(board, size, i, col, RED, announce);
                            mark_square_as(board, size, i+3, col, RED, announce);
                        }
                    }
                }
            }
            if ((i - 1 >= 0) && (i + 1 < size)) {
                if (board[i-1][col] == RED) {
                    if (board[i+1][col] == RED) {
                        mark_square_as(board, size, i, col, BLUE, announce);
                    }
                } else if (board[i-1][col] == BLUE) {
                    if (board[i+1][col] == BLUE) {
                        mark_square_as(board, size, i, col, RED, announce);
                    }
                }
            }
            
        }
    }
}



void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    int blueCount = 0;
    int redCount = 0;
    for (int i = 0; i < size; i++) {
        if (board[row][i] == RED) {
            redCount++;
        } else if (board[row][i] == BLUE) {
            blueCount++;
        }
    }
    if (blueCount == (size / 2)) {
        for (int i = 0; i < size; i++) {
            if (board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, RED, announce);
            }
        }
    }
    if (redCount == (size / 2)) {
        for (int i = 0; i < size; i++) {
            if (board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, BLUE, announce);
            }
        }
    }
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    int blueCount = 0;
    int redCount = 0;
    for (int i = 0; i < size; i++) {
        if (board[i][col] == RED) {
            redCount++;
        } else if (board[i][col] == BLUE) {
            blueCount++;
        }
    }
    if (blueCount == (size / 2)) {
        for (int i = 0; i < size; i++) {
            if (board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, RED, announce);
            }
        }
    }
    if (redCount == (size / 2)) {
        for (int i = 0; i < size; i++) {
            if (board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, BLUE, announce);
            }
        }
    }
}


///////////////////////////////////////
// GAMEPLAY FUNCTIONS /////////////////
///////////////////////////////////////

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // your code here
    return false;
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    // your code here
    return false;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    // your code here
    return false;
}


///////////////////////////////////////
// S'MORE FUNCTIONS ///////////////////
///////////////////////////////////////


void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
                         int size,
                         int row,
                         bool announce) {
    // your code here
}

void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
                            int size,
                            int col,
                            bool announce) {
    // your code here
}
