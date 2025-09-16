#include "solver.h"
int main()
{
    int option;
    int grid[9][9];
    char filename[100];

    printf("Welcome to Sudoku Solver pick an option to enter your puzzle in: \n");
    printf("1: Enter file:\n");
    printf("2: Enter manually:\n");
    scanf("%d", &option);

    if (option == 1)
    {
        printf("\nEnter file name: \n");
        scanf("%s", filename);

        if (readFile(filename, grid) == 1)
        {
            printf("File successful\n");
        }
        else
        {
            printf("Error loading file\n");
            return 0;
        }

        initializeUsedArrays(grid);
        printf("Sudoku\n");
        printGrid(grid);

        if (solvePuzzle(grid))
        {
            printf("\nSudoku solved!\n");
            printGrid(grid);
        }
        else
        {
            printf("\nNo solution\n");
        }
    }
    else if (option == 2)
    {
        printf("Type in the 9x9 grid (use 0 for empty cells):\n");
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                printf("Enter value for cell [%d][%d]: ", row + 1, col + 1);
                scanf("%1d", &grid[row][col]);
            }
        }

        initializeUsedArrays(grid);
        printf("Sudoku\n");
        printGrid(grid);

        if (solvePuzzle(grid))
        {
            printf("\nSudoku solved!\n");
            printGrid(grid);
        }
        else
        {
            printf("\nNo solution\n");
        }
    }
    else
    {
        printf("\nNot an option\n");
        return 0;
    }

    return 0;
}
