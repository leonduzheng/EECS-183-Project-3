/**
 * test.cpp
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Fall 2017
 *
 * <Grace Xu, Noah Weingarden>
 * <xugrace, nwein>
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();
void test_board_is_solved();
void test_check_valid_input();
void test_check_valid_move();

// declare more test functions here

/*

int main() {
    test_count_unknown_squares();
    test_row_has_no_threes_of_color();
    test_col_has_no_threes_of_color();
    test_board_has_no_threes();
    test_rows_are_different();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_solve_balance_row();
    test_solve_balance_column();
    test_board_is_solved();
    test_check_valid_input();
    test_check_valid_move();
    
    // add calls to test functions here
    
    return 0;
}

*/


void test_count_unknown_squares() {
    cout << "count_unknown_squares()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"O-OX",
        "OO--",
        "X---",
        "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;
    
    // add more tests here
    
    // test case 2
    string test_board_2[] = {"----",
        "----",
        "----",
        "----"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << count_unknown_squares(board, size_2) << endl;
    
}

void test_row_has_no_threes_of_color() {
    cout << "row_has_no_threes_of_color()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    
    string test_board_1[] = {"O-OX",
        "OO--",
        "X---",
        "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board, size_1, 0, BLUE) << endl;
    
    // test case 2
    string test_board_2[] = {"OOOX",
        "OO--",
        "X---",
        "-O--"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << row_has_no_threes_of_color(board, size_2, 0, BLUE) << endl;
    
    // test case 3
    string test_board_3[] = {"OOOX",
        "OXXX",
        "X---",
        "-O--"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << row_has_no_threes_of_color(board, size_3, 1, RED) << endl;
}

void test_col_has_no_threes_of_color() {
    cout << "col_has_no_threes_of_color()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    
    string test_board_1[] = {"O-OX",
        "OO--",
        "X---",
        "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << col_has_no_threes_of_color(board, size_1, 0, BLUE) << endl;
    
    // test case 2
    string test_board_2[] = {"O-OX",
        "OO--",
        "O---",
        "-O--"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << col_has_no_threes_of_color(board, size_2, 0, BLUE) << endl;
    
    // test case 3
    string test_board_3[] = {"OOOX",
        "OXXX",
        "X--X",
        "-O-O"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << col_has_no_threes_of_color(board, size_3, 3, RED) << endl;
    
    // test case 4
    string test_board_4[] = {"O-OX",
        "OO--",
        "O---",
        "-O--"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << col_has_no_threes_of_color(board, size_4, 0, BLUE) << endl;
    
    // test case 5
    string test_board_5[] = {"OOOX",
        "OO--",
        "X---",
        "-O--"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << col_has_no_threes_of_color(board, size_5, 0, BLUE) << endl;
    
}

void test_board_has_no_threes() {
    cout << "board_has_no_threes()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    
    string test_board_1[] = {"O-OX",
        "OO--",
        "X---",
        "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_threes(board, size_1)  << endl;
    
    // test case 2
    
    string test_board_2[] = {"O-OX",
        "OO--",
        "O---",
        "-O--"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_threes(board, size_2)  << endl;
    
    // test case 3
    string test_board_3[] = {"XXXO",
        "XO--",
        "O---",
        "-O--"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_threes(board, size_3)  << endl;
}

void test_rows_are_different() {
    cout << "rows_are_different()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    
    string test_board_1[] = {"OXOX",
        "OOXO",
        "XOOO",
        "XOXO"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << rows_are_different(board, size_1, 0, 1)  << endl;
    
    // test case 2
    
    string test_board_2[] = {"OXOX",
        "OXOX",
        "X---",
        "-O--"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << rows_are_different(board, size_2, 0, 1)  << endl;
}

void test_cols_are_different() {
    cout << "cols_are_different()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    
    string test_board_1[] = {"OXOX",
        "OOXX",
        "XOXX",
        "OOXX"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << cols_are_different(board, size_1, 0, 1)  << endl;
    
    // test case 2
    
    string test_board_2[] = {"XXOX",
        "OOOX",
        "XXOO",
        "OOXO"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << cols_are_different(board, size_2, 0, 1)  << endl;
}

void test_board_has_no_duplicates() {
    cout << "board_has_no_duplicates()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    
    string test_board_1[] = {"OXOX",
        "OOXX",
        "XOXO",
        "OXXO"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_duplicates(board, size_1) << endl;
    
    // test case 2
    
    string test_board_2[] = {"OXOX",
        "XOXX",
        "OXOX",
        "XOXO"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_duplicates(board, size_2) << endl;
    
    // test case 3
    
    string test_board_3[] = {"OXOO",
                             "OXOO",
                             "XXOO",
                             "OOOO"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_duplicates(board, size_3) << endl;
    
}

void test_solve_three_in_a_row() {
    cout << "solve_three_in_a_row()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    
    string test_board_1[] = {"-OO-",
        "OO--",
        "X---",
        "-O--"};
    int size_1 = 4;
    int row = 0;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_row(board, size_1, row, true);
    for (int i = 0; i < size_1; i++) {
        cout << board[row][i];
    }
    cout << endl;
    
    // test case 2
    
    string test_board_2[] = {"-OOX",
        "-X-X",
        "X---",
        "-O--"};
    int size_2 = 4;
    row = 1;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_row(board, size_2, row, true);
    for (int i = 0; i < size_2; i++) {
        cout << board[row][i];
    }
    cout << endl;
    
    // test case 3
    
    string test_board_3[] = {"-OOXX-",
        "-X-XXO",
        "O-OO--",
        "-O--XO",
        "X--OX-",
        "--X-OO"};
    int size_3 = 6;
    row = 2;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_row(board, size_3, row, true);
    for (int i = 0; i < size_3; i++) {
        cout << board[row][i];
    }
    cout << endl;
    
}

void test_solve_three_in_a_column() {
    cout << "solve_three_in_a_column()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    
    string test_board_1[] = {"--O-",
                             "OO--",
                             "O---",
                             "-X--"};
    int size_1 = 4;
    int col = 0;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_column(board, size_1, col, true);
    for (int i = 0; i < size_1; i++) {
        cout << board[i][col] << endl;
    }
    cout << endl;
    
    // test case 2
    
    string test_board_2[] = {"-OOX",
                             "-X-X",
                             "X---",
                             "-X--"};
    int size_2 = 4;
    col = 1;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_column(board, size_2, col, true);
    for (int i = 0; i < size_2; i++) {
        cout << board[i][col] << endl;
    }
    cout << endl;
    
    // test case 3
    
    string test_board_3[] = {"-OOXX-",
                             "-X-XXO",
                             "O-OO--",
                             "-OO-XO",
                             "X--OX-",
                             "----OO"};
    int size_3 = 6;
    col = 2;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_column(board, size_3, col, true);
    for (int i = 0; i < size_3; i++) {
        cout << board[i][col] << endl;
    }
    cout << endl;
    
}

void test_solve_balance_row() {
    cout << "solve_balance_row()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    
    string test_board_1[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_1 = 4;
    int row = 1;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_row(board, size_1, row, true);
    for (int i = 0; i < size_1; i++) {
        cout << board[row][i];
    }
    cout << endl;

    // test case 2
    
    string test_board_2[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_2 = 4;
    row = 2;
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_row(board, size_2, row, true);
    for (int i = 0; i < size_2; i++) {
        cout << board[row][i];
    }
    cout << endl;

    // test case 3
    
    string test_board_3[] = {"----",
                             "XX--",
                             "-OO-",
                             "--X-"};
    int size_3 = 4;
    row = 2;
    read_board_from_string(board, test_board_3, size_3);
    solve_balance_row(board, size_3, row, true);
    for (int i = 0; i < size_3; i++) {
        cout << board[row][i];
    }
    cout << endl;
    // test case 4
    
    string test_board_4[] = {"----",
                             "XX--",
                             "-OO-",
                             "--X-"};
    int size_4 = 4;
    row = 3;
    read_board_from_string(board, test_board_4, size_4);
    solve_balance_row(board, size_4, row, true);
    for (int i = 0; i < size_4; i++) {
        cout << board[row][i];
    }
    cout << endl;
}

void test_solve_balance_column() {
    cout << "solve_balance_column()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    
    string test_board_1[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_1 = 4;
    int col = 1;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_column(board, size_1, col, true);
    for (int i = 0; i < size_1; i++) {
        cout << board[i][col] << endl;
    }
    cout << endl;

    // test case 2
    
    string test_board_2[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_2 = 4;
    col = 2;
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_column(board, size_2, col, true);
    for (int i = 0; i < size_2; i++) {
        cout << board[i][col] << endl;
    }
    cout << endl;

    // test case 3
    
    string test_board_3[] = {"----",
                             "XXO-",
                             "-OO-",
                             "XO--"};
    int size_3 = 4;
    col = 2;
    read_board_from_string(board, test_board_3, size_3);
    solve_balance_column(board, size_3, col, true);
    for (int i = 0; i < size_3; i++) {
        cout << board[i][col] << endl;
    }
    cout << endl;
    // test case 4
    
    string test_board_4[] = {"----",
                             "XX-O",
                             "-OOX",
                             "--X-"};
    int size_4 = 4;
    col = 3;
    read_board_from_string(board, test_board_4, size_4);
    solve_balance_column(board, size_4, col, true);
    for (int i = 0; i < size_4; i++) {
        cout << board[i][col] << endl;
    }
    cout << endl;
}

void test_board_is_solved() {
    cout << "board_is_solved()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    
    string test_board_1[] = {"OOXX",
                            "OXXO",
                            "XXOO",
                            "XOOX"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_is_solved(board, size_1) << endl;

    // test case 2
    
    string test_board_2[] = {"XXOO",
                            "OXOX",
                            "OOXX",
                            "XOXO"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_is_solved(board, size_2) << endl;

    // test case 3
    
    string test_board_3[] = {"OOXX",
                            "XXOO",
                            "OXOX",
                            "XOXO"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_is_solved(board, size_3) << endl;

    // test case 4
    
    string test_board_4[] = {"XXOOXO",
                            "XOXXOO",
                            "OOXOXX",
                            "OXOXXO",
                            "XOXOOX",
                            "OXOXOX"};
    int size_4 = 6;
    read_board_from_string(board, test_board_4, size_4);
    cout << board_is_solved(board, size_4) << endl;

    // test case 5
    
    string test_board_5[] = {"XXOOXO",
                            "XOXXOO",
                            "OOOOXX",
                            "OXOXXO",
                            "XOXOOX",
                            "XXOXOX"};
    int size_5 = 6;
    read_board_from_string(board, test_board_5, size_5);
    cout << board_is_solved(board, size_5) << endl;
}

void test_check_valid_input() {
    cout << "check_valid_input()" << endl;

    // Test case 1

    int size = 4;
    int row_input = 3;
    char col_input = 'B';
    char color_char = 'X';
    int row = 0;
    int col = 0;
    cout << check_valid_input(size, row_input, col_input, color_char, row, col) << endl;

    // Test case 2

    size = 4;
    row_input = 5;
    col_input = 'A';
    color_char = 'O';
    row = 0;
    col = 0;
    cout << check_valid_input(size, row_input, col_input, color_char, row, col) << endl;

    // Test case 3
    
    size = 4;
    row_input = 1;
    col_input = 'A';
    color_char = 'O';
    row = 0;
    col = 0;
    cout << check_valid_input(size, row_input, col_input, color_char, row, col) << endl;

    // Test case 4
    
    size = 4;
    row_input = 4;
    col_input = 'D';
    color_char = 'X';
    row = 0;
    col = 0;
    cout << check_valid_input(size, row_input, col_input, color_char, row, col) << endl;

    // Test case 5
    
    size = 4;
    row_input = 4;
    col_input = 'E';
    color_char = 'O';
    row = 0;
    col = 0;
    cout << check_valid_input(size, row_input, col_input, color_char, row, col) << endl;


    // Test case 6
    
    size = 4;
    row_input = 4;
    col_input = 'd';
    color_char = 'x';
    row = 0;
    col = 0;
    cout << check_valid_input(size, row_input, col_input, color_char, row, col) << endl;

    // Test case 7
    
    size = 4;
    row_input = 4;
    col_input = 'd';
    color_char = 'C';
    row = 0;
    col = 0;
    cout << check_valid_input(size, row_input, col_input, color_char, row, col) << endl;

    // Test case 8
    
    size = 4;
    row_input = 1;
    col_input = 'b';
    color_char = '-';
    row = 0;
    col = 0;
    cout << check_valid_input(size, row_input, col_input, color_char, row, col) << endl;
}

void test_check_valid_move() {
    cout << "check_valid_move()" << endl;
    
    // test case 1
    
    int originalBoard[MAX_SIZE][MAX_SIZE];
    string test_board[] =   {"----",
                             "XXO-",
                             "-XO-",
                             "--X-"};
    int currentBoard[MAX_SIZE][MAX_SIZE];
    string test_current_board[] =   {"---X",
                                     "XXOO",
                                     "XXO-",
                                     "--X-"};
    int size = 4;
    int row = 2;
    int col = 3;
    int color = BLUE;
    read_board_from_string(originalBoard, test_board, size);
    read_board_from_string(currentBoard, test_current_board, size);

    cout << check_valid_move(originalBoard, currentBoard, size, row, col, color) << endl;

    // Test case 2

    size = 4;
    row = 3;
    col = 2;
    color = BLUE;
    read_board_from_string(originalBoard, test_board, size);
    read_board_from_string(currentBoard, test_current_board, size);

    cout << check_valid_move(originalBoard, currentBoard, size, row, col, color) << endl;

    // Test case 3

    size = 4;
    row = 0;
    col = 0;
    color = BLUE;
    read_board_from_string(originalBoard, test_board, size);
    read_board_from_string(currentBoard, test_current_board, size);

    cout << check_valid_move(originalBoard, currentBoard, size, row, col, color) << endl;

    // Test case 4

    size = 4;
    row = 1;
    col = 3;
    color = UNKNOWN;
    read_board_from_string(originalBoard, test_board, size);
    read_board_from_string(currentBoard, test_current_board, size);

    cout << check_valid_move(originalBoard, currentBoard, size, row, col, color) << endl;

    // Test case 5

    size = 4;
    row = 0;
    col = 3;
    color = BLUE;
    read_board_from_string(originalBoard, test_board, size);
    read_board_from_string(currentBoard, test_current_board, size);

    cout << check_valid_move(originalBoard, currentBoard, size, row, col, color) << endl;

    // Test case 6

    size = 4;
    row = 0;
    col = 0;
    color = RED;
    read_board_from_string(originalBoard, test_board, size);
    read_board_from_string(currentBoard, test_current_board, size);

    cout << check_valid_move(originalBoard, currentBoard, size, row, col, color) << endl;


}
