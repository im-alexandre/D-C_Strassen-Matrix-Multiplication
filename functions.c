#include "functions.h"
int **A;
int **B;
int **C;


int **strassenMultiply(int **A, int **B, int n)
{
	int** C = initializeMatrix(n);
	int k = n/2;

  	if (n == 1) {
    	int** C = initializeMatrix(1);
    	C[0][0] = A[0][0] * B[0][0];
    	return C;
	}

	else {
		int **A11 = initializeMatrix(k);
		int **A12 = initializeMatrix(k);
		int **A21 = initializeMatrix(k);
		int **A22 = initializeMatrix(k);
		int **B11 = initializeMatrix(k);
		int **B12 = initializeMatrix(k);
		int **B21 = initializeMatrix(k);
		int **B22 = initializeMatrix(k);

		for(int i=0; i<k; i++) {
		    for(int j=0; j<k; j++) {
		        A11[i][j] = A[i][j];
		        A12[i][j] = A[i][k+j];
		        A21[i][j] = A[k+i][j];
		        A22[i][j] = A[k+i][k+j];
		        B11[i][j] = B[i][j];
		        B12[i][j] = B[i][k+j];
		        B21[i][j] = B[k+i][j];
		        B22[i][j] = B[k+i][k+j];
	   		}
		}

		int** M1 = strassenMultiply(A11, subtract(B12, B22, k), k);
		int** M2 = strassenMultiply(add(A11, A12, k), B22, k);
		int** M3 = strassenMultiply(add(A21, A22, k), B11, k);
		int** M4 = strassenMultiply(A22, subtract(B21, B11, k), k);
		int** M5 = strassenMultiply(add(A11, A22, k), add(B11, B22, k), k);
		int** M6 = strassenMultiply(subtract(A12, A22, k), add(B21, B22, k), k);
		int** M7 = strassenMultiply(subtract(A11, A21, k), add(B11, B12, k), k);

		int** C11 = subtract(add(add(M5, M4, k), M6, k), M2, k);
		int** C12 = add(M1, M2, k);
		int** C21 = add(M3, M4, k);
		int** C22 = subtract(subtract(add(M5, M1, k), M3, k), M7, k);

		for(int i = 0; i < k; i++) {
		    for(int j = 0; j < k; j++) {
		        C[i][j] = C11[i][j];
		        C[i][j+k] = C12[i][j];
		        C[k+i][j] = C21[i][j];
		        C[k+i][k+j] = C22[i][j];
		    }
		}
	
		return C;
	}
}

int **subtract(int **M1, int **M2, int n)
{
    int **temp = initializeMatrix(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] - M2[i][j];

    return temp;
}

int** add(int **M1, int **M2, int n)
{
    int **temp = initializeMatrix(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] + M2[i][j];

    return temp;
}

int **initializeMatrix(int n)
{
	int **temp = (int **) malloc(n * sizeof(int *));
	for(int i = 0; i < n; i++)
		temp[i] = (int *) malloc(n * sizeof(int));

	return temp;
}

void allocMatrixes(int n)
{
	A = initializeMatrix(n);
	B = initializeMatrix(n);
	C = initializeMatrix(n);

	srand(time(0));

	for(int l = 0; l < n; l++)
	{
		for(int c = 0; c < n; c++)
		{
			A[l][c] = rand()%31;
			B[l][c] = rand()%31;
		}
	}
}

void GenerateMatrixes(int n)
{
	system("clear");
	printf("\nSerão geradas 2 matrizes 4 x 4 de inteiros aleatórios\n");
	allocMatrixes(n);
	sleep(1);
	printf("Matrizes geradas:\n\n");
	printf("Matriz A\n");
	printMatrix(A, n);
	printf("Matriz B\n");
	printMatrix(B, n);
}

void printMatrix(int **M, int n)
{
	for(int l = 0; l < n; l++) {
		for(int c = 0; c < n; c++) {
			printf("%d | ", M[l][c]);
		}
		printf("\n");
	}
	printf("\n");	
	
}
