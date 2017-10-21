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

// Our original

/*void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    for (int i = 0; i < size; i++) {
        if (board[row][i] == UNKNOWN) {
            if (i + 3 < size) {
                if (board[row][i+1] == RED) {
                    if (board[row][i+2] == RED) {
                        if (board[row][i+3] == UNKNOWN) {
                            mark_square_as(board, size, row, i+3, BLUE, announce);
                        }
                        mark_square_as(board, size, row, i, BLUE, announce);
                    }
                } else if (board[row][i+1] == BLUE) {
                    if (board[row][i+2] == BLUE) {
                        if (board[row][i+3] == UNKNOWN) {
                            mark_square_as(board, size, row, i+3, RED, announce);
                        }
                        mark_square_as(board, size, row, i, RED, announce);
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
}*/

// The new one

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    
    for(int i = 0; i < size; i++) {
        if(board[row][i] == RED && board[row][i+1] == RED) {
            if(i - 1 >= 0 && i + 2 <= size) {
                if (board[row][i-1] == UNKNOWN) {
                    mark_square_as(board, size, row, i-1, BLUE, announce);
                }
                if (board[row][i+2] == UNKNOWN) {
                    mark_square_as(board, size, row, i+2, BLUE, announce);
                }
            } else if(i + 1 == size && i - 1 >= 0) {
                if (board[row][i-1] == UNKNOWN) {
                    mark_square_as(board, size, row, i-1, BLUE, announce);
                }
            } else if(i == 0 && i + 2 <= size){
                if (board[row][i+2] == UNKNOWN) {
                    mark_square_as(board, size, row, i+2, BLUE, announce);
                }
            }
        } else if(board[row][i] == RED && board[row][i+2] == RED) {
            if (board[row][i+1] == UNKNOWN) {
                mark_square_as(board, size, row, i+1, BLUE, announce);
            }
        }
    }
    for(int i = 0; i < size; i++) {
        if(board[row][i] == BLUE && board[row][i+1] == BLUE) {
            if(i - 1 >= 0 && i + 2 <= size) {
                if (board[row][i-1] == UNKNOWN) {
                    mark_square_as(board, size, row, i-1, RED, announce);
                }
                if (board[row][i+2] == UNKNOWN) {
                    mark_square_as(board, size, row, i+2, RED, announce);
                }
            } else if(i + 1 == size && i - 1 >= 0) {
                if (board[row][i-1] == UNKNOWN) {
                    mark_square_as(board, size, row, i-1, RED, announce);
                }
            } else if(i == 0 && i + 2 <= size){
                if (board[row][i+2] == UNKNOWN) {
                    mark_square_as(board, size, row, i+2, RED, announce);
                }
            }
        } else if(board[row][i] == BLUE && board[row][i+2] == BLUE) {
            if (board[row][i+1] == UNKNOWN) {
                mark_square_as(board, size, row, i+1, RED, announce);
            }
        }
    }
}

// The original

/*void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
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
}*/

// The new one

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    
    for(int i = 0; i < size; i++) {
        if(board[i][col] == RED && board[i+1][col] == RED) {
            if(i - 1 >= 0 && i + 2 <= size) {
                if (board[i-1][col] == UNKNOWN) {
                    mark_square_as(board, size, i-1, col, BLUE, announce);
                }
                if (board[i+2][col] == UNKNOWN) {
                    mark_square_as(board, size, i+2, col, BLUE, announce);
                }
            }
            else if(i + 1 == size) {
                if (board[i-1][col] == UNKNOWN) {
                    mark_square_as(board, size, i-1, col, BLUE, announce);
                }
            }
            else {
                if (board[i+2][col] == UNKNOWN) {
                    mark_square_as(board, size, i+2, col, BLUE, announce);
                }
            }
        }
        else if(board[i][col] == RED && board[i+2][col] == RED) {
            if (board[i+1][col] == UNKNOWN) {
                mark_square_as(board, size, i+1, col, BLUE, announce);
            }
        }
    }
    for(int i = 0; i < size; i++) {
        if(board[i][col] == BLUE && board[i+1][col] == BLUE) {
            if(i - 1 >= 0 && i + 2 <= size) {
                if (board[i-1][col] == UNKNOWN) {
                    mark_square_as(board, size, i-1, col, RED, announce);
                }
                if (board[i+2][col] == UNKNOWN) {
                    mark_square_as(board, size, i+2, col, RED, announce);
                }
            }
            else if(i + 1 == size) {
                if (board[i-1][col] == UNKNOWN) {
                    mark_square_as(board, size, i-1, col, RED, announce);
                }
            }
            else {
                if (board[i+2][col] == UNKNOWN) {
                    mark_square_as(board, size, i+2, col, RED, announce);
                }
            }
        }
        else if(board[i][col] == BLUE && board[i+2][col] == BLUE) {
            if (board[i+1][col] == UNKNOWN) {
                mark_square_as(board, size, i+1, col, RED, announce);
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
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == UNKNOWN) {
                return false;
            }
        }
    }
    if (board_has_no_duplicates(board, size) & board_has_no_threes(board, size)) {
        return true;
    } else {
        return false;
    }
}

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
