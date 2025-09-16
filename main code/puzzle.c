#include "solver.h"

// Global boolean arrays for fast constraint checking
bool row_used[9][10] = {false};
bool col_used[9][10] = {false};
bool box_used[9][10] = {false};

void printGrid(int grid[9][9]) // pass in our puzzle as argument
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (grid[row][col] == 0)
            {
                printf(". ");
            }
            else
            {
                printf("%d ", grid[row][col]); // print out all numbers and a "." for empty spots
            }
            if ((col + 1) % 3 == 0 && col != 8) // vertical dividers
            {
                printf("| ");
            }
        }
        printf("\n");
        if ((row + 1) % 3 == 0 && row != 8) // horizontal dividers
        {
            printf("------+-------+------\n");
        }
    }
}

int isSafe(int grid[9][9], int row, int col, int num)
{
    int box = (row / 3) * 3 + (col / 3);
    if (row_used[row][num] || col_used[col][num] || box_used[box][num]) // if false number is safe to place
    {
        return 0;
    }
    return 1;
}

int solvePuzzle(int grid[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(grid, row, col, num)) // chekc if the num is valid to place at the spot
                    {
                        grid[row][col] = num;
                        int box = (row / 3) * 3 + (col / 3);
                        row_used[row][num] = true;
                        col_used[col][num] = true; // marks the num used in this area
                        box_used[box][num] = true;

                        if (solvePuzzle(grid)) // recursively solves the rest of the puzzle
                        {
                            return 1;
                        }
                        grid[row][col] = 0;
                        row_used[row][num] = false;
                        col_used[col][num] = false;
                        box_used[box][num] = false;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int readFile(char *filename, int grid[9][9])
{
    FILE *fp = fopen(filename, "r"); // file pointer to read

    if (fp == NULL)
    {
        printf("Unable to do file input\n");
        return 0;
    }

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            fscanf(fp, "%d", &grid[row][col]); // read every cell in the file
        }
    }

    fclose(fp);
    return 1;
}

void initializeUsedArrays(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int num = grid[i][j];
            if (num != 0)
            {
                int box = (i / 3) * 3 + (j / 3);
                row_used[i][num] = true;
                col_used[j][num] = true;
                box_used[box][num] = true;
            }
        }
    }
}