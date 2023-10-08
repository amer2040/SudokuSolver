#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int ** create_board();
void print_board(int ** board);
bool isNuminRow(int ** board, int row, int num);
bool isNuminCol(int ** board, int col, int num);
bool isNuminBox(int ** board, int row, int col, int num);
bool is_cell_valid(int ** board, int row, int col, int num);
bool solveBoard(int ** board);

#endif