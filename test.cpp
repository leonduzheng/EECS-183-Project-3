/**
 * test.cpp
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Fall 2017
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
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

// declare more test functions here

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
    
    // add calls to test functions here
    
    return 0;
}


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
    
    string test_board_1[] = {"O-OX",
        "OO--",
        "X---",
        "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << rows_are_different(board, size_1, 0, 1)  << endl;
    
    // test case 2
    
    string test_board_2[] = {"O-OX",
        "O-OX",
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
    
    string test_board_1[] = {"O-OX",
        "OO--",
        "X---",
        "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << cols_are_different(board, size_1, 0, 1)  << endl;
    
    // test case 2
    
    string test_board_2[] = {"--OX",
        "--OX",
        "----",
        "OO--"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << cols_are_different(board, size_2, 0, 1)  << endl;
}

void test_board_has_no_duplicates() {
    cout << "board_has_no_duplicates()" << endl;
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    
    string test_board_1[] = {"O-OX",
        "OO--",
        "X---",
        "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_duplicates(board, size_1) << endl;
    
    // test case 2
    
    string test_board_2[] = {"O-OX",
        "O---",
        "O-OX",
        "-O--"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_duplicates(board, size_2) << endl;
    
    // test case 3
    
    string test_board_3[] = {"O-OO",
        "O--O",
        "OOXO",
        "-O--"};
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

// define more test functions here
