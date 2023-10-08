#include "sudoku.h"

/**
 * create_board - function for creating a test board of sudoku board
 *
 * Return: Created board.
*/
int **create_board()
{
	int **board;
	int x, y;
	int puzzle[9][9] = {0, 1, 9,    0, 0, 2,    0, 0, 0,
						4, 7, 0,    6, 9, 0,    0, 0, 1,
						0, 0, 0,    4, 0, 0,    0, 9, 0,

						8, 9, 4,    5, 0, 7,    0, 0, 0,
						0, 0, 0,    0, 0, 0,    0, 0, 0,
						0, 0, 0,    2, 0, 1,    9, 5, 8,

						0, 5, 0,    0, 0, 6,    0, 0, 0,
						6, 0, 0,    0, 2, 8,    0, 7, 9,
						0, 0, 0,    1, 0, 0,    8, 6, 0 };

	board = (int **)malloc(sizeof(int *) * 9);

	for (x = 0; x < 9; x++)
	{
		board[x] = (int *)malloc(sizeof(int *) * 9);

		for (y = 0; y < 9; y++)
		{
			board[x][y] = puzzle[x][y];
		}
	}

	return (board);
}

/**
 *  print_board - function to print the sudoku board.
 * @board: sudoku board given to print.
*/
void print_board(int **board)
{
	int x, y;

	printf("+-------+-------+-------+\n");
	for (x = 0; x < 9; x++)
	{

		printf("|");
		for (y = 0; y < 9; y++)
		{
			printf(" %d", board[x][y]);

			if (((y + 1) % 3) == 0)
			{
				printf(" |");
			}
		}
		printf("\n");
		if (((x + 1) % 3) == 0)
		{
			printf("+-------+-------+-------+\n");
		}
	}
}

/**
 * isNuminRow - function to check if given number is in sudoku board row.
 *
 * @board: sudoku board given.
 * @row: number of row.
 * @num: number given to check if is equal the number in row or not.
 *
 * Return: true if number is in sudoku board row
 *          false if not.
*/
bool isNuminRow(int **board, int row, int num)
{
	for (int x = 0; x < 9; x++)
	{
		if (board[row][x] == num)
		{
			return (true);
		}
	}
	return (false);
}

/**
 * isNuminCol - function to check if given number is in sudoku board column.
 *
 * @board: sudoku board given.
 * @col: number of column.
 * @num: number given to check if is equal the number in column or not.
 *
 * Return: true if number is in sudoku board column
 *          false if not.
*/
bool isNuminCol(int **board, int col, int num)
{
	for (int x = 0; x < 9; x++)
	{
		if (board[x][col] == num)
		{
			return (true);
		}
	}
	return (false);
}

/**
 * isNuminBox - function to check if given number is in sudoku board Box 3x3.
 *
 * @board: sudoku board given.
 * @row: number of row.
 * @col: number of column.
 * @num: number given to check if is equal the number in box 3x3.
 *
 * Return: true if number is in sudoku board Box 3x3
 *          false if not.
*/
bool isNuminBox(int **board, int row, int col, int num)
{
	int boxrow = row - row % 3;
	int boxcol = col - col % 3;

	for (int x = boxrow; x < boxrow + 3; x++)
	{
		for (int y = boxcol; y < boxcol + 3; y++)
		{
			if (board[x][y] == num)
			{
				return (true);
			}
		}
	}
	return (false);
}

/**
 * is_cell_valid - function to check if cell is valid to put the number in it.
 *
 * @board: sudoku board given.
 * @row: number of row.
 * @col: number of column.
 * @num: number given to check if current cell valid add this number or not.
 *
 * Return: True if cell is valid to add number
 *          false if not.
*/
bool is_cell_valid(int **board, int row, int col, int num)
{
	if (!isNuminRow(board, row, num)
	&& !isNuminCol(board, col, num)
	&& !isNuminBox(board, row, col, num))
	{
		return (true);
	}
	return (false);
}

/**
 * solveBoard - function to solve sudoku board by given the board to solve it .
 *
 * @board: sudoku board given to solve.
 *
 * Return: True if can soloved
 *          false if can not solve it.
*/
bool solveBoard(int **board)
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (board[row][col] == 0)
			{
				for (int numtry = 1; numtry <= 9; numtry++)
				{
					if (is_cell_valid(board, row, col, numtry))
					{
						board[row][col] = numtry;

						if (solveBoard(board))
						{
							return (true);
						}
						else
						{
							board[row][col] = 0;
						}
					}
				}
				return (false);
			}
		}
	}
	return (true);
}
