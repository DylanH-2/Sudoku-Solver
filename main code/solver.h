#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void printGrid(int grid[9][9]);
int isSafe(int grid[9][9], int row, int col, int num);
int solvePuzzle(int grid[9][9]);
int readFile(char *filename, int grid[9][9]);
void initializeUsedArrays(int grid[9][9]);

#endif