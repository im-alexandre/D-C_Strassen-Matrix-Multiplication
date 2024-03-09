#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void printMatrix(int **M, int n);
int **initializeMatrix(int n);
void allocMatrixes(int n);
void GenerateMatrixes(int n);
int** add(int **M1, int **M2, int n);
int **subtract(int **M1, int **M2, int n);
int **strassenMultiply(int **A, int **B, int n);
