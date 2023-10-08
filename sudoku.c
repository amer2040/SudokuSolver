#include "sudoku.h"

/**
 * main - Entry point.
 *
 * Return: void.
*/
int main(void)
{
	int **board;

	board = create_board();

	printf("Lets try to solve this sudoku board:\n");

	print_board(board);

	if (solveBoard(board))
	{
		printf("Solved successfully!\n");
	}
	else
	{
		printf("Unsolvable board!\n");
	}

	print_board(board);

}
