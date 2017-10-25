
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
 * <Important functions for a Hioh game which validates and solves basic boards.>
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"
#include "driver.h"

///////////////////////////////////////
// UTILITY FUNCTIONS //////////////////
///////////////////////////////////////


// Check every member of the 2-dimensional array, and increment for each unknown

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
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

// Search the array for squares of the given color. Any square of a different color resets
// the counter, since clearly there must not be three in a row at that point.


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

// Do the exact same thing as row_has_no_threes_of_color(), except searching through columns

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
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

// Use the above two functions for both colors

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

// If any square is unknown, then automatically return true
// If the number of identical squares in each row is equivalent to the size,
// then the rows are the same. Otherwise they are different

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

// Do the same as rows_are_different() but for columns

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

// Iterate through every row and column and check if any are the same as another row/column

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        // Assign j to i + 1 so that i and j never equal each other
        // This ensures that no row or column will be compared with itself
        for (int j = i + 1; j < size; j++) {
            if (!rows_are_different(board, size, i, j) || 
                    !cols_are_different(board, size, i, j)) {
                return false;
             }
        }
    }
    return true;
}


///////////////////////////////////////
// SOLVING FUNCTIONS //////////////////
///////////////////////////////////////

/* *  Examine all non-unknown squares in the given row
   *  First, check if a square is identical to the following square
   *  If so, and the previous square is unknown, assign it to the opposite color
   *  Then check if a square is identical to the previous square
   *  If so, and the following square is unknown, assign it to the opposite color
   *  Lastly, check if the square is identical to the square located two spaces to the right
   *  If it is, and the square in between them is unknown, assign it to the opposite color
*/

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    
     for (int i = 0; i < size - 1; i++) {
        if (board[row][i] != UNKNOWN) {
            if (board[row][i] == board[row][i + 1]) {
                if (i - 1 >= 0 && board[row][i - 1] == UNKNOWN) {
                    mark_square_as(board, size, row, i - 1, opposite_color(board[row][i]), announce);
                }
            }
            if (i - 1 >= 0 && board[row][i] == board[row][i - 1]) {
                if (board[row][i + 1] == UNKNOWN) {
                    mark_square_as(board, size, row, i + 1, opposite_color(board[row][i]), announce);
                }
            }
            if (i + 2 < size && board[row][i] == board[row][i+2]) {
                if (board[row][i + 1] == UNKNOWN) {
                    mark_square_as(board, size, row, i + 1, opposite_color(board[row][i]), announce);
                }
            }
        }
    }
}

// Do the same as solve_three_in_a_row() except for columns

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
     for (int i = 0; i < size - 1; i++) {
        if (board[i][col] != UNKNOWN) {
            if (board[i][col] == board[i + 1][col]) {
                if (i - 1 >= 0 && board[i - 1][col] == UNKNOWN) {
                    mark_square_as(board, size, i - 1, col, opposite_color(board[i][col]), announce);
                }
            }
            if (i - 1 >= 0 && board[i][col] == board[i - 1][col]) {
                if (board[i + 1][col] == UNKNOWN) {
                    mark_square_as(board, size, i + 1, col, opposite_color(board[i][col]), announce);
                }
            }
            if (i + 2 < size && board[i][col] == board[i + 2][col]) {
                if (board[i + 1][col] == UNKNOWN) {
                    mark_square_as(board, size, i + 1, col, opposite_color(board[i][col]), announce);
                }
            }
        }
    }
}

/*  *  Determine how many red and blue squares there are in each row
    *  If squares of any color are present in exactly half the squares of a row, 
    *  assign all the rest to the opposite color
*/

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

// Do the same as solve_balance_row() except for columns

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

// First, check if any square in the board is unknown. If so, then the board is unsolved
// Next use all three validation functions. If all return true, then the board is solved

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    if (count_unknown_squares(board, size) > 0) return false;
    if (board_is_valid(board, size)) {
        return true;
    } else {
        return false;
    }
}

// Confirm that all input values correspond to their function

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    if (row_input >= 1 && row_input <= size) {
        if (toupper(col_input) >= 'A' && 
                toupper(col_input) <= ('A' + size - 1)) {
            if (toupper(color_char) == UNKNOWN_LETTER ||
                    toupper(color_char) == RED_LETTER ||
                    toupper(color_char) == BLUE_LETTER) {
                row = row_input - 1;
                col = toupper(col_input) - 'A';
                return true;
            }
        }
    }
    cout << "Sorry, that's not a valid input." << endl;
    return false;
}

// If the given move uses a square that was originally set to a color, then the move is invalid
// If it passes the first check, make a copy and check if the move breaks any rules

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    if (original_board[row][col] == UNKNOWN) {
        int copyBoard[MAX_SIZE][MAX_SIZE];
        copy_board(current_board, copyBoard, size);
        copyBoard[row][col] = color;
        if (board_is_valid(copyBoard, size)) {
            return true;
        } else {
            cout << "Sorry, that move violates a rule." << endl;
            return false;
        }
    } else {
        cout << "Sorry, original squares cannot be changed." << endl;
        return false;
    }
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
